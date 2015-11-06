/********************************************************************************
** Form generated from reading UI file 'emplistdialog.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLISTDIALOG_H
#define UI_EMPLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_EmpListDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QkSearchEditBox *qksearcheditbox;
    QLabel *label;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QToolButton *cancleButton;
    QToolButton *okButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *EmpListDialog)
    {
        if (EmpListDialog->objectName().isEmpty())
            EmpListDialog->setObjectName(QString::fromUtf8("EmpListDialog"));
        EmpListDialog->resize(370, 453);
        verticalLayout = new QVBoxLayout(EmpListDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        qksearcheditbox = new QkSearchEditBox(EmpListDialog);
        qksearcheditbox->setObjectName(QString::fromUtf8("qksearcheditbox"));

        gridLayout_2->addWidget(qksearcheditbox, 0, 1, 1, 1);

        label = new QLabel(EmpListDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        tableView = new QTableView(EmpListDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cancleButton = new QToolButton(EmpListDialog);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/cancel_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancleButton->setIcon(icon);
        cancleButton->setIconSize(QSize(32, 32));
        cancleButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(cancleButton, 0, 2, 1, 1);

        okButton = new QToolButton(EmpListDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon1);
        okButton->setIconSize(QSize(32, 32));
        okButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(okButton, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(EmpListDialog);

        QMetaObject::connectSlotsByName(EmpListDialog);
    } // setupUi

    void retranslateUi(QDialog *EmpListDialog)
    {
        EmpListDialog->setWindowTitle(QApplication::translate("EmpListDialog", "\351\200\211\346\213\251\345\221\230\345\267\245", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmpListDialog", "\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        cancleButton->setText(QApplication::translate("EmpListDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("EmpListDialog", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmpListDialog: public Ui_EmpListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLISTDIALOG_H
