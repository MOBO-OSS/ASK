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

#include <osg/Camera>
#include <osgText/Text>
#include "ObjectBaseinfo.hpp"
#include "TPSensorBase.hpp"
#include <semaphore.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

class TPHUD : public osg::Camera, public ObjectBaseinfo
{
private:
    /* data */
    void setupProperties(osgText::Font* font,float size,const osg::Vec3& pos );
    void setupProperties(float size,const osg::Vec3& pos );


    osg::ref_ptr<osgText::Font> m_fontKai;

    osg::ref_ptr<osg::Geode> m_geode;
    osg::Vec3 m_pos;

    void createGeometry(/* args */) {}

    osg::Camera* createHUD();
    // int sem_init(sem_t *sem,int pshared,unsigned int value);
    // sem_t binSem;

public:
    TPHUD(/* args */);
    ~TPHUD();

    osg::Node * getNode()
    {
        return this;
    }
    void updateTextContent(const char* string);
    void updateTextContent(const char* string, const osg::Vec3& pos);
    osg::ref_ptr<osgText::Text> m_textObject;
    std::mutex m_mut;
};

