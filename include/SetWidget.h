// =====================================================================================
// 
//       Filename:  SetWidget.h
//
//    Description:  系统设置选项卡控件
//
//        Version:  1.0
//        Created:  2013年03月21日 16时10分51秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef SETWIDGET_H_
#define SETWIDGET_H_

#include <QWidget>

#include "ui_SetWidget.h"

class SetWidget : public QWidget, public Ui::SetWidget
{
	Q_OBJECT

public:
	SetWidget();

public slots:
	void changeUserViewYear();
	void changeUserPermission(int index);
	void exportToExcel();
	void deleteScore();
	void ChangeWelcomeInfo();
	void changePass();

private:

};

#endif // SETWIDGET_H_
