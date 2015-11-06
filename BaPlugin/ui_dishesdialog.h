/********************************************************************************
** Form generated from reading UI file 'dishesdialog.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHESDIALOG_H
#define UI_DISHESDIALOG_H

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
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_DishesDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *priceLabel3;
    QLabel *nameLabel;
    QLabel *codeLabel;
    QDoubleSpinBox *priceSpinBox2;
    QLineEdit *nameEdit;
    QDoubleSpinBox *priceSpinBox3;
    QLineEdit *pinyinEdit;
    QLineEdit *codeEdit;
    QDoubleSpinBox *priceSpinBox;
    QLabel *pinyinLabel;
    QLabel *priceLabel2;
    QLabel *mPricelabel2;
    QLabel *mPricelabel3;
    QDoubleSpinBox *mPriceSpinBox3;
    QLabel *enLabel;
    QLabel *mPricelabel1;
    QLabel *priceLabel1;
    QDoubleSpinBox *mPriceSpinBox;
    QDoubleSpinBox *mPriceSpinBox2;
    QLineEdit *enEdit;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *puStSpinBox;
    QLabel *label_5;
    QComboBox *sUnitComboBox;
    QLabel *unitLabel;
    QComboBox *pUnitComboBox;
    QLabel *typeLabel;
    QkSearchEditBox *qksearcheditbox;
    QLabel *styleLabel;
    QLineEdit *styleEdit;
    QLabel *label_2;
    QDoubleSpinBox *discSpinBox;
    QCheckBox *discCheckBox;
    QCheckBox *statusCheckBox;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_9;
    QDoubleSpinBox *puPriceSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_2;
    QCheckBox *tempCheckBox;
    QCheckBox *pieceCheckBox;
    QCheckBox *pricesCheckBox;
    QCheckBox *confCheckBox;
    QCheckBox *padCheckBox;
    QCheckBox *marketCheckBox;
    QCheckBox *setCheckBox;
    QLabel *label_3;
    QCheckBox *purchaseCheckBox;
    QRadioButton *normalRadio;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DishesDialog)
    {
        if (DishesDialog->objectName().isEmpty())
            DishesDialog->setObjectName(QString::fromUtf8("DishesDialog"));
        DishesDialog->setWindowModality(Qt::WindowModal);
        DishesDialog->resize(792, 469);
        verticalLayout = new QVBoxLayout(DishesDialog);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(DishesDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(630, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        addButton = new QPushButton(frame);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon);
        addButton->setIconSize(QSize(32, 32));
        addButton->setAutoDefault(true);

        gridLayout_3->addWidget(addButton, 0, 1, 1, 1);

        saveButton = new QPushButton(frame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(32, 32));
        saveButton->setAutoDefault(true);

        gridLayout_3->addWidget(saveButton, 0, 2, 1, 1);

        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setIconSize(QSize(32, 32));
        cancelButton->setAutoDefault(true);

        gridLayout_3->addWidget(cancelButton, 0, 3, 1, 1);


        verticalLayout->addWidget(frame);

        groupBox = new QGroupBox(DishesDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        priceLabel3 = new QLabel(groupBox);
        priceLabel3->setObjectName(QString::fromUtf8("priceLabel3"));
        priceLabel3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(priceLabel3, 5, 4, 1, 1);

        nameLabel = new QLabel(groupBox);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 0, 2, 1, 1);

        codeLabel = new QLabel(groupBox);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        priceSpinBox2 = new QDoubleSpinBox(groupBox);
        priceSpinBox2->setObjectName(QString::fromUtf8("priceSpinBox2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(priceSpinBox2->sizePolicy().hasHeightForWidth());
        priceSpinBox2->setSizePolicy(sizePolicy1);
        priceSpinBox2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        priceSpinBox2->setMaximum(1e+06);

        gridLayout->addWidget(priceSpinBox2, 5, 3, 1, 1);

        nameEdit = new QLineEdit(groupBox);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy1.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(nameEdit, 0, 3, 1, 1);

        priceSpinBox3 = new QDoubleSpinBox(groupBox);
        priceSpinBox3->setObjectName(QString::fromUtf8("priceSpinBox3"));
        sizePolicy1.setHeightForWidth(priceSpinBox3->sizePolicy().hasHeightForWidth());
        priceSpinBox3->setSizePolicy(sizePolicy1);
        priceSpinBox3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        priceSpinBox3->setMaximum(1e+06);

        gridLayout->addWidget(priceSpinBox3, 5, 5, 1, 1);

        pinyinEdit = new QLineEdit(groupBox);
        pinyinEdit->setObjectName(QString::fromUtf8("pinyinEdit"));
        sizePolicy1.setHeightForWidth(pinyinEdit->sizePolicy().hasHeightForWidth());
        pinyinEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pinyinEdit, 0, 5, 1, 1);

        codeEdit = new QLineEdit(groupBox);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy1.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        priceSpinBox = new QDoubleSpinBox(groupBox);
        priceSpinBox->setObjectName(QString::fromUtf8("priceSpinBox"));
        sizePolicy1.setHeightForWidth(priceSpinBox->sizePolicy().hasHeightForWidth());
        priceSpinBox->setSizePolicy(sizePolicy1);
        priceSpinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        priceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        priceSpinBox->setMaximum(1e+06);

        gridLayout->addWidget(priceSpinBox, 5, 1, 1, 1);

        pinyinLabel = new QLabel(groupBox);
        pinyinLabel->setObjectName(QString::fromUtf8("pinyinLabel"));
        pinyinLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(pinyinLabel, 0, 4, 1, 1);

        priceLabel2 = new QLabel(groupBox);
        priceLabel2->setObjectName(QString::fromUtf8("priceLabel2"));
        priceLabel2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(priceLabel2, 5, 2, 1, 1);

        mPricelabel2 = new QLabel(groupBox);
        mPricelabel2->setObjectName(QString::fromUtf8("mPricelabel2"));
        mPricelabel2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(mPricelabel2, 6, 2, 1, 1);

        mPricelabel3 = new QLabel(groupBox);
        mPricelabel3->setObjectName(QString::fromUtf8("mPricelabel3"));
        mPricelabel3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(mPricelabel3, 6, 4, 1, 1);

        mPriceSpinBox3 = new QDoubleSpinBox(groupBox);
        mPriceSpinBox3->setObjectName(QString::fromUtf8("mPriceSpinBox3"));
        sizePolicy1.setHeightForWidth(mPriceSpinBox3->sizePolicy().hasHeightForWidth());
        mPriceSpinBox3->setSizePolicy(sizePolicy1);
        mPriceSpinBox3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mPriceSpinBox3->setMaximum(1e+06);

        gridLayout->addWidget(mPriceSpinBox3, 6, 5, 1, 1);

        enLabel = new QLabel(groupBox);
        enLabel->setObjectName(QString::fromUtf8("enLabel"));
        enLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(enLabel, 1, 2, 1, 1);

        mPricelabel1 = new QLabel(groupBox);
        mPricelabel1->setObjectName(QString::fromUtf8("mPricelabel1"));
        mPricelabel1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(mPricelabel1, 6, 0, 1, 1);

        priceLabel1 = new QLabel(groupBox);
        priceLabel1->setObjectName(QString::fromUtf8("priceLabel1"));
        priceLabel1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(priceLabel1, 5, 0, 1, 1);

        mPriceSpinBox = new QDoubleSpinBox(groupBox);
        mPriceSpinBox->setObjectName(QString::fromUtf8("mPriceSpinBox"));
        sizePolicy1.setHeightForWidth(mPriceSpinBox->sizePolicy().hasHeightForWidth());
        mPriceSpinBox->setSizePolicy(sizePolicy1);
        mPriceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mPriceSpinBox->setMaximum(1e+06);

        gridLayout->addWidget(mPriceSpinBox, 6, 1, 1, 1);

        mPriceSpinBox2 = new QDoubleSpinBox(groupBox);
        mPriceSpinBox2->setObjectName(QString::fromUtf8("mPriceSpinBox2"));
        sizePolicy1.setHeightForWidth(mPriceSpinBox2->sizePolicy().hasHeightForWidth());
        mPriceSpinBox2->setSizePolicy(sizePolicy1);
        mPriceSpinBox2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mPriceSpinBox2->setMaximum(1e+06);

        gridLayout->addWidget(mPriceSpinBox2, 6, 3, 1, 1);

        enEdit = new QLineEdit(groupBox);
        enEdit->setObjectName(QString::fromUtf8("enEdit"));
        sizePolicy1.setHeightForWidth(enEdit->sizePolicy().hasHeightForWidth());
        enEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(enEdit, 1, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 4, 2, 1, 1);

        puStSpinBox = new QSpinBox(groupBox);
        puStSpinBox->setObjectName(QString::fromUtf8("puStSpinBox"));
        sizePolicy1.setHeightForWidth(puStSpinBox->sizePolicy().hasHeightForWidth());
        puStSpinBox->setSizePolicy(sizePolicy1);
        puStSpinBox->setMaximum(9999999);
        puStSpinBox->setValue(1);

        gridLayout->addWidget(puStSpinBox, 4, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 3, 2, 1, 1);

        sUnitComboBox = new QComboBox(groupBox);
        sUnitComboBox->setObjectName(QString::fromUtf8("sUnitComboBox"));
        sizePolicy1.setHeightForWidth(sUnitComboBox->sizePolicy().hasHeightForWidth());
        sUnitComboBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(sUnitComboBox, 3, 3, 1, 1);

        unitLabel = new QLabel(groupBox);
        unitLabel->setObjectName(QString::fromUtf8("unitLabel"));
        unitLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(unitLabel, 3, 0, 1, 1);

        pUnitComboBox = new QComboBox(groupBox);
        pUnitComboBox->setObjectName(QString::fromUtf8("pUnitComboBox"));
        sizePolicy1.setHeightForWidth(pUnitComboBox->sizePolicy().hasHeightForWidth());
        pUnitComboBox->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pUnitComboBox, 3, 1, 1, 1);

        typeLabel = new QLabel(groupBox);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(typeLabel, 1, 4, 1, 1);

        qksearcheditbox = new QkSearchEditBox(groupBox);
        qksearcheditbox->setObjectName(QString::fromUtf8("qksearcheditbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(qksearcheditbox->sizePolicy().hasHeightForWidth());
        qksearcheditbox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(qksearcheditbox, 1, 5, 1, 1);

        styleLabel = new QLabel(groupBox);
        styleLabel->setObjectName(QString::fromUtf8("styleLabel"));
        styleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(styleLabel, 1, 0, 1, 1);

        styleEdit = new QLineEdit(groupBox);
        styleEdit->setObjectName(QString::fromUtf8("styleEdit"));
        sizePolicy1.setHeightForWidth(styleEdit->sizePolicy().hasHeightForWidth());
        styleEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(styleEdit, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 7, 2, 1, 1);

        discSpinBox = new QDoubleSpinBox(groupBox);
        discSpinBox->setObjectName(QString::fromUtf8("discSpinBox"));
        sizePolicy1.setHeightForWidth(discSpinBox->sizePolicy().hasHeightForWidth());
        discSpinBox->setSizePolicy(sizePolicy1);
        discSpinBox->setMaximum(1);

        gridLayout->addWidget(discSpinBox, 7, 3, 1, 1);

        discCheckBox = new QCheckBox(groupBox);
        discCheckBox->setObjectName(QString::fromUtf8("discCheckBox"));

        gridLayout->addWidget(discCheckBox, 7, 1, 1, 1);

        statusCheckBox = new QCheckBox(groupBox);
        statusCheckBox->setObjectName(QString::fromUtf8("statusCheckBox"));

        gridLayout->addWidget(statusCheckBox, 8, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 7, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 2, 1, 1);

        puPriceSpinBox = new QDoubleSpinBox(groupBox);
        puPriceSpinBox->setObjectName(QString::fromUtf8("puPriceSpinBox"));
        sizePolicy1.setHeightForWidth(puPriceSpinBox->sizePolicy().hasHeightForWidth());
        puPriceSpinBox->setSizePolicy(sizePolicy1);
        puPriceSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        puPriceSpinBox->setMaximum(1e+06);

        gridLayout->addWidget(puPriceSpinBox, 8, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DishesDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tempCheckBox = new QCheckBox(groupBox_2);
        tempCheckBox->setObjectName(QString::fromUtf8("tempCheckBox"));

        gridLayout_2->addWidget(tempCheckBox, 0, 0, 1, 1);

        pieceCheckBox = new QCheckBox(groupBox_2);
        pieceCheckBox->setObjectName(QString::fromUtf8("pieceCheckBox"));

        gridLayout_2->addWidget(pieceCheckBox, 1, 1, 1, 1);

        pricesCheckBox = new QCheckBox(groupBox_2);
        pricesCheckBox->setObjectName(QString::fromUtf8("pricesCheckBox"));

        gridLayout_2->addWidget(pricesCheckBox, 0, 3, 1, 1);

        confCheckBox = new QCheckBox(groupBox_2);
        confCheckBox->setObjectName(QString::fromUtf8("confCheckBox"));

        gridLayout_2->addWidget(confCheckBox, 0, 1, 1, 1);

        padCheckBox = new QCheckBox(groupBox_2);
        padCheckBox->setObjectName(QString::fromUtf8("padCheckBox"));

        gridLayout_2->addWidget(padCheckBox, 1, 0, 1, 1);

        marketCheckBox = new QCheckBox(groupBox_2);
        marketCheckBox->setObjectName(QString::fromUtf8("marketCheckBox"));

        gridLayout_2->addWidget(marketCheckBox, 0, 2, 1, 1);

        setCheckBox = new QCheckBox(groupBox_2);
        setCheckBox->setObjectName(QString::fromUtf8("setCheckBox"));

        gridLayout_2->addWidget(setCheckBox, 0, 4, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 4);

        purchaseCheckBox = new QCheckBox(groupBox_2);
        purchaseCheckBox->setObjectName(QString::fromUtf8("purchaseCheckBox"));

        gridLayout_2->addWidget(purchaseCheckBox, 1, 2, 1, 1);

        normalRadio = new QRadioButton(groupBox_2);
        normalRadio->setObjectName(QString::fromUtf8("normalRadio"));
        normalRadio->setChecked(true);

        gridLayout_2->addWidget(normalRadio, 1, 3, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        horizontalSpacer_3 = new QSpacerItem(154, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(groupBox_2);

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, pinyinEdit);
        QWidget::setTabOrder(pinyinEdit, enEdit);
        QWidget::setTabOrder(enEdit, priceSpinBox);
        QWidget::setTabOrder(priceSpinBox, priceSpinBox2);
        QWidget::setTabOrder(priceSpinBox2, priceSpinBox3);
        QWidget::setTabOrder(priceSpinBox3, mPriceSpinBox);
        QWidget::setTabOrder(mPriceSpinBox, mPriceSpinBox2);
        QWidget::setTabOrder(mPriceSpinBox2, mPriceSpinBox3);
        QWidget::setTabOrder(mPriceSpinBox3, tempCheckBox);
        QWidget::setTabOrder(tempCheckBox, confCheckBox);
        QWidget::setTabOrder(confCheckBox, marketCheckBox);
        QWidget::setTabOrder(marketCheckBox, pricesCheckBox);
        QWidget::setTabOrder(pricesCheckBox, setCheckBox);
        QWidget::setTabOrder(setCheckBox, padCheckBox);
        QWidget::setTabOrder(padCheckBox, pieceCheckBox);
        QWidget::setTabOrder(pieceCheckBox, cancelButton);
        QWidget::setTabOrder(cancelButton, addButton);
        QWidget::setTabOrder(addButton, saveButton);

        retranslateUi(DishesDialog);

        QMetaObject::connectSlotsByName(DishesDialog);
    } // setupUi

    void retranslateUi(QDialog *DishesDialog)
    {
        DishesDialog->setWindowTitle(QApplication::translate("DishesDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("DishesDialog", "Add", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("DishesDialog", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("DishesDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DishesDialog", "Base Info", 0, QApplication::UnicodeUTF8));
        priceLabel3->setText(QApplication::translate("DishesDialog", "Price 3:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("DishesDialog", "Dishes Name:", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("DishesDialog", "Dishes Code:", 0, QApplication::UnicodeUTF8));
        pinyinLabel->setText(QApplication::translate("DishesDialog", "Pinyin Code:", 0, QApplication::UnicodeUTF8));
        priceLabel2->setText(QApplication::translate("DishesDialog", "Price 2:", 0, QApplication::UnicodeUTF8));
        mPricelabel2->setText(QApplication::translate("DishesDialog", "Member Price 2:", 0, QApplication::UnicodeUTF8));
        mPricelabel3->setText(QApplication::translate("DishesDialog", "Member Price 3:", 0, QApplication::UnicodeUTF8));
        enLabel->setText(QApplication::translate("DishesDialog", "Enlish Name:", 0, QApplication::UnicodeUTF8));
        mPricelabel1->setText(QApplication::translate("DishesDialog", "Member Price 1:", 0, QApplication::UnicodeUTF8));
        priceLabel1->setText(QApplication::translate("DishesDialog", "Price 1:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("DishesDialog", "Purchase Unit:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("DishesDialog", "Stock Unit Scalings", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("DishesDialog", "1:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("DishesDialog", "Stock Unit:", 0, QApplication::UnicodeUTF8));
        unitLabel->setText(QApplication::translate("DishesDialog", "Purchase Unit:", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("DishesDialog", "Dishes Type:", 0, QApplication::UnicodeUTF8));
        styleLabel->setText(QApplication::translate("DishesDialog", "Style:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DishesDialog", "Low Discount:", 0, QApplication::UnicodeUTF8));
        discCheckBox->setText(QString());
        statusCheckBox->setText(QString());
        label_4->setText(QApplication::translate("DishesDialog", "Is Start:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DishesDialog", "Is Discount:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("DishesDialog", "Purchase Price:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("DishesDialog", "Option", 0, QApplication::UnicodeUTF8));
        tempCheckBox->setText(QApplication::translate("DishesDialog", "Is Temp Dishes", 0, QApplication::UnicodeUTF8));
        pieceCheckBox->setText(QApplication::translate("DishesDialog", "Is Piece Dishes", 0, QApplication::UnicodeUTF8));
        pricesCheckBox->setText(QApplication::translate("DishesDialog", "Is Current Prices", 0, QApplication::UnicodeUTF8));
        confCheckBox->setText(QApplication::translate("DishesDialog", "Is Weighing Conf", 0, QApplication::UnicodeUTF8));
        padCheckBox->setText(QApplication::translate("DishesDialog", "Is Down Pad", 0, QApplication::UnicodeUTF8));
        marketCheckBox->setText(QApplication::translate("DishesDialog", "Is Marketing", 0, QApplication::UnicodeUTF8));
        setCheckBox->setText(QApplication::translate("DishesDialog", "Is Set", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DishesDialog", "<html><head/><body><p><span style=\" color:#ff0000;\">\350\257\264\346\230\216\357\274\232\346\234\200\344\275\216\346\212\230\346\211\243\344\270\2720.5- 1.0 \344\271\213\351\227\264\357\274\214\345\246\202\344\270\272\351\233\266,\345\260\261\344\270\215\350\256\276\344\270\272\346\234\200\344\275\216\346\212\230\346\211\243</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        purchaseCheckBox->setText(QApplication::translate("DishesDialog", "Is Purchase", 0, QApplication::UnicodeUTF8));
        normalRadio->setText(QApplication::translate("DishesDialog", "Normal dishes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DishesDialog: public Ui_DishesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHESDIALOG_H
