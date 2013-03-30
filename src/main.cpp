// =====================================================================================
// 
//       Filename:  main.cpp
//
//    Description:  xylms 系统的主函数文件
//
//        Version:  1.0
//        Created:  2013年03月20日 17时49分05秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "MainWindow.h"
#include "xylms.h"

int main(int argc, char *argv[])
{
	// 处理中文乱码问题
	QTextCodec *codec = QTextCodec::codecForName("system");

	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);

	QApplication app(argc, argv);

	//加载Qt自带的控件汉化文件
	QTranslator translator;

	translator.load(":/res/language/qt_zh_CN.qm");
	app.installTranslator(&translator);
	
	// 连接数据库，失败则不启动程序
	if (!createConnect()) {
		return 1;
	}
	
	// 从数据库获取设置信息
	if (getSystemSetInfo() == false) {
		return 1;	
	}

	// 添加启动logo
	QSplashScreen *splash = new QSplashScreen;

	splash->setPixmap(QPixmap(":/res/images/logo.png"));
	splash->show();

	MainWindow *mainwindow = new MainWindow;
	
	// sleep 1 s 只是为了显示启动画面...
	Sleep(1000);

	// 显示主窗口
	mainwindow->show();
	
	// 窗口显示在屏幕正中间
	mainwindow->move((QApplication::desktop()->width() - mainwindow->width()) >> 1,
				(QApplication::desktop()->height() - mainwindow->height()) >> 1);

	// 关闭启动画面
	splash->finish(mainwindow);
	delete splash;

	return app.exec();
}

