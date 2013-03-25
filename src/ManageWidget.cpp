// =====================================================================================
// 
//       Filename:  ManageWidget.cpp
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

#include <QtGui>
#include <QtSql>

#include "ManageWidget.h"
#include "NewJoinWidget.h"

ManageWidget::ManageWidget() : NewJoinWidget()
{
	// TODO
	stuComboBox->clear();	
	stuComboBox->addItem("2006级信息");
	stuComboBox->addItem("2007级信息");
	stuComboBox->addItem("2008级信息");
	stuComboBox->addItem("2009级信息");
	stuComboBox->addItem("2010级信息");
	stuComboBox->addItem("2011级信息");
	stuComboBox->addItem("2012级信息");
	stuComboBox->setEnabled(true);
}

ManageWidget::~ManageWidget()
{

}
