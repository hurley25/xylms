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

#include "NewJoinWidget.h"
#include "ManageWidget.h"
#include "SqlTableModel.h"
#include "xylms.h"

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

	createScoreView();
}

ManageWidget::~ManageWidget()
{

}

void ManageWidget::createScoreView()
{		
	for (int i = stu_level_1; i < stu_curr_level + 1; i++) {
		view->setColumnHidden(i ,false);
	}

	sqlModel->setHeaderData(stu_level_1, Qt::Horizontal, tr("成绩1"));
	sqlModel->setHeaderData(stu_level_2, Qt::Horizontal, tr("成绩2"));
	sqlModel->setHeaderData(stu_level_3, Qt::Horizontal, tr("成绩3"));
	sqlModel->setHeaderData(stu_level_4, Qt::Horizontal, tr("成绩4"));
	sqlModel->setHeaderData(stu_level_5, Qt::Horizontal, tr("成绩5"));
	sqlModel->setHeaderData(stu_level_6, Qt::Horizontal, tr("成绩6"));
	sqlModel->setHeaderData(stu_level_7, Qt::Horizontal, tr("成绩7"));
	sqlModel->setHeaderData(stu_level_8, Qt::Horizontal, tr("成绩8"));
	sqlModel->setHeaderData(stu_level_9, Qt::Horizontal, tr("成绩9"));
	sqlModel->setHeaderData(stu_score, Qt::Horizontal, tr("平均分"));
	sqlModel->setHeaderData(stu_is_pass, Qt::Horizontal, tr("是否通过"));
	sqlModel->setHeaderData(stu_curr_level, Qt::Horizontal, tr("当前进度"));
}

