// =====================================================================================
// 
//       Filename:  ManageWidget.h
//
//    Description:  成员管理选项卡控件
//
//        Version:  1.0
//        Created:  2013年03月21日 16时09分13秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef MANAGEWIDGET_H_
#define MANAGEWIDGET_H_

#include <QWidget>

class QCheckBox;

#include "NewJoinWidget.h"

class ManageWidget : public NewJoinWidget
{
public:
	ManageWidget();
	~ManageWidget();

public slots:
	virtual void refresh();
	void createScoreView();

private:
	QCheckBox *hiddenInfoCheckBox;
	QCheckBox *diaplayScoreCheckBox;
	QCheckBox *autoRerefreshCheckBox;
};

#endif // MANAGEWIDGET_H_
