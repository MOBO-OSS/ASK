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

#include <string>
#include <osg/ref_ptr>
#include "AutoGen/Protobuf/BaseType.pb.h"
#include "TypesRedefine.hpp"
// #include "TPSensorBase.hpp"

#define MAX_OBJECT_INFO_SIZE 200

class TPSensorBase;
class ObjectBaseinfo //:  public osg::Referenced
{
private:
    /* data */
public:
    ObjectBaseinfo(uint32 ID, TP_OBJECT_TYPE type):m_objectID(ID),  m_objecType(type), m_objectInfo(NULL) {}
    virtual ~ObjectBaseinfo() {}

    uint32 m_objectID;
    std::string m_objectName;

    TP_OBJECT_TYPE m_objecType;
    uint32 m_globalobjectID;
    //string m_name;

    char * m_objectInfo;

    COORD_TYPE m_coordType;

    virtual void createGeometry(/* args */) = 0;

    osg::ref_ptr<TPSensorBase> m_observerSensor;

    uint32 getObjectUUId()
    {
        return m_globalobjectID;
    }

    virtual char * getObjectInfo()
    {
        return m_objectInfo;
    }



};

