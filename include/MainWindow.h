// =====================================================================================
// 
//       Filename:  MainWindow.h
//
//    Description:  主窗口程序的声明头文件
//
//        Version:  1.0
//        Created:  2013年03月20日 17时48分21秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

class QLabel;
class QToolBar;
class QAction;
class StackedWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

protected:
	void closeEvent(QCloseEvent *event);

	void createMainWeiget();		// 创建主窗口控件
	void createActions();			// 创建动作
	void createToolBars();			// 创建工具栏
	void createManageToolBars(); 		// 创建管理工具栏
	void removeManageToolBars(); 		// 移除管理工具栏
	void createStatusBar();			// 创建状态栏
	
	void readSettings();			// 读取配置
	void writeSettings();			// 写入配置

private slots:
	void newJoin();
	void proving();
	void about();

private:
	StackedWidget *stackedWidget; 		// 主窗口控件

	QLabel *statusLabel;			// 状态栏文本					

	QToolBar *generalToolBar;		// 普通操作相关工具栏指针
	QToolBar *seniorToolBar;		// 高级管理相关工具栏指针
	QToolBar *infoToolBar;			// 帮助信息相关工具栏指针

	QAction *newJoinAction;			// 新人录入
	QAction *gradeAction;			// 面试打分
	QAction *provingAction;			// 管理登陆
	QAction *manageAction;			// 成员管理
	QAction *setAction;			// 系统设置

	QAction *aboutAction;			// 关于本程序
	QAction *exitAction;			// 退出本程序
};

#endif // MAINWINDOW_H_

