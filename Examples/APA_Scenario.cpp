/* ==================================================================
* Copyright (c) 2020,xxxx.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the
* distribution.
* 3. All advertising materials mentioning features or use of this software
* must display the following acknowledgement:
* This product includes software developed by the xxx Group. and
* its contributors.
* 4. Neither the name of the Group nor the names of its contributors may
* be used to endorse or promote products derived from this software
* without specific prior written permission.
* 5. Licensed under the GNU General Public License v3.0;
* you may not use this file except in compliance with the License.
*
* THIS SOFTWARE IS PROVIDED BY xxx,GROUP AND CONTRIBUTORS
* ===================================================================
* Author: Mobo
* Mail: mobojingjiniao@126.com
*/

#include <string.h>
#include <thread>
#include "Scene/TPScene.hpp"
#include "Ground/Ground.hpp"
#include "TPObjectBase.hpp"
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/NodeTrackerManipulator>

#include <osgViewer/CompositeViewer>
#include "Sensors/TPSensorUnknow.hpp"
#include "Sensors/TPSensorCamera.hpp"
#include "RSP/TPPoint_RSP.hpp"
#include "Scene/TrafficPaticipantCamera.hpp"
#include "Trajectory/TPLaneCurveLine.hpp"
#include "Trajectory/TPStraightLine.hpp"
#include "Lane/TPLaneClothidObject.hpp"
#include "ParkingSlot/TPParkingSlotObject.hpp"
#include "MovingObject/MovingObject.hpp"
#include "Point/TPPointObject.hpp"

#include "Modules/Viewer/TPViewer.hpp"

static TPViewer viewer;

osgViewer::View* createView( int screenNum )
{
    unsigned int width = 800, height = 600;
    osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();
    if ( wsi )
        wsi->getScreenResolution( osg::GraphicsContext::ScreenIdentifier(screenNum), width, height );


    // This works under Windows only
    osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
    //traits->screenNum = screenNum;
    traits->x = 0;
    traits->y = 0;
    traits->width = 800;
    traits->height = 600;
    traits->windowDecoration = false;
    traits->doubleBuffer = true;
    osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get() );
    if(!gc) {
        printf("error\n");
    }
    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
    camera->setGraphicsContext( gc );
    camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
    camera->setClearMask( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );
    camera->setClearColor( osg::Vec4f(0.2f, 0.2f, 0.6f, 1.0f) );
    camera->setProjectionMatrixAsPerspective(30.0f, (double)traits->width/(double)traits->height,1.0, 1000.0 );
    GLenum buffer = traits->doubleBuffer ? GL_BACK : GL_FRONT;

    // camera->setDrawBuffer( buffer );
    // camera->setReadBuffer( buffer );

    osg::ref_ptr<osgViewer::View> view = new osgViewer::View;
    view->setCamera( camera.get() );

    //view->setCameraManipulator( new osgGA::TrackballManipulator );
    return view.release();


}

void setSpdlogCFG()
{

    // setup logger
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] %^[%L] %v%$");
    // with timestamp, thread_id, filename and line number
    //spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%f <thread %t> [%l] [%@] %v");

    //spdlog::set_level(spdlog::level::trace);
    spdlog::set_level(spdlog::level::info);
    //spdlog::set_level(spdlog::level::info);

}

