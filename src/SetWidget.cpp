// =====================================================================================
// 
//       Filename:  SetWidget.cpp
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

#include "SetWidget.h"

SetWidget::SetWidget()
{
	setupUi(this);
	
	// TODO
	yearComboBox->addItem("2006级");
	yearComboBox->addItem("2007级");
	yearComboBox->addItem("2008级");
	yearComboBox->addItem("2009级");
	yearComboBox->addItem("2010级");
	yearComboBox->addItem("2011级");
	yearComboBox->addItem("2012级");

	deleteComboBox->addItem("2006级");
	deleteComboBox->addItem("2007级");
	deleteComboBox->addItem("2008级");
	deleteComboBox->addItem("2009级");
	deleteComboBox->addItem("2010级");
	deleteComboBox->addItem("2011级");
	deleteComboBox->addItem("2012级");

	welcomeEdit->setText(tr(""));

	permissionComboBox->setCurrentIndex(0);
}

SetWidget::~SetWidget()
{

}
