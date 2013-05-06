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

// 全局的系统配置定义
SettingInfo settingInfo;

void Sleep(unsigned int msec)
{
	QTime dieTime = QTime::currentTime().addMSecs(msec);

	while( QTime::currentTime() < dieTime ) {
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}

bool createConnect()
{
	QSqlDatabase db  = QSqlDatabase::addDatabase("QMYSQL");
	
	bool isInput;
	QString ipInput = QInputDialog::getText(NULL, QObject::tr("连接数据库服务器"), 
				QObject::tr("请输入数据库服务器IP："), QLineEdit::Normal,
				QObject::tr("192.168.100.254"), &isInput);
	
	if (isInput && !ipInput.isEmpty()) {
		db.setHostName(ipInput);
	} else {
		QMessageBox::critical(NULL, QObject::tr("输入错误"), QObject::tr("服务器IP输入错误，程序即将退出。"));
		return false;
	}
	db.setDatabaseName("xiyoulinux");
	db.setUserName("root");
	db.setPassword("xiyou_linux");

	if (!db.open()) {
		QMessageBox::critical(NULL, QObject::tr("连接数据库错误"), db.lastError().text());
		return false;
	}
	
	return true;
}

bool getSystemSetInfo()
{
	QString strSql = QString("select now_year, is_open, passwd, welcome_info from root");

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(NULL, QObject::tr("数据库错误"), query.lastError().text());
		return false;
	}

	if (!query.next()) {
		QMessageBox::warning(NULL, QObject::tr("没有找到相关信息"), QObject::tr("数据库无系统设置，请联系DBA同学。"));
		return false;
	} else {
		settingInfo.userViewYears   = query.value(0).toString();
		settingInfo.userPower       = query.value(1).toInt();
		settingInfo.rootPasswd      = query.value(2).toString();
		settingInfo.rootWelcomeInfo = query.value(3).toString();
	}
	
	return true;
}

