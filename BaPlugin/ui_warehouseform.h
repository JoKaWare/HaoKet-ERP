/********************************************************************************
** Form generated from reading UI file 'warehouseform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEFORM_H
#define UI_WAREHOUSEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_WareHouseForm
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTableView *tableView;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QPushButton *newButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *delButton;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QPushButton *editButton;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *depLabel;
    QLineEdit *nameEdit;
    QLabel *codeLabel;
    QLineEdit *codeEdit;
    QLabel *typeLabel;
    QLabel *addrLabel;
    QLabel *linkmanLabel;
    QLabel *linkPhoneLabel;
    QLabel *cargoLabel;
    QLineEdit *addrEdit;
    QLineEdit *phoneEdit;
    QCheckBox *cargoCheckBox;
    QkSearchEditBox *depQksearchEditbox;
    QkSearchEditBox *personQksearchEditbox;
    QLabel *shopLabel;
    QCheckBox *shopCheckBox;
    QLineEdit *memoEdit;
    QLabel *label;

    void setupUi(QWidget *WareHouseForm)
    {
        if (WareHouseForm->objectName().isEmpty())
            WareHouseForm->setObjectName(QString::fromUtf8("WareHouseForm"));
        WareHouseForm->resize(1039, 629);
        horizontalLayout = new QHBoxLayout(WareHouseForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(WareHouseForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy);
        splitter->addWidget(tableView);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        newButton = new QPushButton(frame_2);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon);
        newButton->setIconSize(QSize(24, 24));
        newButton->setAutoRepeat(false);
        newButton->setAutoExclusive(false);
        newButton->setDefault(true);
        newButton->setFlat(false);

        gridLayout_2->addWidget(newButton, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 5, 1, 1);

        delButton = new QPushButton(frame_2);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        sizePolicy2.setHeightForWidth(delButton->sizePolicy().hasHeightForWidth());
        delButton->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/cross_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        delButton->setIcon(icon1);
        delButton->setIconSize(QSize(24, 24));
        delButton->setAutoDefault(true);
        delButton->setDefault(true);
        delButton->setFlat(false);

        gridLayout_2->addWidget(delButton, 0, 3, 1, 1);

        cancelButton = new QPushButton(frame_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        sizePolicy2.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setIconSize(QSize(24, 24));
        cancelButton->setDefault(true);
        cancelButton->setFlat(false);

        gridLayout_2->addWidget(cancelButton, 0, 4, 1, 1);

        saveButton = new QPushButton(frame_2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy2.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon3);
        saveButton->setIconSize(QSize(24, 24));
        saveButton->setAutoRepeat(false);
        saveButton->setAutoExclusive(false);
        saveButton->setDefault(true);
        saveButton->setFlat(false);

        gridLayout_2->addWidget(saveButton, 0, 2, 1, 1);

        editButton = new QPushButton(frame_2);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon4);
        editButton->setIconSize(QSize(24, 24));
        editButton->setAutoDefault(true);
        editButton->setDefault(true);

        gridLayout_2->addWidget(editButton, 0, 1, 1, 1);


        verticalLayout->addWidget(frame_2);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 401, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        depLabel = new QLabel(gridLayoutWidget);
        depLabel->setObjectName(QString::fromUtf8("depLabel"));
        sizePolicy1.setHeightForWidth(depLabel->sizePolicy().hasHeightForWidth());
        depLabel->setSizePolicy(sizePolicy1);
        depLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(depLabel, 2, 0, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(nameEdit, 1, 2, 1, 1);

        codeLabel = new QLabel(gridLayoutWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        sizePolicy1.setHeightForWidth(codeLabel->sizePolicy().hasHeightForWidth());
        codeLabel->setSizePolicy(sizePolicy1);
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        codeEdit = new QLineEdit(gridLayoutWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy2.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(codeEdit, 0, 2, 1, 1);

        typeLabel = new QLabel(gridLayoutWidget);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        sizePolicy1.setHeightForWidth(typeLabel->sizePolicy().hasHeightForWidth());
        typeLabel->setSizePolicy(sizePolicy1);
        typeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(typeLabel, 1, 0, 1, 1);

        addrLabel = new QLabel(gridLayoutWidget);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));
        sizePolicy1.setHeightForWidth(addrLabel->sizePolicy().hasHeightForWidth());
        addrLabel->setSizePolicy(sizePolicy1);
        addrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(addrLabel, 3, 0, 1, 1);

        linkmanLabel = new QLabel(gridLayoutWidget);
        linkmanLabel->setObjectName(QString::fromUtf8("linkmanLabel"));
        linkmanLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(linkmanLabel, 5, 0, 1, 1);

        linkPhoneLabel = new QLabel(gridLayoutWidget);
        linkPhoneLabel->setObjectName(QString::fromUtf8("linkPhoneLabel"));
        linkPhoneLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(linkPhoneLabel, 6, 0, 1, 1);

        cargoLabel = new QLabel(gridLayoutWidget);
        cargoLabel->setObjectName(QString::fromUtf8("cargoLabel"));
        cargoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(cargoLabel, 7, 0, 1, 1);

        addrEdit = new QLineEdit(gridLayoutWidget);
        addrEdit->setObjectName(QString::fromUtf8("addrEdit"));

        gridLayout->addWidget(addrEdit, 3, 2, 1, 1);

        phoneEdit = new QLineEdit(gridLayoutWidget);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        sizePolicy2.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(phoneEdit, 6, 2, 1, 1);

        cargoCheckBox = new QCheckBox(gridLayoutWidget);
        cargoCheckBox->setObjectName(QString::fromUtf8("cargoCheckBox"));

        gridLayout->addWidget(cargoCheckBox, 7, 2, 1, 1);

        depQksearchEditbox = new QkSearchEditBox(gridLayoutWidget);
        depQksearchEditbox->setObjectName(QString::fromUtf8("depQksearchEditbox"));

        gridLayout->addWidget(depQksearchEditbox, 2, 2, 1, 1);

        personQksearchEditbox = new QkSearchEditBox(gridLayoutWidget);
        personQksearchEditbox->setObjectName(QString::fromUtf8("personQksearchEditbox"));

        gridLayout->addWidget(personQksearchEditbox, 5, 2, 1, 1);

        shopLabel = new QLabel(gridLayoutWidget);
        shopLabel->setObjectName(QString::fromUtf8("shopLabel"));
        shopLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(shopLabel, 8, 0, 1, 1);

        shopCheckBox = new QCheckBox(gridLayoutWidget);
        shopCheckBox->setObjectName(QString::fromUtf8("shopCheckBox"));

        gridLayout->addWidget(shopCheckBox, 8, 2, 1, 1);

        memoEdit = new QLineEdit(gridLayoutWidget);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        gridLayout->addWidget(memoEdit, 9, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 9, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        splitter->addWidget(frame);

        horizontalLayout->addWidget(splitter);

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, depQksearchEditbox);
        QWidget::setTabOrder(depQksearchEditbox, addrEdit);
        QWidget::setTabOrder(addrEdit, personQksearchEditbox);
        QWidget::setTabOrder(personQksearchEditbox, phoneEdit);
        QWidget::setTabOrder(phoneEdit, cargoCheckBox);
        QWidget::setTabOrder(cargoCheckBox, shopCheckBox);
        QWidget::setTabOrder(shopCheckBox, memoEdit);
        QWidget::setTabOrder(memoEdit, newButton);
        QWidget::setTabOrder(newButton, editButton);
        QWidget::setTabOrder(editButton, saveButton);
        QWidget::setTabOrder(saveButton, delButton);
        QWidget::setTabOrder(delButton, cancelButton);
        QWidget::setTabOrder(cancelButton, tableView);

        retranslateUi(WareHouseForm);

        QMetaObject::connectSlotsByName(WareHouseForm);
    } // setupUi

    void retranslateUi(QWidget *WareHouseForm)
    {
        WareHouseForm->setWindowTitle(QApplication::translate("WareHouseForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("WareHouseForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("WareHouseForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("WareHouseForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("WareHouseForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("WareHouseForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        groupBox->setTitle(QApplication::translate("WareHouseForm", "Warehouse Info", 0, QApplication::UnicodeUTF8));
        depLabel->setText(QApplication::translate("WareHouseForm", "Department:", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("WareHouseForm", "Warehouse Code:", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("WareHouseForm", "Warehouse Name:", 0, QApplication::UnicodeUTF8));
        addrLabel->setText(QApplication::translate("WareHouseForm", "Addr:", 0, QApplication::UnicodeUTF8));
        linkmanLabel->setText(QApplication::translate("WareHouseForm", "Person:", 0, QApplication::UnicodeUTF8));
        linkPhoneLabel->setText(QApplication::translate("WareHouseForm", "Link Phone:", 0, QApplication::UnicodeUTF8));
        cargoLabel->setText(QApplication::translate("WareHouseForm", "Is Cargo:", 0, QApplication::UnicodeUTF8));
        cargoCheckBox->setText(QString());
        shopLabel->setText(QApplication::translate("WareHouseForm", "Is Shop:", 0, QApplication::UnicodeUTF8));
        shopCheckBox->setText(QString());
        label->setText(QApplication::translate("WareHouseForm", "Memo:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WareHouseForm: public Ui_WareHouseForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEFORM_H
