 cmake_minimum_required(VERSION 3.4)
 
 project( TPV )
 
set(ROOT "${PROJECT_SOURCE_DIR}" CACHE INTERNAL "Root location" )

 #SET(CMAKE_BUILD_TYPE "Debug")  
 option(LINUXSIM "switch for linux simulator" ON)
 option(ANDROID  "switch for android " OFF)
 if(LINUXSIM)
 	message("platform : linux simulation")
    #find_package( OpenCV REQUIRED )
	#find_package( OpenSceneGraph REQUIRED )
 
 	SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -std=c++11 -pthread -fPIC -O2 -Wall -m64 -DLINUXSIM -DCHECK_GL_ERRORS")
 	INCLUDE_DIRECTORIES(
	. Include Maps  3rdParty  AutoGen/Protobuf AutoGen
	TrafficParticipantObject  
	TrafficParticipantObject/Sensors
	TrafficParticipantObject/Objects
	TrafficParticipantObject/Objects/Base
	TrafficParticipantObject/Objects/StaticObjects
	TrafficParticipantObject/Objects/ConstObjects
	TrafficParticipantObject/Objects/DynamicObjects
	3rdParty/spdlog/include
 	)

	 FIND_PACKAGE(Protobuf  REQUIRED)
	 # Threads
	 find_package(Threads REQUIRED)
	 
	 if(Protobuf_VERBOSE)
		 message(STATUS "Using Protocol Buffers ${Protobuf_VERSION}")
		 else()
		 message(STATUS "cant find protobuf ${Protobuf_VERSION}")
	 endif()

	FIND_PATH(OPENSCENEGRAPH_LIB_DIR libso.so osg.lib
	PATHS
	$ENV{OSG_ROOT}/lib
	)

	LINK_DIRECTORIES(${OPENSCENEGRAPH_LIB_DIR})
 elseif(ANDROID)
    #SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -std=c++11  -fPIC -O2 -Wall -m64 -DANDROID -DCHECK_GL_ERRORS")
    INCLUDE_DIRECTORIES(
	   . distortion camera tools mess include video conf  overlay FI/API FI/CAN overlay/trajectory overlay/PDC view view/extended 
	   video/ImageSequence FI video/OpenCV tools/lpng1068
       - Add comments to the test functions
 	)

	find_library( # Sets the name of the path variable.
			log-lib

			# Specifies the name of the NDK library that
			# you want CMake to locate.
			log)

 else()
    message("platform : arm")
    
 	# this is required
    SET(CMAKE_SYSTEM_NAME Linux)
    SET(EmbeedRootPath /opt/fsl-imx-x11/4.14-sumo/sysroots)
    
    #where is the target environment
	set(CMAKE_FIND_ROOT_PATH  ${EmbeedRootPath}/cortexa9hf-neon-poky-linux-gnueabi 
	)
	# set for android
	#set(CMAKE_FIND_ROOT_PATH /usr/mobo/M_Workspace/Android/NDKStandalone/android-24/arm64-v8a/sysroot /usr/mobo/M_Workspace/Android/NDKStandalone/android-24/arm64-v8a)
    
    # specify the cross compiler
	SET(CMAKE_C_COMPILER  ${EmbeedRootPath}/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-gcc)
	SET(CMAKE_CXX_COMPILER  ${EmbeedRootPath}/x86_64-pokysdk-linux/usr/bin/arm-poky-linux-gnueabi/arm-poky-linux-gnueabi-g++)
	
 	# search for programs in the build host directories (not necessary)
	#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
	
	# for libraries and headers in the target directories
	SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
	SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
 	
 	find_package( OpenCV REQUIRED )
 	
 	#SET(STAGING_DIR ${MyspinupPath}/sysroots/atlas7-arm)
 	add_definitions(-DENABLE_PRECOMPILED_HEADERS=OFF)
 	SET(CMAKE_C_FLAGS "--sysroot=${EmbeedRootPath}/cortexa9hf-neon-poky-linux-gnueabi -mfloat-abi=hard")
 	SET(CMAKE_CXX_FLAGS "-Wno-deprecated-declarations -std=c++11  -fPIC -O2 -Wall --sysroot=${EmbeedRootPath}/cortexa9hf-neon-poky-linux-gnueabi -mfloat-abi=hard -DTarget -DCAMERA_FRONTEND=${CAMERA_FRONTEND} -DENABLE_PRECOMPILED_HEADERS=OFF -DCHECK_GL_ERRORS")
 
 	message(${CMAKE_CXX_FLAGS})

	INCLUDE_DIRECTORIES(
		${EmbeedRootPath}/cortexa9hf-neon-poky-linux-gnueabi/usr/linux/include
		${EmbeedRootPath}/cortexa9hf-neon-poky-linux-gnueabi/usr/include/c++/7.3.0
		${EmbeedRootPath}/cortexa9hf-neon-poky-linux-gnueabi/usr/include/c++/7.3.0/arm-poky-linux-gnueabi
		${EmbeedRootPath}/cortexa9hf-neon-poky-linux-gnueabi/usr/include
	)
	

 	INCLUDE_DIRECTORIES(
	. distortion camera tools mess include video conf  overlay FI/API FI/CAN overlay/trajectory overlay/PDC view view/extended 
	 video/ImageSequence FI video/OpenCV
 	)

 endif()
 
 #FIND_LIBRARY(RUNTIME_LIB ../../3rdParty/PowerVR_SDK_2017_R2//Builds/Linux/x86_64/Lib  )
 #SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_CXX_FLAGS} -L../../3rdParty/PowerVR_SDK_2017_R2//Builds/Linux/x86_64/Lib") 
 #SET(CMAKE_SHARE_LINKER_FLAGS "${CMAKE_CXX_FLAGS} -L/../../3rdParty/PowerVR_SDK_2017_R2//Builds/Linux/x86_64/Lib")
 LINK_DIRECTORIES(lib)

