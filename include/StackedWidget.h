// =====================================================================================
// 
//       Filename:  StackedWidget.h
//
//    Description:  主窗口显示的分页控件的声明
//
//        Version:  1.0
//        Created:  2013年03月21日 10时52分15秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef STACKWIDGET_H_
#define STACKWIDGET_H_

#include <QStackedWidget>

class StackedWidget : public QStackedWidget
{
	Q_OBJECT

public:
	StackedWidget();
	~StackedWidget();
	
private:
	
};

#endif // STACKWIDGET_H_
