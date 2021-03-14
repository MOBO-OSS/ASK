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
#include <osgUtil/Optimizer>
#include "TPViewer.hpp"
#include "UserEventHandler.hpp"
#include "Scene/TPScene.hpp"
#include <osgGA/NodeTrackerManipulator>
#include "Scene/TPHUD.hpp"
#include "ConstObjects/EGO/EgoObject.hpp"

TPViewer::TPViewer(/* args */)
{
    //this->addEventHandler(new UseEventHandler);
}

TPViewer::~TPViewer()
{
}

osg::ref_ptr<EgoObject>  TPViewer::getEgoObject()
{
    return TPScene::getInstance().getEGONode();
}

void TPViewer::initialize()
{
    // std::unique_ptr<std::thread> panligon_thread_  = std::unique_ptr<std::thread>(new std::thread(run, 1))
    osg::ref_ptr<osg::Group>  root = TPScene::getInstance().getRoot();

    //! todo
    // osgUtil::Optimizer op;
    // op.optimize(root);

    this->setSceneData(root);
    //this->setSceneData(TPScene::getInstance().getHudNode()->createHUD());

    // 位置在右上
    //this->getLight()->setPosition(osg::Vec4(1.0f, 1.0f, 0.0f, 0.0f));
    // 环境光
    this->getLight()->setAmbient(osg::Vec4(0.6f, 0.6f, 0.6f, 1.0f));
    // 漫反射光
    this->getLight()->setDiffuse(osg::Vec4(0.2f, 0.2f, 0.2f, 1.0f));

    osg::Vec4 clearColor(0.0f,0.0f,0.0f,0.0f);
    this->getCamera()->setClearColor(clearColor);

    this->setUpViewInWindow(200, 200, 1200, 600, 0);

    printf("Traits: smaple:%d \n", this->getCamera()->getGraphicsContext()->getTraits()->samples);

    osg::ref_ptr<osgGA::NodeTrackerManipulator> trackball = new osgGA::NodeTrackerManipulator;
    trackball->setHomePosition(osg::Vec3d(0.0f, -1200.0f, 600.0f), osg::Vec3d(0.0f,600.0f, 0.0f), osg::Vec3d(0.0f, 1.0f, 0.0f));

    trackball->setTrackNode(TPScene::getInstance().getEGONode());
    trackball->setTrackerMode(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION);
    trackball->setRotationMode(osgGA::NodeTrackerManipulator::ELEVATION_AZIM);

    this->setCameraManipulator( trackball.get() );
    //this->addEventHandler( new  osgViewer::StatsHandler );

    // this->addEventHandler(new KeyboardEventHandler);

    this->addEventHandler(new UserEventHandler(this));

    // this->addSlave(TPScene::getInstance().getHudNode());


    osg::CullStack::CullingMode cullingMode = this->getCamera()->getCullingMode();

    cullingMode &= ~(osg::CullStack::SMALL_FEATURE_CULLING);

    this->getCamera()->setCullingMode(cullingMode);

    this->realize();

}