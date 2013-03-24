// =====================================================================================
// 
//       Filename:  ChangeInfoDialog.h
//
//    Description:  修改成员信息对话框的声明
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

#ifndef CHANGEINFODIALOG_H_
#define CHANGEINFODIALOG_H_

#include <QDialog>

#include "ui_ChangeInfoDialog.h"

class SqlTableModel;

class ChangeInfoDialog : public QDialog, public Ui::ChangeInfoDialog
{
	Q_OBJECT

public:
	ChangeInfoDialog(QWidget *parent = 0);
	ChangeInfoDialog(SqlTableModel *sqlModel, int index, QWidget *parent = 0);
	~ChangeInfoDialog();

	void setSqlTableModel(SqlTableModel *sqlModel);
	void setRegExp();

private:
	SqlTableModel *sqlModel;
};

#endif // CHANGEINFODIALOG_H_
