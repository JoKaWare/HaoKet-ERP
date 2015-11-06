/********************************************************************************
** Form generated from reading UI file 'sadeliverywin.ui'
**
** Created: Fri Nov 6 10:53:11 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SADELIVERYWIN_H
#define UI_SADELIVERYWIN_H

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

class Ui_SaDeliveryWin
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
    QLabel *label_5;
    QLineEdit *phoneEdit;
    QkSearchEditBox *whSearchEditbox;
    QSpacerItem *horizontalSpacer;
    QLabel *idLabel;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QkSearchEditBox *cusSearchEditbox;
    QDateEdit *dateEdit;
    QLabel *label_9;
    QLineEdit *memoEdit;
    QLineEdit *noEdit;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_12;
    QComboBox *busTypeComboBox;
    QkSearchEditBox *depSearchEditbox;
    QLabel *label_3;
    QkSearchEditBox *userSearchEditbox;
    QLabel *label_7;
    QLineEdit *makerEdit;
    QLabel *label_8;
    QLabel *label_10;
    QLineEdit *auditEdit;
    QLabel *label_4;
    QLabel *label_11;
    QLineEdit *linkEdit;
    QLineEdit *addressEdit;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SaDeliveryWin)
    {
        if (SaDeliveryWin->objectName().isEmpty())
            SaDeliveryWin->setObjectName(QString::fromUtf8("SaDeliveryWin"));
        SaDeliveryWin->resize(992, 600);
        centralwidget = new QWidget(SaDeliveryWin);
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
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        headGridLayout->addWidget(label_5, 2, 6, 1, 1);

        phoneEdit = new QLineEdit(frame_2);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(phoneEdit, 2, 7, 1, 1);

        whSearchEditbox = new QkSearchEditBox(frame_2);
        whSearchEditbox->setObjectName(QString::fromUtf8("whSearchEditbox"));

        headGridLayout->addWidget(whSearchEditbox, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer, 1, 11, 1, 1);

        idLabel = new QLabel(frame_2);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idLabel->sizePolicy().hasHeightForWidth());
        idLabel->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(idLabel, 0, 0, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_2, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_5, 0, 8, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_4, 0, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        headGridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        cusSearchEditbox = new QkSearchEditBox(frame_2);
        cusSearchEditbox->setObjectName(QString::fromUtf8("cusSearchEditbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cusSearchEditbox->sizePolicy().hasHeightForWidth());
        cusSearchEditbox->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(cusSearchEditbox, 0, 10, 1, 2);

        dateEdit = new QDateEdit(frame_2);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy3);
        dateEdit->setCalendarPopup(true);

        headGridLayout->addWidget(dateEdit, 0, 4, 1, 1);

        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        headGridLayout->addWidget(label_9, 3, 0, 1, 1);

        memoEdit = new QLineEdit(frame_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        headGridLayout->addWidget(memoEdit, 3, 1, 1, 4);

        noEdit = new QLineEdit(frame_2);
        noEdit->setObjectName(QString::fromUtf8("noEdit"));
        sizePolicy.setHeightForWidth(noEdit->sizePolicy().hasHeightForWidth());
        noEdit->setSizePolicy(sizePolicy);
        noEdit->setDragEnabled(true);
        noEdit->setReadOnly(true);

        headGridLayout->addWidget(noEdit, 0, 1, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        headGridLayout->addWidget(label, 1, 0, 1, 1);

        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_6, 1, 6, 1, 1);

        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy1.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_12, 1, 9, 1, 1);

        busTypeComboBox = new QComboBox(frame_2);
        busTypeComboBox->setObjectName(QString::fromUtf8("busTypeComboBox"));
        sizePolicy2.setHeightForWidth(busTypeComboBox->sizePolicy().hasHeightForWidth());
        busTypeComboBox->setSizePolicy(sizePolicy2);

        headGridLayout->addWidget(busTypeComboBox, 1, 1, 1, 1);

        depSearchEditbox = new QkSearchEditBox(frame_2);
        depSearchEditbox->setObjectName(QString::fromUtf8("depSearchEditbox"));
        sizePolicy3.setHeightForWidth(depSearchEditbox->sizePolicy().hasHeightForWidth());
        depSearchEditbox->setSizePolicy(sizePolicy3);

        headGridLayout->addWidget(depSearchEditbox, 1, 7, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        headGridLayout->addWidget(label_3, 0, 9, 1, 1);

        userSearchEditbox = new QkSearchEditBox(frame_2);
        userSearchEditbox->setObjectName(QString::fromUtf8("userSearchEditbox"));
        sizePolicy.setHeightForWidth(userSearchEditbox->sizePolicy().hasHeightForWidth());
        userSearchEditbox->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(userSearchEditbox, 1, 10, 1, 1);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        headGridLayout->addWidget(label_7, 0, 6, 1, 1);

        makerEdit = new QLineEdit(frame_2);
        makerEdit->setObjectName(QString::fromUtf8("makerEdit"));
        sizePolicy.setHeightForWidth(makerEdit->sizePolicy().hasHeightForWidth());
        makerEdit->setSizePolicy(sizePolicy);
        makerEdit->setReadOnly(true);

        headGridLayout->addWidget(makerEdit, 3, 7, 1, 1);

        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        headGridLayout->addWidget(label_8, 3, 6, 1, 1);

        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        headGridLayout->addWidget(label_10, 3, 9, 1, 1);

        auditEdit = new QLineEdit(frame_2);
        auditEdit->setObjectName(QString::fromUtf8("auditEdit"));
        sizePolicy.setHeightForWidth(auditEdit->sizePolicy().hasHeightForWidth());
        auditEdit->setSizePolicy(sizePolicy);
        auditEdit->setReadOnly(true);

        headGridLayout->addWidget(auditEdit, 3, 10, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        headGridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        headGridLayout->addWidget(label_11, 1, 3, 1, 1);

        linkEdit = new QLineEdit(frame_2);
        linkEdit->setObjectName(QString::fromUtf8("linkEdit"));
        sizePolicy.setHeightForWidth(linkEdit->sizePolicy().hasHeightForWidth());
        linkEdit->setSizePolicy(sizePolicy);

        headGridLayout->addWidget(linkEdit, 1, 4, 1, 1);

        addressEdit = new QLineEdit(frame_2);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));

        headGridLayout->addWidget(addressEdit, 2, 1, 1, 4);


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

        SaDeliveryWin->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SaDeliveryWin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SaDeliveryWin->setStatusBar(statusbar);
        toolBar = new QToolBar(SaDeliveryWin);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        SaDeliveryWin->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(noEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, whSearchEditbox);
        QWidget::setTabOrder(whSearchEditbox, cusSearchEditbox);
        QWidget::setTabOrder(cusSearchEditbox, busTypeComboBox);
        QWidget::setTabOrder(busTypeComboBox, linkEdit);
        QWidget::setTabOrder(linkEdit, depSearchEditbox);
        QWidget::setTabOrder(depSearchEditbox, userSearchEditbox);
        QWidget::setTabOrder(userSearchEditbox, addressEdit);
        QWidget::setTabOrder(addressEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, memoEdit);
        QWidget::setTabOrder(memoEdit, makerEdit);
        QWidget::setTabOrder(makerEdit, auditEdit);
        QWidget::setTabOrder(auditEdit, tableWidget);

        retranslateUi(SaDeliveryWin);

        QMetaObject::connectSlotsByName(SaDeliveryWin);
    } // setupUi

    void retranslateUi(QMainWindow *SaDeliveryWin)
    {
        SaDeliveryWin->setWindowTitle(QApplication::translate("SaDeliveryWin", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SaDeliveryWin", "\351\224\200\345\224\256\345\217\221\350\264\247\345\215\225", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SaDeliveryWin", "\350\201\224\347\263\273\347\224\265\350\257\235:", 0, QApplication::UnicodeUTF8));
        idLabel->setText(QApplication::translate("SaDeliveryWin", "\345\217\221\350\264\247\345\215\225\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SaDeliveryWin", "\345\217\221\350\264\247\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SaDeliveryWin", "\345\244\207    \346\263\250:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SaDeliveryWin", "\351\224\200\345\224\256\347\261\273\345\236\213:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SaDeliveryWin", "\344\270\232\345\212\241\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SaDeliveryWin", "\344\270\232 \345\212\241 \345\221\230:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SaDeliveryWin", "\345\256\242    \346\210\267:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SaDeliveryWin", "\345\207\272\345\272\223\344\273\223\345\272\223:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SaDeliveryWin", "\345\210\266 \345\215\225 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("SaDeliveryWin", "\345\256\241 \346\240\270 \344\272\272:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SaDeliveryWin", "\345\217\221\350\264\247\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SaDeliveryWin", "\350\201\224 \347\263\273 \344\272\272;", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SaDeliveryWin", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaDeliveryWin: public Ui_SaDeliveryWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SADELIVERYWIN_H