#  ADD_SUBDIRECTORY(TrafficParticipants)
 ADD_SUBDIRECTORY(TrafficParticipantObject)
#  ADD_SUBDIRECTORY(Utility)
 ADD_SUBDIRECTORY(Modules)

 AUX_SOURCE_DIRECTORY(. DIR_API_SRCS)
 AUX_SOURCE_DIRECTORY(AutoGen/Protobuf DIR_AGPB_SRCS)
 
 ADD_LIBRARY(TPV_shared SHARED ${DIR_API_SRCS} ${DIR_AGPB_SRCS})
 ADD_LIBRARY(TPV_static STATIC ${DIR_API_SRCS} ${DIR_AGPB_SRCS})
 
#  add_executable(TPV_bin ${DIR_API_SRCS} ${DIR_AGPB_SRCS})

 SET_TARGET_PROPERTIES(TPV_shared PROPERTIES OUTPUT_NAME "TPV")
 SET_TARGET_PROPERTIES(TPV_static PROPERTIES OUTPUT_NAME "TPV")
 
 SET_TARGET_PROPERTIES(TPV_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
 SET_TARGET_PROPERTIES(TPV_shared PROPERTIES VERSION 1.2 SOVERSION 1)


if(LINUXSIM)
	 link_directories(3rdParty/libs/x64)
	 target_link_libraries( TPV_shared "-Wl,--whole-archive" TPOs  MODULES  Threads::Threads "-Wl,--no-whole-archive" png ${OpenCV_LIBS} ${PROTOBUF_LIBRARY}  glog  EGL osg osgViewer osgFX osgUtil osgGA osgDB osgText osgManipulator OpenThreads)
	 target_link_libraries( TPV_static "-Wl,--whole-archive" TPOs  MODULES  Threads::Threads "-Wl,--no-whole-archive" png ${OpenCV_LIBS} ${PROTOBUF_LIBRARY}  glog  EGL osg osgViewer osgFX osgUtil osgGA osgDB osgText osgManipulator OpenThreads)
	#  target_link_libraries( TPV_bin "-Wl,--whole-archive" TPOs   TOOLS "-Wl,--no-whole-archive" png ${OpenCV_LIBS} glog  EGL osg osgViewer osgGA osgDB osgText osgManipulator OpenThreads ${PROTOBUF_LIBRARY})
	ADD_SUBDIRECTORY(Examples)
elseif(ANDROID)
	 message("platform : android")
	 target_link_libraries( # Specifies the target library.
                            epv_shared "-Wl,--whole-archive" android VIDEO  VIEW MESS DISTOR  CAMERA  OVERLAY CONF TOOLS  FI "-Wl,--no-whole-archive" GLESv2   ${log-lib}  z)

	 target_link_libraries( # Specifies the target library.
			 				epv_static "-Wl,--whole-archive" android VIDEO  VIEW MESS DISTOR  CAMERA  OVERLAY CONF TOOLS  FI "-Wl,--no-whole-archive" GLESv2  z)
else()
     target_link_libraries( epv_shared "-Wl,--whole-archive" VIDEO  VIEW MESS DISTOR  CAMERA  OVERLAY CONF TOOLS  FI "-Wl,--no-whole-archive" GLESv2 EGL png ${OpenCV_LIBS})
	 target_link_libraries( epv_static "-Wl,--whole-archive" VIDEO  VIEW MESS DISTOR  CAMERA  OVERLAY CONF TOOLS  FI "-Wl,--no-whole-archive" GLESv2 EGL png ${OpenCV_LIBS})
	 ADD_SUBDIRECTORY(examples)
endif()

#######Generate Protobuf files#######
# message("Gnerate Protobuf files:")
add_custom_target(generate_protobuf_target
    #COMMAND echo " generate protobuf target "
    COMMENT "Generate protobuf files"
	)
add_custom_target(astyle_check
    #COMMAND echo " generate protobuf target "
    COMMENT "Running astyle check"
	)
	
file(GLOB_RECURSE PROTOBUF_SRC_LIST ${CMAKE_CURRENT_LIST_DIR}/**.proto)
execute_process(COMMAND mkdir -p ${CMAKE_CURRENT_LIST_DIR}/AutoGen/Protobuf)

foreach(v ${PROTOBUF_SRC_LIST})
    string(REGEX REPLACE ".*/\(.*\)" "\\1" file_name ${v})
    string(REGEX REPLACE ${file_name} "" target_path ${v})
	
	string(REGEX REPLACE ${CMAKE_CURRENT_LIST_DIR}/ "" Related_path ${target_path})
 	#message(${Related_path})	
	add_custom_command(
        TARGET generate_protobuf_target
		PRE_BUILD
		COMMAND protoc -I=${target_path} -I=${CMAKE_CURRENT_LIST_DIR}/TrafficParticipantObject --cpp_out=${CMAKE_CURRENT_LIST_DIR}/AutoGen/Protobuf ${v}
        COMMENT "prebuild file:" ${v}
    )
endforeach()

add_custom_command(
        TARGET astyle_check
		PRE_BUILD
		#COMMAND cd ${PROJECT_SOURCE_DIR}
		COMMAND cd .. && astyle  --style=linux --recursive --indent=spaces=4 --suffix=none --mode=c *.hpp *.cpp && cd build
        COMMENT "check coding style via astyle"
)


 INSTALL(TARGETS  TPV_shared TPV_static LIBRARY DESTINATION usr/lib ARCHIVE DESTINATION usr/lib) 
 install(DIRECTORY FI/API DESTINATION include FILES_MATCHING PATTERN "*.h")
 #install(DIRECTORY include DESTINATION include FILES_MATCHING PATTERN "*.h")
 #install(DIRECTORY Res/shaders DESTINATION opt/epv FILES_MATCHING PATTERN "*.glsl")
 install(DIRECTORY Res/images DESTINATION opt/epv FILES_MATCHING PATTERN "*.png")
 install(DIRECTORY Res/epv_20180124_withCAN/szh202_03 DESTINATION opt/epv/records FILES_MATCHING PATTERN "*")
 #install(DIRECTORY /opt/fsl-imx-x11/4.14-sumo/sysroots/cortexa9hf-neon-poky-linux-gnueabi/usr/lib  DESTINATION usr FILES_MATCHING PATTERN "libopencv_*")
 
