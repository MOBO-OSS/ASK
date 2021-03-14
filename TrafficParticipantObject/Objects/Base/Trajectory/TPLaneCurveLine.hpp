#ifndef  __TP_LANE_CURVE_LINE_H__
#define  __TP_LANE_CURVE_LINE_H__

#include "TPLineBase.hpp"

class LaneCurveLine: public TPLineBase
{
private:
    /* data */
public:
    LaneCurveLine(uint32 ID );


    ~LaneCurveLine();

    float32 m_c[5];
    float32 m_lineLength;
    float32 m_lineWidth;
    // uint8  m_clor[4];


    void setGeometryPara(float32  *c, float32 length, float32 width);
    void createGeometry();
};




#endif