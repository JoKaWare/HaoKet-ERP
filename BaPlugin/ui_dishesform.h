/********************************************************************************
** Form generated from reading UI file 'dishesform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHESFORM_H
#define UI_DISHESFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DishesForm
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *cancelButton;
    QPushButton *delButton;
    QPushButton *newButton;
    QPushButton *editButton;
    QLabel *label_4;
    QGridLayout *gridLayout_4;
    QLineEdit *nameEdit;
    QLineEdit *pinyinEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPinyin;
    QToolButton *queryButton;
    QComboBox *typeComboBox;
    QLabel *labelName;
    QLabel *labelType;
    QTableView *tableView;

    void setupUi(QWidget *DishesForm)
    {
        if (DishesForm->objectName().isEmpty())
            DishesForm->setObjectName(QString::fromUtf8("DishesForm"));
        DishesForm->resize(1075, 526);
        verticalLayout = new QVBoxLayout(DishesForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(DishesForm);
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
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cancelButton = new QPushButton(frame_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon);
        cancelButton->setIconSize(QSize(24, 24));
        cancelButton->setDefault(true);
        cancelButton->setFlat(false);

        gridLayout->addWidget(cancelButton, 0, 3, 1, 1);

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

        gridLayout->addWidget(delButton, 0, 2, 1, 1);

        newButton = new QPushButton(frame_2);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        sizePolicy2.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon2);
        newButton->setIconSize(QSize(24, 24));
        newButton->setAutoRepeat(false);
        newButton->setAutoExclusive(false);
        newButton->setDefault(true);
        newButton->setFlat(false);

        gridLayout->addWidget(newButton, 0, 0, 1, 1);

        editButton = new QPushButton(frame_2);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        sizePolicy2.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editButton->setIcon(icon3);
        editButton->setIconSize(QSize(24, 24));
        editButton->setAutoDefault(true);
        editButton->setDefault(true);

        gridLayout->addWidget(editButton, 0, 1, 1, 1);

        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 4, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        nameEdit = new QLineEdit(frame_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(nameEdit, 0, 2, 1, 1);

        pinyinEdit = new QLineEdit(frame_2);
        pinyinEdit->setObjectName(QString::fromUtf8("pinyinEdit"));
        sizePolicy2.setHeightForWidth(pinyinEdit->sizePolicy().hasHeightForWidth());
        pinyinEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pinyinEdit, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 0, 1, 1);

        labelPinyin = new QLabel(frame_2);
        labelPinyin->setObjectName(QString::fromUtf8("labelPinyin"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelPinyin->sizePolicy().hasHeightForWidth());
        labelPinyin->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(labelPinyin, 0, 3, 1, 1);

        queryButton = new QToolButton(frame_2);
        queryButton->setObjectName(QString::fromUtf8("queryButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/search_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        queryButton->setIcon(icon4);
        queryButton->setIconSize(QSize(24, 24));
        queryButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_4->addWidget(queryButton, 0, 5, 1, 1);

        typeComboBox = new QComboBox(frame_2);
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));
        typeComboBox->setEditable(true);

        gridLayout_4->addWidget(typeComboBox, 1, 2, 1, 1);

        labelName = new QLabel(frame_2);
        labelName->setObjectName(QString::fromUtf8("labelName"));
        sizePolicy3.setHeightForWidth(labelName->sizePolicy().hasHeightForWidth());
        labelName->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(labelName, 0, 1, 1, 1);

        labelType = new QLabel(frame_2);
        labelType->setObjectName(QString::fromUtf8("labelType"));

        gridLayout_4->addWidget(labelType, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 5, 1, 1);


        gridLayout_3->addWidget(frame_2, 0, 0, 1, 1);

        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_3->addWidget(tableView, 1, 0, 1, 1);

        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);


        retranslateUi(DishesForm);

        QMetaObject::connectSlotsByName(DishesForm);
    } // setupUi

    void retranslateUi(QWidget *DishesForm)
    {
        DishesForm->setWindowTitle(QApplication::translate("DishesForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("DishesForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("DishesForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("DishesForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("DishesForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        label_4->setText(QString());
        labelPinyin->setText(QApplication::translate("DishesForm", "\346\213\274\351\237\263\347\274\226\347\240\201:", 0, QApplication::UnicodeUTF8));
        queryButton->setText(QApplication::translate("DishesForm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        labelName->setText(QApplication::translate("DishesForm", "\350\217\234\345\223\201\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        labelType->setText(QApplication::translate("DishesForm", "\350\217\234\345\223\201\347\261\273\345\210\253:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DishesForm: public Ui_DishesForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHESFORM_H
