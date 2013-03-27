// =====================================================================================
// 
//       Filename:  GradeWidget.cpp
//
//    Description:  面试打分选项卡控件
//
//        Version:  1.0
//        Created:  2013年03月21日 16时07分09秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>
#include <QtSql>

#include "GradeWidget.h"

GradeWidget::GradeWidget()
{	
	setupUi(this);
	
	createAction();

	toolBar = new QToolBar();
	toolBar->setIconSize(QSize(70, 70));
	toolBar->setMovable(false);
	toolBar->addSeparator();
	toolBar->addAction(aPlusAction);
	toolBar->addSeparator();
	toolBar->addAction(aAction);
	toolBar->addSeparator();
	toolBar->addAction(aMinusAction);
	toolBar->addSeparator();
	toolBar->addSeparator();
	toolBar->addAction(bPlusAction);
	toolBar->addSeparator();
	toolBar->addAction(bAction);
	toolBar->addSeparator();
	toolBar->addAction(bMinusAction);
	toolBar->addSeparator();
	toolBar->addSeparator();
	toolBar->addAction(cPlusAction);
	toolBar->addSeparator();
	toolBar->addAction(cAction);
	toolBar->addSeparator();
	toolBar->addAction(cMinusAction);
	toolBar->addSeparator();
	toolBar->addSeparator();
	toolBar->addAction(dAction);
	toolBar->addSeparator();

	toolLayout->addWidget(toolBar);

	reset();

	QRegExp idRegExp("[0-9]{8}");
	idEdit->setValidator(new QRegExpValidator(idRegExp, this));

	findButton->setEnabled(false);

	connect(idEdit, SIGNAL(textChanged(QString)), this, SLOT(setButtonEnable(QString)));
	connect(findButton, SIGNAL(clicked()), this, SLOT(findUser()));
	connect(resetButton, SIGNAL(clicked()), this, SLOT(reset()));

	levelVector.append(level_1);
	levelVector.append(level_2);
	levelVector.append(level_3);
	levelVector.append(level_4);
	levelVector.append(level_5);
	levelVector.append(level_6);
	levelVector.append(level_7);
	levelVector.append(level_8);
	levelVector.append(level_9);
}

GradeWidget::~GradeWidget()
{

}

void GradeWidget::createAction()
{
	aPlusAction = new QAction(tr("A+"), this);
	aPlusAction->setIcon(QIcon(":/res/images/aPlus.png"));
	connect(aPlusAction, SIGNAL(triggered()), this, SLOT(setAPlus()));
	
	aAction = new QAction(tr("A"), this);
	aAction->setIcon(QIcon(":/res/images/a.png"));
	connect(aAction, SIGNAL(triggered()), this, SLOT(setA()));
	
	aMinusAction = new QAction(tr("A-"), this);
	aMinusAction->setIcon(QIcon(":/res/images/aMinus.png"));
	connect(aMinusAction, SIGNAL(triggered()), this, SLOT(setAMinus()));

	bPlusAction = new QAction(tr("B+"), this);
	bPlusAction->setIcon(QIcon(":/res/images/bPlus.png"));
	connect(bPlusAction, SIGNAL(triggered()), this, SLOT(setBPlus()));
	
	bAction = new QAction(tr("B"), this);
	bAction->setIcon(QIcon(":/res/images/b.png"));
	connect(bAction, SIGNAL(triggered()), this, SLOT(setB()));

	bMinusAction = new QAction(tr("B-"), this);
	bMinusAction->setIcon(QIcon(":/res/images/bMinus.png"));
	connect(bMinusAction, SIGNAL(triggered()), this, SLOT(setBMinus()));
	
	cPlusAction = new QAction(tr("C+"), this);
	cPlusAction->setIcon(QIcon(":/res/images/cPlus.png"));
	connect(cPlusAction, SIGNAL(triggered()), this, SLOT(setCPlus()));
	
	cAction = new QAction(tr("C"), this);
	cAction->setIcon(QIcon(":/res/images/c.png"));
	connect(cAction, SIGNAL(triggered()), this, SLOT(setC()));
	
	cMinusAction = new QAction(tr("C-"), this);
	cMinusAction->setIcon(QIcon(":/res/images/cMinus.png"));
	connect(cMinusAction, SIGNAL(triggered()), this, SLOT(setCMinus()));
	
	dAction = new QAction(tr("D"), this);
	dAction->setIcon(QIcon(":/res/images/d.png"));
	connect(dAction, SIGNAL(triggered()), this, SLOT(setD()));
}

