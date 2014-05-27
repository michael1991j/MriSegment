#-------------------------------------------------
#
# Project created by QtCreator 2014-02-12T21:26:59
#
#-------------------------------------------------

QT       += core gui

TARGET = MRI
unix:LIBS += -lpthread
LIBS += /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_ocl.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_superres.so /usr/local/lib/libopencv_ts.a /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so /usr/lib/x86_64-linux-gnu/libXext.so /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libICE.so /usr/lib/x86_64-linux-gnu/libSM.so /usr/lib/x86_64-linux-gnu/libGL.so /usr/lib/x86_64-linux-gnu/libGLU.so -ltbb -lrt -lpthread -lm -ldl
INCLUDEPATH +=   /usr/local/include/opencv \
                 /usr/local/include
IMEBRA_PATH = ../../Libary
SOURCES += main.cpp\
        mainwindow.cpp\
    $${IMEBRA_PATH}/library/base/src/thread.cpp \
    $${IMEBRA_PATH}/library/base/src/streamWriter.cpp \
    $${IMEBRA_PATH}/library/base/src/streamReader.cpp \
    $${IMEBRA_PATH}/library/base/src/streamController.cpp \
    $${IMEBRA_PATH}/library/base/src/stream.cpp \
    $${IMEBRA_PATH}/library/base/src/memoryStream.cpp \
    $${IMEBRA_PATH}/library/base/src/memory.cpp \
    $${IMEBRA_PATH}/library/base/src/huffmanTable.cpp \
    $${IMEBRA_PATH}/library/base/src/exception.cpp \
    $${IMEBRA_PATH}/library/base/src/criticalSection.cpp \
    $${IMEBRA_PATH}/library/base/src/charsetConversion.cpp \
    $${IMEBRA_PATH}/library/base/src/baseStream.cpp \
    $${IMEBRA_PATH}/library/base/src/baseObject.cpp \
    $${IMEBRA_PATH}/library/imebra/src/YBRPARTIALToRGB.cpp \
    $${IMEBRA_PATH}/library/imebra/src/YBRFULLToRGB.cpp \
    $${IMEBRA_PATH}/library/imebra/src/YBRFULLToMONOCHROME2.cpp \
    $${IMEBRA_PATH}/library/imebra/src/waveform.cpp \
    $${IMEBRA_PATH}/library/imebra/src/VOILUT.cpp \
    $${IMEBRA_PATH}/library/imebra/src/viewHelper.cpp \
    $${IMEBRA_PATH}/library/imebra/src/transformsChain.cpp \
    $${IMEBRA_PATH}/library/imebra/src/transformHighBit.cpp \
    $${IMEBRA_PATH}/library/imebra/src/transaction.cpp \
    $${IMEBRA_PATH}/library/imebra/src/RGBToYBRPARTIAL.cpp \
    $${IMEBRA_PATH}/library/imebra/src/RGBToYBRFULL.cpp \
    $${IMEBRA_PATH}/library/imebra/src/RGBToMONOCHROME2.cpp \
    $${IMEBRA_PATH}/library/imebra/src/PALETTECOLORToRGB.cpp \
    $${IMEBRA_PATH}/library/imebra/src/MONOCHROME2ToYBRFULL.cpp \
    $${IMEBRA_PATH}/library/imebra/src/MONOCHROME2ToRGB.cpp \
    $${IMEBRA_PATH}/library/imebra/src/MONOCHROME1ToRGB.cpp \
    $${IMEBRA_PATH}/library/imebra/src/MONOCHROME1ToMONOCHROME2.cpp \
    $${IMEBRA_PATH}/library/imebra/src/modalityVOILUT.cpp \
    $${IMEBRA_PATH}/library/imebra/src/LUT.cpp \
    $${IMEBRA_PATH}/library/imebra/src/jpegCodec.cpp \
    $${IMEBRA_PATH}/library/imebra/src/image.cpp \
    $${IMEBRA_PATH}/library/imebra/src/drawBitmap.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dicomDir.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dicomDict.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dicomCodec.cpp \
        $${IMEBRA_PATH}/library/imebra/src/dataSet.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerTime.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringUT.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringUnicode.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringUI.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringST.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringSH.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringPN.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringLT.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringLO.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringIS.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringDS.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringCS.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringAS.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerStringAE.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerString.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerDateTimeBase.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerDateTime.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandlerDate.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataHandler.cpp \
    $${IMEBRA_PATH}/library/imebra/src/dataGroup.cpp \
    $${IMEBRA_PATH}/library/imebra/src/data.cpp \
    $${IMEBRA_PATH}/library/imebra/src/colorTransformsFactory.cpp \
    $${IMEBRA_PATH}/library/imebra/src/colorTransform.cpp \
    $${IMEBRA_PATH}/library/imebra/src/codecFactory.cpp \
    $${IMEBRA_PATH}/library/imebra/src/codec.cpp \
    $${IMEBRA_PATH}/library/imebra/src/charsetsList.cpp \
    $${IMEBRA_PATH}/library/imebra/src/buffer.cpp \
        $${IMEBRA_PATH}/library/imebra/src/transform.cpp \
    $${IMEBRA_PATH}/library/base/src/charsetConversionICU.cpp \
    $${IMEBRA_PATH}/library/base/src/charsetConversionWindows.cpp \
    $${IMEBRA_PATH}/library/base/src/charsetConversionIconv.cpp \
    mriscene.cpp \
    mrimatrix.cpp \
    mrimanualscene.cpp \
    record.cpp \
    recordhandel.cpp

