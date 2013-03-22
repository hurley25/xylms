// =====================================================================================
// 
//       Filename:  SqlTableModel.cpp
//
//    Description:  成员数据显示模式定义
//
//        Version:  1.0
//        Created:  2013年03月22日 18时09分19秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include "SqlTableModel.h"

SqlTableModel::SqlTableModel()
{

}

SqlTableModel::~SqlTableModel()
{

}

// 重载 data 成员函数，实现数据显示居中对齐
QVariant SqlTableModel::data(const QModelIndex &item, int role) const 
{
	QVariant value = QSqlTableModel::data(item, role);
	
	if (role == Qt::TextAlignmentRole)
	{
		value = int(Qt::AlignHCenter | Qt::AlignVCenter);
		return value;
	}
	
	return value;
}

