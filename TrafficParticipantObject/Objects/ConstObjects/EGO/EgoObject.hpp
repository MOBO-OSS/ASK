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
#include "TPObjectBase.hpp"
#include "TPTrajectoryBase.hpp"
#include "AutoGen/Protobuf/EgoObjectFormat.pb.h"


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

class EgoObject: public osg::Group, public ObjectBaseinfo
{
private:
    /* data */
    EgoObjectFormat m_egoObjectFormat;
    osg::ref_ptr<osg::Node>  m_ego;
    //TP_OBJECT_TYPE m_type;
    osg::ref_ptr<osg::MatrixTransform> m_trans;
    osg::ref_ptr<TPTrajectoryBase> m_track;
    float m_headingAngle;

    void createGeometry();

    osg::Matrixd m_sacleMat;
    osg::Matrixd m_RoationMat;
    osg::Matrixd m_RoationSelfMat;
    osg::Matrixd m_transMat;

    osg::Matrixd m_finalMat;

    osg::Matrixd calFinalMat();

public:
    EgoObject(uint32 ID): ObjectBaseinfo(ID, TP_OBJECT_TYPE_EGO)
    {
        m_trans =  new osg::MatrixTransform();
        m_track = new TPTrajectoryBase();
        m_objectName = "EGO";
        m_objectInfo = new char[MAX_OBJECT_INFO_SIZE];

        createGeometry();
    }
    ~EgoObject() {}

    osg::Vec3 getEgoPos();
    bool updateEgoPos(const osg::Vec3d & deltTrans);
    bool updateHeading(const float & heading);
    bool setEgoPos(const osg::Vec3d & pos);

};

#endif