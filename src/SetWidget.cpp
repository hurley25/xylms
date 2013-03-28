// =====================================================================================
// 
//       Filename:  SetWidget.cpp
//
//    Description:  系统设置选项卡控件
//
//        Version:  1.0
//        Created:  2013年03月21日 16时10分51秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#include <QtGui>
#include <QtSql>

#include "SetWidget.h"
#include "xylms.h"

SetWidget::SetWidget()
{
	setupUi(this);
	
	// TODO
	yearComboBox->addItem("2006级");
	yearComboBox->addItem("2007级");
	yearComboBox->addItem("2008级");
	yearComboBox->addItem("2009级");
	yearComboBox->addItem("2010级");
	yearComboBox->addItem("2011级");
	yearComboBox->addItem("2012级");

	deleteComboBox->addItem("2006级");
	deleteComboBox->addItem("2007级");
	deleteComboBox->addItem("2008级");
	deleteComboBox->addItem("2009级");
	deleteComboBox->addItem("2010级");
	deleteComboBox->addItem("2011级");
	deleteComboBox->addItem("2012级");
	
	yearComboBox->setCurrentIndex(settingInfo.userViewYears.toInt() - 2006);
	permissionComboBox->setCurrentIndex(settingInfo.userPower);
	welcomeEdit->setText(settingInfo.rootWelcomeInfo);
	
	oldPassEdit->setEchoMode(QLineEdit::Password);
	newPassEdit->setEchoMode(QLineEdit::Password);
	reNewPassEdit->setEchoMode(QLineEdit::Password);

	connect(yearComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeUserViewYear()));
	connect(permissionComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeUserPermission(int)));

	connect(exportButton, SIGNAL(clicked()), this, SLOT(exportToExcel()));
	connect(deleteScoreButton, SIGNAL(clicked()), this, SLOT(deleteScore()));
	connect(changeWelcomeButton, SIGNAL(clicked()), this, SLOT(ChangeWelcomeInfo()));
	connect(changePassButton, SIGNAL(clicked()), this, SLOT(changePass()));
}

void SetWidget::changeUserViewYear()
{
	QString strTmp = yearComboBox->currentText();	
	QString strSql = QString("update root set now_year = '%1'").arg(strTmp.mid(0, 4));

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	} else {
		QMessageBox::information(this, tr("提交成功"), tr("您的修改成功提交到数据库。"));
		settingInfo.userViewYears = strTmp.mid(0, 4);
	}
}

void SetWidget::changeUserPermission(int index)
{
	QString strSql = QString("update root set is_open = %1").arg(index);

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	} else {
		QMessageBox::information(this, tr("提交成功"), tr("您的修改成功提交到数据库。"));
		settingInfo.userPower = index;
	}
}
void SetWidget::exportToExcel()
{
	
}

void SetWidget::deleteScore()
{
	int choose = QMessageBox::question(this, tr("成绩信息删除确认"),
                      	      tr("<H3>您确认要把选中年级的成绩信息全部删除吗？</H3>"
					"<p><font color=red>* 注意此操作不可逆！</font>"),
				QMessageBox::Yes | QMessageBox::No);

	if (choose == QMessageBox::No) {
		return;
	}

	QString passwdInput = QInputDialog::getText(this, tr("管理员登陆"), 
					tr("危险操作，请输入管理员密码："), QLineEdit::Password, NULL, NULL);
	
	if (passwdInput != settingInfo.rootPasswd) {
		QMessageBox::warning(this, tr("密码错误"), tr("管理员密码输入错误，不予执行！"));
		return;
	}

	QString strCombo = deleteComboBox->currentText();	

	QString strSql = QString("update stu_%1 set level_1 = 0, level_2 = 0, level_3 = 0,"
			"level_4 = 0, level_5 = 0, level_6 = 0,level_7 = 0, level_8 = 0, level_9 = 0, "
			"score = 0, curr_level = 0").arg(strCombo.mid(0, 4));

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	} else {
		QMessageBox::information(this, tr("提交成功"), tr("您的命令成功提交到数据库。"));
	}
}

void SetWidget::ChangeWelcomeInfo()
{
	QString tmpInfo = welcomeEdit->text();	

	QString strSql = QString("update root set welcome_info = '%1'").arg(tmpInfo);

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	} else {
		QMessageBox::information(this, tr("提交成功"), tr("您的欢迎信息修改修改成功提交到数据库。"));
		settingInfo.rootWelcomeInfo = tmpInfo;
	}
}

void SetWidget::changePass()
{
	QString oldPass   = oldPassEdit->text();
	QString newPass   = newPassEdit->text();
	QString reNewPass = reNewPassEdit->text();

	if (settingInfo.rootPasswd != oldPass) {
		QMessageBox::warning(this, tr("输入错误"), tr("您的原始密码输入错误"));
		return;
	}

	if (newPass != reNewPass) {
		QMessageBox::warning(this, tr("输入错误"), tr("您两次输入密码不一致"));
		return;	
	}

	QString strSql = QString("update root set passwd = '%1'").arg(newPass);

	QSqlQuery query(strSql);

	if (!query.isActive()) {
		QMessageBox::warning(this, tr("数据库错误"), query.lastError().text());
	} else {
		QMessageBox::information(this, tr("提交成功"), tr("您的密码修改成功提交到数据库。"));
		settingInfo.rootPasswd = newPass;
	}
}

