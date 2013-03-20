// =====================================================================================
// 
//       Filename:  MainWindow.h
//
//    Description:  主窗口程序的声明头文件
//
//        Version:  1.0
//        Created:  2013年03月20日 17时48分21秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

	void sleep(unsigned int msec); // 延时函数

protected:
	// void closeEvent(QCloseEvent *event);

private slots:

private:

};

#endif // MAINWINDOW_H_
