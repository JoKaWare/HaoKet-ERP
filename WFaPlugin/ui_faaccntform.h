/********************************************************************************
** Form generated from reading UI file 'faaccntform.ui'
**
** Created: Fri Nov 6 10:54:55 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAACCNTFORM_H
#define UI_FAACCNTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaAccntForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *AccntMonthLabel;
    QLabel *label_6;
    QLabel *label;
    QToolButton *cancelBtn;
    QToolButton *queryBtn;
    QLabel *ACCNTLabel;
    QDateEdit *dateEdit;
    QLabel *label_2;
    QDateEdit *dateEdit1;
    QToolButton *AccntBtn;
    QLabel *noteLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPrompt;
    QToolButton *AccntCancelBtn;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;

    void setupUi(QWidget *FaAccntForm)
    {
        if (FaAccntForm->objectName().isEmpty())
            FaAccntForm->setObjectName(QString::fromUtf8("FaAccntForm"));
        FaAccntForm->resize(838, 486);
        verticalLayout_3 = new QVBoxLayout(FaAccntForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(FaAccntForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        AccntMonthLabel = new QLabel(groupBox);
        AccntMonthLabel->setObjectName(QString::fromUtf8("AccntMonthLabel"));

        gridLayout->addWidget(AccntMonthLabel, 1, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cancelBtn = new QToolButton(groupBox);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setIconSize(QSize(24, 24));

        gridLayout->addWidget(cancelBtn, 0, 10, 1, 1);

        queryBtn = new QToolButton(groupBox);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));
        queryBtn->setIconSize(QSize(24, 24));

        gridLayout->addWidget(queryBtn, 0, 9, 1, 1);

        ACCNTLabel = new QLabel(groupBox);
        ACCNTLabel->setObjectName(QString::fromUtf8("ACCNTLabel"));

        gridLayout->addWidget(ACCNTLabel, 1, 1, 1, 1);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        dateEdit1 = new QDateEdit(groupBox);
        dateEdit1->setObjectName(QString::fromUtf8("dateEdit1"));
        dateEdit1->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit1, 0, 3, 1, 1);

        AccntBtn = new QToolButton(groupBox);
        AccntBtn->setObjectName(QString::fromUtf8("AccntBtn"));
        AccntBtn->setIconSize(QSize(24, 24));

        gridLayout->addWidget(AccntBtn, 0, 4, 1, 1);

        noteLabel = new QLabel(groupBox);
        noteLabel->setObjectName(QString::fromUtf8("noteLabel"));

        gridLayout->addWidget(noteLabel, 1, 4, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 7, 1, 1);

        labelPrompt = new QLabel(groupBox);
        labelPrompt->setObjectName(QString::fromUtf8("labelPrompt"));

        gridLayout->addWidget(labelPrompt, 0, 6, 1, 1);

        AccntCancelBtn = new QToolButton(groupBox);
        AccntCancelBtn->setObjectName(QString::fromUtf8("AccntCancelBtn"));
        AccntCancelBtn->setIconSize(QSize(24, 24));

        gridLayout->addWidget(AccntCancelBtn, 0, 5, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_3->addWidget(groupBox);

        tabWidget = new QTabWidget(FaAccntForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout_2->addWidget(tableView);

        tabWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(FaAccntForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FaAccntForm);
    } // setupUi

    void retranslateUi(QWidget *FaAccntForm)
    {
        FaAccntForm->setWindowTitle(QApplication::translate("FaAccntForm", "\345\215\225\346\215\256\350\256\260\345\270\220", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("FaAccntForm", "\350\256\241\344\273\267\346\226\271\345\274\217:", 0, QApplication::UnicodeUTF8));
        AccntMonthLabel->setText(QString());
        label_6->setText(QApplication::translate("FaAccntForm", "\350\256\260\345\270\220\346\234\210\344\273\275:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FaAccntForm", "\345\274\200\345\247\213\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("FaAccntForm", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        queryBtn->setText(QApplication::translate("FaAccntForm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        ACCNTLabel->setText(QApplication::translate("FaAccntForm", "<html><head/><body><p><span style=\" font-weight:600; color:#ff0000;\">\345\205\210\350\277\233\345\205\210\345\207\272\346\263\225</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FaAccntForm", "\347\273\223\346\235\237\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        AccntBtn->setText(QApplication::translate("FaAccntForm", "\350\256\260\345\270\220", 0, QApplication::UnicodeUTF8));
        noteLabel->setText(QApplication::translate("FaAccntForm", "-", 0, QApplication::UnicodeUTF8));
        labelPrompt->setText(QApplication::translate("FaAccntForm", "<html><head/><body><p><span style=\" font-weight:600; color:#ff0000;\">\346\263\250\346\204\217\357\274\232\350\256\260\345\270\220\345\211\215\357\274\214\350\257\267\347\241\256\344\277\235\345\205\266\344\273\226\347\224\250\346\210\267\345\267\262\351\200\200\345\207\272\347\263\273\347\273\237\343\200\202</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        AccntCancelBtn->setText(QApplication::translate("FaAccntForm", "\345\217\226\346\266\210\350\256\260\345\270\220", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("FaAccntForm", "\346\234\252\350\256\260\345\270\220\345\215\225\346\215\256\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FaAccntForm: public Ui_FaAccntForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAACCNTFORM_H
