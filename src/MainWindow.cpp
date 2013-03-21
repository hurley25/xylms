// =====================================================================================
// 
//       Filename:  MainWindow.cpp
//
//    Description:  主窗口程序的实现文件
//
//        Version:  1.0
//        Created:  2013年03月20日 17时53分22秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>

#include "MainWindow.h"
#include "StackedWidget.h"

MainWindow::MainWindow()
{
	createMainWeiget();
	createActions();
	createToolBars();
	createStatusBar();
	readSettings();
}

MainWindow::~MainWindow()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	int res = QMessageBox::question(NULL, this->windowTitle(),
						tr("您真的要退出本程序吗？"),
						QMessageBox::Yes | QMessageBox::No);
	if (res == QMessageBox::Yes) {
		writeSettings();
		event->accept();
	} else{
		event->ignore();
	}
}

void MainWindow::proving()
{
	static bool isRoot = false;
	static int inputCount;
	QString passwdRoot("123456");
	
	if (isRoot == false) {

		// TODO 从数据库验证密码
		bool isInput;
		QString passwdInput = QInputDialog::getText(this, tr("管理员登陆"), 
					tr("请输入管理员密码："), QLineEdit::Password, NULL, &isInput);
		if (isInput) {
			if (passwdInput == passwdRoot) {
				isRoot = true;
				createManageToolBars();
			} else {
				if (++inputCount >= 3) {
					QMessageBox::warning(this, tr("警告"),
							tr("请不要多次尝试管理员密码，这会让组长同志很不开心。"));
				} else {
					QMessageBox::question(this, tr("密码错误"), 
							tr("您输入的密码有误，忘记了吗？"));
				}
			}
		} 
	} else {
		isRoot = false;
		removeManageToolBars();
	}
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("关于"),
			tr("<h2>Xiyou Linux Group 成员管理系统</h2>"
			"<p>Copyright (C) 2013 Xiyou Linux Group 版权所有，保留一切权利。"));
}

void MainWindow::createMainWeiget()
{
	stackedWidget = new StackedWidget();
	
	resize(1000, 650);
	setCentralWidget(stackedWidget);
	setWindowIcon(QIcon(":/res/images/logo.png"));
	setWindowTitle(tr("Xiyou Linux Group 成员管理系统"));
}

void MainWindow::createActions()
{
	newJoinAction = new QAction(tr("新人录入"), this);
	newJoinAction->setIcon(QIcon(":/res/images/newJoin.png"));
	newJoinAction->setStatusTip(tr("新成员的录入"));
	connect(newJoinAction, SIGNAL(triggered()), stackedWidget, SLOT(setCurrentRow(0)));

	gradeAction = new QAction(tr("面试打分"), this);
	gradeAction->setIcon(QIcon(":/res/images/grade.png"));
	gradeAction->setStatusTip(tr("面试打分"));
	//connect(gradeAction, SIGNAL(triggered()), this, SLOT(grade()));
	
	provingAction = new QAction(tr("管理登陆"), this);
	provingAction->setIcon(QIcon(":/res/images/proving_in.png"));
	provingAction->setStatusTip(tr("超级管理员登陆"));
	connect(provingAction, SIGNAL(triggered()), this, SLOT(proving()));
	
	manageAction = new QAction(tr("成员管理"), this);
	manageAction->setIcon(QIcon(":/res/images/manage.png"));
	manageAction->setStatusTip(tr("成员数据的管理"));
	//connect(manageAction, SIGNAL(triggered()), this, SLOT(manage()));
	
	setAction = new QAction(tr("系统设置"), this);
	setAction->setIcon(QIcon(":/res/images/set.png"));
	setAction->setStatusTip(tr("系统设置"));
	//connect(setAction, SIGNAL(triggered()), this, SLOT(set()));

	aboutAction = new QAction(tr("关于程序"), this);
	aboutAction->setIcon(QIcon(":/res/images/about.png"));
	aboutAction->setStatusTip(tr("关于程序"));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
	
	exitAction = new QAction(tr("退出程序"), this);
	exitAction->setIcon(QIcon(":/res/images/exit.png"));
	exitAction->setStatusTip(tr("退出程序"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createToolBars()
{
	generalToolBar = addToolBar(tr("常规工具"));
	generalToolBar->setIconSize(QSize(60, 70));
	generalToolBar->addAction(newJoinAction);
	generalToolBar->addAction(gradeAction);

	seniorToolBar = addToolBar(tr("高级工具"));
	seniorToolBar->setIconSize(QSize(60, 70));
	seniorToolBar->addAction(provingAction);

	infoToolBar = addToolBar(tr("关于信息"));
	infoToolBar->setIconSize(QSize(60, 70));
	infoToolBar->addAction(aboutAction);
	infoToolBar->addAction(exitAction);
}

void MainWindow::createManageToolBars()
{
	provingAction->setIcon(QIcon(":/res/images/proving_out.png"));
	provingAction->setStatusTip(tr("超级管理员登出"));
	
	seniorToolBar->addAction(manageAction);
	seniorToolBar->addAction(setAction);
}

void MainWindow::removeManageToolBars()
{
	provingAction->setIcon(QIcon(":/res/images/proving_in.png"));
	provingAction->setStatusTip(tr("超级管理员登陆"));
	
	seniorToolBar->removeAction(manageAction);
	seniorToolBar->removeAction(setAction);
}

void MainWindow::createStatusBar()
{
	statusLabel = new QLabel(this->windowTitle());
	statusLabel->setAlignment(Qt::AlignHCenter);
	statusLabel->setMinimumSize(statusLabel->sizeHint());

	this->statusBar()->addWidget(statusLabel);
}
	
void MainWindow::readSettings()
{

}

void MainWindow::writeSettings()
{

}


