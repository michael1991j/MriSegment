cmake_minimum_required(VERSION 2.8)
project( MRIOpenCV )
add_library(MRIOpenCV SHARED DebugView.cpp           FindBoneTibia.cpp   MRIOpenCVSettings.cpp
FindBoneFemer.cpp       FindCartilage.cpp   MRIProcess.cpp
FindBoneFemurTrans.cpp  LabeledResults.cpp RunAll.cpp
FindBonePatella.cpp     MRIOpenCV.cpp)
set(CMAKE_BUILD_TYPE Debug)
find_package( OpenCV REQUIRED )
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

include_directories(/usr/local/include/gdcm-2.4/)
LINK_DIRECTORIES(/usr/local/lib/)
target_link_libraries( MRIOpenCV /usr/local/lib/libgdcmcharls.so  /usr/local/lib/libLoggingTool.so /usr/local/lib/libgdcmjpeg16.so /usr/local/lib/libgdcmCommon.so  /usr/local/lib/libgdcmjpeg8.so /usr/local/lib/libgdcmDICT.so    /usr/local/lib/libgdcmMEXD.so /usr/local/lib/libgdcmDSED.so    /usr/local/lib/libgdcmMSFF.so /usr/local/lib/libgdcmexpat.so   /usr/local/lib/libgdcmopenjpeg.so /usr/local/lib/libgdcmIOD.so     /usr/local/lib/libgdcmuuid.so /usr/local/lib/libgdcmjpeg12.so  /usr/local/lib/libgdcmzlib.so /usr/local/lib/libDisplayImage.so
  ${QT_LIBRARIES}  ${OpenCV_LIBS} ${PCL_LIBRARIES} /usr/local/lib/libpugixml.so)



install(TARGETS MRIOpenCV DESTINATION lib)
install(FILES DebugView.h           FindBonePatella.h  LabeledResults.h     MRIProcess.h
FindBoneFemer.h       FindBoneTibia.h    MRIOpenCV.h
FindBoneFemurTrans.h  FindCartilage.h RunAll.h   MRIOpenCVSettings.h DESTINATION include)


