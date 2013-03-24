/********************************************************************************
** Form generated from reading UI file 'ChangeInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEINFODIALOG_H
#define UI_CHANGEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChangeInfoDialog
{
public:
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QComboBox *sexComboBox;
    QLabel *label_4;
    QLineEdit *classEdit;
    QLabel *label_5;
    QDateEdit *birthdayEdit;
    QLabel *label_6;
    QLineEdit *qqEdit;
    QLabel *label_7;
    QLineEdit *phone1Edit;
    QLabel *label_8;
    QLineEdit *phone2Edit;
    QLabel *label_9;
    QLineEdit *mailEdit;
    QLabel *label_10;
    QLineEdit *blogEdit;
    QLabel *label_11;
    QLineEdit *wheretogoEdit;
    QLabel *label_12;
    QTextEdit *otherinfoEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChangeInfoDialog)
    {
        if (ChangeInfoDialog->objectName().isEmpty())
            ChangeInfoDialog->setObjectName(QString::fromUtf8("ChangeInfoDialog"));
        ChangeInfoDialog->resize(620, 422);
        formLayout = new QFormLayout(ChangeInfoDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ChangeInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        idEdit = new QLineEdit(ChangeInfoDialog);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        gridLayout->addWidget(idEdit, 0, 1, 1, 1);

        label_2 = new QLabel(ChangeInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        nameEdit = new QLineEdit(ChangeInfoDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 3, 1, 1);

        label_3 = new QLabel(ChangeInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        sexComboBox = new QComboBox(ChangeInfoDialog);
        sexComboBox->setObjectName(QString::fromUtf8("sexComboBox"));

        gridLayout->addWidget(sexComboBox, 0, 5, 1, 1);

        label_4 = new QLabel(ChangeInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        classEdit = new QLineEdit(ChangeInfoDialog);
        classEdit->setObjectName(QString::fromUtf8("classEdit"));

        gridLayout->addWidget(classEdit, 1, 1, 1, 1);

        label_5 = new QLabel(ChangeInfoDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        birthdayEdit = new QDateEdit(ChangeInfoDialog);
        birthdayEdit->setObjectName(QString::fromUtf8("birthdayEdit"));

        gridLayout->addWidget(birthdayEdit, 1, 3, 1, 1);

        label_6 = new QLabel(ChangeInfoDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 4, 1, 1);

        qqEdit = new QLineEdit(ChangeInfoDialog);
        qqEdit->setObjectName(QString::fromUtf8("qqEdit"));

        gridLayout->addWidget(qqEdit, 1, 5, 1, 1);

        label_7 = new QLabel(ChangeInfoDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        phone1Edit = new QLineEdit(ChangeInfoDialog);
        phone1Edit->setObjectName(QString::fromUtf8("phone1Edit"));

        gridLayout->addWidget(phone1Edit, 2, 1, 1, 1);

        label_8 = new QLabel(ChangeInfoDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        phone2Edit = new QLineEdit(ChangeInfoDialog);
        phone2Edit->setObjectName(QString::fromUtf8("phone2Edit"));

        gridLayout->addWidget(phone2Edit, 2, 3, 1, 1);

        label_9 = new QLabel(ChangeInfoDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        mailEdit = new QLineEdit(ChangeInfoDialog);
        mailEdit->setObjectName(QString::fromUtf8("mailEdit"));

        gridLayout->addWidget(mailEdit, 3, 1, 1, 1);

        label_10 = new QLabel(ChangeInfoDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 3, 2, 1, 1);

        blogEdit = new QLineEdit(ChangeInfoDialog);
        blogEdit->setObjectName(QString::fromUtf8("blogEdit"));

        gridLayout->addWidget(blogEdit, 3, 3, 1, 1);

        label_11 = new QLabel(ChangeInfoDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 4, 1, 1);

        wheretogoEdit = new QLineEdit(ChangeInfoDialog);
        wheretogoEdit->setObjectName(QString::fromUtf8("wheretogoEdit"));

        gridLayout->addWidget(wheretogoEdit, 3, 5, 1, 1);

        label_12 = new QLabel(ChangeInfoDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 4, 0, 1, 2);

        otherinfoEdit = new QTextEdit(ChangeInfoDialog);
        otherinfoEdit->setObjectName(QString::fromUtf8("otherinfoEdit"));

        gridLayout->addWidget(otherinfoEdit, 5, 0, 1, 6);

        buttonBox = new QDialogButtonBox(ChangeInfoDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 4, 1, 2);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);


        retranslateUi(ChangeInfoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeInfoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ChangeInfoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangeInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeInfoDialog)
    {
        ChangeInfoDialog->setWindowTitle(QApplication::translate("ChangeInfoDialog", "\346\210\220\345\221\230\344\277\241\346\201\257\347\274\226\350\276\221", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChangeInfoDialog", "I D", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChangeInfoDialog", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChangeInfoDialog", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        sexComboBox->clear();
        sexComboBox->insertItems(0, QStringList()
         << QApplication::translate("ChangeInfoDialog", "\347\224\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ChangeInfoDialog", "\345\245\263", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("ChangeInfoDialog", "\347\217\255\347\272\247", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ChangeInfoDialog", "\347\224\237\346\227\245", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ChangeInfoDialog", "QQ", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ChangeInfoDialog", "\346\211\213\346\234\2721", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ChangeInfoDialog", "\346\211\213\346\234\2722", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ChangeInfoDialog", "\351\202\256\347\256\261", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ChangeInfoDialog", "\345\215\232\345\256\242", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ChangeInfoDialog", "\345\216\273\345\220\221", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ChangeInfoDialog", "\345\244\207\346\263\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChangeInfoDialog: public Ui_ChangeInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEINFODIALOG_H
