// =====================================================================================
// 
//       Filename:  ChangeInfoDialog.cpp
//
//    Description:  修改成员信息对话框的定义
//
//        Version:  1.0
//        Created:  2013年03月23日 22时11分55秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "ChangeInfoDialog.h"

ChangeInfoDialog::ChangeInfoDialog(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	
	// 固定对话框大小，不允许调整
	this->setFixedSize(this->width(),this->height());
}

ChangeInfoDialog::~ChangeInfoDialog()
{

}
