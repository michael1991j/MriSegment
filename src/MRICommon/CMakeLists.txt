cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
add_library(DisplayImage SHARED MRIDataSet.cpp MRICommon.cpp MRIDataSet.cpp MRISlice.cpp MRISliceInfo.cpp DicomLoader.cpp MRITransformation.cpp MRICommonSettings.cpp)
set(CMAKE_BUILD_TYPE Debug)
find_package( OpenCV REQUIRED )
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

include_directories(/usr/local/include/gdcm-2.4/)
LINK_DIRECTORIES(/usr/local/lib/)
target_link_libraries( DisplayImage /usr/local/lib/libgdcmcharls.so  /usr/local/lib/libgdcmjpeg16.so /usr/local/lib/libgdcmCommon.so  /usr/local/lib/libgdcmjpeg8.so /usr/local/lib/libgdcmDICT.so    /usr/local/lib/libgdcmMEXD.so /usr/local/lib/libgdcmDSED.so    /usr/local/lib/libgdcmMSFF.so /usr/local/lib/libgdcmexpat.so   /usr/local/lib/libgdcmopenjpeg.so /usr/local/lib/libgdcmIOD.so     /usr/local/lib/libgdcmuuid.so /usr/local/lib/libgdcmjpeg12.so  /usr/local/lib/libgdcmzlib.so   ${QT_LIBRARIES} ${OpenCV_LIBS} /usr/local/lib/libpugixml.so)



install(TARGETS DisplayImage DESTINATION lib)
install(FILES DicomLoader.h  MRICommon.h  MRIDataSet.h  MRISlice.h  MRISliceInfo.h MRITransformation.h MRICommonSettings.h DESTINATION include)


