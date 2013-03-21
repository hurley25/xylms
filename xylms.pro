# =====================================================================================
# 
#       Filename:  xylms.pro
#
#    Description:  为 xylms项目 写的 Qt 项目文件
#
#        Created:  2013年03月20日 17时57分02秒
#
#         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
#        Company:  Class 1107 of Computer Science and Technology
#
# =====================================================================================

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
INCLUDEPATH += include

QT += sql

# Input

HEADERS +=  include/MainWindow.h include/StackedWidget.h include/xylms.h \
		include/NewJoinWidget.h include/GradeWidget.h include/ManageWidget.h include/SetWidget.h

SOURCES +=  src/main.cpp src/MainWindow.cpp src/StackedWidget.cpp src/xylms.cpp \
		src/NewJoinWidget.cpp src/GradeWidget.cpp src/ManageWidget.cpp src/SetWidget.cpp

FORMS += 

RESOURCES += xylms.qrc
