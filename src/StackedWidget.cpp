// =====================================================================================
// 
//       Filename:  StackedWidget.cpp
//
//    Description:  主程序显示的分页控件的实现
//
//        Version:  1.0
//        Created:  2013年03月21日 10时57分28秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "StackedWidget.h"
#include "NewJoinWidget.h"
#include "GradeWidget.h"
#include "ManageWidget.h"
#include "SetWidget.h"

StackedWidget::StackedWidget()
{
	newJoinWidget = new NewJoinWidget();
	gradeWidget   = new GradeWidget();
	manageWidget  = new ManageWidget();
	setWidget     = new SetWidget();
	
	this->addWidget(newJoinWidget);
	this->addWidget(gradeWidget);
	this->addWidget(manageWidget);
	this->addWidget(setWidget);
	
	//QTextStream cout(stdout, QIODevice::WriteOnly);
	//cout << indexOf(newJoinWidget) << endl;
	//cout << indexOf(gradeWidget) << endl;
	//cout << indexOf(manageWidget) << endl;
	//cout << indexOf(setWidget) << endl;
}

StackedWidget::~StackedWidget()
{

}
