#ifndef  __TP_LINE_BASE_H__
#define  __TP_LINE_BASE_H__
#include "TPObjectBase.hpp"

#define  DISTANCE_STEPS  0.2
class TPLineBase: public TPObjectBase
{
private:
    /* data */
public:
    TPLineBase(uint32 ID, TP_OBJECT_TYPE type);
    ~TPLineBase();


    osg::ref_ptr<osg::Geode> m_geode;
    osg::ref_ptr<osg::Vec3Array> m_vert;
    osg::ref_ptr<osg::Vec4Array> m_color;
    osg::ref_ptr<osg::Geometry>  m_geom;

};

#endif