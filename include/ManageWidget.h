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
class QPushButton;
class QTimer;

#include "NewJoinWidget.h"

class ChangeScoreDialog;

class ManageWidget : public NewJoinWidget
{
public:
	ManageWidget();
	~ManageWidget();

public slots:
	virtual void refresh();
	virtual void changeScore();
	virtual void AutoRefreshScore(int flag);
	void createScoreView();
	void changeRowScoreInfo(ChangeScoreDialog &changeInfoDialog, int rowNum);

private:
	QCheckBox *hiddenInfoCheckBox;
	QCheckBox *diaplayScoreCheckBox;
	QCheckBox *autoRefreshCheckBox;
	QPushButton *changeScoreButton;

	QTimer *autoRefreshTimer;
};

#endif // MANAGEWIDGET_H_
