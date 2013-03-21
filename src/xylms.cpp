// =====================================================================================
// 
//       Filename:  xylms.cpp
//
//    Description:   项目的一些独立函数定义
//
//        Version:  1.0
//        Created:  2013年03月21日 14时18分22秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>
#include <QtSql>

#include "xylms.h"

void xyl_sleep(unsigned int msec)
{
	QTime dieTime = QTime::currentTime().addMSecs(msec);

	while( QTime::currentTime() < dieTime ) {
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}

bool xyl_create_connect()
{

}
