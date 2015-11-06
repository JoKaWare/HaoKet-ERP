/********************************************************************************
** Form generated from reading UI file 'sareturnedwin.ui'
**
** Created: Fri Nov 6 10:53:11 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SARETURNEDWIN_H
#define UI_SARETURNEDWIN_H

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

class Ui_SaReturnedWin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_16;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *headGridLayout;
    QSpacerItem *horizontalSpacer;
    QkSearchEditBox *cusSearchEditbox;
    QLabel *idLabel;
    QSpacerItem *horizontalSpacer_3;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *noEdit;
    QLabel *label_9;
    QLineEdit *memoEdit;
    QLabel *label_6;
    QkSearchEditBox *depSearchEditbox;
    QLabel *label_12;
    QkSearchEditBox *userSearchEditbox;
    QLabel *label_3;
    QkSearchEditBox *whSearchEditbox;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *makerEdit;
    QLabel *label_10;
    QLineEdit *auditEdit;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SaReturnedWin)
    {
        if (SaReturnedWin->objectName().isEmpty())
            SaReturnedWin->setObjectName(QString::fromUtf8("SaReturnedWin"));
        SaReturnedWin->resize(992, 600);
        centralwidget = new QWidget(SaReturnedWin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Plain);
        frame_4->setLineWidth(0);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_16 = new QLabel(frame_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_16);


        verticalLayout_2->addWidget(frame_4);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        headGridLayout = new QGridLayout();
        headGridLayout->setObjectName(QString::fromUtf8("headGridLayout"));
        headGridLayout->setHorizontalSpacing(10);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer, 1, 11, 1, 1);

        cusSearchEditbox = new QkSearchEditBox(frame_2);
        cusSearchEditbox->setObjectName(QString::fromUtf8("cusSearchEditbox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cusSearchEditbox->sizePolicy().hasHeightForWidth());
        cusSearchEditbox->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(cusSearchEditbox, 0, 10, 1, 2);

        idLabel = new QLabel(frame_2);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(idLabel, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy2);
        dateEdit->setCalendarPopup(true);

        headGridLayout->addWidget(dateEdit, 0, 4, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_2, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_5, 0, 8, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        noEdit = new QLineEdit(frame_2);
        noEdit->setObjectName(QString::fromUtf8("noEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(noEdit->sizePolicy().hasHeightForWidth());
        noEdit->setSizePolicy(sizePolicy3);
        noEdit->setDragEnabled(true);
        noEdit->setReadOnly(true);

        headGridLayout->addWidget(noEdit, 0, 1, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        headGridLayout->addWidget(label_9, 2, 0, 1, 1);

        memoEdit = new QLineEdit(frame_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        headGridLayout->addWidget(memoEdit, 2, 1, 1, 4);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_6, 1, 6, 1, 1);

        depSearchEditbox = new QkSearchEditBox(frame_2);
        depSearchEditbox->setObjectName(QString::fromUtf8("depSearchEditbox"));
        sizePolicy2.setHeightForWidth(depSearchEditbox->sizePolicy().hasHeightForWidth());
        depSearchEditbox->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(depSearchEditbox, 1, 7, 1, 1);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_12, 1, 9, 1, 1);

        userSearchEditbox = new QkSearchEditBox(frame_2);
        userSearchEditbox->setObjectName(QString::fromUtf8("userSearchEditbox"));
        sizePolicy3.setHeightForWidth(userSearchEditbox->sizePolicy().hasHeightForWidth());
        userSearchEditbox->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(userSearchEditbox, 1, 10, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_3, 0, 9, 1, 1);

        whSearchEditbox = new QkSearchEditBox(frame_2);
        whSearchEditbox->setObjectName(QString::fromUtf8("whSearchEditbox"));

        headGridLayout->addWidget(whSearchEditbox, 0, 7, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        headGridLayout->addWidget(label_7, 0, 6, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        headGridLayout->addWidget(label_8, 1, 0, 1, 1);

        makerEdit = new QLineEdit(frame_2);
        makerEdit->setObjectName(QString::fromUtf8("makerEdit"));
        sizePolicy3.setHeightForWidth(makerEdit->sizePolicy().hasHeightForWidth());
        makerEdit->setSizePolicy(sizePolicy3);
        makerEdit->setReadOnly(true);

        headGridLayout->addWidget(makerEdit, 1, 1, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        headGridLayout->addWidget(label_10, 1, 3, 1, 1);

        auditEdit = new QLineEdit(frame_2);
        auditEdit->setObjectName(QString::fromUtf8("auditEdit"));
        sizePolicy3.setHeightForWidth(auditEdit->sizePolicy().hasHeightForWidth());
        auditEdit->setSizePolicy(sizePolicy3);
        auditEdit->setReadOnly(true);

        headGridLayout->addWidget(auditEdit, 1, 4, 1, 1);


        verticalLayout->addLayout(headGridLayout);


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

        SaReturnedWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SaReturnedWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SaReturnedWin->setStatusBar(statusbar);
        toolBar = new QToolBar(SaReturnedWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        SaReturnedWin->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(SaReturnedWin);

        QMetaObject::connectSlotsByName(SaReturnedWin);
    } // setupUi

    void retranslateUi(QMainWindow *SaReturnedWin)
    {
        SaReturnedWin->setWindowTitle(QApplication::translate("SaReturnedWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SaReturnedWin", "<html><head/><body><p><span style=\" color:#ff0000;\">\351\224\200\345\224\256\351\200\200\350\264\247\345\215\225</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("SaReturnedWin", "\351\200\200\350\264\247\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SaReturnedWin", "\351\200\200\350\264\247\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SaReturnedWin", "\345\244\207    \346\263\250:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SaReturnedWin", "\344\270\232\345\212\241\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SaReturnedWin", "\344\270\232 \345\212\241 \345\221\230:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SaReturnedWin", "\345\256\242    \346\210\267:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SaReturnedWin", "\344\273\223    \345\272\223:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SaReturnedWin", "\345\210\266 \345\215\225 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SaReturnedWin", "\345\256\241 \346\240\270 \344\272\272:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SaReturnedWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaReturnedWin: public Ui_SaReturnedWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SARETURNEDWIN_H
