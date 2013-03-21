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

	// 添加启动logo
	QSplashScreen *splash = new QSplashScreen;

	splash->setPixmap(QPixmap(":/res/images/logo.png"));
	splash->show();

	if (!xyl_create_connect()) {
		return 1;
	}

	MainWindow *mainwindow = new MainWindow;

	xyl_sleep(1000);

	mainwindow->show();

	splash->finish(mainwindow);
	delete splash;

	return app.exec();
}

