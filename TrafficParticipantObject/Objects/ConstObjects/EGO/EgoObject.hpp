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
#ifndef __EGO_H__
#define __EGO_H__
#include<osg/StateSet>
#include<osg/ShapeDrawable>
#include <osgDB/ReaderWriter>
#include <osgDB/Archive>
#include <osgDB/ReadFile>
#include <osg/LOD>
#include "TPObjectBase.hpp"
#include "TPTrajectoryBase.hpp"
#include "AutoGen/Protobuf/EgoObjectFormat.pb.h"
#include "DynamicObjects/MovingObject/MovingObject.hpp"
#include <osg/BoundingBox>
#include <osg/ComputeBoundsVisitor>
#include "CollisionCheck/EGOCollisionCheck.hpp"

// #include <osgUtil/IntersectVisitor>

class TPScene;
class EgoNodeCallback : public osg::NodeCallback
{
public:
    EgoNodeCallback() : _count(0) {}

    virtual void operator()( osg::Node* node, osg::NodeVisitor* nv )
    {

        //printf("Ego node Pos:(%f, %f, %f)\n", node->getBound().center().x(), node->getBound().center().y(), node->getBound().center().z());

        traverse( node, nv );
    }

protected:
    unsigned int _count;
};

class EGOCollisionCheck;
class MovingObject;
class EgoObject: public MovingObject
{
private:
    /* data */
    EgoObjectFormat m_egoObjectFormat;
    osg::ref_ptr<osg::Node>  m_ego;

    float m_headingAngle;


    std::shared_ptr<EGOCollisionCheck> m_collisionCheck;

    osg::ref_ptr<osg::LOD> m_LOD;


    osg::BoundingBox m_boundingBox;
    std::unique_ptr<std::thread> m_ckThread;


    void createGeometry();
    void updateCollisionCheckBoundary();


public:
    EgoObject(uint32 ID): MovingObject(ID, TP_OBJECT_TYPE_EGO)
    {

        m_objectName = "EGO";
        m_objectInfo = new char[MAX_OBJECT_INFO_SIZE];

        m_LOD = new osg::LOD();

        m_collisionCheck = std::make_shared<EGOCollisionCheck>();

        createGeometry();
    }
    ~EgoObject()
    {

        warn("deconstruct Ego Object");
    }

    osg::Vec3 getEgoPos();
    bool updateEgoPos(const osg::Vec3d & deltTrans);
    bool updateHeading(const float & heading);
    bool setEgoPos(const osg::Vec3d & pos);

    const osg::ref_ptr<osgUtil::IntersectionVisitor> getIntersectionVisitor()
    {
        return m_collisionCheck->getIntersectionVisitor();
    };

};

#endif