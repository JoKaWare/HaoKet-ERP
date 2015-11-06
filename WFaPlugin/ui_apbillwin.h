/********************************************************************************
** Form generated from reading UI file 'apbillwin.ui'
**
** Created: Fri Nov 6 10:54:55 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APBILLWIN_H
#define UI_APBILLWIN_H

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

class Ui_ApBillWin
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *titleLabel;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *headGridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *noEdit;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *idLabel;
    QLabel *label_3;
    QLabel *dateLabel;
    QLabel *label_9;
    QLineEdit *memoEdit;
    QkSearchEditBox *busQsk;
    QLabel *label;
    QComboBox *busTypeCmb;
    QLabel *depLabel;
    QkSearchEditBox *depQsk;
    QLabel *personLabel;
    QkSearchEditBox *personQsk;
    QLabel *settleLabel;
    QComboBox *settleCmb;
    QLabel *bankNameLabel;
    QLabel *apLabel;
    QLabel *preLabel;
    QLineEdit *apEdit;
    QLineEdit *preEdit;
    QSpacerItem *horizontalSpacer;
    QLineEdit *auditEdit;
    QLabel *label_10;
    QLabel *label_8;
    QLineEdit *makerEdit;
    QLabel *bankLabel;
    QLineEdit *bankCardEdit;
    QLineEdit *bankNameEdit;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ApBillWin)
    {
        if (ApBillWin->objectName().isEmpty())
            ApBillWin->setObjectName(QString::fromUtf8("ApBillWin"));
        ApBillWin->resize(945, 600);
        centralwidget = new QWidget(ApBillWin);
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
        titleLabel = new QLabel(frame_4);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
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

        idLabel = new QLabel(frame_2);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(idLabel, 0, 0, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_3, 0, 9, 1, 1);

        dateLabel = new QLabel(frame_2);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        sizePolicy2.setHeightForWidth(dateLabel->sizePolicy().hasHeightForWidth());
        dateLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(dateLabel, 0, 3, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        headGridLayout->addWidget(label_9, 3, 0, 1, 1);

        memoEdit = new QLineEdit(frame_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        headGridLayout->addWidget(memoEdit, 3, 1, 1, 4);

        busQsk = new QkSearchEditBox(frame_2);
        busQsk->setObjectName(QString::fromUtf8("busQsk"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(busQsk->sizePolicy().hasHeightForWidth());
        busQsk->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(busQsk, 0, 10, 1, 2);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        headGridLayout->addWidget(label, 1, 0, 1, 1);

        busTypeCmb = new QComboBox(frame_2);
        busTypeCmb->setObjectName(QString::fromUtf8("busTypeCmb"));
        sizePolicy3.setHeightForWidth(busTypeCmb->sizePolicy().hasHeightForWidth());
        busTypeCmb->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(busTypeCmb, 1, 1, 1, 1);

        depLabel = new QLabel(frame_2);
        depLabel->setObjectName(QString::fromUtf8("depLabel"));
        sizePolicy2.setHeightForWidth(depLabel->sizePolicy().hasHeightForWidth());
        depLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(depLabel, 0, 6, 1, 1);

        depQsk = new QkSearchEditBox(frame_2);
        depQsk->setObjectName(QString::fromUtf8("depQsk"));
        sizePolicy1.setHeightForWidth(depQsk->sizePolicy().hasHeightForWidth());
        depQsk->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(depQsk, 0, 7, 1, 1);

        personLabel = new QLabel(frame_2);
        personLabel->setObjectName(QString::fromUtf8("personLabel"));
        sizePolicy2.setHeightForWidth(personLabel->sizePolicy().hasHeightForWidth());
        personLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(personLabel, 1, 6, 1, 1);

        personQsk = new QkSearchEditBox(frame_2);
        personQsk->setObjectName(QString::fromUtf8("personQsk"));
        sizePolicy.setHeightForWidth(personQsk->sizePolicy().hasHeightForWidth());
        personQsk->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(personQsk, 1, 7, 1, 1);

        settleLabel = new QLabel(frame_2);
        settleLabel->setObjectName(QString::fromUtf8("settleLabel"));

        headGridLayout->addWidget(settleLabel, 1, 3, 1, 1);

        settleCmb = new QComboBox(frame_2);
        settleCmb->setObjectName(QString::fromUtf8("settleCmb"));

        headGridLayout->addWidget(settleCmb, 1, 4, 1, 1);

        bankNameLabel = new QLabel(frame_2);
        bankNameLabel->setObjectName(QString::fromUtf8("bankNameLabel"));

        headGridLayout->addWidget(bankNameLabel, 2, 9, 1, 1);

        apLabel = new QLabel(frame_2);
        apLabel->setObjectName(QString::fromUtf8("apLabel"));

        headGridLayout->addWidget(apLabel, 2, 0, 1, 1);

        preLabel = new QLabel(frame_2);
        preLabel->setObjectName(QString::fromUtf8("preLabel"));

        headGridLayout->addWidget(preLabel, 2, 3, 1, 1);

        apEdit = new QLineEdit(frame_2);
        apEdit->setObjectName(QString::fromUtf8("apEdit"));
        apEdit->setReadOnly(true);

        headGridLayout->addWidget(apEdit, 2, 1, 1, 1);

        preEdit = new QLineEdit(frame_2);
        preEdit->setObjectName(QString::fromUtf8("preEdit"));
        preEdit->setReadOnly(true);

        headGridLayout->addWidget(preEdit, 2, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer, 1, 11, 1, 1);

        auditEdit = new QLineEdit(frame_2);
        auditEdit->setObjectName(QString::fromUtf8("auditEdit"));
        sizePolicy.setHeightForWidth(auditEdit->sizePolicy().hasHeightForWidth());
        auditEdit->setSizePolicy(sizePolicy);
        auditEdit->setReadOnly(true);

        headGridLayout->addWidget(auditEdit, 3, 10, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        headGridLayout->addWidget(label_10, 3, 9, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        headGridLayout->addWidget(label_8, 3, 6, 1, 1);

        makerEdit = new QLineEdit(frame_2);
        makerEdit->setObjectName(QString::fromUtf8("makerEdit"));
        sizePolicy.setHeightForWidth(makerEdit->sizePolicy().hasHeightForWidth());
        makerEdit->setSizePolicy(sizePolicy);
        makerEdit->setReadOnly(true);

        headGridLayout->addWidget(makerEdit, 3, 7, 1, 1);

        bankLabel = new QLabel(frame_2);
        bankLabel->setObjectName(QString::fromUtf8("bankLabel"));

        headGridLayout->addWidget(bankLabel, 2, 6, 1, 1);

        bankCardEdit = new QLineEdit(frame_2);
        bankCardEdit->setObjectName(QString::fromUtf8("bankCardEdit"));

        headGridLayout->addWidget(bankCardEdit, 2, 7, 1, 1);

        bankNameEdit = new QLineEdit(frame_2);
        bankNameEdit->setObjectName(QString::fromUtf8("bankNameEdit"));

        headGridLayout->addWidget(bankNameEdit, 2, 10, 1, 2);


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

        ApBillWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ApBillWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ApBillWin->setStatusBar(statusbar);
        toolBar = new QToolBar(ApBillWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        ApBillWin->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(ApBillWin);

        QMetaObject::connectSlotsByName(ApBillWin);
    } // setupUi

    void retranslateUi(QMainWindow *ApBillWin)
    {
        ApBillWin->setWindowTitle(QApplication::translate("ApBillWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("ApBillWin", "\344\273\230\346\254\276\345\215\225", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("ApBillWin", "\344\273\230\346\254\276\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ApBillWin", "\344\276\233 \345\272\224 \345\225\206:", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("ApBillWin", "\344\273\230\346\254\276\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ApBillWin", "\345\244\207    \346\263\250:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ApBillWin", "\346\224\266\344\273\230\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        depLabel->setText(QApplication::translate("ApBillWin", "\344\270\232\345\212\241\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        personLabel->setText(QApplication::translate("ApBillWin", "\344\270\232 \345\212\241 \345\221\230:", 0, QApplication::UnicodeUTF8));
        settleLabel->setText(QApplication::translate("ApBillWin", "\347\273\223\347\256\227\346\226\271\345\274\217:", 0, QApplication::UnicodeUTF8));
        bankNameLabel->setText(QApplication::translate("ApBillWin", "\351\223\266\350\241\214\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        apLabel->setText(QApplication::translate("ApBillWin", "\345\272\224\344\273\230\344\275\231\351\242\235:", 0, QApplication::UnicodeUTF8));
        preLabel->setText(QApplication::translate("ApBillWin", "\351\242\204\344\273\230\344\275\231\351\242\235:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ApBillWin", "\345\256\241 \346\240\270 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ApBillWin", "\345\210\266 \345\215\225 \344\272\272:", 0, QApplication::UnicodeUTF8));
        bankLabel->setText(QApplication::translate("ApBillWin", "\351\223\266\350\241\214\345\270\220\345\217\267:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("ApBillWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ApBillWin: public Ui_ApBillWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APBILLWIN_H
