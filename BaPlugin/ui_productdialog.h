/********************************************************************************
** Form generated from reading UI file 'productdialog.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTDIALOG_H
#define UI_PRODUCTDIALOG_H

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

class Ui_ProductDialog
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
    QSpinBox *topSumSpinBox;
    QSpinBox *stDoSpinBox;
    QSpinBox *lowSumSpinBox;
    QLabel *priceLabel;
    QSpinBox *puStSpinBox;
    QLabel *codeLabel;
    QLabel *assistedLabel;
    QLabel *unitLabel2;
    QLabel *nameLabel;
    QLineEdit *codeEdit;
    QLineEdit *styleEdit;
    QLabel *lowLabel;
    QLabel *label_2;
    QLineEdit *pinyinEdit;
    QLineEdit *assistedEdit;
    QDoubleSpinBox *mPriceSpinBox;
    QLabel *styleLabel;
    QLabel *pinyinLabel;
    QLabel *mPricelabel3;
    QkSearchEditBox *typeQkSearchEditbox;
    QLabel *unitLabel3;
    QLabel *label;
    QLabel *typeLabel;
    QComboBox *pUnitComboBox;
    QComboBox *sUnitComboBox;
    QLabel *label_5;
    QLabel *unitLabel1;
    QLabel *label_3;
    QLabel *label_6;
    QComboBox *dUnitComboBox;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *uCodeButton;
    QLineEdit *nameEdit;
    QGridLayout *gridLayout_4;
    QLineEdit *memoEdit;
    QLabel *label_7;
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

    void setupUi(QDialog *ProductDialog)
    {
        if (ProductDialog->objectName().isEmpty())
            ProductDialog->setObjectName(QString::fromUtf8("ProductDialog"));
        ProductDialog->resize(790, 385);
        verticalLayout_2 = new QVBoxLayout(ProductDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(ProductDialog);
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

        groupBox = new QGroupBox(ProductDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        topSumSpinBox = new QSpinBox(groupBox);
        topSumSpinBox->setObjectName(QString::fromUtf8("topSumSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topSumSpinBox->sizePolicy().hasHeightForWidth());
        topSumSpinBox->setSizePolicy(sizePolicy1);
        topSumSpinBox->setMaximum(999999);

        gridLayout->addWidget(topSumSpinBox, 6, 6, 1, 1);

        stDoSpinBox = new QSpinBox(groupBox);
        stDoSpinBox->setObjectName(QString::fromUtf8("stDoSpinBox"));
        sizePolicy1.setHeightForWidth(stDoSpinBox->sizePolicy().hasHeightForWidth());
        stDoSpinBox->setSizePolicy(sizePolicy1);
        stDoSpinBox->setMaximum(999999);
        stDoSpinBox->setValue(1);

        gridLayout->addWidget(stDoSpinBox, 4, 4, 1, 1);

        lowSumSpinBox = new QSpinBox(groupBox);
        lowSumSpinBox->setObjectName(QString::fromUtf8("lowSumSpinBox"));
        sizePolicy1.setHeightForWidth(lowSumSpinBox->sizePolicy().hasHeightForWidth());
        lowSumSpinBox->setSizePolicy(sizePolicy1);
        lowSumSpinBox->setMaximum(999999);

        gridLayout->addWidget(lowSumSpinBox, 6, 4, 1, 1);

        priceLabel = new QLabel(groupBox);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));
        priceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(priceLabel, 6, 0, 1, 1);

        puStSpinBox = new QSpinBox(groupBox);
        puStSpinBox->setObjectName(QString::fromUtf8("puStSpinBox"));
        sizePolicy1.setHeightForWidth(puStSpinBox->sizePolicy().hasHeightForWidth());
        puStSpinBox->setSizePolicy(sizePolicy1);
        puStSpinBox->setMaximum(999999);
        puStSpinBox->setValue(1);

        gridLayout->addWidget(puStSpinBox, 3, 4, 1, 1);

        codeLabel = new QLabel(groupBox);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        assistedLabel = new QLabel(groupBox);
        assistedLabel->setObjectName(QString::fromUtf8("assistedLabel"));
        assistedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(assistedLabel, 1, 0, 1, 1);

        unitLabel2 = new QLabel(groupBox);
        unitLabel2->setObjectName(QString::fromUtf8("unitLabel2"));
        unitLabel2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(unitLabel2, 2, 0, 1, 1);

        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 0, 3, 1, 1);

        codeEdit = new QLineEdit(groupBox);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy1.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        styleEdit = new QLineEdit(groupBox);
        styleEdit->setObjectName(QString::fromUtf8("styleEdit"));
        sizePolicy1.setHeightForWidth(styleEdit->sizePolicy().hasHeightForWidth());
        styleEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(styleEdit, 1, 6, 1, 1);

        lowLabel = new QLabel(groupBox);
        lowLabel->setObjectName(QString::fromUtf8("lowLabel"));
        lowLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lowLabel, 6, 3, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        pinyinEdit = new QLineEdit(groupBox);
        pinyinEdit->setObjectName(QString::fromUtf8("pinyinEdit"));
        sizePolicy1.setHeightForWidth(pinyinEdit->sizePolicy().hasHeightForWidth());
        pinyinEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pinyinEdit, 0, 6, 1, 1);

        assistedEdit = new QLineEdit(groupBox);
        assistedEdit->setObjectName(QString::fromUtf8("assistedEdit"));
        sizePolicy1.setHeightForWidth(assistedEdit->sizePolicy().hasHeightForWidth());
        assistedEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(assistedEdit, 1, 1, 1, 1);

        mPriceSpinBox = new QDoubleSpinBox(groupBox);
        mPriceSpinBox->setObjectName(QString::fromUtf8("mPriceSpinBox"));
        sizePolicy1.setHeightForWidth(mPriceSpinBox->sizePolicy().hasHeightForWidth());
        mPriceSpinBox->setSizePolicy(sizePolicy1);
        mPriceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mPriceSpinBox->setMaximum(1e+06);

        gridLayout->addWidget(mPriceSpinBox, 6, 1, 1, 1);

        styleLabel = new QLabel(groupBox);
        styleLabel->setObjectName(QString::fromUtf8("styleLabel"));
        styleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(styleLabel, 1, 5, 1, 1);

        pinyinLabel = new QLabel(groupBox);
        pinyinLabel->setObjectName(QString::fromUtf8("pinyinLabel"));
        pinyinLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pinyinLabel, 0, 5, 1, 1);

        mPricelabel3 = new QLabel(groupBox);
        mPricelabel3->setObjectName(QString::fromUtf8("mPricelabel3"));
        mPricelabel3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(mPricelabel3, 6, 5, 1, 1);

        typeQkSearchEditbox = new QkSearchEditBox(groupBox);
        typeQkSearchEditbox->setObjectName(QString::fromUtf8("typeQkSearchEditbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(typeQkSearchEditbox->sizePolicy().hasHeightForWidth());
        typeQkSearchEditbox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(typeQkSearchEditbox, 1, 4, 1, 1);

        unitLabel3 = new QLabel(groupBox);
        unitLabel3->setObjectName(QString::fromUtf8("unitLabel3"));
        unitLabel3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(unitLabel3, 2, 3, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(typeLabel, 1, 3, 1, 1);

        pUnitComboBox = new QComboBox(groupBox);
        pUnitComboBox->setObjectName(QString::fromUtf8("pUnitComboBox"));

        gridLayout->addWidget(pUnitComboBox, 2, 1, 1, 1);

        sUnitComboBox = new QComboBox(groupBox);
        sUnitComboBox->setObjectName(QString::fromUtf8("sUnitComboBox"));

        gridLayout->addWidget(sUnitComboBox, 2, 4, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 3, 1, 1);

        unitLabel1 = new QLabel(groupBox);
        unitLabel1->setObjectName(QString::fromUtf8("unitLabel1"));
        unitLabel1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(unitLabel1, 2, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 3, 1, 1);

        dUnitComboBox = new QComboBox(groupBox);
        dUnitComboBox->setObjectName(QString::fromUtf8("dUnitComboBox"));

        gridLayout->addWidget(dUnitComboBox, 2, 6, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 7, 1, 1);

        uCodeButton = new QPushButton(groupBox);
        uCodeButton->setObjectName(QString::fromUtf8("uCodeButton"));
        sizePolicy1.setHeightForWidth(uCodeButton->sizePolicy().hasHeightForWidth());
        uCodeButton->setSizePolicy(sizePolicy1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        uCodeButton->setIcon(icon3);

        gridLayout->addWidget(uCodeButton, 0, 2, 1, 1);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        memoEdit = new QLineEdit(groupBox);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(memoEdit->sizePolicy().hasHeightForWidth());
        memoEdit->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(memoEdit, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy4);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ProductDialog);
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

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, pinyinEdit);
        QWidget::setTabOrder(pinyinEdit, assistedEdit);
        QWidget::setTabOrder(assistedEdit, typeQkSearchEditbox);
        QWidget::setTabOrder(typeQkSearchEditbox, styleEdit);
        QWidget::setTabOrder(styleEdit, pUnitComboBox);
        QWidget::setTabOrder(pUnitComboBox, sUnitComboBox);
        QWidget::setTabOrder(sUnitComboBox, dUnitComboBox);
        QWidget::setTabOrder(dUnitComboBox, puStSpinBox);
        QWidget::setTabOrder(puStSpinBox, stDoSpinBox);
        QWidget::setTabOrder(stDoSpinBox, mPriceSpinBox);
        QWidget::setTabOrder(mPriceSpinBox, lowSumSpinBox);
        QWidget::setTabOrder(lowSumSpinBox, topSumSpinBox);
        QWidget::setTabOrder(topSumSpinBox, memoEdit);
        QWidget::setTabOrder(memoEdit, sPucgaseCheckBox);
        QWidget::setTabOrder(sPucgaseCheckBox, sDownCheckBox);
        QWidget::setTabOrder(sDownCheckBox, sConCheckBox);
        QWidget::setTabOrder(sConCheckBox, wConfCheckBox);
        QWidget::setTabOrder(wConfCheckBox, saleCheckBox);
        QWidget::setTabOrder(saleCheckBox, purchaseCheckBox);
        QWidget::setTabOrder(purchaseCheckBox, comsumeCheckBox);
        QWidget::setTabOrder(comsumeCheckBox, cancelButton);
        QWidget::setTabOrder(cancelButton, addButton);
        QWidget::setTabOrder(addButton, uCodeButton);
        QWidget::setTabOrder(uCodeButton, saveButton);

        retranslateUi(ProductDialog);

        QMetaObject::connectSlotsByName(ProductDialog);
    } // setupUi

    void retranslateUi(QDialog *ProductDialog)
    {
        ProductDialog->setWindowTitle(QApplication::translate("ProductDialog", "\345\216\237\346\226\231\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("ProductDialog", "Add", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("ProductDialog", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("ProductDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ProductDialog", "Base Info", 0, QApplication::UnicodeUTF8));
        priceLabel->setText(QApplication::translate("ProductDialog", "Puchase Price:", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("ProductDialog", "Product Code:", 0, QApplication::UnicodeUTF8));
        assistedLabel->setText(QApplication::translate("ProductDialog", "Assisted Code:", 0, QApplication::UnicodeUTF8));
        unitLabel2->setText(QApplication::translate("ProductDialog", "Purchase Unit:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ProductDialog", "Product Name:", 0, QApplication::UnicodeUTF8));
        lowLabel->setText(QApplication::translate("ProductDialog", "Low Sum:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProductDialog", "Stock Unit Scalings", 0, QApplication::UnicodeUTF8));
        styleLabel->setText(QApplication::translate("ProductDialog", "Style:", 0, QApplication::UnicodeUTF8));
        pinyinLabel->setText(QApplication::translate("ProductDialog", "Pinyin Code:", 0, QApplication::UnicodeUTF8));
        mPricelabel3->setText(QApplication::translate("ProductDialog", "Top Sum:", 0, QApplication::UnicodeUTF8));
        unitLabel3->setText(QApplication::translate("ProductDialog", "Stock Unit:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProductDialog", "Purchase Unit:", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("ProductDialog", "Product Type:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ProductDialog", "1:", 0, QApplication::UnicodeUTF8));
        unitLabel1->setText(QApplication::translate("ProductDialog", "Dose Unit:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ProductDialog", "Stock Unit:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ProductDialog", "1:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ProductDialog", "Dose Unit Scalings", 0, QApplication::UnicodeUTF8));
        uCodeButton->setText(QString());
        label_7->setText(QApplication::translate("ProductDialog", "         Memo:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ProductDialog", "Option", 0, QApplication::UnicodeUTF8));
        sDownCheckBox->setText(QApplication::translate("ProductDialog", "Is Shop Down", 0, QApplication::UnicodeUTF8));
        sConCheckBox->setText(QApplication::translate("ProductDialog", "Is Sale Consumption", 0, QApplication::UnicodeUTF8));
        sPucgaseCheckBox->setText(QApplication::translate("ProductDialog", "Is Shop Pucgase", 0, QApplication::UnicodeUTF8));
        wConfCheckBox->setText(QApplication::translate("ProductDialog", "Is Weighing Conf", 0, QApplication::UnicodeUTF8));
        saleCheckBox->setText(QApplication::translate("ProductDialog", "Is Sale", 0, QApplication::UnicodeUTF8));
        purchaseCheckBox->setText(QApplication::translate("ProductDialog", "Is Purchase", 0, QApplication::UnicodeUTF8));
        comsumeCheckBox->setText(QApplication::translate("ProductDialog", "Is Comsume", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProductDialog: public Ui_ProductDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTDIALOG_H
