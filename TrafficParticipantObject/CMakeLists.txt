 
INCLUDE_DIRECTORIES(
    Objects/Base
    Objects/StaticObjects
    FeaturePoint
    Scene
)

SET(LIB_NAME TPO)

 AUX_SOURCE_DIRECTORY(. DIR_TPO_SRCS)

 #base 
 AUX_SOURCE_DIRECTORY(Objects/Base DIR_TPO_BASE_SRCS)
 AUX_SOURCE_DIRECTORY(Objects/Base/Trajectory DIR_TPO_BASE_TRAJECTORY_SRCS)

 #Const object
 AUX_SOURCE_DIRECTORY(Objects/ConstObjects/EGO DIR_TPO_S_EGO_SRCS)
 AUX_SOURCE_DIRECTORY(Objects/ConstObjects/Ground DIR_TPO_S_GROUND_SRCS)

 #dynamic object
 AUX_SOURCE_DIRECTORY(Objects/DynamicObjects/FeaturePoint DIR_TPO_D_FEATUREPOINT_SRCS)
 AUX_SOURCE_DIRECTORY(Objects/DynamicObjects/RSP DIR_TPO_D_RSP_SRCS)
 AUX_SOURCE_DIRECTORY(Objects/DynamicObjects/MovingObject DIR_TPO_D_MOVING_SRCS)
 AUX_SOURCE_DIRECTORY(Objects/DynamicObjects/Point DIR_TPO_D_POINT_SRCS)
 
 #Static object
 AUX_SOURCE_DIRECTORY(Objects/StaticObjects/Lane DIR_TPO_S_LANE_SRCS)
 AUX_SOURCE_DIRECTORY(Objects/StaticObjects/ParkingSlot DIR_TPO_S_PS_SRCS)


 AUX_SOURCE_DIRECTORY(Scene DIR_TPO_SCENE_SRCS)
 AUX_SOURCE_DIRECTORY(Sensors DIR_TPO_SENSOR_SRCS)


#  AUX_SOURCE_DIRECTORY(CatagoryGround DIR_GROUND_SRCS)
#  AUX_SOURCE_DIRECTORY(CatagoryRawSensors DIR_RAWSENSOR_SRCS)

 ADD_LIBRARY (${LIB_NAME}  STATIC
            ${DIR_TPO_SRCS} 
            ${DIR_TPO_BASE_SRCS} 
            ${DIR_TPO_BASE_TRAJECTORY_SRCS}
            ${DIR_TPO_D_FEATUREPOINT_SRCS}
            ${DIR_TPO_D_RSP_SRCS}
            ${DIR_TPO_S_LANE_SRCS}
            ${DIR_TPO_S_PS_SRCS}
            ${DIR_TPO_S_EGO_SRCS}
            ${DIR_TPO_S_GROUND_SRCS}
            ${DIR_TPO_SCENE_SRCS} 
            ${DIR_TPO_SENSOR_SRCS}
            ${DIR_TPO_D_MOVING_SRCS}
            ${DIR_TPO_D_POINT_SRCS}
            )

set_target_properties(${LIB_NAME} PROPERTIES
      OUTPUT_NAME ${LIB_NAME}s
      ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) 
# message(${PROJECT_SOURCE_DIR}/lib)
