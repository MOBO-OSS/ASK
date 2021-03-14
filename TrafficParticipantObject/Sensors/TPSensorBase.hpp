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
#ifndef __TPSENSORBASE_H__
#define __TPSENSORBASE_H__

#include "CommonHPP.hpp"
#include <map>
#include <hash_map>
#include "TPObjectBase.hpp"
#include <osg/MatrixTransform>
#include <osg/Group>
#include <TPObjectBase.hpp>
#include "AutoGen/Protobuf/BaseType.pb.h"
// enum TP_SENSOR_TYPE{
//     TP_SENSOR_TYPE_UNKNOW = 0,  // unknown
//     TP_SENSOR_TYPE_CAMERA,
//     TP_SENSOR_TYPE_USS,
//     TP_SENSOR_TYPE_RADAR,
//     TP_SENSOR_TYPE_LIDAR,

//     TP_SENSOR_TYPE_MAX,

// };

class TPSensorBase: public osg::Geode
{
private:
    /* data */
    //std::map<uint32, TPObjectBase * > m_TPObjectsTable;

public:
    TPSensorBase(TP_SENSOR_TYPE type, uint8 ID):m_sensorID(ID), m_SensorType(type)
    {
        //printf("%d  %d\n", ID, 2<<10);
        assert(ID < (2<<5));
        assert(((type < TP_SENSOR_TYPE_MAX)&(type >=TP_SENSOR_TYPE_UNKNOW)));
        m_GlobalSensorID = (2<<5) + ID;

        m_globalTrans = new osg::MatrixTransform();
        m_localTrans = new osg::MatrixTransform();

        this->addChild(m_globalTrans);
        this->addChild(m_localTrans);

    }
    ~TPSensorBase() {}

    uint32 m_sensorID;
    TP_SENSOR_TYPE m_SensorType;
    uint32 m_GlobalSensorID;

    osg::ref_ptr<osg::MatrixTransform> m_globalTrans;
    osg::ref_ptr<osg::MatrixTransform> m_localTrans;

    virtual void setSensorPostion(osg::Vec3 pos) = 0;
    //void addObject(COORD_TYPE coordType, osg::ref_ptr<TPObjectBase> object);

    Pos m_posV2S;


};



#endif