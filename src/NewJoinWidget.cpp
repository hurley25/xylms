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

	view = new QTableView();
	view->setModel(sqlModel);

	// 只允许单选
	view->setSelectionMode(QAbstractItemView::SingleSelection);

	// 每次选中一行
	view->setSelectionBehavior(QAbstractItemView::SelectRows);

	// 按照显示内容重新调整列宽度
	view->resizeColumnsToContents();
	
	// 默认不允许用户编辑数据
	view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	
	// 建立数据操作按钮
	createUserItem();

	// 组装主显示右侧的 Layout
	rightLayout = new QVBoxLayout();
	rightLayout->addWidget(stuGroupBox);
	rightLayout->addStretch();
	rightLayout->addWidget(seniorGroupBox);
	rightLayout->addStretch();
	rightLayout->addWidget(buttonGroupBox);
	
	// 组装主显示的 Layout
	mainLayout = new QHBoxLayout();
	mainLayout->addWidget(view);
	mainLayout->addLayout(rightLayout);

	this->setLayout(mainLayout);
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
	submitButton = new QPushButton(tr("提交修改"));;
	submitButton->setEnabled(false);
	connect(submitButton, SIGNAL(clicked()), this, SLOT(submitDataChange()));
	restoreButton = new QPushButton(tr("撤销修改"));;
	restoreButton->setEnabled(false);
	connect(restoreButton, SIGNAL(clicked()), sqlModel, SLOT(revertAll()));

	seniorLayout = new QVBoxLayout();
	seniorLayout->addWidget(seniorCheckBox);
	seniorLayout->addWidget(submitButton);
	seniorLayout->addWidget(restoreButton);
	
	// TODO 组装高级操作选项的 GroupBox
	seniorGroupBox = new QGroupBox(tr("高级操作 [请谨慎]"));
	seniorGroupBox->setLayout(seniorLayout);

	addButton = new QPushButton(tr("增加成员"));
	connect(addButton, SIGNAL(clicked()), this, SLOT(addInfo()));
	changeButton = new QPushButton(tr("修改选中"));
	connect(changeButton, SIGNAL(clicked()), this, SLOT(changeInfo()));
	delButton = new QPushButton(tr("删除选中"));
	connect(delButton, SIGNAL(clicked()), this, SLOT(delInfo()));
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
		view->setEditTriggers(QAbstractItemView::DoubleClicked);
		submitButton->setEnabled(true);
		restoreButton->setEnabled(true);
	} else {
		view->setEditTriggers(QAbstractItemView::NoEditTriggers);
		submitButton->setEnabled(false);
		restoreButton->setEnabled(false);
	}
}

void NewJoinWidget::commitToDatabase()
{
	// 采用事务的方式进行数据提交
	sqlModel->database().transaction();

	if (sqlModel->submitAll()) {
		sqlModel->database().commit();	// 成功则提交数据
		QMessageBox::information(this, tr("数据修改提交成功"),
                              tr("修改已经成功同步到数据库。"));
	} else {
		sqlModel->database().rollback();	// 失败则回滚修改
		QMessageBox::warning(this, tr("数据修改提交错误"),
                              tr("数据库报告了一个错误: %1，本次所有修改已回滚，点击刷新按钮重置显示。")
                              .arg(sqlModel->lastError().text()));
	}
}

void NewJoinWidget::submitDataChange()
{
	int choose = QMessageBox::question(this, tr("数据提交确认"),
                      	      tr("<H3>您确认要把当前数据表显示的数据提交到数据库吗？</H3>"
					"<p><font color=red>* 注意此操作不可逆！</font>"),
				QMessageBox::Yes | QMessageBox::No);

	if (choose == QMessageBox::Yes) {
		commitToDatabase();
	}
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

void NewJoinWidget::delInfo()
{
	int flag = view->currentIndex().column();
	
	if (flag == 0) {
		QMessageBox::information(this, tr("删除操作失败"),
                              tr("没找到您选择了哪一行哎～～</p>请您删除前先选择一行好吗？"));
		return;
	}

	int choose = QMessageBox::question(this, tr("数据删除确认"),
                      	      tr("<H3>您确认要把当前选中行删除并提交到数据库吗？</H3>"
					"<p><font color=red>* 注意此操作不可逆！</font>"),
				QMessageBox::Yes | QMessageBox::No);

	if (choose == QMessageBox::Yes) {
		sqlModel->removeRow(view->currentIndex().row());
		commitToDatabase();
	}
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

	// 按照显示内容重新调整列宽度
	view->resizeColumnsToContents();
}

