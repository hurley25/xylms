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
#include "SqlTableModel.h"

enum {
	stu_id          = 0,
	stu_name        = 1,
	stu_sex         = 2,
	stu_class       = 3,
	stu_birthday    = 4,
	stu_qq          = 5,
	stu_phone1      = 6,
	stu_phone2      = 7,
	stu_mail        = 8,
	stu_blog        = 9,
	stu_where_to_go = 10,
	stu_other_info  = 11
};

NewJoinWidget::NewJoinWidget()
{
	sqlModel = new SqlTableModel();
	sqlModel->setTable("stu_2009");
	sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	
	// 插入表头
	sqlModel->setHeaderData(stu_id, Qt::Horizontal, tr("学号"));
	sqlModel->setHeaderData(stu_name, Qt::Horizontal, tr("姓名"));
	sqlModel->setHeaderData(stu_sex, Qt::Horizontal, tr("性别"));
	sqlModel->setHeaderData(stu_class, Qt::Horizontal, tr("班级"));
	sqlModel->setHeaderData(stu_birthday, Qt::Horizontal, tr("生日"));
	sqlModel->setHeaderData(stu_qq, Qt::Horizontal, tr("QQ"));
	sqlModel->setHeaderData(stu_phone1, Qt::Horizontal, tr("手机1"));
	sqlModel->setHeaderData(stu_phone2, Qt::Horizontal, tr("手机2"));
	sqlModel->setHeaderData(stu_mail, Qt::Horizontal, tr("邮箱"));
	sqlModel->setHeaderData(stu_blog, Qt::Horizontal, tr("博客"));
	sqlModel->setHeaderData(stu_where_to_go, Qt::Horizontal, tr("去向"));
	sqlModel->setHeaderData(stu_other_info, Qt::Horizontal, tr("备注信息"));
	sqlModel->select();
	
	// 设置表头居中对齐
	headView = new QHeaderView(Qt::Horizontal);
	headView->setDefaultAlignment(Qt::AlignHCenter);
	// 设置根据内容大小自动调整大小
	headView->setResizeMode(QHeaderView::ResizeToContents);
	//headView->setResizeMode(QHeaderView::Interactive);

	treeView = new QTreeView();
	treeView->setModel(sqlModel);
	treeView->setHeader(headView);
	
	// 不允许用户编辑数据
	treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	addButton = new QPushButton(tr("增加成员"));
	changeButton = new QPushButton(tr("修改选中"));
	delButton = new QPushButton(tr("删除选中"));
	refreshButton = new QPushButton(tr("刷新数据"));
	connect(refreshButton, SIGNAL(clicked()), this, SLOT(refresh()));

	rightLayout = new QVBoxLayout();
	rightLayout->addWidget(addButton);
	rightLayout->addWidget(changeButton);
	rightLayout->addWidget(delButton);
	rightLayout->addWidget(refreshButton);

	mainLayout = new QHBoxLayout();
	mainLayout->addWidget(treeView);
	mainLayout->addLayout(rightLayout);

	this->setLayout(mainLayout);
}

void NewJoinWidget::refresh()
{
	sqlModel->select();
}

NewJoinWidget::~NewJoinWidget()
{

}
