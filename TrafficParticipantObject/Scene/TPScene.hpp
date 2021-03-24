#ifndef __TRAFFICPATICIPANTSMANGER_H__
#define __TRAFFICPATICIPANTSMANGER_H__

#include <map>
#include <hash_map>
#include "TPObjectBase.hpp"
#include "TPSensorBase.hpp"
#include <osg/Group>
#include "TrafficPaticipantCamera.hpp"
#include "TPSensorCamera.hpp"
#include "EGO/EgoObject.hpp"
#include "AutoGen/Protobuf/BaseType.pb.h"
#include "Scene/TPHUD.hpp"

class EgoObject;
class MovingObject;
class TPHUD;
class TPScene
{
private:
    /* data */
    TPScene(/* args */);

    //std::hash_map<uint32, TPBase * > m_TPTable1;
    std::map<uint32, TPSensorBase * > m_TPSensorable;

    osg::ref_ptr<osg::Group> m_root;
    osg::ref_ptr<TrafficPaticipantCamera> m_TPCamera;
    osg::ref_ptr<osg::Group> m_TPNodes;

    osg::ref_ptr<EgoObject> m_ego;
    osg::ref_ptr<TPHUD> m_HUD;

    //! todo: merge to same vector
    std::vector<std::map<int, osg::ref_ptr<TPObjectBase>>> m_TPOBuff;
    // std::vector<std::map<int,  osg::ref_ptr<MovingObject>>> m_MoveTPOBuff;
    // std::vector<std::map<int,  osg::ref_ptr<EgoObject>>> m_EgoTPOBuff;

    std::vector<int> m_TPOMaxId;

public:
    ~TPScene();

    static TPScene&  getInstance()
    {
        static TPScene  m_instancePtr;

        return m_instancePtr;
    }

    // Sensor will not be free automaticlly, TPO will
    void updateTPObject(osg::ref_ptr<TPObjectBase>  object, osg::ref_ptr<TPSensorBase> senseor);
    void removeTPObject(osg::ref_ptr<TPObjectBase>  object, osg::ref_ptr<TPSensorBase> senseor);

    void updateTPObject(osg::ref_ptr<TPObjectBase>  object);
    // void updateTPObject(osg::ref_ptr<MovingObject>  object);

    bool addNewSensor(osg::ref_ptr<TPSensorBase>  senseor);
    osg::ref_ptr<osg::Node>  getSensorNode(std::string name);

    osg::ref_ptr<EgoObject> getEGONode()
    {
        return m_ego;
    }


    osg::Group * getRoot();

    osg::ref_ptr<TPHUD> getHudNode()
    {
        return m_HUD ;
    }
};


#endif
