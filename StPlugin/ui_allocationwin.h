/********************************************************************************
** Form generated from reading UI file 'allocationwin.ui'
**
** Created: Fri Nov 6 10:54:12 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLOCATIONWIN_H
#define UI_ALLOCATIONWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_AllocationWin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *titleLabel;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QDateEdit *dateEdit;
    QLineEdit *noEdit;
    QSpacerItem *horizontalSpacer_4;
    QLabel *idLabel;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_9;
    QLabel *dateLabel;
    QLineEdit *memoEdit;
    QLabel *label_6;
    QkSearchEditBox *depSearchEditbox;
    QLabel *label_12;
    QkSearchEditBox *userSearchEditbox;
    QLabel *label_8;
    QLineEdit *makerEdit;
    QLabel *label_10;
    QLineEdit *auditEdit;
    QLabel *wareLabel;
    QkSearchEditBox *whOutSearchEditbox;
    QLabel *label_4;
    QkSearchEditBox *whInSearchEditbox;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *AllocationWin)
    {
        if (AllocationWin->objectName().isEmpty())
            AllocationWin->setObjectName(QString::fromUtf8("AllocationWin"));
        AllocationWin->resize(1142, 600);
        centralwidget = new QWidget(AllocationWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Plain);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        titleLabel = new QLabel(frame_4);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(titleLabel);


        verticalLayout_2->addWidget(frame_4);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 11, 1, 1);

        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 0, 4, 1, 1);

        noEdit = new QLineEdit(frame_2);
        noEdit->setObjectName(QString::fromUtf8("noEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(noEdit->sizePolicy().hasHeightForWidth());
        noEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(noEdit, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        idLabel = new QLabel(frame_2);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(idLabel, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 8, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 0, 1, 1);

        dateLabel = new QLabel(frame_2);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        sizePolicy2.setHeightForWidth(dateLabel->sizePolicy().hasHeightForWidth());
        dateLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(dateLabel, 0, 3, 1, 1);

        memoEdit = new QLineEdit(frame_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        gridLayout->addWidget(memoEdit, 3, 1, 1, 4);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_6, 0, 6, 1, 1);

        depSearchEditbox = new QkSearchEditBox(frame_2);
        depSearchEditbox->setObjectName(QString::fromUtf8("depSearchEditbox"));
        sizePolicy.setHeightForWidth(depSearchEditbox->sizePolicy().hasHeightForWidth());
        depSearchEditbox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(depSearchEditbox, 0, 7, 1, 1);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_12, 0, 9, 1, 1);

        userSearchEditbox = new QkSearchEditBox(frame_2);
        userSearchEditbox->setObjectName(QString::fromUtf8("userSearchEditbox"));
        sizePolicy1.setHeightForWidth(userSearchEditbox->sizePolicy().hasHeightForWidth());
        userSearchEditbox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(userSearchEditbox, 0, 10, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 6, 1, 1);

        makerEdit = new QLineEdit(frame_2);
        makerEdit->setObjectName(QString::fromUtf8("makerEdit"));
        sizePolicy1.setHeightForWidth(makerEdit->sizePolicy().hasHeightForWidth());
        makerEdit->setSizePolicy(sizePolicy1);
        makerEdit->setReadOnly(true);

        gridLayout->addWidget(makerEdit, 1, 7, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 1, 9, 1, 1);

        auditEdit = new QLineEdit(frame_2);
        auditEdit->setObjectName(QString::fromUtf8("auditEdit"));
        sizePolicy1.setHeightForWidth(auditEdit->sizePolicy().hasHeightForWidth());
        auditEdit->setSizePolicy(sizePolicy1);
        auditEdit->setReadOnly(true);

        gridLayout->addWidget(auditEdit, 1, 10, 1, 1);

        wareLabel = new QLabel(frame_2);
        wareLabel->setObjectName(QString::fromUtf8("wareLabel"));
        sizePolicy2.setHeightForWidth(wareLabel->sizePolicy().hasHeightForWidth());
        wareLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(wareLabel, 1, 0, 1, 1);

        whOutSearchEditbox = new QkSearchEditBox(frame_2);
        whOutSearchEditbox->setObjectName(QString::fromUtf8("whOutSearchEditbox"));

        gridLayout->addWidget(whOutSearchEditbox, 1, 1, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 3, 1, 1);

        whInSearchEditbox = new QkSearchEditBox(frame_2);
        whInSearchEditbox->setObjectName(QString::fromUtf8("whInSearchEditbox"));

        gridLayout->addWidget(whInSearchEditbox, 1, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addWidget(frame_2);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(5);

        verticalLayout_2->addWidget(tableWidget);

        AllocationWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(AllocationWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AllocationWin->setStatusBar(statusbar);
        toolBar = new QToolBar(AllocationWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        AllocationWin->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(AllocationWin);

        QMetaObject::connectSlotsByName(AllocationWin);
    } // setupUi

    void retranslateUi(QMainWindow *AllocationWin)
    {
        AllocationWin->setWindowTitle(QApplication::translate("AllocationWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("AllocationWin", "\350\260\203\346\213\250\345\215\225", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("AllocationWin", "\350\260\203\346\213\250\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("AllocationWin", "\345\244\207    \346\263\250:", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("AllocationWin", "\350\260\203\346\213\250\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AllocationWin", "\351\203\250    \351\227\250:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("AllocationWin", "\350\264\237 \350\264\243 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("AllocationWin", "\345\210\266 \345\215\225 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("AllocationWin", "\345\256\241 \346\240\270 \344\272\272:", 0, QApplication::UnicodeUTF8));
        wareLabel->setText(QApplication::translate("AllocationWin", "\350\275\254\345\207\272\344\273\223\345\272\223:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AllocationWin", "\350\275\254\345\205\245\344\273\223\345\272\223:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("AllocationWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AllocationWin: public Ui_AllocationWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLOCATIONWIN_H
