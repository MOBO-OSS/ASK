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
#include <osgText/Text>
#include <memory>
#include "TPObjectBase.hpp"
#include "PointObjectFormat.pb.h"

class TPPointObject: public TPObjectBase
{

private:
    /* data */
    std::shared_ptr<PointObjectFormat> m_objectFormat;
    void createGeometry();




public:
    TPPointObject(uint32 ID): TPObjectBase( ID,  TP_OBJECT_TYPE_D_POINT)
    {
        //createGeometry();
    }
    virtual ~TPPointObject() {}


    // void setGeometryPara(float32  *c, float32 length, float32 width);
    void updateObjectFormat(std::shared_ptr<PointObjectFormat> &format);

};