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

	hiddenInfoCheckBox = new QCheckBox(tr("隐藏详细资料"));
	diaplayScoreCheckBox = new QCheckBox(tr("显示成绩信息"));
	autoRerefreshCheckBox = new QCheckBox(tr("自动刷新成绩"));

	connect(hiddenInfoCheckBox, SIGNAL(stateChanged(int)), this, SLOT(setDisplayInfo(int)));
	connect(diaplayScoreCheckBox, SIGNAL(stateChanged(int)), this, SLOT(setDisplayScore(int)));

	stuLayout->addWidget(hiddenInfoCheckBox);
	stuLayout->addWidget(diaplayScoreCheckBox);
	stuLayout->addWidget(autoRerefreshCheckBox);
	
	createScoreView();
}

ManageWidget::~ManageWidget()
{

}

void ManageWidget::createScoreView()
{
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

void ManageWidget::refresh()
{
	QString strTableName("stu_");
	QString strCombo = stuComboBox->currentText();
	
	// 这个语句在公元9999年以后可能会出 bug ... 
	strTableName.append(strCombo.mid(0, 4));
	
	sqlModel->setTable(strTableName);
	createSqlTableModel();

	// 重载父类的显示函数，在此显示新的数据列的显示文字
	createScoreView();
	sqlModel->select();

	// 按照显示内容重新调整列宽度
	view->resizeColumnsToContents();
}

