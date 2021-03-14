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
#pragma once
#include <osgGA/GUIEventHandler>
#include <osgViewer/Viewer>
#include <osgFX/Scribe>
#include "Scene/TPScene.hpp"
#include "Objects/StaticObjects/ParkingSlot/TPParkingSlotObject.hpp"

class TPParkingSlotObject;
class UserEventHandler : public osgGA::GUIEventHandler
{

public:
    UserEventHandler(osgViewer::Viewer* viewer) :mViewer(viewer) {}

public:
    virtual bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter &aa)
    {

        osgViewer::Viewer *viewer = dynamic_cast<osgViewer::Viewer *>(&aa);
        if (!viewer)  {
            printf("error ");
            return false;
        }

        switch (ea.getEventType()) {
        case osgGA::GUIEventAdapter::KEYDOWN: // 键盘事件
            //printf("GUIEventHandler: handle: KEYDOWN:0x%x \n ",ea.getKey() );
            if (ea.getKey() == 0xFF51) { // 键盘左键
                TPScene::getInstance().getEGONode()->updateEgoPos(osg::Vec3d(-10,0,0));
            }
            if (ea.getKey() == 0xFF52) { // 键盘up键
                TPScene::getInstance().getEGONode()->updateEgoPos(osg::Vec3d(0, 10,0));
            }
            if (ea.getKey() == 0xFF53) { // 键盘右键
                TPScene::getInstance().getEGONode()->updateEgoPos(osg::Vec3d(10,0,0));
            }

            if (ea.getKey() == 0xFF54) { // 键盘down键
                TPScene::getInstance().getEGONode()->updateEgoPos(osg::Vec3d(0,-10,0));
            }
            break;

        // case osgGA::GUIEventAdapter::DOUBLECLICK: // 双击
        //     if (ea.getButton() == 1) { // 左键
        //         viewer->getSceneData()->asGroup()->getChild(0)->setNodeMask(1);
        //         viewer->getSceneData()->asGroup()->getChild(1)->setNodeMask(1);
        //     }
        //     break;

        case osgGA::GUIEventAdapter::PUSH:
            if (ea.getButton() == 1) {
                printf("get mouse left-key push event\n");
                Pick(ea.getX(), ea.getY());
            }
            break;

        default:
            break;
        }
        return false;
    }
protected:
    void Pick(float x, float y)
    {
        osgUtil::LineSegmentIntersector::Intersections intersections;
        if (mViewer->computeIntersections(x, y, intersections)) {
            for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin(); hitr != intersections.end(); ++hitr) {
                printf("intersection:%d %d  \n", !hitr->nodePath.empty(), !(hitr->nodePath.back()->getName().empty()));
                //if (!hitr->nodePath.empty() && !(hitr->nodePath.back()->getName().empty()))
                if (!hitr->nodePath.empty()) {
                    const osg::NodePath& np = hitr->nodePath;
                    for (int i = np.size() - 1; i >= 0; --i) {
                        printf("intersection size:%d \n",np.size());

                        TPObjectBase* sc = dynamic_cast<TPObjectBase *>(np[i]);
                        if (sc != NULL) {
                            printf("get node\n");
                            if (sc->getNodeMask() != 0)
                                sc->setNodeMask(0);
                        }

                        // if (np[i]->getNodeMask() != 0)
                        //     np[i]->setNodeMask(0);
                    }

                }
            }
        }
    }

private:
    osgViewer::Viewer* mViewer;
};

// class CPickHandler :public osgGA::GUIEventHandler
// {
// public:
// 	CPickHandler(osgViewer::Viewer* viewer) :mViewer(viewer){}
// 	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
// 	{
// 		switch (ea.getEventType())
// 		{
// 		        return true;
// 		}
// 		return false;
// 	}

// };