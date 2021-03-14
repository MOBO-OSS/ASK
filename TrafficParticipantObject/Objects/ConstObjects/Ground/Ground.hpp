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
#ifndef __GROUND_H__
#define __GROUND_H__

#include "TPObjectBase.hpp"
#include<osg/Material>
#include<osg/StateSet>
#include<osg/ShapeDrawable>
#include <osgTerrain/GeometryPool>

class Ground : public TPObjectBase
{
    /* data */
public:
    explicit Ground(uint32 ID, TP_OBJECT_TYPE type, uint32 Width, uint32 Height):TPObjectBase(ID,type),
        m_width(Width), m_length(Height) // unit: meter
    {
        m_geom = new osg::Geometry();
        m_vert = new osg::Vec3Array();
        m_color = new osg::Vec4Array();


        createGeometry();
    }


    void createGeometry();

private:
    uint32 m_width;
    uint32 m_length;

    osg::ref_ptr<osg::Vec3Array> m_vert;
    osg::ref_ptr<osg::Vec4Array> m_color;
    osg::ref_ptr<osg::Geometry>  m_geom;
    osg::ref_ptr<osg::Geometry>  m_geomVer;

protected:
    virtual ~Ground() {};
};



#endif