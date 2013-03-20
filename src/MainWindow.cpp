// =====================================================================================
// 
//       Filename:  MainWindow.cpp
//
//    Description:  主窗口程序的实现文件
//
//        Version:  1.0
//        Created:  2013年03月20日 17时53分22秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "MainWindow.h"

MainWindow::MainWindow()
{

}

MainWindow::~MainWindow()
{

}

void MainWindow::sleep(unsigned int msec)
{
	QTime dieTime = QTime::currentTime().addMSecs(msec);

	while( QTime::currentTime() < dieTime ) {
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}

