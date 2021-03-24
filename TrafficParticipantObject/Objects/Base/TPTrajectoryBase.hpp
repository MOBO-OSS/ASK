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

#include <osg/Vec3f>
#include <osg/Vec2f>
#include <cassert>
#include <osg/Geode>
#include <osg/Geometry>
#include "Ringbuff.hpp"
//#include "TPObjectBase.hpp"

typedef enum {
    LINE_TYPE_SOLID = 0,
    LINE_TYPE_DASHED_TYPE1 = 1,

    LINE_TYPE_RESERVE = 10,
} TRAJ_LINE_TYPE;

using PointBuf = RingBuffer<osg::Vec3f, 100, false>;
class OSG_EXPORT TPTrajectoryBase: public osg::Geode
{
private:

    void createGeometry();

    PointBuf m_pointBuf;

    osg::ref_ptr<osg::Vec3Array> m_vert;
    osg::ref_ptr<osg::Vec4Array> m_color;
    osg::ref_ptr<osg::Geometry>  m_geom;
    TRAJ_LINE_TYPE m_lineType;
    /* data */
public:
    TPTrajectoryBase(/* args */);
    TPTrajectoryBase(TRAJ_LINE_TYPE type);
    ~TPTrajectoryBase();
    void updatePot(const osg::Vec3f point, const osg::Vec4f color = osg::Vec4(1.0, 0.0, 0.0, 0.5));
    void clearPots();
    //!


};

