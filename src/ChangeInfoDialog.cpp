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
#include <QtSql>

#include "ChangeInfoDialog.h"
#include "SqlTableModel.h"
#include "xylms.h"

ChangeInfoDialog::ChangeInfoDialog(QWidget *parent) : QDialog(parent)
{
	setupUi(this);

	// 设置输入过滤器
	setRegExp();
	
	// 固定对话框大小，不允许调整
	this->setFixedSize(this->width(),this->height());
}

ChangeInfoDialog::ChangeInfoDialog(SqlTableModel *sqlModel, int index, QWidget *parent) : QDialog(parent)
{
	setupUi(this);

	this->sqlModel = sqlModel;
	
	// 设置输入过滤器
	setRegExp();
	
	idEdit->setText(sqlModel->record(index).value(stu_id).toString());
	nameEdit->setText(sqlModel->record(index).value(stu_name).toString());
	sexComboBox->setCurrentIndex(((sqlModel->record(index).value(stu_sex).toString()) == "男") ? 0 : 1);
	classEdit->setText(sqlModel->record(index).value(stu_class).toString());
	birthdayEdit->setText(sqlModel->record(index).value(stu_birthday).toString());
	qqEdit->setText(sqlModel->record(index).value(stu_qq).toString());
	phone1Edit->setText(sqlModel->record(index).value(stu_phone1).toString());
	phone2Edit->setText(sqlModel->record(index).value(stu_phone2).toString());
	mailEdit->setText(sqlModel->record(index).value(stu_mail).toString());
	blogEdit->setText(sqlModel->record(index).value(stu_blog).toString());
	wheretogoEdit->setText(sqlModel->record(index).value(stu_where_to_go).toString());
	otherinfoEdit->setText(sqlModel->record(index).value(stu_other_info).toString());
	
	// 固定对话框大小，不允许调整
	this->setFixedSize(this->width(),this->height());
}

void ChangeInfoDialog::setRegExp()
{
	QRegExp idRegExp("[0-9]{8}");
	idEdit->setValidator(new QRegExpValidator(idRegExp, this));
	
	QRegExp birthdayRegExp("[0-9]{4,8}");
	birthdayEdit->setValidator(new QRegExpValidator(birthdayRegExp, this));
	
	QRegExp qqRegExp("[0-9]{0,12}");
	qqEdit->setValidator(new QRegExpValidator(qqRegExp, this));
	
	QRegExp phoneRegExp("[0-9]{0,8}");
	phone1Edit->setValidator(new QRegExpValidator(phoneRegExp, this));
	phone2Edit->setValidator(new QRegExpValidator(phoneRegExp, this));
}

void ChangeInfoDialog::setSqlTableModel(SqlTableModel *sqlModel)
{
	this->sqlModel = sqlModel;
}

ChangeInfoDialog::~ChangeInfoDialog()
{

}
