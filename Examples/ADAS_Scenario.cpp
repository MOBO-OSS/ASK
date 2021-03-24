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
    pedestrain->updateObjectPos(osg::Vec3d(200, 200, 0));
    TPScene::getInstance().updateTPObject(pedestrain);


    int d = 2000;
    osg::ref_ptr<MovingObject> truck = new MovingObject(0, TP_OBJECT_TYPE_D_TRUCK);
    truck->m_observerSensor = unknowSensor;
    truck->updateObjectPos(osg::Vec3d(500 +  0.005 * d + 0.0001 * d *d ,d, 0));
    TPScene::getInstance().updateTPObject(truck);

    osg::ref_ptr<MovingObject> truck1 = new MovingObject(1, TP_OBJECT_TYPE_D_TRUCK);
    truck1->m_observerSensor = unknowSensor;
    truck1->updateObjectPos(osg::Vec3d(0.0f, d, 0));
    TPScene::getInstance().updateTPObject(truck1);

    int d1 = 1000;
    osg::ref_ptr<MovingObject> car = new MovingObject(0, TP_OBJECT_TYPE_D_CAR);
    car->m_observerSensor = unknowSensor;
    // pedestrain->updateObjectFormat(psPar);
    car->updateObjectPos(osg::Vec3d(500 + 0.005 * d1 + 0.0001 * d1 *d1 ,d1, 0));
    TPScene::getInstance().updateTPObject(car);





    //! update TPO
    // osg::ref_ptr<TPPoint_RSP> Point1 =  new TPPoint_RSP(0);
    // //Point1->updateObjectLocation(1000, 1000, 500);
    // Point1->updateObjectLocation(100.0f, 200.0f, 30.0f);
    // Point1->m_observerSensor = cameraSensor;

    osg::ref_ptr<LaneCurveLine> Line =  new LaneCurveLine(2);
    Line->m_observerSensor = unknowSensor;

    float32 c[5] = {40, 8e-4, 8e-8f, 0.0, 0.0};
    Line->setGeometryPara(c, 800, 10);


    TPStraightLine * SLine  = new TPStraightLine(3);

    SLine->setGeometryPara(osg::Vec2f(50,50), osg::Vec2f(180,180), 10);


    // Lane info
    TPLaneClothid * Lane =  new TPLaneClothid(1);

    std::shared_ptr<LaneClothidObjectFormat> lanPar = std::make_shared<LaneClothidObjectFormat>();
    lanPar->add_clothidpar(130);
    lanPar->add_clothidpar(0.000005);
    lanPar->add_clothidpar(0.0000001);
    lanPar->set_length(5000);
    lanPar->set_width (20);

    Lane->updateObjectFormat(lanPar);
    TPScene::getInstance().updateTPObject(Lane, unknowSensor);

    TPLaneClothid * Lane1 =  new TPLaneClothid(2);
    lanPar->set_clothidpar(0,-130);

    Lane1->updateObjectFormat(lanPar);
    TPScene::getInstance().updateTPObject(Lane1, unknowSensor);

    TPLaneClothid * Lane2 =  new TPLaneClothid(3);
    lanPar->set_clothidpar(0, -390);
    lanPar->set_clothidpar(1, -0.005);
    lanPar->set_clothidpar(2, -0.0001);
    Lane2->updateObjectFormat(lanPar);

    TPScene::getInstance().updateTPObject(Lane2, unknowSensor);


    TPLaneClothid * Lane3 =  new TPLaneClothid(4);
    lanPar->set_clothidpar(0, 390);
    lanPar->set_clothidpar(1, 0.005);
    lanPar->set_clothidpar(2, 0.0001);
    Lane3->updateObjectFormat(lanPar);

    TPScene::getInstance().updateTPObject(Lane3, unknowSensor);


    TPLaneClothid * Lane4 =  new TPLaneClothid(5);
    lanPar->set_clothidpar(0, 650);
    lanPar->set_clothidpar(1, 0.005);
    lanPar->set_clothidpar(2, 0.0001);
    Lane4->updateObjectFormat(lanPar);

    TPScene::getInstance().updateTPObject(Lane4, unknowSensor);


    TPLaneClothid * Lane5 =  new TPLaneClothid(6);
    lanPar->set_clothidpar(0, -650);
    lanPar->set_clothidpar(1, -0.005);
    lanPar->set_clothidpar(2, -0.0001);

    Lane5->updateObjectFormat(lanPar);

    TPScene::getInstance().updateTPObject(Lane5, unknowSensor);

    sleep(15);

    osg::Vec3  egoPos1 = viewer.getEgoObject()->getEgoPos();
    while(1) {

        for(int i =1; i < 4000;  i+=1) {
            osg::Vec3  egoPos(0.005 + 0.0001*(i*i - (i-1)*(i-1)), 1, 0);
            viewer.getEgoObject()->updateEgoPos(egoPos);

            // viewer.getEgoObject()->updateHeading(atan((0.5 + 0.008*(i*i - (i-1)*(i-1)))*10.0f));
            viewer.getEgoObject()->updateHeading(-i *40.f/4000.0);
            usleep(4000);
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