HEADERS  += mainwindow.h \
    $${IMEBRA_PATH}/library/base/include/thread.h \
    $${IMEBRA_PATH}/library/base/include/streamWriter.h \
    $${IMEBRA_PATH}/library/base/include/streamReader.h \
    $${IMEBRA_PATH}/library/base/include/streamController.h \
    $${IMEBRA_PATH}/library/base/include/stream.h \
    $${IMEBRA_PATH}/library/base/include/nullStream.h \
    $${IMEBRA_PATH}/library/base/include/memoryStream.h \
    $${IMEBRA_PATH}/library/base/include/memory.h \
    $${IMEBRA_PATH}/library/base/include/huffmanTable.h \
    $${IMEBRA_PATH}/library/base/include/exception.h \
    $${IMEBRA_PATH}/library/base/include/criticalSection.h \
    $${IMEBRA_PATH}/library/base/include/configuration.h \
    $${IMEBRA_PATH}/library/base/include/charsetConversion.h \
    $${IMEBRA_PATH}/library/base/include/baseStream.h \
    $${IMEBRA_PATH}/library/base/include/baseObject.h \
    $${IMEBRA_PATH}/library/imebra/include/YBRPARTIALToRGB.h \
    $${IMEBRA_PATH}/library/imebra/include/YBRFULLToRGB.h \
    $${IMEBRA_PATH}/library/imebra/include/YBRFULLToMONOCHROME2.h \
    $${IMEBRA_PATH}/library/imebra/include/waveform.h \
    $${IMEBRA_PATH}/library/imebra/include/VOILUT.h \
    $${IMEBRA_PATH}/library/imebra/include/viewHelper.h \
    $${IMEBRA_PATH}/library/imebra/include/transformsChain.h \
    $${IMEBRA_PATH}/library/imebra/include/transformHighBit.h \
    $${IMEBRA_PATH}/library/imebra/include/transaction.h \
    $${IMEBRA_PATH}/library/imebra/include/RGBToYBRPARTIAL.h \
    $${IMEBRA_PATH}/library/imebra/include/RGBToYBRFULL.h \
    $${IMEBRA_PATH}/library/imebra/include/RGBToMONOCHROME2.h \
    $${IMEBRA_PATH}/library/imebra/include/PALETTECOLORToRGB.h \
    $${IMEBRA_PATH}/library/imebra/include/MONOCHROME2ToYBRFULL.h \
    $${IMEBRA_PATH}/library/imebra/include/MONOCHROME2ToRGB.h \
    $${IMEBRA_PATH}/library/imebra/include/MONOCHROME1ToRGB.h \
    $${IMEBRA_PATH}/library/imebra/include/MONOCHROME1ToMONOCHROME2.h \
    $${IMEBRA_PATH}/library/imebra/include/modalityVOILUT.h \
    $${IMEBRA_PATH}/library/imebra/include/LUT.h \
    $${IMEBRA_PATH}/library/imebra/include/jpegCodec.h \
    $${IMEBRA_PATH}/library/imebra/include/imebraDoc.h \
    $${IMEBRA_PATH}/library/imebra/include/imebra.h \
    $${IMEBRA_PATH}/library/imebra/include/image.h \
    $${IMEBRA_PATH}/library/imebra/include/drawBitmap.h \
    $${IMEBRA_PATH}/library/imebra/include/dicomDir.h \
    $${IMEBRA_PATH}/library/imebra/include/dicomDict.h \
    $${IMEBRA_PATH}/library/imebra/include/dicomCodec.h \
    $${IMEBRA_PATH}/library/imebra/include/dataSet.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerTime.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringUT.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringUnicode.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringUI.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringST.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringSH.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringPN.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringLT.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringLO.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringIS.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringDS.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringCS.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringAS.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerStringAE.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerString.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerNumeric.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerDateTimeBase.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerDateTime.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandlerDate.h \
    $${IMEBRA_PATH}/library/imebra/include/dataHandler.h \
    $${IMEBRA_PATH}/library/imebra/include/dataGroup.h \
    $${IMEBRA_PATH}/library/imebra/include/dataCollection.h \
    $${IMEBRA_PATH}/library/imebra/include/data.h \
    $${IMEBRA_PATH}/library/imebra/include/colorTransformsFactory.h \
    $${IMEBRA_PATH}/library/imebra/include/colorTransform.h \
    $${IMEBRA_PATH}/library/imebra/include/codecFactory.h \
    $${IMEBRA_PATH}/library/imebra/include/codec.h \
    $${IMEBRA_PATH}/library/imebra/include/charsetsList.h \
    $${IMEBRA_PATH}/library/imebra/include/bufferStream.h \
    $${IMEBRA_PATH}/library/imebra/include/buffer.h \
        $${IMEBRA_PATH}/library/imebra/include/transform.h \
    $${IMEBRA_PATH}/library/base/include/charsetConversionICU.h \
    $${IMEBRA_PATH}/library/base/include/charsetConversionWindows.h \
    $${IMEBRA_PATH}/library/base/include/charsetConversionIconv.h \
    mriscene.h \
    boxregion.h \
    mrimatrix.h \
    regionselect.h \
    manualsegmentation.h \
    mrimanualscene.h \
    record.h \
    recordhandel.h


FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../OpenCVCommonLibary/MriCommon-build-desktop-Qt_4_8_1_in_PATH__System__Release/release/ -lMriCommon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../OpenCVCommonLibary/MriCommon-build-desktop-Qt_4_8_1_in_PATH__System__Release/debug/ -lMriCommon
else:symbian: LIBS += -lMriCommon
else:unix: LIBS += -L$$PWD/../../OpenCVCommonLibary/MriCommon-build-desktop-Qt_4_8_1_in_PATH__System__Release/ -lMriCommon

INCLUDEPATH += $$PWD/../../OpenCVCommonLibary/MriCommon
DEPENDPATH += $$PWD/../../OpenCVCommonLibary/MriCommon
