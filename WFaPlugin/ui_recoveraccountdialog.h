/********************************************************************************
** Form generated from reading UI file 'recoveraccountdialog.ui'
**
** Created: Fri Nov 6 10:54:55 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOVERACCOUNTDIALOG_H
#define UI_RECOVERACCOUNTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RecoverAccountDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *infoLabel;
    QLabel *label;
    QLabel *noteLabel;
    QLabel *endLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *okBtn;
    QToolButton *cancelBtn;

    void setupUi(QDialog *RecoverAccountDialog)
    {
        if (RecoverAccountDialog->objectName().isEmpty())
            RecoverAccountDialog->setObjectName(QString::fromUtf8("RecoverAccountDialog"));
        RecoverAccountDialog->resize(477, 196);
        verticalLayout_2 = new QVBoxLayout(RecoverAccountDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(RecoverAccountDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoLabel = new QLabel(groupBox);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setTextFormat(Qt::AutoText);
        infoLabel->setWordWrap(true);

        verticalLayout->addWidget(infoLabel);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        noteLabel = new QLabel(groupBox);
        noteLabel->setObjectName(QString::fromUtf8("noteLabel"));

        verticalLayout->addWidget(noteLabel);

        endLabel = new QLabel(groupBox);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));

        verticalLayout->addWidget(endLabel);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okBtn = new QToolButton(RecoverAccountDialog);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(okBtn);

        cancelBtn = new QToolButton(RecoverAccountDialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(cancelBtn);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(RecoverAccountDialog);

        QMetaObject::connectSlotsByName(RecoverAccountDialog);
    } // setupUi

    void retranslateUi(QDialog *RecoverAccountDialog)
    {
        RecoverAccountDialog->setWindowTitle(QApplication::translate("RecoverAccountDialog", "\346\201\242\345\244\215\350\256\260\345\270\220", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RecoverAccountDialog", "\346\201\242\345\244\215\350\256\260\345\270\220", 0, QApplication::UnicodeUTF8));
        infoLabel->setText(QApplication::translate("RecoverAccountDialog", "<html><head/><body><p><span style=\" color:#000000;\">\346\263\250\346\204\217\357\274\232\346\201\242\345\244\215\350\256\260\345\270\220\345\277\205\351\241\273\351\200\206\345\220\221\346\223\215\344\275\234\357\274\214\345\257\271\344\272\216\347\247\273\345\212\250\345\271\263\345\235\207\343\200\201\345\205\210\350\277\233\345\205\210\345\207\272\346\240\270\347\256\227\347\232\204\346\226\271\345\274\217\344\270\213\357\274\214\347\224\261\344\272\216\346\240\270\347\256\227\346\226\271\345\274\217\344\270\216\350\256\260\350\264\246\350\241\214\350\256\260\345\275\225\347\232\204\345\205\210\345\220\216\351\241\272\345\272\217\346\234\211\345\205\263\357\274\214\345\246\202\346\236\234\345\215\225\347\213\254\346\201\242\345\244\215\345\205\266\344\270\255\346\237\220\344\270\252\350\241\214\350\256\260\345\275\225\346\227\266\357\274\214\346\230\223\351\200\240\346\210\220\346\225\260\346\215\256\351\224\231\350\257\257\357\274\214\346\211\200\344\273\245\347\263\273\347\273\237\344\270\215\345\205\201"
                        "\350\256\270\345\215\225\347\213\254\346\201\242\345\244\215\344\270\255\351\227\264\347\232\204\346\237\220\350\241\214\350\256\260\345\275\225\357\274\214\345\272\224\346\214\211\350\256\260\350\264\246\351\241\272\345\272\217\344\273\216\345\220\216\345\220\221\345\211\215\346\201\242\345\244\215</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RecoverAccountDialog", "\345\275\223\345\211\215\350\256\260\345\270\220\346\234\210:", 0, QApplication::UnicodeUTF8));
        noteLabel->setText(QString());
        endLabel->setText(QString());
        okBtn->setText(QApplication::translate("RecoverAccountDialog", "\346\201\242\345\244\215", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("RecoverAccountDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RecoverAccountDialog: public Ui_RecoverAccountDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOVERACCOUNTDIALOG_H
