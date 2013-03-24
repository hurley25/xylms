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
#include "ChangeInfoDialog.h"

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
	
	//TODO
	sqlModel->setTable("stu_2006");
	createSqlTableModel();
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
	
	// 默认不允许用户编辑数据
	treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	
	// 建立数据操作按钮
	createUserItem();
}

NewJoinWidget::~NewJoinWidget()
{

}

void NewJoinWidget::createUserItem()
{
	// TODO 数据表列表	
	stuComboBox = new QComboBox();
	stuComboBox->addItem("2006级信息");
	stuComboBox->addItem("2007级信息");
	stuComboBox->addItem("2008级信息");
	stuComboBox->addItem("2009级信息");
	stuComboBox->addItem("2010级信息");
	stuComboBox->addItem("2011级信息");
	stuComboBox->addItem("2012级信息");
	stuComboBox->setCurrentIndex(0);
	connect(stuComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh()));
	
	stuLayout = new QVBoxLayout();
	stuLayout->addWidget(stuComboBox);
	
	// 组装数据浏览 GroupBox
	stuGroupBox = new QGroupBox(tr("当前显示"));
	stuGroupBox->setLayout(stuLayout);
	
	seniorCheckBox = new QCheckBox(tr("启用自由编辑"));
	connect(seniorCheckBox, SIGNAL(stateChanged(int)), this, SLOT(setSeniorButtonState(int)));
	commitButton = new QPushButton(tr("提交修改"));;
	commitButton->setEnabled(false);	
	connect(commitButton, SIGNAL(clicked()), this, SLOT(commitDataChange()));
	restoreButton = new QPushButton(tr("修改还原"));;
	restoreButton->setEnabled(false);
	connect(restoreButton, SIGNAL(clicked()), this, SLOT(restoreDataChange()));

	seniorLayout = new QVBoxLayout();
	seniorLayout->addWidget(seniorCheckBox);
	seniorLayout->addWidget(commitButton);
	seniorLayout->addWidget(restoreButton);
	
	// TODO 组装高级操作选项的 GroupBox
	seniorGroupBox = new QGroupBox(tr("高级操作"));
	seniorGroupBox->setLayout(seniorLayout);

	addButton = new QPushButton(tr("增加成员"));
	connect(addButton, SIGNAL(clicked()), this, SLOT(addInfo()));
	changeButton = new QPushButton(tr("修改选中"));
	changeButton->setEnabled(false);
	connect(changeButton, SIGNAL(clicked()), this, SLOT(changeInfo()));
	delButton = new QPushButton(tr("删除选中"));
	delButton->setEnabled(false);
	refreshButton = new QPushButton(tr("刷新数据"));
	connect(refreshButton, SIGNAL(clicked()), this, SLOT(refresh()));

	buttonLayout = new QVBoxLayout();
	buttonLayout->addWidget(addButton);
	buttonLayout->addStretch();
	buttonLayout->addWidget(changeButton);
	buttonLayout->addStretch();
	buttonLayout->addWidget(delButton);
	buttonLayout->addStretch();
	buttonLayout->addWidget(refreshButton);
	
	// 组装数据操作 GroupBox
	buttonGroupBox = new QGroupBox(tr("数据操作"));
	buttonGroupBox->setLayout(buttonLayout);
	
	// 组装主显示右侧的 Layout
	rightLayout = new QVBoxLayout();
	rightLayout->addWidget(stuGroupBox);
	rightLayout->addStretch();
	rightLayout->addWidget(seniorGroupBox);
	rightLayout->addStretch();
	rightLayout->addWidget(buttonGroupBox);
	
	// 组装主显示的 Layout
	mainLayout = new QHBoxLayout();
	mainLayout->addWidget(treeView);
	mainLayout->addLayout(rightLayout);

	this->setLayout(mainLayout);
}

void NewJoinWidget::createSqlTableModel()
{
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
}

void NewJoinWidget::setSeniorButtonState(int flag)
{
	if (flag == Qt::Checked) {
		treeView->setEditTriggers(QAbstractItemView::DoubleClicked);
		commitButton->setEnabled(true);
		restoreButton->setEnabled(true);
	} else {
		treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		commitButton->setEnabled(false);
		restoreButton->setEnabled(false);
	}
}

void NewJoinWidget::commitDataChange()
{

}

void NewJoinWidget::restoreDataChange()
{

}

void NewJoinWidget::addInfo()
{
	ChangeInfoDialog changeInfoDialog;
	
	changeInfoDialog.exec();
}

void NewJoinWidget::changeInfo()
{
	ChangeInfoDialog changeInfoDialog;
	
	changeInfoDialog.exec();
}

void NewJoinWidget::refresh()
{
	QString strTableName("stu_");
	QString strCombo = stuComboBox->currentText();
	
	// 这个语句在公元9999年以后可能会出 bug ... 
	strTableName.append(strCombo.mid(0, 4));

	//QTextStream cout(stdout, QIODevice::WriteOnly);
	//cout << strTableName << endl;;
	
	sqlModel->setTable(strTableName);
	createSqlTableModel();
	sqlModel->select();
}

