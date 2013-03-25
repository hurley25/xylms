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

class GradeWidget : public QWidget, public Ui::GradeWidget
{
public:
	GradeWidget();
	~GradeWidget();

private:

};

#endif // GRADEWIDGET_H_
