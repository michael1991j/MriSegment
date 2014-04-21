cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
FIND_PACKAGE(Qt4 REQUIRED)
SET(DisplayImage_SOURCES boxregion.cpp   mriscene.cpp
main.cpp                       record.cpp
mainwindow.cpp                 recordhandel.cpp
manualsegmentation.cpp  mrimanualscene.cpp      regionselect.cpp
      mrimatrix.cpp moc_mainwindow.cpp      moc_mrimatrix.cpp
moc_mrimanualscene.cpp  moc_mriscene.cpp
 )
SET(DisplayImage_HEADERS  )
QT4_WRAP_CPP(DisplayImage_HEADERS_MOC ${DisplayImage_HEADERS})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_EXECUTABLE(ManualSEG ${DisplayImage_SOURCES}${DisplayImage_HEADERS_MOC})

set(CMAKE_BUILD_TYPE Debug)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

include_directories(/usr/local/include/gdcm-2.4/)
LINK_DIRECTORIES(/usr/local/lib/)
target_link_libraries( ManualSEG /usr/local/lib/libgdcmcharls.so  /usr/local/lib/libgdcmjpeg16.so /usr/local/lib/libgdcmCommon.so  /usr/local/lib/libgdcmjpeg8.so /usr/local/lib/libgdcmDICT.so    /usr/local/lib/libgdcmMEXD.so /usr/local/lib/libgdcmDSED.so    /usr/local/lib/libgdcmMSFF.so /usr/local/lib/libgdcmexpat.so   /usr/local/lib/libgdcmopenjpeg.so /usr/local/lib/libgdcmIOD.so     /usr/local/lib/libgdcmuuid.so /usr/local/lib/libgdcmjpeg12.so  /usr/local/lib/libgdcmzlib.so   ${QT_LIBRARIES} /usr/local/lib/libDisplayImage.so ${OpenCV_LIBS}

)






