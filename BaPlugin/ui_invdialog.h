/********************************************************************************
** Form generated from reading UI file 'invdialog.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVDIALOG_H
#define UI_INVDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_InvDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *unitLabel2;
    QComboBox *pUnitComboBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *styleLabel;
    QLabel *mPricelabel3;
    QSpinBox *topSumSpinBox;
    QkSearchEditBox *typeQkSearchEditbox;
    QLineEdit *styleEdit;
    QLabel *typeLabel;
    QLabel *nameLabel;
    QLabel *lowLabel;
    QLineEdit *nameEdit;
    QSpinBox *lowSumSpinBox;
    QPushButton *uCodeButton;
    QLabel *priceLabel;
    QLabel *codeLabel;
    QLineEdit *codeEdit;
    QDoubleSpinBox *mPriceSpinBox;
    QLabel *label_7;
    QLineEdit *memoEdit;
    QLabel *pinyinLabel;
    QLineEdit *pinyinEdit;
    QLabel *assistedLabel;
    QLineEdit *assistedEdit;
    QLabel *label;
    QCheckBox *isImeiChk;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QCheckBox *sDownCheckBox;
    QCheckBox *sConCheckBox;
    QCheckBox *sPucgaseCheckBox;
    QCheckBox *wConfCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *saleCheckBox;
    QCheckBox *purchaseCheckBox;
    QCheckBox *comsumeCheckBox;

    void setupUi(QDialog *InvDialog)
    {
        if (InvDialog->objectName().isEmpty())
            InvDialog->setObjectName(QString::fromUtf8("InvDialog"));
        InvDialog->resize(709, 421);
        verticalLayout_2 = new QVBoxLayout(InvDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(InvDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(630, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addButton = new QPushButton(frame);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 32));
        addButton->setAutoDefault(true);

        horizontalLayout_2->addWidget(addButton);

        saveButton = new QPushButton(frame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(32, 32));
        saveButton->setAutoDefault(true);

        horizontalLayout_2->addWidget(saveButton);

        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setIconSize(QSize(32, 32));
        cancelButton->setAutoDefault(true);

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout_2->addWidget(frame);

        groupBox = new QGroupBox(InvDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        unitLabel2 = new QLabel(groupBox);
        unitLabel2->setObjectName(QString::fromUtf8("unitLabel2"));
        unitLabel2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(unitLabel2, 4, 0, 1, 1);

        pUnitComboBox = new QComboBox(groupBox);
        pUnitComboBox->setObjectName(QString::fromUtf8("pUnitComboBox"));

        gridLayout->addWidget(pUnitComboBox, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        styleLabel = new QLabel(groupBox);
        styleLabel->setObjectName(QString::fromUtf8("styleLabel"));
        styleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(styleLabel, 3, 3, 1, 1);

        mPricelabel3 = new QLabel(groupBox);
        mPricelabel3->setObjectName(QString::fromUtf8("mPricelabel3"));
        mPricelabel3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(mPricelabel3, 6, 3, 1, 1);

        topSumSpinBox = new QSpinBox(groupBox);
        topSumSpinBox->setObjectName(QString::fromUtf8("topSumSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topSumSpinBox->sizePolicy().hasHeightForWidth());
        topSumSpinBox->setSizePolicy(sizePolicy1);
        topSumSpinBox->setMaximum(999999);

        gridLayout->addWidget(topSumSpinBox, 6, 4, 1, 1);

        typeQkSearchEditbox = new QkSearchEditBox(groupBox);
        typeQkSearchEditbox->setObjectName(QString::fromUtf8("typeQkSearchEditbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(typeQkSearchEditbox->sizePolicy().hasHeightForWidth());
        typeQkSearchEditbox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(typeQkSearchEditbox, 3, 1, 1, 1);

        styleEdit = new QLineEdit(groupBox);
        styleEdit->setObjectName(QString::fromUtf8("styleEdit"));
        sizePolicy1.setHeightForWidth(styleEdit->sizePolicy().hasHeightForWidth());
        styleEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(styleEdit, 3, 4, 1, 1);

        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(typeLabel, 3, 0, 1, 1);

        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        lowLabel = new QLabel(groupBox);
        lowLabel->setObjectName(QString::fromUtf8("lowLabel"));
        lowLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lowLabel, 6, 0, 1, 1);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 1, 1, 1, 4);

        lowSumSpinBox = new QSpinBox(groupBox);
        lowSumSpinBox->setObjectName(QString::fromUtf8("lowSumSpinBox"));
        sizePolicy1.setHeightForWidth(lowSumSpinBox->sizePolicy().hasHeightForWidth());
        lowSumSpinBox->setSizePolicy(sizePolicy1);
        lowSumSpinBox->setMaximum(999999);

        gridLayout->addWidget(lowSumSpinBox, 6, 1, 1, 1);

        uCodeButton = new QPushButton(groupBox);
        uCodeButton->setObjectName(QString::fromUtf8("uCodeButton"));
        sizePolicy1.setHeightForWidth(uCodeButton->sizePolicy().hasHeightForWidth());
        uCodeButton->setSizePolicy(sizePolicy1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        uCodeButton->setIcon(icon3);

        gridLayout->addWidget(uCodeButton, 0, 2, 1, 1);

        priceLabel = new QLabel(groupBox);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));
        priceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(priceLabel, 5, 0, 1, 1);

        codeLabel = new QLabel(groupBox);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        codeEdit = new QLineEdit(groupBox);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy1.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        mPriceSpinBox = new QDoubleSpinBox(groupBox);
        mPriceSpinBox->setObjectName(QString::fromUtf8("mPriceSpinBox"));
        sizePolicy1.setHeightForWidth(mPriceSpinBox->sizePolicy().hasHeightForWidth());
        mPriceSpinBox->setSizePolicy(sizePolicy1);
        mPriceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mPriceSpinBox->setMaximum(1e+06);

        gridLayout->addWidget(mPriceSpinBox, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        memoEdit = new QLineEdit(groupBox);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(memoEdit->sizePolicy().hasHeightForWidth());
        memoEdit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(memoEdit, 7, 1, 1, 4);

        pinyinLabel = new QLabel(groupBox);
        pinyinLabel->setObjectName(QString::fromUtf8("pinyinLabel"));
        pinyinLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pinyinLabel, 2, 0, 1, 1);

        pinyinEdit = new QLineEdit(groupBox);
        pinyinEdit->setObjectName(QString::fromUtf8("pinyinEdit"));
        sizePolicy1.setHeightForWidth(pinyinEdit->sizePolicy().hasHeightForWidth());
        pinyinEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pinyinEdit, 2, 1, 1, 1);

        assistedLabel = new QLabel(groupBox);
        assistedLabel->setObjectName(QString::fromUtf8("assistedLabel"));
        assistedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(assistedLabel, 2, 3, 1, 1);

        assistedEdit = new QLineEdit(groupBox);
        assistedEdit->setObjectName(QString::fromUtf8("assistedEdit"));
        sizePolicy1.setHeightForWidth(assistedEdit->sizePolicy().hasHeightForWidth());
        assistedEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(assistedEdit, 2, 4, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 5, 3, 1, 1);

        isImeiChk = new QCheckBox(groupBox);
        isImeiChk->setObjectName(QString::fromUtf8("isImeiChk"));

        gridLayout->addWidget(isImeiChk, 5, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(InvDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sDownCheckBox = new QCheckBox(groupBox_2);
        sDownCheckBox->setObjectName(QString::fromUtf8("sDownCheckBox"));

        gridLayout_2->addWidget(sDownCheckBox, 0, 1, 1, 1);

        sConCheckBox = new QCheckBox(groupBox_2);
        sConCheckBox->setObjectName(QString::fromUtf8("sConCheckBox"));

        gridLayout_2->addWidget(sConCheckBox, 0, 2, 1, 1);

        sPucgaseCheckBox = new QCheckBox(groupBox_2);
        sPucgaseCheckBox->setObjectName(QString::fromUtf8("sPucgaseCheckBox"));

        gridLayout_2->addWidget(sPucgaseCheckBox, 0, 0, 1, 1);

        wConfCheckBox = new QCheckBox(groupBox_2);
        wConfCheckBox->setObjectName(QString::fromUtf8("wConfCheckBox"));

        gridLayout_2->addWidget(wConfCheckBox, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        saleCheckBox = new QCheckBox(groupBox_2);
        saleCheckBox->setObjectName(QString::fromUtf8("saleCheckBox"));

        gridLayout_2->addWidget(saleCheckBox, 1, 0, 1, 1);

        purchaseCheckBox = new QCheckBox(groupBox_2);
        purchaseCheckBox->setObjectName(QString::fromUtf8("purchaseCheckBox"));

        gridLayout_2->addWidget(purchaseCheckBox, 1, 1, 1, 1);

        comsumeCheckBox = new QCheckBox(groupBox_2);
        comsumeCheckBox->setObjectName(QString::fromUtf8("comsumeCheckBox"));

        gridLayout_2->addWidget(comsumeCheckBox, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        verticalLayout_2->addWidget(groupBox_2);


        retranslateUi(InvDialog);

        QMetaObject::connectSlotsByName(InvDialog);
    } // setupUi

    void retranslateUi(QDialog *InvDialog)
    {
        InvDialog->setWindowTitle(QApplication::translate("InvDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("InvDialog", "Add", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("InvDialog", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("InvDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("InvDialog", "Base Info", 0, QApplication::UnicodeUTF8));
        unitLabel2->setText(QApplication::translate("InvDialog", "Unit:", 0, QApplication::UnicodeUTF8));
        styleLabel->setText(QApplication::translate("InvDialog", "Style:", 0, QApplication::UnicodeUTF8));
        mPricelabel3->setText(QApplication::translate("InvDialog", "Top Sum:", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("InvDialog", "Product Type:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("InvDialog", "Product Name:", 0, QApplication::UnicodeUTF8));
        lowLabel->setText(QApplication::translate("InvDialog", "Low Sum:", 0, QApplication::UnicodeUTF8));
        uCodeButton->setText(QString());
        priceLabel->setText(QApplication::translate("InvDialog", "Puchase Price:", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("InvDialog", "Product Code:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("InvDialog", "         Memo:", 0, QApplication::UnicodeUTF8));
        pinyinLabel->setText(QApplication::translate("InvDialog", "Pinyin Code:", 0, QApplication::UnicodeUTF8));
        assistedLabel->setText(QApplication::translate("InvDialog", "Assisted Code:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InvDialog", "Is Imei:", 0, QApplication::UnicodeUTF8));
        isImeiChk->setText(QString());
        groupBox_2->setTitle(QApplication::translate("InvDialog", "Option", 0, QApplication::UnicodeUTF8));
        sDownCheckBox->setText(QApplication::translate("InvDialog", "Is Shop Down", 0, QApplication::UnicodeUTF8));
        sConCheckBox->setText(QApplication::translate("InvDialog", "Is Sale Consumption", 0, QApplication::UnicodeUTF8));
        sPucgaseCheckBox->setText(QApplication::translate("InvDialog", "Is Shop Pucgase", 0, QApplication::UnicodeUTF8));
        wConfCheckBox->setText(QApplication::translate("InvDialog", "Is Weighing Conf", 0, QApplication::UnicodeUTF8));
        saleCheckBox->setText(QApplication::translate("InvDialog", "Is Sale", 0, QApplication::UnicodeUTF8));
        purchaseCheckBox->setText(QApplication::translate("InvDialog", "Is Purchase", 0, QApplication::UnicodeUTF8));
        comsumeCheckBox->setText(QApplication::translate("InvDialog", "Is Comsume", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InvDialog: public Ui_InvDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVDIALOG_H
