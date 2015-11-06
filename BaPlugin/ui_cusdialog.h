/********************************************************************************
** Form generated from reading UI file 'cusdialog.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSDIALOG_H
#define UI_CUSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_CusDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_11;
    QkSearchEditBox *typeQkSearchEditbox;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_12;
    QLabel *label_13;
    QDateEdit *devDateEdit;
    QkSearchEditBox *personQkSearchEditbox;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_10;
    QLineEdit *emailEdit;
    QLineEdit *faxEdit;
    QLineEdit *contactsEdit;
    QLineEdit *phoneEdit;
    QLineEdit *telEdit;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_9;
    QLineEdit *codeEdit;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *cusAliasEdit;
    QLineEdit *pinyinEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *cusNameEdit;
    QLabel *label_23;
    QLabel *label_15;
    QLabel *label_28;
    QLineEdit *cusAddressEdit;
    QCheckBox *isShopCheckBox;
    QPushButton *uCodeButton;
    QLineEdit *memoEdit;
    QLabel *label_29;
    QLineEdit *postEdit;
    QLabel *label_6;
    QLineEdit *areaCityEdit;
    QLabel *label_7;
    QLineEdit *tradeEdit;
    QLabel *label_30;
    QkSearchEditBox *depQks;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_25;
    QLineEdit *regCodeEdit;
    QLineEdit *accountEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_19;
    QLineEdit *bankEdit;
    QLabel *label_17;
    QLabel *label_20;
    QLineEdit *corporateEdit;
    QLabel *label_18;
    QLineEdit *creGradeEdit;
    QDoubleSpinBox *creLineSpinBox;
    QLabel *label_22;
    QDateEdit *sDteEdit;
    QSpinBox *creDateSpinBox;
    QLabel *label_27;
    QLabel *label_8;
    QDateEdit *eDateEdit;
    QLabel *label_26;
    QLabel *label_24;
    QLabel *label_21;
    QCheckBox *isCreditCheckBox;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *addressEdit;

    void setupUi(QDialog *CusDialog)
    {
        if (CusDialog->objectName().isEmpty())
            CusDialog->setObjectName(QString::fromUtf8("CusDialog"));
        CusDialog->resize(668, 431);
        verticalLayout = new QVBoxLayout(CusDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(630, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addButton = new QPushButton(CusDialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 32));
        addButton->setAutoDefault(true);

        horizontalLayout->addWidget(addButton);

        saveButton = new QPushButton(CusDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(32, 32));
        saveButton->setAutoDefault(true);

        horizontalLayout->addWidget(saveButton);

        cancelButton = new QPushButton(CusDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setIconSize(QSize(32, 32));
        cancelButton->setAutoDefault(true);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(CusDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(8);
        gridLayout->setVerticalSpacing(6);
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 0, 4, 1, 1);

        typeQkSearchEditbox = new QkSearchEditBox(tab);
        typeQkSearchEditbox->setObjectName(QString::fromUtf8("typeQkSearchEditbox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(typeQkSearchEditbox->sizePolicy().hasHeightForWidth());
        typeQkSearchEditbox->setSizePolicy(sizePolicy);

        gridLayout->addWidget(typeQkSearchEditbox, 3, 1, 1, 1);

        label_16 = new QLabel(tab);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_16, 6, 4, 1, 1);

        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_14, 3, 4, 1, 1);

        label_12 = new QLabel(tab);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 1, 4, 1, 1);

        label_13 = new QLabel(tab);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_13, 2, 4, 1, 1);

        devDateEdit = new QDateEdit(tab);
        devDateEdit->setObjectName(QString::fromUtf8("devDateEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(devDateEdit->sizePolicy().hasHeightForWidth());
        devDateEdit->setSizePolicy(sizePolicy1);
        devDateEdit->setCalendarPopup(true);

        gridLayout->addWidget(devDateEdit, 8, 1, 1, 1);

        personQkSearchEditbox = new QkSearchEditBox(tab);
        personQkSearchEditbox->setObjectName(QString::fromUtf8("personQkSearchEditbox"));

        gridLayout->addWidget(personQkSearchEditbox, 6, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 8, 0, 1, 1);

        emailEdit = new QLineEdit(tab);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));

        gridLayout->addWidget(emailEdit, 4, 5, 1, 1);

        faxEdit = new QLineEdit(tab);
        faxEdit->setObjectName(QString::fromUtf8("faxEdit"));
        sizePolicy1.setHeightForWidth(faxEdit->sizePolicy().hasHeightForWidth());
        faxEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(faxEdit, 2, 5, 1, 1);

        contactsEdit = new QLineEdit(tab);
        contactsEdit->setObjectName(QString::fromUtf8("contactsEdit"));
        sizePolicy1.setHeightForWidth(contactsEdit->sizePolicy().hasHeightForWidth());
        contactsEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(contactsEdit, 0, 5, 1, 1);

        phoneEdit = new QLineEdit(tab);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        sizePolicy1.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(phoneEdit, 3, 5, 1, 1);

        telEdit = new QLineEdit(tab);
        telEdit->setObjectName(QString::fromUtf8("telEdit"));
        sizePolicy1.setHeightForWidth(telEdit->sizePolicy().hasHeightForWidth());
        telEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(telEdit, 1, 5, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 12, 0, 1, 1);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 11, 0, 1, 1);

        codeEdit = new QLineEdit(tab);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy1.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cusAliasEdit = new QLineEdit(tab);
        cusAliasEdit->setObjectName(QString::fromUtf8("cusAliasEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cusAliasEdit->sizePolicy().hasHeightForWidth());
        cusAliasEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(cusAliasEdit, 2, 1, 1, 1);

        pinyinEdit = new QLineEdit(tab);
        pinyinEdit->setObjectName(QString::fromUtf8("pinyinEdit"));
        sizePolicy3.setHeightForWidth(pinyinEdit->sizePolicy().hasHeightForWidth());
        pinyinEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pinyinEdit, 4, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        cusNameEdit = new QLineEdit(tab);
        cusNameEdit->setObjectName(QString::fromUtf8("cusNameEdit"));
        sizePolicy3.setHeightForWidth(cusNameEdit->sizePolicy().hasHeightForWidth());
        cusNameEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(cusNameEdit, 1, 1, 1, 1);

        label_23 = new QLabel(tab);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_23, 4, 4, 1, 1);

        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_15, 10, 0, 1, 1);

        label_28 = new QLabel(tab);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_28, 9, 0, 1, 1);

        cusAddressEdit = new QLineEdit(tab);
        cusAddressEdit->setObjectName(QString::fromUtf8("cusAddressEdit"));

        gridLayout->addWidget(cusAddressEdit, 10, 1, 1, 5);

        isShopCheckBox = new QCheckBox(tab);
        isShopCheckBox->setObjectName(QString::fromUtf8("isShopCheckBox"));

        gridLayout->addWidget(isShopCheckBox, 9, 1, 1, 1);

        uCodeButton = new QPushButton(tab);
        uCodeButton->setObjectName(QString::fromUtf8("uCodeButton"));
        sizePolicy1.setHeightForWidth(uCodeButton->sizePolicy().hasHeightForWidth());
        uCodeButton->setSizePolicy(sizePolicy1);
        uCodeButton->setFlat(false);

        gridLayout->addWidget(uCodeButton, 0, 2, 1, 1);

        memoEdit = new QLineEdit(tab);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));
        sizePolicy.setHeightForWidth(memoEdit->sizePolicy().hasHeightForWidth());
        memoEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(memoEdit, 11, 1, 1, 5);

        label_29 = new QLabel(tab);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_29, 5, 4, 1, 1);

        postEdit = new QLineEdit(tab);
        postEdit->setObjectName(QString::fromUtf8("postEdit"));
        sizePolicy1.setHeightForWidth(postEdit->sizePolicy().hasHeightForWidth());
        postEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(postEdit, 5, 5, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        areaCityEdit = new QLineEdit(tab);
        areaCityEdit->setObjectName(QString::fromUtf8("areaCityEdit"));
        sizePolicy3.setHeightForWidth(areaCityEdit->sizePolicy().hasHeightForWidth());
        areaCityEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(areaCityEdit, 5, 1, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        tradeEdit = new QLineEdit(tab);
        tradeEdit->setObjectName(QString::fromUtf8("tradeEdit"));

        gridLayout->addWidget(tradeEdit, 6, 1, 1, 1);

        label_30 = new QLabel(tab);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_30, 8, 4, 1, 1);

        depQks = new QkSearchEditBox(tab);
        depQks->setObjectName(QString::fromUtf8("depQks"));

        gridLayout->addWidget(depQks, 8, 5, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(8);
        label_25 = new QLabel(tab_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_25, 11, 0, 1, 1);

        regCodeEdit = new QLineEdit(tab_2);
        regCodeEdit->setObjectName(QString::fromUtf8("regCodeEdit"));
        sizePolicy1.setHeightForWidth(regCodeEdit->sizePolicy().hasHeightForWidth());
        regCodeEdit->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(regCodeEdit, 1, 1, 1, 1);

        accountEdit = new QLineEdit(tab_2);
        accountEdit->setObjectName(QString::fromUtf8("accountEdit"));

        gridLayout_2->addWidget(accountEdit, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_19, 2, 0, 1, 1);

        bankEdit = new QLineEdit(tab_2);
        bankEdit->setObjectName(QString::fromUtf8("bankEdit"));

        gridLayout_2->addWidget(bankEdit, 2, 1, 1, 1);

        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_17, 1, 0, 1, 1);

        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_20, 3, 0, 1, 1);

        corporateEdit = new QLineEdit(tab_2);
        corporateEdit->setObjectName(QString::fromUtf8("corporateEdit"));
        sizePolicy1.setHeightForWidth(corporateEdit->sizePolicy().hasHeightForWidth());
        corporateEdit->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(corporateEdit, 0, 1, 1, 1);

        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy4);
        label_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_18, 0, 0, 1, 1);

        creGradeEdit = new QLineEdit(tab_2);
        creGradeEdit->setObjectName(QString::fromUtf8("creGradeEdit"));

        gridLayout_2->addWidget(creGradeEdit, 9, 1, 1, 1);

        creLineSpinBox = new QDoubleSpinBox(tab_2);
        creLineSpinBox->setObjectName(QString::fromUtf8("creLineSpinBox"));
        sizePolicy1.setHeightForWidth(creLineSpinBox->sizePolicy().hasHeightForWidth());
        creLineSpinBox->setSizePolicy(sizePolicy1);
        creLineSpinBox->setMaximum(1e+08);

        gridLayout_2->addWidget(creLineSpinBox, 10, 1, 1, 1);

        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_22, 9, 0, 1, 1);

        sDteEdit = new QDateEdit(tab_2);
        sDteEdit->setObjectName(QString::fromUtf8("sDteEdit"));
        sizePolicy1.setHeightForWidth(sDteEdit->sizePolicy().hasHeightForWidth());
        sDteEdit->setSizePolicy(sizePolicy1);
        sDteEdit->setCalendarPopup(true);

        gridLayout_2->addWidget(sDteEdit, 4, 1, 1, 1);

        creDateSpinBox = new QSpinBox(tab_2);
        creDateSpinBox->setObjectName(QString::fromUtf8("creDateSpinBox"));
        sizePolicy1.setHeightForWidth(creDateSpinBox->sizePolicy().hasHeightForWidth());
        creDateSpinBox->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(creDateSpinBox, 11, 1, 1, 1);

        label_27 = new QLabel(tab_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_27, 4, 0, 1, 1);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8, 8, 0, 1, 1);

        eDateEdit = new QDateEdit(tab_2);
        eDateEdit->setObjectName(QString::fromUtf8("eDateEdit"));
        sizePolicy1.setHeightForWidth(eDateEdit->sizePolicy().hasHeightForWidth());
        eDateEdit->setSizePolicy(sizePolicy1);
        eDateEdit->setCalendarPopup(true);

        gridLayout_2->addWidget(eDateEdit, 5, 1, 1, 1);

        label_26 = new QLabel(tab_2);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        sizePolicy2.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy2);
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_26, 5, 0, 1, 1);

        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_24, 10, 0, 1, 1);

        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_21, 6, 0, 1, 1);

        isCreditCheckBox = new QCheckBox(tab_2);
        isCreditCheckBox->setObjectName(QString::fromUtf8("isCreditCheckBox"));

        gridLayout_2->addWidget(isCreditCheckBox, 8, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 12, 0, 1, 1);

        addressEdit = new QLineEdit(tab_2);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));

        gridLayout_2->addWidget(addressEdit, 6, 1, 1, 2);


        verticalLayout_3->addLayout(gridLayout_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        QWidget::setTabOrder(codeEdit, cusNameEdit);
        QWidget::setTabOrder(cusNameEdit, cusAliasEdit);
        QWidget::setTabOrder(cusAliasEdit, typeQkSearchEditbox);
        QWidget::setTabOrder(typeQkSearchEditbox, pinyinEdit);
        QWidget::setTabOrder(pinyinEdit, devDateEdit);
        QWidget::setTabOrder(devDateEdit, isShopCheckBox);
        QWidget::setTabOrder(isShopCheckBox, cusAddressEdit);
        QWidget::setTabOrder(cusAddressEdit, memoEdit);
        QWidget::setTabOrder(memoEdit, contactsEdit);
        QWidget::setTabOrder(contactsEdit, telEdit);
        QWidget::setTabOrder(telEdit, faxEdit);
        QWidget::setTabOrder(faxEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, emailEdit);
        QWidget::setTabOrder(emailEdit, postEdit);
        QWidget::setTabOrder(postEdit, personQkSearchEditbox);
        QWidget::setTabOrder(personQkSearchEditbox, corporateEdit);
        QWidget::setTabOrder(corporateEdit, regCodeEdit);
        QWidget::setTabOrder(regCodeEdit, bankEdit);
        QWidget::setTabOrder(bankEdit, accountEdit);
        QWidget::setTabOrder(accountEdit, sDteEdit);
        QWidget::setTabOrder(sDteEdit, eDateEdit);
        QWidget::setTabOrder(eDateEdit, addressEdit);
        QWidget::setTabOrder(addressEdit, isCreditCheckBox);
        QWidget::setTabOrder(isCreditCheckBox, creGradeEdit);
        QWidget::setTabOrder(creGradeEdit, creLineSpinBox);
        QWidget::setTabOrder(creLineSpinBox, creDateSpinBox);
        QWidget::setTabOrder(creDateSpinBox, tabWidget);
        QWidget::setTabOrder(tabWidget, uCodeButton);
        QWidget::setTabOrder(uCodeButton, cancelButton);
        QWidget::setTabOrder(cancelButton, addButton);
        QWidget::setTabOrder(addButton, saveButton);

        retranslateUi(CusDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CusDialog);
    } // setupUi

    void retranslateUi(QDialog *CusDialog)
    {
        CusDialog->setWindowTitle(QApplication::translate("CusDialog", "\345\256\242\346\210\267\350\265\204\346\226\231", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("CusDialog", "Add", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("CusDialog", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("CusDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CusDialog", "\350\201\224\347\263\273\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("CusDialog", "\344\270\223\347\256\241\344\270\232\345\212\241\345\221\230:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("CusDialog", "\350\201\224\347\263\273\346\211\213\346\234\272:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("CusDialog", "\350\201\224\347\263\273\347\224\265\350\257\235:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("CusDialog", "\344\274\240\347\234\237\345\217\267\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CusDialog", "\345\217\221\345\261\225\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CusDialog", "\346\213\274\351\237\263\347\274\226\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("CusDialog", "\345\244\207\346\263\250:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CusDialog", "\345\256\242\346\210\267\345\210\206\347\261\273:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CusDialog", "\345\256\242\346\210\267\347\274\226\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CusDialog", "\345\256\242\346\210\267\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CusDialog", "\345\256\242\346\210\267\345\210\253\345\220\215:", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("CusDialog", "EMail\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("CusDialog", "\345\217\221\350\264\247\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("CusDialog", "\346\230\257\345\220\246\351\227\250\345\272\227:", 0, QApplication::UnicodeUTF8));
        isShopCheckBox->setText(QString());
        uCodeButton->setText(QString());
        label_29->setText(QApplication::translate("CusDialog", "\351\202\256\346\224\277\347\274\226\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CusDialog", "\345\234\260\345\214\272:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CusDialog", "\346\211\200\345\261\236\350\241\214\344\270\232:", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("CusDialog", "\346\211\200\345\261\236\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("CusDialog", "\345\256\242\346\210\267\345\237\272\346\234\254\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("CusDialog", "\344\277\241\347\224\250\346\234\237\351\231\220(\345\244\251):", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("CusDialog", "\345\274\200\346\210\267\351\223\266\350\241\214:", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("CusDialog", "\347\272\263\347\250\216\344\272\272\347\231\273\350\256\260\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("CusDialog", "\351\223\266\350\241\214\350\264\246\345\217\267:", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("CusDialog", "\346\263\225\344\272\272:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("CusDialog", "\344\277\241\347\224\250\347\255\211\347\272\247:", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("CusDialog", "\350\220\245\344\270\232\346\211\247\347\205\247\345\210\260\346\234\237\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CusDialog", "\346\230\257\345\220\246\346\216\247\345\210\266\344\277\241\347\224\250\351\242\235\345\272\246:", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("CusDialog", "\350\220\245\344\270\232\346\211\247\347\205\247\347\224\237\346\225\210\346\227\245\346\234\237:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("CusDialog", "\344\277\241\347\224\250\351\242\235\345\272\246:", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("CusDialog", "\345\205\254\345\217\270\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        isCreditCheckBox->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("CusDialog", "\345\205\254\345\217\270/\344\277\241\347\224\250\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CusDialog: public Ui_CusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSDIALOG_H
