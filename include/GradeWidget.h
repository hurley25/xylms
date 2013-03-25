// =====================================================================================
// 
//       Filename:  GradeWidget.h
//
//    Description:  面试打分选项卡控件
//
//        Version:  1.0
//        Created:  2013年03月21日 16时07分09秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef GRADEWIDGET_H_
#define GRADEWIDGET_H_

#include <QWidget>

#include "ui_GradeWidget.h"

class QToolBar;
class QAction;

class GradeWidget : public QWidget, public Ui::GradeWidget
{
	Q_OBJECT

public:
	GradeWidget();
	~GradeWidget();

private slots:
	void findUser();
	void reset();
	void setButtonEnable(QString str);

	void setAPlus();
	void setA();
	void setAMinus();
	void setBPlus();
	void setB();
	void setBMinus();
	void setCPlus();
	void setC();
	void setCMinus();
	void setD();

private:

	void createAction();

	QToolBar *toolBar;

	QAction *aPlusAction;
	QAction *aAction;
	QAction *aMinusAction;
	QAction *bPlusAction;
	QAction *bAction;
	QAction *bMinusAction;
	QAction *cPlusAction;
	QAction *cAction;
	QAction *cMinusAction;
	QAction *dAction;
};

#endif // GRADEWIDGET_H_
