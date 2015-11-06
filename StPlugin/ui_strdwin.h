/********************************************************************************
** Form generated from reading UI file 'strdwin.ui'
**
** Created: Fri Nov 6 10:54:12 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRDWIN_H
#define UI_STRDWIN_H

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

class Ui_StRdWin
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
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *noEdit;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *depLabel;
    QLabel *idLabel;
    QkSearchEditBox *depSearchEditbox;
    QLabel *busLabel;
    QLabel *dateLabel;
    QkSearchEditBox *userSearchEditbox;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer;
    QkSearchEditBox *venSearchEditbox;
    QLabel *label;
    QLabel *whLabel;
    QkSearchEditBox *whSearchEditbox;
    QLabel *label_9;
    QLineEdit *memoEdit;
    QLineEdit *auditEdit;
    QLabel *label_10;
    QLineEdit *makerEdit;
    QLabel *label_8;
    QLabel *arrivalLabel;
    QLineEdit *arrivalNoEdit;
    QLabel *rdLabel;
    QLineEdit *busTypeEdit;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *StRdWin)
    {
        if (StRdWin->objectName().isEmpty())
            StRdWin->setObjectName(QString::fromUtf8("StRdWin"));
        StRdWin->resize(961, 600);
        centralwidget = new QWidget(StRdWin);
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
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        noEdit = new QLineEdit(frame_2);
        noEdit->setObjectName(QString::fromUtf8("noEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(noEdit->sizePolicy().hasHeightForWidth());
        noEdit->setSizePolicy(sizePolicy);
        noEdit->setDragEnabled(true);
        noEdit->setReadOnly(true);

        headGridLayout->addWidget(noEdit, 0, 1, 1, 1);

        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy1);
        dateEdit->setCalendarPopup(true);

        headGridLayout->addWidget(dateEdit, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_5, 0, 8, 1, 1);

        depLabel = new QLabel(frame_2);
        depLabel->setObjectName(QString::fromUtf8("depLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(depLabel->sizePolicy().hasHeightForWidth());
        depLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(depLabel, 1, 6, 1, 1);

        idLabel = new QLabel(frame_2);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        sizePolicy2.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(idLabel, 0, 0, 1, 1);

        depSearchEditbox = new QkSearchEditBox(frame_2);
        depSearchEditbox->setObjectName(QString::fromUtf8("depSearchEditbox"));
        sizePolicy1.setHeightForWidth(depSearchEditbox->sizePolicy().hasHeightForWidth());
        depSearchEditbox->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(depSearchEditbox, 1, 7, 1, 1);

        busLabel = new QLabel(frame_2);
        busLabel->setObjectName(QString::fromUtf8("busLabel"));
        sizePolicy2.setHeightForWidth(busLabel->sizePolicy().hasHeightForWidth());
        busLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(busLabel, 0, 9, 1, 1);

        dateLabel = new QLabel(frame_2);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        sizePolicy2.setHeightForWidth(dateLabel->sizePolicy().hasHeightForWidth());
        dateLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(dateLabel, 0, 3, 1, 1);

        userSearchEditbox = new QkSearchEditBox(frame_2);
        userSearchEditbox->setObjectName(QString::fromUtf8("userSearchEditbox"));
        sizePolicy.setHeightForWidth(userSearchEditbox->sizePolicy().hasHeightForWidth());
        userSearchEditbox->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(userSearchEditbox, 1, 10, 1, 1);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_12, 1, 9, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer, 1, 11, 1, 1);

        venSearchEditbox = new QkSearchEditBox(frame_2);
        venSearchEditbox->setObjectName(QString::fromUtf8("venSearchEditbox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(venSearchEditbox->sizePolicy().hasHeightForWidth());
        venSearchEditbox->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(venSearchEditbox, 0, 10, 1, 2);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        headGridLayout->addWidget(label, 1, 0, 1, 1);

        whLabel = new QLabel(frame_2);
        whLabel->setObjectName(QString::fromUtf8("whLabel"));

        headGridLayout->addWidget(whLabel, 0, 6, 1, 1);

        whSearchEditbox = new QkSearchEditBox(frame_2);
        whSearchEditbox->setObjectName(QString::fromUtf8("whSearchEditbox"));

        headGridLayout->addWidget(whSearchEditbox, 0, 7, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        headGridLayout->addWidget(label_9, 2, 0, 1, 1);

        memoEdit = new QLineEdit(frame_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        headGridLayout->addWidget(memoEdit, 2, 1, 1, 4);

        auditEdit = new QLineEdit(frame_2);
        auditEdit->setObjectName(QString::fromUtf8("auditEdit"));
        sizePolicy.setHeightForWidth(auditEdit->sizePolicy().hasHeightForWidth());
        auditEdit->setSizePolicy(sizePolicy);
        auditEdit->setReadOnly(true);

        headGridLayout->addWidget(auditEdit, 2, 10, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        headGridLayout->addWidget(label_10, 2, 9, 1, 1);

        makerEdit = new QLineEdit(frame_2);
        makerEdit->setObjectName(QString::fromUtf8("makerEdit"));
        sizePolicy.setHeightForWidth(makerEdit->sizePolicy().hasHeightForWidth());
        makerEdit->setSizePolicy(sizePolicy);
        makerEdit->setReadOnly(true);

        headGridLayout->addWidget(makerEdit, 2, 7, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        headGridLayout->addWidget(label_8, 2, 6, 1, 1);

        arrivalLabel = new QLabel(frame_2);
        arrivalLabel->setObjectName(QString::fromUtf8("arrivalLabel"));

        headGridLayout->addWidget(arrivalLabel, 1, 3, 1, 1);

        arrivalNoEdit = new QLineEdit(frame_2);
        arrivalNoEdit->setObjectName(QString::fromUtf8("arrivalNoEdit"));
        arrivalNoEdit->setReadOnly(true);

        headGridLayout->addWidget(arrivalNoEdit, 1, 4, 1, 1);

        rdLabel = new QLabel(frame_2);
        rdLabel->setObjectName(QString::fromUtf8("rdLabel"));

        headGridLayout->addWidget(rdLabel, 2, 11, 1, 1);

        busTypeEdit = new QLineEdit(frame_2);
        busTypeEdit->setObjectName(QString::fromUtf8("busTypeEdit"));

        headGridLayout->addWidget(busTypeEdit, 1, 1, 1, 1);


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

        StRdWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(StRdWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StRdWin->setStatusBar(statusbar);
        toolBar = new QToolBar(StRdWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        StRdWin->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(StRdWin);

        QMetaObject::connectSlotsByName(StRdWin);
    } // setupUi

    void retranslateUi(QMainWindow *StRdWin)
    {
        StRdWin->setWindowTitle(QApplication::translate("StRdWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("StRdWin", "\351\207\207\350\264\255\345\205\245\345\272\223\345\215\225", 0, QApplication::UnicodeUTF8));
        depLabel->setText(QApplication::translate("StRdWin", "\344\270\232\345\212\241\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("StRdWin", "\345\205\245\345\272\223\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        busLabel->setText(QApplication::translate("StRdWin", "\344\276\233 \345\272\224 \345\225\206:", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("StRdWin", "\345\205\245\345\272\223\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("StRdWin", "\344\270\232 \345\212\241 \345\221\230:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StRdWin", "\345\215\225\346\215\256\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        whLabel->setText(QApplication::translate("StRdWin", "\345\205\245\345\272\223\344\273\223\345\272\223:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("StRdWin", "\345\244\207    \346\263\250:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("StRdWin", "\345\256\241 \346\240\270 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("StRdWin", "\345\210\266 \345\215\225 \344\272\272:", 0, QApplication::UnicodeUTF8));
        arrivalLabel->setText(QApplication::translate("StRdWin", "\345\210\260\350\264\247\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        rdLabel->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("StRdWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StRdWin: public Ui_StRdWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRDWIN_H
