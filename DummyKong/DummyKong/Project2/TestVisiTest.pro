TEMPLATE     = vcapp
TARGET       = TestVisiTest
CONFIG      += warn_on qt debug_and_release windows console
HEADERS     += MonInterface.h switches.h leds.h centralwidget.h VisiTest.h CommunicationFPGA.h myVector.h
SOURCES     += TestVisiTest.cpp MonInterface.cpp 
INCLUDEPATH += .
LIBS	      += ./VisiTest.lib ./CommunicationFPGA.lib
QT += widgets
