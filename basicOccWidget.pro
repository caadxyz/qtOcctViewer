QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = basicOccWidget
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        occview.cpp

HEADERS  += mainwindow.h \
            occview.h
FORMS    += mainwindow.ui

INCLUDEPATH +=  $$(CASROOT)/include/opencascade
LIBS += -L$$(CASROOT)/lib

LIBS += -lTKernel  -lTKMath -lTKService -lTKV3d -lTKOpenGl \
        -lTKBRep -lTKIGES -lTKSTL -lTKVRML -lTKSTEP -lTKSTEPAttr -lTKSTEP209 \
        -lTKSTEPBase  -lTKGeomBase -lTKGeomAlgo -lTKG3d -lTKG2d \
        -lTKXSBase  -lTKShHealing -lTKHLR -lTKTopAlgo -lTKMesh -lTKPrim \
        -lTKCDF -lTKBool -lTKBO -lTKFillet -lTKOffset \
