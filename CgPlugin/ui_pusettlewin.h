/********************************************************************************
** Form generated from reading UI file 'pusettlewin.ui'
**
** Created: Fri Nov 6 10:52:07 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUSETTLEWIN_H
#define UI_PUSETTLEWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDoubleSpinBox>
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

class Ui_PuSettleWin
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
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *noEdit;
    QLabel *label_3;
    QLabel *dateLabel;
    QLabel *idLabel;
    QLabel *label_12;
    QLabel *label_9;
    QkSearchEditBox *userSearchEditbox;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *memoEdit;
    QComboBox *busTypeComboBox;
    QkSearchEditBox *depSearchEditbox;
    QSpacerItem *horizontalSpacer;
    QkSearchEditBox *venSearchEditbox;
    QLineEdit *makerEdit;
    QLabel *label_10;
    QLabel *label_8;
    QLineEdit *auditEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *profitEdit;
    QLineEdit *rdNoEdit;
    QLabel *label_2;
    QLabel *label_11;
    QLineEdit *apNoEdit;
    QDoubleSpinBox *apMoneySpinBox;
    QDoubleSpinBox *profitMoneySpinBox;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *PuSettleWin)
    {
        if (PuSettleWin->objectName().isEmpty())
            PuSettleWin->setObjectName(QString::fromUtf8("PuSettleWin"));
        PuSettleWin->resize(1389, 600);
        centralwidget = new QWidget(PuSettleWin);
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
        headGridLayout = new QGridLayout();
        headGridLayout->setObjectName(QString::fromUtf8("headGridLayout"));
        headGridLayout->setHorizontalSpacing(10);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_5, 0, 8, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy);
        dateEdit->setCalendarPopup(true);

        headGridLayout->addWidget(dateEdit, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        noEdit = new QLineEdit(frame_2);
        noEdit->setObjectName(QString::fromUtf8("noEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(noEdit->sizePolicy().hasHeightForWidth());
        noEdit->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(noEdit, 0, 1, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_3, 0, 9, 1, 1);

        dateLabel = new QLabel(frame_2);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        sizePolicy2.setHeightForWidth(dateLabel->sizePolicy().hasHeightForWidth());
        dateLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(dateLabel, 0, 3, 1, 1);

        idLabel = new QLabel(frame_2);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        sizePolicy2.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(idLabel, 0, 0, 1, 1);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_12, 1, 9, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        headGridLayout->addWidget(label_9, 3, 0, 1, 1);

        userSearchEditbox = new QkSearchEditBox(frame_2);
        userSearchEditbox->setObjectName(QString::fromUtf8("userSearchEditbox"));
        sizePolicy1.setHeightForWidth(userSearchEditbox->sizePolicy().hasHeightForWidth());
        userSearchEditbox->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(userSearchEditbox, 1, 10, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        headGridLayout->addWidget(label, 1, 0, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(label_6, 0, 6, 1, 1);

        memoEdit = new QLineEdit(frame_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        headGridLayout->addWidget(memoEdit, 3, 1, 1, 4);

        busTypeComboBox = new QComboBox(frame_2);
        busTypeComboBox->setObjectName(QString::fromUtf8("busTypeComboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(busTypeComboBox->sizePolicy().hasHeightForWidth());
        busTypeComboBox->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(busTypeComboBox, 1, 1, 1, 1);

        depSearchEditbox = new QkSearchEditBox(frame_2);
        depSearchEditbox->setObjectName(QString::fromUtf8("depSearchEditbox"));
        sizePolicy.setHeightForWidth(depSearchEditbox->sizePolicy().hasHeightForWidth());
        depSearchEditbox->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(depSearchEditbox, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer, 1, 11, 1, 1);

        venSearchEditbox = new QkSearchEditBox(frame_2);
        venSearchEditbox->setObjectName(QString::fromUtf8("venSearchEditbox"));
        sizePolicy3.setHeightForWidth(venSearchEditbox->sizePolicy().hasHeightForWidth());
        venSearchEditbox->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(venSearchEditbox, 0, 10, 1, 2);

        makerEdit = new QLineEdit(frame_2);
        makerEdit->setObjectName(QString::fromUtf8("makerEdit"));
        sizePolicy1.setHeightForWidth(makerEdit->sizePolicy().hasHeightForWidth());
        makerEdit->setSizePolicy(sizePolicy1);
        makerEdit->setReadOnly(true);

        headGridLayout->addWidget(makerEdit, 3, 7, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        headGridLayout->addWidget(label_10, 3, 9, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        headGridLayout->addWidget(label_8, 3, 6, 1, 1);

        auditEdit = new QLineEdit(frame_2);
        auditEdit->setObjectName(QString::fromUtf8("auditEdit"));
        sizePolicy1.setHeightForWidth(auditEdit->sizePolicy().hasHeightForWidth());
        auditEdit->setSizePolicy(sizePolicy1);
        auditEdit->setReadOnly(true);

        headGridLayout->addWidget(auditEdit, 3, 10, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        headGridLayout->addWidget(label_4, 1, 6, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        headGridLayout->addWidget(label_5, 2, 0, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        headGridLayout->addWidget(label_7, 2, 3, 1, 1);

        profitEdit = new QLineEdit(frame_2);
        profitEdit->setObjectName(QString::fromUtf8("profitEdit"));
        profitEdit->setReadOnly(true);

        headGridLayout->addWidget(profitEdit, 2, 1, 1, 1);

        rdNoEdit = new QLineEdit(frame_2);
        rdNoEdit->setObjectName(QString::fromUtf8("rdNoEdit"));
        sizePolicy1.setHeightForWidth(rdNoEdit->sizePolicy().hasHeightForWidth());
        rdNoEdit->setSizePolicy(sizePolicy1);
        rdNoEdit->setReadOnly(true);

        headGridLayout->addWidget(rdNoEdit, 2, 7, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        headGridLayout->addWidget(label_2, 2, 6, 1, 1);

        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        headGridLayout->addWidget(label_11, 1, 3, 1, 1);

        apNoEdit = new QLineEdit(frame_2);
        apNoEdit->setObjectName(QString::fromUtf8("apNoEdit"));
        apNoEdit->setReadOnly(true);

        headGridLayout->addWidget(apNoEdit, 1, 4, 1, 1);

        apMoneySpinBox = new QDoubleSpinBox(frame_2);
        apMoneySpinBox->setObjectName(QString::fromUtf8("apMoneySpinBox"));
        sizePolicy1.setHeightForWidth(apMoneySpinBox->sizePolicy().hasHeightForWidth());
        apMoneySpinBox->setSizePolicy(sizePolicy1);
        apMoneySpinBox->setReadOnly(true);
        apMoneySpinBox->setMaximum(1e+09);

        headGridLayout->addWidget(apMoneySpinBox, 1, 7, 1, 1);

        profitMoneySpinBox = new QDoubleSpinBox(frame_2);
        profitMoneySpinBox->setObjectName(QString::fromUtf8("profitMoneySpinBox"));
        sizePolicy1.setHeightForWidth(profitMoneySpinBox->sizePolicy().hasHeightForWidth());
        profitMoneySpinBox->setSizePolicy(sizePolicy1);
        profitMoneySpinBox->setReadOnly(true);
        profitMoneySpinBox->setMaximum(1e+09);

        headGridLayout->addWidget(profitMoneySpinBox, 2, 4, 1, 1);


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

        PuSettleWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(PuSettleWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PuSettleWin->setStatusBar(statusbar);
        toolBar = new QToolBar(PuSettleWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        PuSettleWin->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(PuSettleWin);

        QMetaObject::connectSlotsByName(PuSettleWin);
    } // setupUi

    void retranslateUi(QMainWindow *PuSettleWin)
    {
        PuSettleWin->setWindowTitle(QApplication::translate("PuSettleWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        titleLabel->setText(QApplication::translate("PuSettleWin", "\351\207\207\350\264\255\347\273\223\347\256\227\345\215\225", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PuSettleWin", "\344\276\233 \345\272\224 \345\225\206:", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("PuSettleWin", "\347\273\223\347\256\227\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("PuSettleWin", "\347\273\223\347\256\227\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("PuSettleWin", "\350\264\237 \350\264\243 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("PuSettleWin", "\345\244\207    \346\263\250:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PuSettleWin", "\347\273\223\347\256\227\346\226\271\345\274\217:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PuSettleWin", "\351\203\250    \351\227\250:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("PuSettleWin", "\345\256\241 \346\240\270 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PuSettleWin", "\345\210\266 \345\215\225 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PuSettleWin", "\344\273\230\346\254\276\351\207\221\351\242\235:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PuSettleWin", "\350\277\224\345\210\251\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PuSettleWin", "\350\277\224\345\210\251\351\207\221\351\242\235:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PuSettleWin", "\345\205\245\345\272\223\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("PuSettleWin", "\344\273\230\346\254\276\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("PuSettleWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PuSettleWin: public Ui_PuSettleWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUSETTLEWIN_H
