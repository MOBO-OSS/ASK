
add_executable(APA_Demo APA_Scenario.cpp)

SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -std=c++11 -pthread -fPIC -O2 -Wall -m64 -DLINUXSIM -DCHECK_GL_ERRORS")

#target_link_libraries( TPV_bin "-Wl,--whole-archive" TPV_static   TOOLS "-Wl,--no-whole-archive" png ${OpenCV_LIBS} glog  EGL osg osgViewer osgGA osgDB osgText osgManipulator OpenThreads ${PROTOBUF_LIBRARY})
target_link_libraries( APA_Demo TPV_shared pthread)


add_executable(ADAS_Demo ADAS_Scenario.cpp )
target_link_libraries( ADAS_Demo TPV_shared  pthread)


add_executable(ROBOT_Demo Robot_Scenario.cpp )
target_link_libraries( ROBOT_Demo TPV_shared  pthread)



