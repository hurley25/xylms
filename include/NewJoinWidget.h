// =====================================================================================
// 
//       Filename:  NewJoinWidget.h
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

#ifndef NEWJOINWIDGET_H_
#define NEWJOINWIDGET_H_

#include <QWidget>

class QTreeView;
class QHeaderView;
class SqlTableModel;
class QGroupBox;
class QComboBox;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QCheckBox;

class NewJoinWidget : public QWidget
{
	Q_OBJECT

public:
	NewJoinWidget();
	~NewJoinWidget();

public slots:
	void setSeniorButtonState(int flag);
	void commitDataChange();
	void restoreDataChange();
	void addInfo();
	void changeInfo();
	void refresh();

private:
	void createUserItem();
	void createSqlTableModel();

private:
	QTreeView *treeView;
	QHeaderView *headView;
	SqlTableModel *sqlModel; 
	
	// 浏览数据组
	QGroupBox   *stuGroupBox;
	QVBoxLayout *stuLayout;
	QComboBox   *stuComboBox;

	QPushButton *addButton;
	QPushButton *changeButton;
	QPushButton *delButton;
	QPushButton *refreshButton;
	
	// 高级选项组
	QGroupBox   *seniorGroupBox;
	QVBoxLayout *seniorLayout;
	QCheckBox   *seniorCheckBox;
	QPushButton *commitButton;
	QPushButton *restoreButton;
	
	// 数据操作组
	QGroupBox   *buttonGroupBox;
	QVBoxLayout *buttonLayout;

	QVBoxLayout *rightLayout;
	QHBoxLayout *mainLayout;
};

#endif // NEWJOINWIDGET_H_
