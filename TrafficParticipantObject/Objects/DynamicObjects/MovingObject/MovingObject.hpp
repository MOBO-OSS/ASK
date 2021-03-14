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

#include<osg/StateSet>
#include<osg/ShapeDrawable>
#include <osgDB/ReaderWriter>
#include <osgDB/Archive>
#include <osgDB/ReadFile>
#include "TPObjectBase.hpp"
#include "TPTrajectoryBase.hpp"
#include "AutoGen/Protobuf/MovingObjectFormat.pb.h"
#include "MovingObject.hpp"
#include "ObjectBaseinfo.hpp"
class MovingObjectNodeCallback : public osg::NodeCallback
{
public:
    MovingObjectNodeCallback() : _count(0) {}

    virtual void operator()( osg::Node* node, osg::NodeVisitor* nv )
    {
        //printf("Ego node Pos:(%f, %f, %f)\n", node->getBound().center().x(), node->getBound().center().y(), node->getBound().center().z());

        traverse( node, nv );
    }

protected:
    unsigned int _count;
};

class MovingObject: public osg::Group, public ObjectBaseinfo
{
private:
    /* data */
    MovingObjectFormat m_MovingObjectFormat;
    osg::ref_ptr<osg::Node>  m_model;
    // TP_OBJECT_TYPE m_objecType;
    osg::ref_ptr<osg::MatrixTransform> m_trans;
    osg::ref_ptr<TPTrajectoryBase> m_track;
    float m_headingAngle;
    // osg::ref_ptr<osg::Geode> m_boudingBox;

    osg::Matrixd m_sacleMat;
    osg::Matrixd m_RoationMat;
    osg::Matrixd m_RoationSelfMat;
    osg::Matrixd m_transMat;

    osg::Matrixd m_finalMat;

    osg::Matrixd calFinalMat();

    void createGeometry();
    void drawContour();

    void updateObjectFormat(std::shared_ptr<MovingObjectFormat> &format);
public:
    MovingObject(uint32 ID, TP_OBJECT_TYPE type):ObjectBaseinfo(ID, type)
    {
        // osg::ref_ptr<osg::Geode> m_boudingBox = new osg::Geode();
        m_trans =  new osg::MatrixTransform();
        m_track = new TPTrajectoryBase();
        
        createGeometry();
    }
    ~MovingObject() {}
    

    osg::Vec3 getObjectPos();

    bool updateObjectPos(const osg::Vec3d & deltTrans);
    bool updateHeading(const float & headingAngle);
    osg::ref_ptr<TPSensorBase> m_observerSensor;

};





