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
#ifndef __TERRAIN_H__
#define __TERRAIN_H__

#include <osgTerrain/TerrainTile>
#include <osgTerrain/Locator>

class terrain
{
private:
    /* data */
public:
    terrain(/* args */);
    ~terrain();
};

terrain::terrain(/* args */)
{
    osg::ref_ptr<osgTerrain::TerrainTile>terrainTile=new osgTerrain::TerrainTile;
    osg::ref_ptr<osgTerrain::Locator>locator=new osgTerrain::Locator;


    //设置高程无效数据

    osg::ref_ptr<osgTerrain::ValidDataOperator>validDataOperator=new osgTerrain::NoDataValue(0.0);
    osg::ref_ptr<osgTerrain::Layer>lastAppliedLayer;


//设置坐标系统的类型(地球坐标，描述地球体)
    locator->setCoordinateSystemType(osgTerrain::Locator::GEOGRAPHIC);

//设置坐标的范围值(x,y最小最大值)
//locator->setTransformAsExtents(x,y,x+w,y+h);


}

terrain::~terrain()
{
}



#endif