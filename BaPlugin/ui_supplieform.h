/********************************************************************************
** Form generated from reading UI file 'supplieform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPLIEFORM_H
#define UI_SUPPLIEFORM_H

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
#include <QtGui/QTreeView>
#include <QtGui/QWidget>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_SupplieForm
{
public:
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    QFrame *frame;
    QGridLayout *gridLayout_3;
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
    QLineEdit *bankNameEdit;
    QLabel *bankNameLabel;
    QLabel *explianLabel;
    QLabel *linkFuncLabel;
    QLineEdit *funcEdit;
    QLineEdit *memoEdit;
    QLineEdit *addrEdit;
    QLineEdit *bankEdit;
    QLabel *linkPhoneLabel;
    QLabel *addrLabel;
    QLineEdit *bankCardEdit;
    QLineEdit *nameEdit;
    QLabel *taxLabel;
    QLabel *nameLabel;
    QLabel *bankLabel;
    QLabel *bankCardLabel;
    QLineEdit *phoneEdit;
    QLineEdit *taxEdit;
    QLineEdit *manEdit;
    QLabel *linkmanLabel;
    QLineEdit *explianEdit;
    QLabel *typeLabel;
    QLabel *memoLabel;
    QLabel *label;
    QLineEdit *codeEdit;
    QCheckBox *statusCheckBox;
    QLabel *label_2;
    QkSearchEditBox *typeQsk;

    void setupUi(QWidget *SupplieForm)
    {
        if (SupplieForm->objectName().isEmpty())
            SupplieForm->setObjectName(QString::fromUtf8("SupplieForm"));
        SupplieForm->resize(1071, 618);
        horizontalLayout = new QHBoxLayout(SupplieForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(SupplieForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setSelectionMode(QAbstractItemView::SingleSelection);
        splitter->addWidget(treeView);
        treeView->header()->setHighlightSections(false);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        newButton = new QPushButton(frame_2);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy3);
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
        sizePolicy3.setHeightForWidth(delButton->sizePolicy().hasHeightForWidth());
        delButton->setSizePolicy(sizePolicy3);
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
        sizePolicy3.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setIconSize(QSize(24, 24));
        cancelButton->setDefault(true);
        cancelButton->setFlat(false);

        gridLayout_2->addWidget(cancelButton, 0, 4, 1, 1);

        saveButton = new QPushButton(frame_2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy3.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy3);
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


        gridLayout_3->addWidget(frame_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 421, 356));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bankNameEdit = new QLineEdit(gridLayoutWidget);
        bankNameEdit->setObjectName(QString::fromUtf8("bankNameEdit"));

        gridLayout->addWidget(bankNameEdit, 16, 1, 1, 1);

        bankNameLabel = new QLabel(gridLayoutWidget);
        bankNameLabel->setObjectName(QString::fromUtf8("bankNameLabel"));
        sizePolicy2.setHeightForWidth(bankNameLabel->sizePolicy().hasHeightForWidth());
        bankNameLabel->setSizePolicy(sizePolicy2);
        bankNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(bankNameLabel, 16, 0, 1, 1);

        explianLabel = new QLabel(gridLayoutWidget);
        explianLabel->setObjectName(QString::fromUtf8("explianLabel"));
        sizePolicy2.setHeightForWidth(explianLabel->sizePolicy().hasHeightForWidth());
        explianLabel->setSizePolicy(sizePolicy2);
        explianLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(explianLabel, 5, 0, 1, 1);

        linkFuncLabel = new QLabel(gridLayoutWidget);
        linkFuncLabel->setObjectName(QString::fromUtf8("linkFuncLabel"));
        linkFuncLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(linkFuncLabel, 9, 0, 1, 1);

        funcEdit = new QLineEdit(gridLayoutWidget);
        funcEdit->setObjectName(QString::fromUtf8("funcEdit"));

        gridLayout->addWidget(funcEdit, 9, 1, 1, 1);

        memoEdit = new QLineEdit(gridLayoutWidget);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));
        memoEdit->setCursorMoveStyle(Qt::VisualMoveStyle);

        gridLayout->addWidget(memoEdit, 17, 1, 1, 1);

        addrEdit = new QLineEdit(gridLayoutWidget);
        addrEdit->setObjectName(QString::fromUtf8("addrEdit"));

        gridLayout->addWidget(addrEdit, 6, 1, 1, 1);

        bankEdit = new QLineEdit(gridLayoutWidget);
        bankEdit->setObjectName(QString::fromUtf8("bankEdit"));

        gridLayout->addWidget(bankEdit, 14, 1, 1, 1);

        linkPhoneLabel = new QLabel(gridLayoutWidget);
        linkPhoneLabel->setObjectName(QString::fromUtf8("linkPhoneLabel"));
        linkPhoneLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(linkPhoneLabel, 8, 0, 1, 1);

        addrLabel = new QLabel(gridLayoutWidget);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));
        sizePolicy2.setHeightForWidth(addrLabel->sizePolicy().hasHeightForWidth());
        addrLabel->setSizePolicy(sizePolicy2);
        addrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(addrLabel, 6, 0, 1, 1);

        bankCardEdit = new QLineEdit(gridLayoutWidget);
        bankCardEdit->setObjectName(QString::fromUtf8("bankCardEdit"));

        gridLayout->addWidget(bankCardEdit, 15, 1, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        taxLabel = new QLabel(gridLayoutWidget);
        taxLabel->setObjectName(QString::fromUtf8("taxLabel"));
        sizePolicy2.setHeightForWidth(taxLabel->sizePolicy().hasHeightForWidth());
        taxLabel->setSizePolicy(sizePolicy2);
        taxLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(taxLabel, 13, 0, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy2.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy2);
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        bankLabel = new QLabel(gridLayoutWidget);
        bankLabel->setObjectName(QString::fromUtf8("bankLabel"));
        sizePolicy2.setHeightForWidth(bankLabel->sizePolicy().hasHeightForWidth());
        bankLabel->setSizePolicy(sizePolicy2);
        bankLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(bankLabel, 14, 0, 1, 1);

        bankCardLabel = new QLabel(gridLayoutWidget);
        bankCardLabel->setObjectName(QString::fromUtf8("bankCardLabel"));
        sizePolicy2.setHeightForWidth(bankCardLabel->sizePolicy().hasHeightForWidth());
        bankCardLabel->setSizePolicy(sizePolicy2);
        bankCardLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(bankCardLabel, 15, 0, 1, 1);

        phoneEdit = new QLineEdit(gridLayoutWidget);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        sizePolicy3.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(phoneEdit, 8, 1, 1, 1);

        taxEdit = new QLineEdit(gridLayoutWidget);
        taxEdit->setObjectName(QString::fromUtf8("taxEdit"));

        gridLayout->addWidget(taxEdit, 13, 1, 1, 1);

        manEdit = new QLineEdit(gridLayoutWidget);
        manEdit->setObjectName(QString::fromUtf8("manEdit"));
        sizePolicy3.setHeightForWidth(manEdit->sizePolicy().hasHeightForWidth());
        manEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(manEdit, 7, 1, 1, 1);

        linkmanLabel = new QLabel(gridLayoutWidget);
        linkmanLabel->setObjectName(QString::fromUtf8("linkmanLabel"));
        linkmanLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(linkmanLabel, 7, 0, 1, 1);

        explianEdit = new QLineEdit(gridLayoutWidget);
        explianEdit->setObjectName(QString::fromUtf8("explianEdit"));
        sizePolicy4.setHeightForWidth(explianEdit->sizePolicy().hasHeightForWidth());
        explianEdit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(explianEdit, 5, 1, 1, 1);

        typeLabel = new QLabel(gridLayoutWidget);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        sizePolicy2.setHeightForWidth(typeLabel->sizePolicy().hasHeightForWidth());
        typeLabel->setSizePolicy(sizePolicy2);
        typeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(typeLabel, 2, 0, 1, 1);

        memoLabel = new QLabel(gridLayoutWidget);
        memoLabel->setObjectName(QString::fromUtf8("memoLabel"));
        sizePolicy2.setHeightForWidth(memoLabel->sizePolicy().hasHeightForWidth());
        memoLabel->setSizePolicy(sizePolicy2);
        memoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(memoLabel, 17, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        codeEdit = new QLineEdit(gridLayoutWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy3.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        statusCheckBox = new QCheckBox(gridLayoutWidget);
        statusCheckBox->setObjectName(QString::fromUtf8("statusCheckBox"));

        gridLayout->addWidget(statusCheckBox, 3, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        typeQsk = new QkSearchEditBox(gridLayoutWidget);
        typeQsk->setObjectName(QString::fromUtf8("typeQsk"));

        gridLayout->addWidget(typeQsk, 2, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        splitter->addWidget(frame);

        horizontalLayout->addWidget(splitter);

        QWidget::setTabOrder(nameEdit, explianEdit);
        QWidget::setTabOrder(explianEdit, addrEdit);
        QWidget::setTabOrder(addrEdit, manEdit);
        QWidget::setTabOrder(manEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, funcEdit);
        QWidget::setTabOrder(funcEdit, taxEdit);
        QWidget::setTabOrder(taxEdit, bankEdit);
        QWidget::setTabOrder(bankEdit, bankCardEdit);
        QWidget::setTabOrder(bankCardEdit, bankNameEdit);
        QWidget::setTabOrder(bankNameEdit, memoEdit);
        QWidget::setTabOrder(memoEdit, cancelButton);
        QWidget::setTabOrder(cancelButton, treeView);
        QWidget::setTabOrder(treeView, newButton);
        QWidget::setTabOrder(newButton, delButton);
        QWidget::setTabOrder(delButton, editButton);
        QWidget::setTabOrder(editButton, saveButton);

        retranslateUi(SupplieForm);

        QMetaObject::connectSlotsByName(SupplieForm);
    } // setupUi

    void retranslateUi(QWidget *SupplieForm)
    {
        SupplieForm->setWindowTitle(QApplication::translate("SupplieForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("SupplieForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("SupplieForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("SupplieForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("SupplieForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("SupplieForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        groupBox->setTitle(QApplication::translate("SupplieForm", "Suppliers Information", 0, QApplication::UnicodeUTF8));
        bankNameLabel->setText(QApplication::translate("SupplieForm", "Bank Name:", 0, QApplication::UnicodeUTF8));
        explianLabel->setText(QApplication::translate("SupplieForm", "Suppliers Explian:", 0, QApplication::UnicodeUTF8));
        linkFuncLabel->setText(QApplication::translate("SupplieForm", "Link Func:", 0, QApplication::UnicodeUTF8));
        linkPhoneLabel->setText(QApplication::translate("SupplieForm", "Link Phone:", 0, QApplication::UnicodeUTF8));
        addrLabel->setText(QApplication::translate("SupplieForm", "Addr:", 0, QApplication::UnicodeUTF8));
        taxLabel->setText(QApplication::translate("SupplieForm", "Tax:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("SupplieForm", "Suppliers Name:", 0, QApplication::UnicodeUTF8));
        bankLabel->setText(QApplication::translate("SupplieForm", "Bank;", 0, QApplication::UnicodeUTF8));
        bankCardLabel->setText(QApplication::translate("SupplieForm", "Bank Card:", 0, QApplication::UnicodeUTF8));
        linkmanLabel->setText(QApplication::translate("SupplieForm", "LinkMan:", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("SupplieForm", "Suppliers Type:", 0, QApplication::UnicodeUTF8));
        memoLabel->setText(QApplication::translate("SupplieForm", "Memo:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SupplieForm", "Suppliers Code:", 0, QApplication::UnicodeUTF8));
        statusCheckBox->setText(QString());
        label_2->setText(QApplication::translate("SupplieForm", "Is Start:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SupplieForm: public Ui_SupplieForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPLIEFORM_H
