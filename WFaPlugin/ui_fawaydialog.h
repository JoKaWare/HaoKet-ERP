/********************************************************************************
** Form generated from reading UI file 'fawaydialog.ui'
**
** Created: Fri Nov 6 10:54:55 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAWAYDIALOG_H
#define UI_FAWAYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FaWayDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *rBtn1;
    QRadioButton *rBtn2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *okBtn;
    QToolButton *cancelBtn;

    void setupUi(QDialog *FaWayDialog)
    {
        if (FaWayDialog->objectName().isEmpty())
            FaWayDialog->setObjectName(QString::fromUtf8("FaWayDialog"));
        FaWayDialog->resize(445, 145);
        verticalLayout_2 = new QVBoxLayout(FaWayDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(FaWayDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rBtn1 = new QRadioButton(groupBox);
        rBtn1->setObjectName(QString::fromUtf8("rBtn1"));
        rBtn1->setChecked(true);

        verticalLayout->addWidget(rBtn1);

        rBtn2 = new QRadioButton(groupBox);
        rBtn2->setObjectName(QString::fromUtf8("rBtn2"));

        verticalLayout->addWidget(rBtn2);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QToolButton(FaWayDialog);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QToolButton(FaWayDialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(FaWayDialog);

        QMetaObject::connectSlotsByName(FaWayDialog);
    } // setupUi

    void retranslateUi(QDialog *FaWayDialog)
    {
        FaWayDialog->setWindowTitle(QApplication::translate("FaWayDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FaWayDialog", "\346\210\220\346\234\254\346\240\270\347\256\227\350\256\241\344\273\267\346\226\271\345\274\217", 0, QApplication::UnicodeUTF8));
        rBtn1->setText(QApplication::translate("FaWayDialog", "\345\205\210\350\277\233\345\205\210\345\207\272", 0, QApplication::UnicodeUTF8));
        rBtn2->setText(QApplication::translate("FaWayDialog", "\347\247\273\345\212\250\345\271\263\345\235\207", 0, QApplication::UnicodeUTF8));
        okBtn->setText(QApplication::translate("FaWayDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("FaWayDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FaWayDialog: public Ui_FaWayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAWAYDIALOG_H