void run()
{

    //! add sensor list
    osg::ref_ptr<TPSensorBase> unknowSensor = new TPSensorUnknow(0);
    TPScene::getInstance().addNewSensor(unknowSensor);

    osg::ref_ptr<TPSensorBase> cameraSensor = new TPSensorCamera(1, 40.0f);
    TPScene::getInstance().addNewSensor(cameraSensor);


    //! moving Object
    osg::ref_ptr<MovingObject> pedestrain = new MovingObject(0, TP_OBJECT_TYPE_D_PEDESTRAIN);
    pedestrain->m_observerSensor = unknowSensor;
    // pedestrain->updateObjectFormat(psPar);
    pedestrain->updateObjectPos(osg::Vec3d(150, 200, 0));
    TPScene::getInstance().updateTPObject(pedestrain);


    osg::ref_ptr<MovingObject> truck = new MovingObject(0, TP_OBJECT_TYPE_D_TRUCK);
    truck->m_observerSensor = unknowSensor;
    // pedestrain->updateObjectFormat(psPar);
    truck->updateObjectPos(osg::Vec3d(100, 1500, 0));
    TPScene::getInstance().updateTPObject(truck);


    osg::ref_ptr<MovingObject> dog = new MovingObject(0, TP_OBJECT_TYPE_D_DOG);
    dog->m_observerSensor = unknowSensor;
    std::shared_ptr<MovingObjectFormat> dogPar = std::make_shared<MovingObjectFormat>();
    // Contour* dogcontor = dogPar->mutable_contour();
    // dogcontor->set

    // dog->updateObjectFormat(dogPar);
    dog->updateObjectPos(osg::Vec3d(300, 250, 0));
    TPScene::getInstance().updateTPObject(dog);

    //! Parking slot info

    float32 widh = 200.0f, length = 450.0f;
    float32 start_x = 200.0f, start_y = -2000.0f;
    float32 offset = 10.0f;
    int PSCnt = 25;
    osg::Vec3d  pos1(start_x,          start_y,        0.0f);
    osg::Vec3d  pos2(start_x,          start_y + widh, 0.0f);
    osg::Vec3d  pos3(start_x + length, start_y + widh, 0.0f);
    osg::Vec3d  pos4(start_x + length, start_y,        0.0f);


    for(int i = 0; i< PSCnt; i++) {

        //! PS Left
        TPParkingSlotObject * PS =  new TPParkingSlotObject(i);
        std::shared_ptr<ParkingSlotObjectFormat> psPar = std::make_shared<ParkingSlotObjectFormat>();

        Point * p1 = psPar->add_corner_array();
        p1->set_x(pos1.x());
        p1->set_y(pos1.y() + i * (widh + offset));
        p1->set_z(0);


        Point * p2 = psPar->add_corner_array();
        p2->set_x(pos2.x());
        p2->set_y(pos2.y()+ i * (widh + offset));
        p2->set_z(0);


        Point * p3 = psPar->add_corner_array();
        p3->set_x(pos3.x());
        p3->set_y(pos3.y()+ i * (widh + offset));
        p3->set_z(0);


        Point * p4 = psPar->add_corner_array();
        p4->set_x(pos4.x());
        p4->set_y(pos4.y()+ i * (widh + offset));
        p4->set_z(0);

        if(i%2) {
            psPar->set_status(PS_STATUS_OCCUPIED);
        }

#if 0
        PS->updateObjectFormat(psPar);
        TPScene::getInstance().updateTPObject(PS, unknowSensor);
#endif

        //! PS Right
        TPParkingSlotObject * PSRight =  new TPParkingSlotObject(i + PSCnt);
        // std::shared_ptr<ParkingSlotObjectFormat> psPar = std::make_shared<ParkingSlotObjectFormat>();

        psPar->Clear();
        p1 = psPar->add_corner_array();
        p1->set_x(-pos1.x());
        p1->set_y(pos1.y() + i * (widh + offset));
        p1->set_z(0);

        p2 = psPar->add_corner_array();
        p2->set_x(-pos2.x());
        p2->set_y(pos2.y()+ i * (widh + offset));
        p2->set_z(0);

        p3 = psPar->add_corner_array();
        p3->set_x(-pos3.x());
        p3->set_y(pos3.y()+ i * (widh + offset));
        p3->set_z(0);

        p4 = psPar->add_corner_array();
        p4->set_x(-pos4.x());
        p4->set_y(pos4.y()+ i * (widh + offset));
        p4->set_z(0);

        if(i%2) {
            psPar->set_status(PS_STATUS_OCCUPIED);
        }

        // Lane1->updateObjectFormat(lanPar1);
        PSRight->updateObjectFormat(psPar);
        TPScene::getInstance().updateTPObject(PSRight, unknowSensor);
    }

    //! feature points
    int pointId = 1;
    TPPointObject * pointObj =  new TPPointObject();
    std::shared_ptr<PointObjectFormat> pointFormat  = std::make_shared<PointObjectFormat>();

    TPPointObject * pointObj1 =  new TPPointObject();
    std::shared_ptr<PointObjectFormat> pointFormat1  = std::make_shared<PointObjectFormat>();

    for(int i = 0; i < 100; i++) {
        for( int j = 0; j<300; j++ ) {
            Point * pos = pointFormat->add_pos();
            pos->set_x(700);
            pos->set_y(0 + 30 *i);
            pos->set_z(0 + 20* j);


            Point * pos1 = pointFormat1->add_pos();
            pos1->set_x(-700);
            pos1->set_y(0 + 40 *j);
            pos1->set_z(0 + 20* i);

            Color * color = pointFormat->add_color();
            color->set_r(1);
            color->set_g(0);
            color->set_b(0);
            color->set_a(1.0);

            Color * color1 = pointFormat1->add_color();
            color1->set_r(0);
            color1->set_g(1);
            color1->set_b(0);
            color1->set_a(1.0);
        }
    }

    pointObj->updateObjectFormat(pointFormat);
    TPScene::getInstance().updateTPObject(pointObj, unknowSensor);

    pointObj1->updateObjectFormat(pointFormat1);
    TPScene::getInstance().updateTPObject(pointObj1, unknowSensor);
    // // Point  pointFormat->
    sleep(15);
    osg::Vec3  egoPos1 = viewer.getEgoObject()->getEgoPos();
    int predictPotCnt = 50;
    osg::ref_ptr< osg::Vec3Array> predicTra = new osg::Vec3Array(predictPotCnt);


    while(1) {

        for(int i =1; i < 750;  i+=1) {
            predicTra->clear();
            // predicTra->empty();

            // osg::Vec3  egoPos(1, 0.5 + 0.008*(i*i - (i-1)*(i-1)), 0);
            osg::Vec3  egoPos(1, 0.5 + 0.016*i, 0);
            viewer.getEgoObject()->updateEgoPos(egoPos);

            for(int index = i; index < i+predictPotCnt; index++) {
                predicTra->push_back(osg::Vec3f(1.0f*index - viewer.getEgoObject()->getEgoPos().x(), (0.5f *index + 0.008f* index * index) - viewer.getEgoObject()->getEgoPos().y(), 0));
                //    predicTra->push_back(osg::Vec3f(1.0f*index, (0.5f *index + 0.004f* index * index)  , 0));
            }

            viewer.getEgoObject()->updatePredictTra(*predicTra);

            // viewer.getEgoObject()->updateHeading(-90.0f + atan((0.5f + 0.008*(i*i - (i-1)*(i-1))))*180.0f/3.1415f);
            viewer.getEgoObject()->updateHeading(-90.0f + atan(0.5f + 0.016*i)*180.0f/3.1415f);
            // viewer.getEgoObject()->updateHeading(-i *25.f/800.0);
            usleep(5000);
        }

        for(int i =1; i < 850;  i+=1) {
            //predicTra->clear();
            osg::Vec3  egoPos(-1, -0.5 - 0.010*i, 0);
            viewer.getEgoObject()->updateEgoPos(egoPos);

            // for(int index = i; index < i+predictPotCnt; index++) {
            //     predicTra->push_back(osg::Vec3f(-1.0f*index + viewer.getEgoObject()->getEgoPos().x(), (-0.5f *index - 0.005f* index * index) + viewer.getEgoObject()->getEgoPos().y(), 0));
            //  }

            //  printf("%d\n", predicTra->size());
            //  viewer.getEgoObject()->updatePredictTra(*predicTra);

            // viewer.getEgoObject()->updateHeading(i *25.f/1000.0);
            viewer.getEgoObject()->updateHeading(90.0f -  atan((-0.5f - 0.005*(i*i - (i-1)*(i-1))))*180.0f/3.1415f);
            usleep(5000);

        }

        break;

        usleep(100);

    }
}

int main()
{

    setSpdlogCFG();

    debug("spdlog test");

    // std::unique_ptr<std::thread> panligon_thread_  = std::unique_ptr<std::thread>(new std::thread(run, 1));


    viewer.initialize();

    std::thread updateObject(run);

    return viewer.run();

}