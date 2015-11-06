/********************************************************************************
** Form generated from reading UI file 'depform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPFORM_H
#define UI_DEPFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
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

class Ui_DepForm
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
    QLabel *personLabel;
    QLineEdit *nameEdit;
    QLabel *nameLabel;
    QLabel *label_4;
    QLabel *codeLabel;
    QLineEdit *personEdit;
    QLineEdit *addrEdit;
    QLineEdit *telEdit;
    QLabel *addrLabel;
    QLineEdit *codeEdit;
    QLabel *telLabel;
    QLabel *memoLabel;
    QLineEdit *memoEdit;
    QCheckBox *endCheckBox;
    QLabel *endLabel;

    void setupUi(QWidget *DepForm)
    {
        if (DepForm->objectName().isEmpty())
            DepForm->setObjectName(QString::fromUtf8("DepForm"));
        DepForm->resize(815, 470);
        verticalLayout = new QVBoxLayout(DepForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(DepForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(5);
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
        newButton->setEnabled(true);
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
        gridLayoutWidget->setGeometry(QRect(10, 30, 361, 174));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        personLabel = new QLabel(gridLayoutWidget);
        personLabel->setObjectName(QString::fromUtf8("personLabel"));
        sizePolicy1.setHeightForWidth(personLabel->sizePolicy().hasHeightForWidth());
        personLabel->setSizePolicy(sizePolicy1);
        personLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(personLabel, 2, 0, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy1.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy1);
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        codeLabel = new QLabel(gridLayoutWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        sizePolicy2.setHeightForWidth(codeLabel->sizePolicy().hasHeightForWidth());
        codeLabel->setSizePolicy(sizePolicy2);
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        personEdit = new QLineEdit(gridLayoutWidget);
        personEdit->setObjectName(QString::fromUtf8("personEdit"));
        sizePolicy2.setHeightForWidth(personEdit->sizePolicy().hasHeightForWidth());
        personEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(personEdit, 2, 1, 1, 1);

        addrEdit = new QLineEdit(gridLayoutWidget);
        addrEdit->setObjectName(QString::fromUtf8("addrEdit"));

        gridLayout->addWidget(addrEdit, 5, 1, 1, 2);

        telEdit = new QLineEdit(gridLayoutWidget);
        telEdit->setObjectName(QString::fromUtf8("telEdit"));
        sizePolicy2.setHeightForWidth(telEdit->sizePolicy().hasHeightForWidth());
        telEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(telEdit, 4, 1, 1, 1);

        addrLabel = new QLabel(gridLayoutWidget);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));
        sizePolicy1.setHeightForWidth(addrLabel->sizePolicy().hasHeightForWidth());
        addrLabel->setSizePolicy(sizePolicy1);
        addrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(addrLabel, 5, 0, 1, 1);

        codeEdit = new QLineEdit(gridLayoutWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy2.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        telLabel = new QLabel(gridLayoutWidget);
        telLabel->setObjectName(QString::fromUtf8("telLabel"));
        sizePolicy1.setHeightForWidth(telLabel->sizePolicy().hasHeightForWidth());
        telLabel->setSizePolicy(sizePolicy1);
        telLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(telLabel, 4, 0, 1, 1);

        memoLabel = new QLabel(gridLayoutWidget);
        memoLabel->setObjectName(QString::fromUtf8("memoLabel"));
        memoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(memoLabel, 6, 0, 1, 1);

        memoEdit = new QLineEdit(gridLayoutWidget);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));
        memoEdit->setCursorMoveStyle(Qt::VisualMoveStyle);

        gridLayout->addWidget(memoEdit, 6, 1, 1, 2);

        endCheckBox = new QCheckBox(gridLayoutWidget);
        endCheckBox->setObjectName(QString::fromUtf8("endCheckBox"));

        gridLayout->addWidget(endCheckBox, 3, 1, 1, 1);

        endLabel = new QLabel(gridLayoutWidget);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        sizePolicy1.setHeightForWidth(endLabel->sizePolicy().hasHeightForWidth());
        endLabel->setSizePolicy(sizePolicy1);
        endLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(endLabel, 3, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, personEdit);
        QWidget::setTabOrder(personEdit, telEdit);
        QWidget::setTabOrder(telEdit, addrEdit);
        QWidget::setTabOrder(addrEdit, memoEdit);
        QWidget::setTabOrder(memoEdit, newButton);
        QWidget::setTabOrder(newButton, editButton);
        QWidget::setTabOrder(editButton, saveButton);
        QWidget::setTabOrder(saveButton, delButton);
        QWidget::setTabOrder(delButton, cancelButton);
        QWidget::setTabOrder(cancelButton, treeView);

        retranslateUi(DepForm);

        QMetaObject::connectSlotsByName(DepForm);
    } // setupUi

    void retranslateUi(QWidget *DepForm)
    {
        DepForm->setWindowTitle(QApplication::translate("DepForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("DepForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("DepForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("DepForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("DepForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("DepForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        groupBox->setTitle(QApplication::translate("DepForm", "Department Information", 0, QApplication::UnicodeUTF8));
        personLabel->setText(QApplication::translate("DepForm", "\350\264\237\350\264\243\344\272\272:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("DepForm", "\351\203\250\351\227\250\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DepForm", "** *** \344\276\213\345\246\202:01001", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("DepForm", "\351\203\250\351\227\250\347\274\226\347\240\201:", 0, QApplication::UnicodeUTF8));
        addrLabel->setText(QApplication::translate("DepForm", "\351\203\250\351\227\250\345\234\260\345\235\200:", 0, QApplication::UnicodeUTF8));
        codeEdit->setInputMask(QApplication::translate("DepForm", "99999; ", 0, QApplication::UnicodeUTF8));
        telLabel->setText(QApplication::translate("DepForm", "\351\203\250\351\227\250\347\224\265\350\257\235:", 0, QApplication::UnicodeUTF8));
        memoLabel->setText(QApplication::translate("DepForm", "    \345\244\207\346\263\250:", 0, QApplication::UnicodeUTF8));
        endCheckBox->setText(QString());
        endLabel->setText(QApplication::translate("DepForm", "Is End:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DepForm: public Ui_DepForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPFORM_H