void GradeWidget::findUser()
{
	// TODO 按照管理员设置填充此处字符串
	QString strSql = QString("select name, sex, class, curr_level from stu_%1 where id='%2'").arg("2012").arg(idEdit->text());

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	}

	if (!query.next()) {
		QMessageBox::warning(this, tr("没有找到相关信息"), tr("数据库无此人记录，请检查您的输入学号。"));	
	} else {
		nameEdit->setText(query.value(0).toString());
		sexEdit->setText(query.value(1).toString());
		classEdit->setText(query.value(2).toString());
	
		nowUserLevel = query.value(3).toInt();
		setLevelPixMap(nowUserLevel);
		nowUserID = idEdit->text();
		
		if (nowUserLevel >= 9) {
			toolBar->setEnabled(false);
		}else {
			toolBar->setEnabled(true);
		}
	}
}

void GradeWidget::setLevelPixMap(int nowLevel)
{	
	// 考虑到移植性，没有在 for 循环内定义 i，
	// 因为C++标准没有对此种情况下 i 变量的作用域是否可以扩展到循环外做出明确的规定

	int i;
	for (i = 0; i < nowLevel && i < levelVector.count(); i++) {
		levelVector[i]->setPixmap(QPixmap(":/res/images/Pass.png"));
	}

	for (; i < levelVector.count(); i++) {
		levelVector[i]->setPixmap(QPixmap(":/res/images/noPass.png"));
	}

	// 其实这里用 QVector 放置指针，然后使用循环实现了
	// 但是感觉这个思路有意思，所以注释掉留下来
	/*	
	switch (nowLevel) {
		case 9: level_9->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 8: level_8->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 7: level_7->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 6: level_6->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 5: level_5->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 4: level_4->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 3: level_3->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 2: level_2->setPixmap(QPixmap(":/res/images/Pass.png"));
		case 1: level_1->setPixmap(QPixmap(":/res/images/Pass.png"));
	}
	*/	
}

void GradeWidget::reset()
{
	idEdit->clear();	
	nameEdit->clear();
	sexEdit->clear();
	classEdit->clear();
	toolBar->setEnabled(false);
	setLevelPixMap(0);
}

void GradeWidget::setButtonEnable(QString str)
{
	findButton->setEnabled(!(str.length() == 0));
}

void GradeWidget::commitGrade(int grade)
{
	int choose = QMessageBox::question(this, tr("数据提交确认"),
                      	      tr("<H3>您确认要把成绩提交到数据库吗？</H3>"
					"<p><font color=red>* 注意此操作普通用户不可逆。</font>"),
				QMessageBox::Yes | QMessageBox::No);

	if (choose == QMessageBox::No) {
		return;
	}
	
	// 增加当前进度，在新的分数槽处打分 TODO
	nowUserLevel++;
	QString strSql = QString("update stu_%1 set level_%2 = %3, curr_level = %2"
		" where id='%4'").arg("2012").arg(nowUserLevel).arg(grade).arg(nowUserID);

	//QTextStream cout(stdout, QIODevice::WriteOnly);
	//cout << strSql << endl;

	QSqlQuery query(strSql);
	
	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	} else {
		QMessageBox::information(this, tr("提交成功"), tr("成绩提交数据库成功！<p>若有修改需求，请求助管理员。"));
		reset();
	}
}

void GradeWidget::setAPlus()
{
	commitGrade(95);
}

void GradeWidget::setA()
{
	commitGrade(90);
}

void GradeWidget::setAMinus()
{
	commitGrade(85);
}

void GradeWidget::setBPlus()
{
	commitGrade(80);
}

void GradeWidget::setB()
{
	commitGrade(75);
}

void GradeWidget::setBMinus()
{
	commitGrade(70);
}

void GradeWidget::setCPlus()
{
	commitGrade(65);
}

void GradeWidget::setC()
{
	commitGrade(60);
}

void GradeWidget::setCMinus()
{
	commitGrade(55);
}

void GradeWidget::setD()
{
	commitGrade(50);
}
