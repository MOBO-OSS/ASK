#ifndef  __TP_STRAIGHTLINE_H__
#define  __TP_STRAIGHTLINE_H__

#include "TPLineBase.hpp"
#include <osg/Vec3f>
#include <osg/Vec2f>

class TPStraightLine: public TPLineBase
{
private:
    /* data */
    osg::Vec3f m_startPoint;
    osg::Vec3f m_endPoint;
    float32 m_width;

public:
    TPStraightLine(uint32 ID );
    ~TPStraightLine();


    void setGeometryPara(osg::Vec3f startPoint, osg::Vec3f endPoint, float32 width);
    void setGeometryPara(osg::Vec2f startPoint, osg::Vec2f endPoint, float32 width);

    virtual void createGeometry();
};








#endif