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
*
* THIS SOFTWARE IS PROVIDED BY xxx,GROUP AND CONTRIBUTORS
* ===================================================================
* Author: Mobo
* Mail: mobojingjiniao@126.com
*/

#pragma once

#include <map>
#include <hash_map>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <osgUtil/IntersectionVisitor>
#include <osgUtil/LineSegmentIntersector>
#include "AutoGen/Protobuf/EgoObjectFormat.pb.h"

//! todo: define white list
const TP_OBJECT_TYPE CollisionWhiteList[] = {
    TP_OBJECT_TYPE_D_DOG,
    TP_OBJECT_TYPE_D_PEDESTRAIN,
    TP_OBJECT_TYPE_D_POINT,

};

class EGOCollisionCheck
{
private:
    /* data */
    osg::ref_ptr<osgUtil::IntersectorGroup> m_intersectorGroup;
    osg::ref_ptr<osgUtil::IntersectionVisitor> m_intersectVisitor;

    std::mutex m_mut;
    std::map<TP_OBJECT_TYPE, int > m_CWL;
public:
    EGOCollisionCheck(/* args */);
    ~EGOCollisionCheck();

    void run();
    void addIntersector(const osg::ref_ptr<osgUtil::LineSegmentIntersector> & inter);

    const osg::ref_ptr<osgUtil::IntersectionVisitor> getIntersectionVisitor()
    {
        std::unique_lock<std::mutex> lock(m_mut);
        return m_intersectVisitor;
    };

    void clearIntersectors()
    {
        std::unique_lock<std::mutex> lock(m_mut);
        m_intersectorGroup->clear();
        //m_intersectorGroup->reset();
        //printf("refe cnt: %d\n", m_intersectorGroup->referenceCount());

        //m_intersectorGroup->referenceCount;
    };
};



