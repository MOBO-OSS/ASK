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
#ifndef _TFBase_h_
#define _TFBase_h_

#include "CommonHPP.hpp"
#include <cassert>
#include <osg/Geode>
#include <osg/Group>
#include <osg/Geometry>
#include "TPSensorBase.hpp"
#include "ObjectBaseinfo.hpp"

class TPSensorBase;
class TPScene;
class TPTrajectoryBase;
// template<class ObjecDataFormat>
// using PointBuf = RingBuffer<osg::Vec3f, 100, false>;

class OSG_EXPORT TPObjectBase : public osg::Group, public ObjectBaseinfo
//: public osg::Geometry
{

public:
    explicit TPObjectBase(const uint32 ID, const TP_OBJECT_TYPE type);

    virtual void createGeometry(/* args */) = 0;

    osg::ref_ptr<TPSensorBase> m_observerSensor;
    virtual ~TPObjectBase();

private:


protected:
    // std::unique_ptr<TPTrajectoryBase> m_track;
    // PointBuf m_pointBuf;

};

#endif
