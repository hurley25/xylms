// =====================================================================================
// 
//       Filename:  ChangeScoreDialog.h
//
//    Description:  成绩修改对话框的声明
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

#ifndef CHANGESCOREDIALOG_H_
#define CHANGESCOREDIALOG_H_

#include <QDialog>

class SqlTableModel;

#include "ui_ChangeScoreDialog.h"

class ChangeScoreDialog : public QDialog, public Ui::ChangeScoreDialog
{
public:
	ChangeScoreDialog(QWidget *parent = 0);
	ChangeScoreDialog(SqlTableModel *sqlModel, int index, QWidget *parent = 0);
	~ChangeScoreDialog();

	void setRegExp();
	void setSqlTableModel(SqlTableModel *sqlModel);

private:
	SqlTableModel *sqlModel;
};

#endif

