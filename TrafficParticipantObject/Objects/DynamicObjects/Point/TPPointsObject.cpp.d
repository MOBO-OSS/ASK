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

#include "TPPointsObject.hpp"
#include <osg/Point>
#include <osg/LineWidth>

void TPPointsObject::createGeometry()
{

    
}



void TPPointsObject::updateObjectFormat(std::shared_ptr<PointObjectFormat> &format)
{
	assert(format->pos_size() > 1);
	
	m_objectFormat = format;

	m_vert->push_back(osg::Vec3(format->pos().x(), format->pos().y(), format->pos().z()));
	if(format->has_color()) {
		m_color->push_back(osg::Vec4(format->color().r(), format->color().g(), format->color().b(), format->color().a()));
	} else {
		warn("Point Object(ID:{}) not set color, using default(<1.0, 0.0, 0.0, 0.8>)", m_objectID);
		m_color->push_back(osg::Vec4(1.0, 0.0, 0.0, 0.8));
	}
	
	//m_geom = new osg::Geometry;
	m_geom->setVertexArray(m_vert);

	m_geom->setColorArray(m_color);
	m_geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	osg::ref_ptr<osg::PrimitiveSet> primitiveSet = new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, 4);
	m_geom->addPrimitiveSet(primitiveSet);

	this->addDrawable(m_geom.get());

	// Set StateSet
	osg::StateSet* stateSet = getOrCreateStateSet();
	osg::Point* point=new osg::Point; //设置一些样式，如线宽等
	point->setSize(2);
	/*point->setSize(size);*/
	stateSet->setAttribute(point);

	//! set Blend effect active
	stateSet->setMode(GL_BLEND,osg::StateAttribute::ON);
	//root->getOrCreateStateSet()->setMode(GL_LIGHTING, StateAttribute::OFF | StateAttribute::OVERRIDE);

	
}

