/********************************************************************************
** Form generated from reading UI file 'languagedlg.ui'
**
** Created: Thu Jul 10 16:17:56 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANGUAGEDLG_H
#define UI_LANGUAGEDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LanguageDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *lblLanguage;
    QComboBox *cmbLanguage;
    QGridLayout *gridLayout;
    QPushButton *btnCancel;
    QPushButton *btnOk;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *LanguageDlg)
    {
        if (LanguageDlg->objectName().isEmpty())
            LanguageDlg->setObjectName(QString::fromUtf8("LanguageDlg"));
        LanguageDlg->resize(374, 107);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/applications-education-language.png"), QSize(), QIcon::Normal, QIcon::Off);
        LanguageDlg->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(LanguageDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(LanguageDlg);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lblLanguage = new QLabel(LanguageDlg);
        lblLanguage->setObjectName(QString::fromUtf8("lblLanguage"));

        gridLayout_2->addWidget(lblLanguage, 0, 0, 1, 1);

        cmbLanguage = new QComboBox(LanguageDlg);
        cmbLanguage->setObjectName(QString::fromUtf8("cmbLanguage"));

        gridLayout_2->addWidget(cmbLanguage, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnCancel = new QPushButton(LanguageDlg);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 0, 2, 1, 1);

        btnOk = new QPushButton(LanguageDlg);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout->addWidget(btnOk, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(LanguageDlg);

        QMetaObject::connectSlotsByName(LanguageDlg);
    } // setupUi

    void retranslateUi(QDialog *LanguageDlg)
    {
        LanguageDlg->setWindowTitle(QApplication::translate("LanguageDlg", "Language", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LanguageDlg", "Please choose the language which should be used for this application.", 0, QApplication::UnicodeUTF8));
        lblLanguage->setText(QApplication::translate("LanguageDlg", "Language:", 0, QApplication::UnicodeUTF8));
        cmbLanguage->clear();
        cmbLanguage->insertItems(0, QStringList()
         << QApplication::translate("LanguageDlg", "System Default", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LanguageDlg", "American English", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LanguageDlg", "Russian", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LanguageDlg", "Serbian", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LanguageDlg", "Serbian Latin", 0, QApplication::UnicodeUTF8)
        );
        btnCancel->setText(QApplication::translate("LanguageDlg", "Cancel", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("LanguageDlg", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LanguageDlg: public Ui_LanguageDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANGUAGEDLG_H
