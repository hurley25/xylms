/********************************************************************************
** Form generated from reading UI file 'GradeWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADEWIDGET_H
#define UI_GRADEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradeWidget
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *findButton;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QFrame *line_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *progressBar;
    QFrame *line_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QFrame *line_3;

    void setupUi(QWidget *GradeWidget)
    {
        if (GradeWidget->objectName().isEmpty())
            GradeWidget->setObjectName(QString::fromUtf8("GradeWidget"));
        GradeWidget->resize(589, 438);
        formLayout = new QFormLayout(GradeWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(GradeWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        idEdit = new QLineEdit(groupBox);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        horizontalLayout->addWidget(idEdit);

        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        findButton = new QPushButton(groupBox);
        findButton->setObjectName(QString::fromUtf8("findButton"));

        horizontalLayout->addWidget(findButton);

        horizontalSpacer_4 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMaximumSize(QSize(30, 16777215));
        lineEdit_2->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_2);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(groupBox);

        line_4 = new QFrame(GradeWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        groupBox_2 = new QGroupBox(GradeWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);


        verticalLayout_4->addWidget(groupBox_2);

        line_2 = new QFrame(GradeWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        groupBox_3 = new QGroupBox(GradeWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toolBox = new QToolBox(groupBox_3);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 543, 70));
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 543, 70));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));

        verticalLayout_3->addWidget(toolBox);


        verticalLayout_4->addWidget(groupBox_3);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout_4);

        line_3 = new QFrame(GradeWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(1, QFormLayout::FieldRole, line_3);


        retranslateUi(GradeWidget);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GradeWidget);
    } // setupUi

    void retranslateUi(QWidget *GradeWidget)
    {
        GradeWidget->setWindowTitle(QApplication::translate("GradeWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GradeWidget", "\344\277\241\346\201\257\346\243\200\347\264\242", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GradeWidget", "\345\255\246\345\217\267", 0, QApplication::UnicodeUTF8));
        findButton->setText(QApplication::translate("GradeWidget", "\346\243\200\347\264\242", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("GradeWidget", "\346\243\200\347\264\242\347\273\223\346\236\234\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GradeWidget", "\345\247\223\345\220\215", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GradeWidget", "\346\200\247\345\210\253", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GradeWidget", "\347\217\255\347\272\247", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("GradeWidget", "\345\275\223\345\211\215\350\277\233\345\272\246", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("GradeWidget", "\351\235\242\350\257\225\346\211\223\345\210\206", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("GradeWidget", "Page 1", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("GradeWidget", "Page 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GradeWidget: public Ui_GradeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADEWIDGET_H
