/********************************************************************************
** Form generated from reading UI file 'kmform.ui'
**
** Created: Fri Nov 6 10:54:55 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KMFORM_H
#define UI_KMFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KmForm
{
public:
    QVBoxLayout *verticalLayout;
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
    QLabel *codeLabel;
    QLineEdit *nameEdit;
    QLineEdit *explianEdit;
    QLabel *exLabel;
    QLineEdit *codeEdit;
    QLabel *endLabel;
    QCheckBox *isEndChk;
    QLabel *nameLabel;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *sCodeEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QComboBox *propertyCmb;
    QCheckBox *isCusChk;
    QCheckBox *isSupChk;
    QCheckBox *isCashChk;
    QCheckBox *isBankChk;

    void setupUi(QWidget *KmForm)
    {
        if (KmForm->objectName().isEmpty())
            KmForm->setObjectName(QString::fromUtf8("KmForm"));
        KmForm->resize(831, 463);
        verticalLayout = new QVBoxLayout(KmForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(KmForm);
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
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
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


        gridLayout_3->addWidget(frame_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 417, 233));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        codeLabel = new QLabel(gridLayoutWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        sizePolicy1.setHeightForWidth(codeLabel->sizePolicy().hasHeightForWidth());
        codeLabel->setSizePolicy(sizePolicy1);
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);
        nameEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        explianEdit = new QLineEdit(gridLayoutWidget);
        explianEdit->setObjectName(QString::fromUtf8("explianEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(explianEdit->sizePolicy().hasHeightForWidth());
        explianEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(explianEdit, 3, 1, 1, 2);

        exLabel = new QLabel(gridLayoutWidget);
        exLabel->setObjectName(QString::fromUtf8("exLabel"));
        sizePolicy1.setHeightForWidth(exLabel->sizePolicy().hasHeightForWidth());
        exLabel->setSizePolicy(sizePolicy1);
        exLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(exLabel, 3, 0, 1, 1);

        codeEdit = new QLineEdit(gridLayoutWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy2.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy2);
        codeEdit->setMaxLength(8);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        endLabel = new QLabel(gridLayoutWidget);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        endLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(endLabel, 4, 0, 1, 1);

        isEndChk = new QCheckBox(gridLayoutWidget);
        isEndChk->setObjectName(QString::fromUtf8("isEndChk"));
        isEndChk->setCheckable(true);
        isEndChk->setChecked(false);

        gridLayout->addWidget(isEndChk, 4, 1, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy1.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy1);
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        sCodeEdit = new QLineEdit(gridLayoutWidget);
        sCodeEdit->setObjectName(QString::fromUtf8("sCodeEdit"));
        sizePolicy2.setHeightForWidth(sCodeEdit->sizePolicy().hasHeightForWidth());
        sCodeEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(sCodeEdit, 2, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 7, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        propertyCmb = new QComboBox(gridLayoutWidget);
        propertyCmb->setObjectName(QString::fromUtf8("propertyCmb"));

        gridLayout->addWidget(propertyCmb, 5, 1, 1, 1);

        isCusChk = new QCheckBox(gridLayoutWidget);
        isCusChk->setObjectName(QString::fromUtf8("isCusChk"));

        gridLayout->addWidget(isCusChk, 6, 1, 1, 1);

        isSupChk = new QCheckBox(gridLayoutWidget);
        isSupChk->setObjectName(QString::fromUtf8("isSupChk"));

        gridLayout->addWidget(isSupChk, 7, 1, 1, 1);

        isCashChk = new QCheckBox(gridLayoutWidget);
        isCashChk->setObjectName(QString::fromUtf8("isCashChk"));

        gridLayout->addWidget(isCashChk, 8, 1, 1, 1);

        isBankChk = new QCheckBox(gridLayoutWidget);
        isBankChk->setObjectName(QString::fromUtf8("isBankChk"));

        gridLayout->addWidget(isBankChk, 9, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);


        retranslateUi(KmForm);

        QMetaObject::connectSlotsByName(KmForm);
    } // setupUi

    void retranslateUi(QWidget *KmForm)
    {
        KmForm->setWindowTitle(QApplication::translate("KmForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("KmForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("KmForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("KmForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("KmForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
        editButton->setText(QString());
        groupBox->setTitle(QApplication::translate("KmForm", "\347\247\221\347\233\256", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("KmForm", "\347\247\221\347\233\256\347\274\226\347\240\201:", 0, QApplication::UnicodeUTF8));
        exLabel->setText(QApplication::translate("KmForm", "\347\247\221\347\233\256\350\257\264\346\230\216:", 0, QApplication::UnicodeUTF8));
        codeEdit->setInputMask(QApplication::translate("KmForm", "99999999; ", 0, QApplication::UnicodeUTF8));
        endLabel->setText(QApplication::translate("KmForm", "\346\230\257\345\220\246\346\234\253\347\272\247:", 0, QApplication::UnicodeUTF8));
        isEndChk->setText(QString());
        nameLabel->setText(QApplication::translate("KmForm", "\347\247\221\347\233\256\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("KmForm", "*** ***  ***\344\276\213\345\246\202:001001001", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("KmForm", "\346\216\245\345\217\243\347\274\226\347\240\201:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("KmForm", "\346\230\257\345\220\246\344\276\233\345\272\224\345\225\206\345\276\200\346\235\245\346\240\270\347\256\227:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("KmForm", "\346\230\257\345\220\246\347\216\260\351\207\221\347\247\221\347\233\256:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("KmForm", "\347\247\221\347\233\256\346\226\271\345\220\221:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("KmForm", "\346\230\257\345\220\246\345\256\242\346\210\267\345\276\200\346\235\245\346\240\270\347\256\227:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("KmForm", "\346\230\257\345\220\246\351\223\266\350\241\214\347\247\221\347\233\256:", 0, QApplication::UnicodeUTF8));
        isCusChk->setText(QString());
        isSupChk->setText(QString());
        isCashChk->setText(QString());
        isBankChk->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KmForm: public Ui_KmForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KMFORM_H
