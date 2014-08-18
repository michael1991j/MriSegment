cmake_minimum_required(VERSION 2.8)
project( Gui )

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

if(${VTK_VERSION} VERSION_GREATER "6" AND VTK_QT_VERSION VERSION_GREATER "4")
  # Instruct CMake to run moc automatically when needed.
  set(CMAKE_AUTOMOC ON)
  find_package(Qt5Widgets REQUIRED QUIET)
else()
  find_package(Qt4 REQUIRED)
  include(${QT_USE_FILE})
endif()
find_package( OpenCV REQUIRED )
FIND_PACKAGE(Qt4 REQUIRED)
SET(Gui_SOURCES  layerslide.cpp          tissueviewer.cpp      wizard_loadimages.cpp
main.cpp                welcomescreen.cpp  dataset.cpp    wizard_processfiles.cpp
mainwindow.cpp       layerslidewidget.cpp    wizardcontroller.cpp  wizard_selectimage.cpp
selectregionwidget.cpp  wizarddataconfig.cpp loadworkerthread.cpp mriscene.cpp processworkerthread.cpp
   )
SET(Gui_FORMS layerslide.ui          tissueviewer.ui       wizard_processfiles.ui
mainwindow.ui          welcomescreen.ui      wizard_selectimage.ui
selectregionwidget.ui  wizard_loadimages.ui)
include_directories(/home/michaelroberts/Build/MriSegment/Build/Implementation/gui/ /home/michaelroberts/Build/MriSegment/src/Implementation/gui/ )
SET(Gui_HEADERS   layerslide.h   layerslidewidget.h       welcomescreen.h      wizard_processfiles.h wizardcontroller.h processworkerthread.h
mainwindow.h            wizard_selectimage.h
selectregionwidget.h  wizarddataconfig.h dataset.h
tissueviewer.h        wizard_loadimages.h loadworkerthread.h mriscene.h
 )
QT4_WRAP_UI(gui_FORMS_HEADERS ${Gui_FORMS})
QT4_WRAP_CPP(DisplayImage_HEADERS_MOC ${Gui_HEADERS})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_EXECUTABLE(ManualSEG  ${DisplayImage_HEADERS_MOC}  ${gui_FORMS_HEADERS} ${Gui_SOURCES})

set(CMAKE_BUILD_TYPE Debug)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

include_directories(/usr/local/include/gdcm-2.4/)
LINK_DIRECTORIES(/usr/local/lib/)
target_link_libraries( ManualSEG /usr/local/lib/libgdcmcharls.so   QVTK   /usr/local/lib/libgdcmjpeg16.so /usr/local/lib/libgdcmCommon.so  ${VTK_LIBRARIES} 
 /usr/local/lib/libgdcmjpeg8.so /usr/local/lib/libgdcmDICT.so    /usr/local/lib/libgdcmMEXD.so /usr/local/lib/libgdcmDSED.so    /usr/local/lib/libgdcmMSFF.so /usr/local/lib/libgdcmexpat.so   /usr/local/lib/libgdcmopenjpeg.so /usr/local/lib/libgdcmIOD.so     /usr/local/lib/libgdcmuuid.so /usr/local/lib/libgdcmjpeg12.so  /usr/local/lib/libgdcmzlib.so   ${QT_LIBRARIES} /usr/local/lib/libDisplayImage.so /usr/local/lib/libMRIOpenCV.so /usr/local/lib/libMRIPCL.so ${OpenCV_LIBS} /usr/local/lib/libpugixml.so ${PCL_LIBRARIES}

)






