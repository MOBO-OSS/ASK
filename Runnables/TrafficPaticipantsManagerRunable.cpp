
#include "TrafficParticipants/TrafficPaticipantsManager.hpp"
#include "Ground/Ground.hpp"
#include "TPObjectBase.hpp"
#include <osgViewer/Viewer>
#include "Sensors/TPSensorUnknow.hpp"

int _TmainTest()
{

    TPSensorUnknow * unknowSensor = new TPSensorUnknow(TP_SENSOR_TYPE_UNKNOW, 0);

    TPObjectBase  * ground = new Ground(1, TP_OBJECT_TYPE_GROUND, 1000, 1000);

    TrafficPaticipantsManager::getInstance().updateTPObject(ground, unknowSensor);




    return 0;
}