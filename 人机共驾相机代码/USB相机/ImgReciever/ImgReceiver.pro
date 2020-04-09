TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TARGET = ImgReciever
DESTDIR += ../../../bin/

CONFIG(debug, debug|release) {
    OBJECTS_DIR = ./tmp_Debug
}
CONFIG(release, debug|release) {
    OBJECTS_DIR = ./tmp_Release
}

SOURCES += \
    ImgReciever.cc \
    ImgLoopmain.cpp

HEADERS += \
    ImgReciever.hh \
    Img.hh

INCLUDEPATH += \
    ../../message \
#    /usr/local/opencv/include \
#    /usr/local/opencv/include/opencv \
#    /usr/local/opencv/include/opencv2
    /opt/ros/kinetic/include/opencv-3.3.1-dev  \
    /opt/ros/kinetic/include/opencv-3.3.1-dev/opencv  \
    /opt/ros/kinetic/include/opencv-3.3.1-dev/opencv2


LIBS += \
    -L/usr/local/lib \
    -lrcs \
    ../../../lib/libUGVAuto.a \
   -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_ml  \
   -lpthread

LIBS += \
    -L/opt/ros/kinetic/lib/x86_64-linux-gnu  \
   -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_ml  \

