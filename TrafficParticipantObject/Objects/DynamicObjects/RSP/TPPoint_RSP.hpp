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
#ifndef __TP_POINT_RSP_H__
#define __TP_POINT_RSP_H__

#include "TPObstacleBase.hpp"


#define  RSP_SECTION_DEGREE 3.0f
#define  DEFAULT_OBJECT_LOCATION 100000.0F;


class TPPoint_RSP: public TPObstacleBase
{
private:
    /* data */
public:
    TPPoint_RSP(uint32 ID);
    ~TPPoint_RSP();

    float32 m_x, m_y, m_z;

    void updateObjectLocation(float32 x, float32 y, float32 z);
    void createGeometry();
};


#endif