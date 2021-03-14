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
#include "EGO/EgoObject.hpp"
#include "Modules/Viewer/TPViewer.hpp"

static TPViewer viewer;

//! add sensor list
osg::ref_ptr<TPSensorBase> unknowSensor = new TPSensorUnknow(0);
osg::ref_ptr<TPSensorBase> cameraSensor = new TPSensorCamera(1, 40.0f);


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

void runRobot1()
{
    osg::ref_ptr<EgoObject>  EGO = new EgoObject(1);
    EGO->m_observerSensor = unknowSensor;
    TPScene::getInstance().updateTPObject(EGO);

    EGO->setEgoPos(osg::Vec3f(-1000.0f,100.0f,0.0f));
    EGO->updateHeading(-90.0f);
    // m_root->addChild(m_ego);

    while(1) {

        EGO->updateHeading(0.0f);
        for(int i =1; i < 2000;  i+=1) {
            osg::Vec3  egoPos(0, 2, 0);
            EGO->updateEgoPos(egoPos);
            // EGO->updateHeading(atan((0.5 + 0.008*(i*i - (i-1)*(i-1)))*10.0f));
            usleep(8000);
    
            
        }

        EGO->updateHeading(180.0f);
        for(int i =1; i < 2000;  i+=1) {
            osg::Vec3  egoPos(0, -2, 0);
            EGO->updateEgoPos(egoPos);
            // EGO->updateHeading(atan((0.5 + 0.008*(i*i - (i-1)*(i-1)))*10.0f));
            usleep(8000);
        }

        //break;

        sleep(1);

    }
}

void runRobot2()
{
    osg::ref_ptr<EgoObject>  EGO = new EgoObject(2);
    EGO->m_observerSensor = unknowSensor;
    TPScene::getInstance().updateTPObject(EGO);

    EGO->updateHeading(-90.0f);
    while(1) {

        EGO->updateHeading(-90.0f);
        for(int i =1; i < 2000;  i+=1) {
            osg::Vec3  egoPos(2, 0, 0);
            EGO->updateEgoPos(egoPos);
            // EGO->updateHeading(atan((0.5 + 0.008*(i*i - (i-1)*(i-1)))*10.0f));
            usleep(8000);
    
            
        }

        EGO->updateHeading(90.0f);
        for(int i =1; i < 2000;  i+=1) {
            osg::Vec3  egoPos(-2, 0, 0);
            EGO->updateEgoPos(egoPos);
            // EGO->updateHeading(atan((0.5 + 0.008*(i*i - (i-1)*(i-1)))*10.0f));
            usleep(8000);
        }

        //break;

        sleep(1);

    }
}


int main()
{

    setSpdlogCFG();

    debug("spdlog test");

    //! add sensor list
    TPScene::getInstance().addNewSensor(unknowSensor);

    TPScene::getInstance().addNewSensor(cameraSensor);


    viewer.initialize();

    std::thread updateObject(runRobot1);
    std::thread updateObject1(runRobot2);

    return viewer.run();

}