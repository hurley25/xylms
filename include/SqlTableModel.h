// =====================================================================================
// 
//       Filename:  SqlTableModel.h
//
//    Description:  成员数据显示模式声明
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

#ifndef SQLTABLEMODEL_H_
#define SQLTABLEMODEL_H_

#include <QSqlTableModel>

class SqlTableModel : public QSqlTableModel
{
	Q_OBJECT
public:
	SqlTableModel();
	~SqlTableModel();

protected:
	QVariant data( const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif // SQLTABLEMODEL_H_
