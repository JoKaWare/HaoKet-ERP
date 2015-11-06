/********************************************************************************
** Form generated from reading UI file 'saorderwin.ui'
**
** Created: Fri Nov 6 10:53:11 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAORDERWIN_H
#define UI_SAORDERWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
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

class Ui_SaOrderWin
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
    QLabel *label_6;
    QDateEdit *projectDateEdit;
    QLabel *idLabel;
    QkSearchEditBox *depSearchEditbox;
    QDateEdit *demanddDateEdit;
    QComboBox *busTypeComboBox;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QkSearchEditBox *userSearchEditbox;
    QLabel *label_5;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer;
    QkSearchEditBox *cusSearchEditbox;
    QLabel *label_9;
    QLineEdit *auditEdit;
    QLabel *label_10;
    QLineEdit *makerEdit;
    QLabel *label_8;
    QLineEdit *memoEdit;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SaOrderWin)
    {
        if (SaOrderWin->objectName().isEmpty())
            SaOrderWin->setObjectName(QString::fromUtf8("SaOrderWin"));
        SaOrderWin->resize(1039, 600);
        centralwidget = new QWidget(SaOrderWin);
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

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_6, 1, 6, 1, 1);

        projectDateEdit = new QDateEdit(frame_2);
        projectDateEdit->setObjectName(QString::fromUtf8("projectDateEdit"));
        projectDateEdit->setCalendarPopup(true);

        headGridLayout->addWidget(projectDateEdit, 1, 4, 1, 1);

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

        demanddDateEdit = new QDateEdit(frame_2);
        demanddDateEdit->setObjectName(QString::fromUtf8("demanddDateEdit"));
        sizePolicy1.setHeightForWidth(demanddDateEdit->sizePolicy().hasHeightForWidth());
        demanddDateEdit->setSizePolicy(sizePolicy1);
        demanddDateEdit->setCalendarPopup(true);

        headGridLayout->addWidget(demanddDateEdit, 1, 1, 1, 1);

        busTypeComboBox = new QComboBox(frame_2);
        busTypeComboBox->setObjectName(QString::fromUtf8("busTypeComboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(busTypeComboBox->sizePolicy().hasHeightForWidth());
        busTypeComboBox->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(busTypeComboBox, 0, 7, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        headGridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_3, 0, 9, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_2, 0, 3, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        headGridLayout->addWidget(label, 0, 6, 1, 1);

        userSearchEditbox = new QkSearchEditBox(frame_2);
        userSearchEditbox->setObjectName(QString::fromUtf8("userSearchEditbox"));
        sizePolicy.setHeightForWidth(userSearchEditbox->sizePolicy().hasHeightForWidth());
        userSearchEditbox->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(userSearchEditbox, 1, 10, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_5, 1, 3, 1, 1);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_12, 1, 9, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer, 1, 11, 1, 1);

        cusSearchEditbox = new QkSearchEditBox(frame_2);
        cusSearchEditbox->setObjectName(QString::fromUtf8("cusSearchEditbox"));
        sizePolicy3.setHeightForWidth(cusSearchEditbox->sizePolicy().hasHeightForWidth());
        cusSearchEditbox->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(cusSearchEditbox, 0, 10, 1, 2);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        headGridLayout->addWidget(label_9, 2, 0, 1, 1);

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

        memoEdit = new QLineEdit(frame_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        headGridLayout->addWidget(memoEdit, 2, 1, 1, 4);


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

        SaOrderWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SaOrderWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SaOrderWin->setStatusBar(statusbar);
        toolBar = new QToolBar(SaOrderWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        SaOrderWin->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(SaOrderWin);

        QMetaObject::connectSlotsByName(SaOrderWin);
    } // setupUi

    void retranslateUi(QMainWindow *SaOrderWin)
    {
        SaOrderWin->setWindowTitle(QApplication::translate("SaOrderWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SaOrderWin", "\351\224\200\345\224\256\350\256\242\345\215\225", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SaOrderWin", "\344\270\232\345\212\241\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("SaOrderWin", "\350\256\242\345\215\225\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SaOrderWin", "\351\234\200\346\261\202\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SaOrderWin", "\345\256\242    \346\210\267:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SaOrderWin", "\350\256\242\345\215\225\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SaOrderWin", "\351\224\200\345\224\256\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SaOrderWin", "\345\217\221\350\264\247\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SaOrderWin", "\344\270\232 \345\212\241 \345\221\230:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SaOrderWin", "\345\244\207    \346\263\250:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SaOrderWin", "\345\256\241 \346\240\270 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SaOrderWin", "\345\210\266 \345\215\225 \344\272\272:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SaOrderWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaOrderWin: public Ui_SaOrderWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAORDERWIN_H
