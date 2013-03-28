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
#include "ChangeScoreDialog.h"
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
	autoRefreshCheckBox = new QCheckBox(tr("自动刷新成绩"));
	sortScoreButton = new QPushButton(tr("按照成绩排序"));
	changeScoreButton = new QPushButton(tr("修改成绩"));

	autoRefreshTimer = new QTimer(this);
	connect(autoRefreshTimer, SIGNAL(timeout()), this, SLOT(sortScore()));

	connect(hiddenInfoCheckBox, SIGNAL(stateChanged(int)), this, SLOT(setDisplayInfo(int)));
	connect(diaplayScoreCheckBox, SIGNAL(stateChanged(int)), this, SLOT(setDisplayScore(int)));
	connect(autoRefreshCheckBox, SIGNAL(stateChanged(int)), this, SLOT(AutoRefreshScore(int)));
	connect(sortScoreButton, SIGNAL(clicked()), this, SLOT(sortScore()));
	connect(changeScoreButton, SIGNAL(clicked()), this, SLOT(changeScore()));

	stuLayout->addWidget(hiddenInfoCheckBox);
	stuLayout->addWidget(diaplayScoreCheckBox);
	stuLayout->addWidget(autoRefreshCheckBox);
	stuLayout->addWidget(sortScoreButton);
	stuLayout->addWidget(changeScoreButton);
	
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

void ManageWidget::changeScore()
{
	refresh();
	
	int flag = view->currentIndex().column();
	
	if (flag == 0) {
		QMessageBox::information(this, tr("修改操作失败"),
                              tr("没找到您选择了哪一行哎～～<p>请您先选择待修改的行好吗？"));
		return;
	}	
	
	int rowNum = view->currentIndex().row();

	ChangeScoreDialog changeScoreDialog(sqlModel, rowNum);
	
	if (changeScoreDialog.exec() == QDialog::QDialog::Rejected) {
		return;
	}

	changeRowScoreInfo(changeScoreDialog, rowNum);
	commitToDatabase();
	
	// 按照显示内容重新调整列宽度
	view->resizeColumnsToContents();
}

void ManageWidget::changeRowScoreInfo(ChangeScoreDialog &changeScoreDialog, int rowNum)
{
	sqlModel->setData(sqlModel->index(rowNum, stu_level_1), QVariant(changeScoreDialog.level_1_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_2), QVariant(changeScoreDialog.level_2_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_3), QVariant(changeScoreDialog.level_3_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_4), QVariant(changeScoreDialog.level_4_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_5), QVariant(changeScoreDialog.level_5_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_6), QVariant(changeScoreDialog.level_6_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_7), QVariant(changeScoreDialog.level_7_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_8), QVariant(changeScoreDialog.level_8_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_level_9), QVariant(changeScoreDialog.level_9_Edit->text()));
	sqlModel->setData(sqlModel->index(rowNum, stu_curr_level), QVariant(changeScoreDialog.levelEdit->text()));
}

void ManageWidget::AutoRefreshScore(int flag)
{
	if (flag) {
		autoRefreshTimer->start(5000);  // 5s 刷新一次
	} else {
		autoRefreshTimer->stop();	
	}
}

void ManageWidget::sortScore()
{
	refresh();
	
	sqlModel->setSort(stu_score, Qt::DescendingOrder);
	sqlModel->select();

	// 按照显示内容重新调整列宽度
	view->resizeColumnsToContents();
}

