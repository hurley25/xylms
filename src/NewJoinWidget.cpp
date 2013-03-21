// =====================================================================================
// 
//       Filename:  NewJoinWidget.cpp
//
//    Description:  新人录入选项卡控件
//
//        Version:  1.0
//        Created:  2013年03月21日 16时03分54秒
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

enum {
	stu_id          = 0,
	stu_name        = 1,
	stu_sex         = 2,
	stu_class       = 3,
	stu_birthday    = 4,
	stu_qq          = 5,
	stu_phone       = 6,
	stu_where_to_go = 7,
	stu_other_info  = 8
};

NewJoinWidget::NewJoinWidget()
{
	sqlModel = new QSqlTableModel(this);
	sqlModel->setTable("stu_2011");
	sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	sqlModel->setHeaderData(stu_id, Qt::Horizontal, tr("学号"));
	sqlModel->setHeaderData(stu_name, Qt::Horizontal, tr("姓名"));
	sqlModel->setHeaderData(stu_sex, Qt::Horizontal, tr("性别"));
	sqlModel->setHeaderData(stu_class, Qt::Horizontal, tr("班级"));
	sqlModel->setHeaderData(stu_birthday, Qt::Horizontal, tr("生日"));
	sqlModel->setHeaderData(stu_qq, Qt::Horizontal, tr("QQ"));
	sqlModel->setHeaderData(stu_phone, Qt::Horizontal, tr("电话"));
	sqlModel->setHeaderData(stu_where_to_go, Qt::Horizontal, tr("去向"));
	sqlModel->select();
	
	tableView = new QTableView();
	tableView->setModel(sqlModel);
	tableView->resizeColumnsToContents();
	tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	addButton = new QPushButton(tr("增加成员"));
	changeButton = new QPushButton(tr("修改选中"));
	delButton = new QPushButton(tr("删除选中"));
	refreshButton = new QPushButton(tr("刷新数据"));

	rightLayout = new QVBoxLayout();
	rightLayout->addStretch();
	rightLayout->addWidget(addButton);
	rightLayout->addStretch();
	rightLayout->addWidget(changeButton);
	rightLayout->addStretch();
	rightLayout->addWidget(delButton);
	rightLayout->addStretch();
	rightLayout->addWidget(refreshButton);
	rightLayout->addStretch();

	mainLayout = new QHBoxLayout();
	mainLayout->addWidget(tableView);
	mainLayout->addLayout(rightLayout);

	this->setLayout(mainLayout);
}


NewJoinWidget::~NewJoinWidget()
{

}
