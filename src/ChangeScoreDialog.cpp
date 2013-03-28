// =====================================================================================
// 
//       Filename:  ChangeScoreDialog.cpp
//
//    Description:  成绩修改对话框的实现
//
//        Version:  1.0
//        Created:  2013年03月27日 14时08分12秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>
#include <QtSql>

#include "SqlTableModel.h"
#include "ChangeScoreDialog.h"
#include "xylms.h"

ChangeScoreDialog::ChangeScoreDialog(QWidget *parent) : QDialog(parent)
{
	setupUi(this);

	// 设置输入过滤器
	setRegExp();

	// 固定对话框大小，不允许调整
	this->setFixedSize(this->width(),this->height());
}

ChangeScoreDialog::ChangeScoreDialog(SqlTableModel *sqlModel, int index, QWidget *parent) : QDialog(parent)
{
	setupUi(this);

	this->sqlModel = sqlModel;
	
	// 设置输入过滤器
	setRegExp();
	
	idEdit->setText(sqlModel->record(index).value(stu_id).toString());
	nameEdit->setText(sqlModel->record(index).value(stu_name).toString());
	levelEdit->setText(sqlModel->record(index).value(stu_curr_level).toString());
	level_1_Edit->setText(sqlModel->record(index).value(stu_level_1).toString());
	level_2_Edit->setText(sqlModel->record(index).value(stu_level_2).toString());
	level_3_Edit->setText(sqlModel->record(index).value(stu_level_3).toString());
	level_4_Edit->setText(sqlModel->record(index).value(stu_level_4).toString());
	level_5_Edit->setText(sqlModel->record(index).value(stu_level_5).toString());
	level_6_Edit->setText(sqlModel->record(index).value(stu_level_6).toString());
	level_7_Edit->setText(sqlModel->record(index).value(stu_level_7).toString());
	level_8_Edit->setText(sqlModel->record(index).value(stu_level_8).toString());
	level_9_Edit->setText(sqlModel->record(index).value(stu_level_9).toString());
	remarkEdit->setText(sqlModel->record(index).value(stu_remark).toString());

	// 固定对话框大小，不允许调整
	this->setFixedSize(this->width(),this->height());
}

void ChangeScoreDialog::setRegExp()
{
	QRegExp idRegExp("[0-9]{2}");

	level_1_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_2_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_3_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_4_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_5_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_6_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_7_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_8_Edit->setValidator(new QRegExpValidator(idRegExp, this));
	level_9_Edit->setValidator(new QRegExpValidator(idRegExp, this));
}

void ChangeScoreDialog::setSqlTableModel(SqlTableModel *sqlModel)
{
	this->sqlModel = sqlModel;
}

ChangeScoreDialog::~ChangeScoreDialog()
{

}

