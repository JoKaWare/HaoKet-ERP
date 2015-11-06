/********************************************************************************
** Form generated from reading UI file 'structuredialog.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRUCTUREDIALOG_H
#define UI_STRUCTUREDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_StructureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *newButton;
    QToolButton *delRowButton;
    QToolButton *saveButton;
    QToolButton *printButton;
    QToolButton *cancelButton;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *unitEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *styleEdit;
    QkSearchEditBox *productSearchEditbox;
    QLineEdit *makeEdit;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_6;
    QCheckBox *reckonCheckBox;
    QLabel *label_4;
    QkSearchEditBox *depSearchEditbox;
    QTableWidget *tableWidget;

    void setupUi(QDialog *StructureDialog)
    {
        if (StructureDialog->objectName().isEmpty())
            StructureDialog->setObjectName(QString::fromUtf8("StructureDialog"));
        StructureDialog->resize(890, 558);
        verticalLayout = new QVBoxLayout(StructureDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(StructureDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(236, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        newButton = new QToolButton(groupBox_2);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon);
        newButton->setIconSize(QSize(24, 24));
        newButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(newButton);

        delRowButton = new QToolButton(groupBox_2);
        delRowButton->setObjectName(QString::fromUtf8("delRowButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        delRowButton->setIcon(icon1);
        delRowButton->setIconSize(QSize(24, 24));
        delRowButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(delRowButton);

        saveButton = new QToolButton(groupBox_2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon2);
        saveButton->setIconSize(QSize(24, 24));
        saveButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(saveButton);

        printButton = new QToolButton(groupBox_2);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/Print_48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        printButton->setIcon(icon3);
        printButton->setIconSize(QSize(24, 24));
        printButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(printButton);

        cancelButton = new QToolButton(groupBox_2);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon4);
        cancelButton->setIconSize(QSize(24, 24));
        cancelButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(StructureDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
#ifndef Q_OS_MAC
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
#endif
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        unitEdit = new QLineEdit(groupBox);
        unitEdit->setObjectName(QString::fromUtf8("unitEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(unitEdit->sizePolicy().hasHeightForWidth());
        unitEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(unitEdit, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 8, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 6, 1, 1);

        styleEdit = new QLineEdit(groupBox);
        styleEdit->setObjectName(QString::fromUtf8("styleEdit"));
        sizePolicy.setHeightForWidth(styleEdit->sizePolicy().hasHeightForWidth());
        styleEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(styleEdit, 0, 3, 1, 1);

        productSearchEditbox = new QkSearchEditBox(groupBox);
        productSearchEditbox->setObjectName(QString::fromUtf8("productSearchEditbox"));

        gridLayout->addWidget(productSearchEditbox, 0, 1, 1, 1);

        makeEdit = new QLineEdit(groupBox);
        makeEdit->setObjectName(QString::fromUtf8("makeEdit"));
        makeEdit->setReadOnly(true);

        gridLayout->addWidget(makeEdit, 0, 7, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 4, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        reckonCheckBox = new QCheckBox(groupBox);
        reckonCheckBox->setObjectName(QString::fromUtf8("reckonCheckBox"));

        gridLayout->addWidget(reckonCheckBox, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        depSearchEditbox = new QkSearchEditBox(groupBox);
        depSearchEditbox->setObjectName(QString::fromUtf8("depSearchEditbox"));

        gridLayout->addWidget(depSearchEditbox, 1, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);

        tableWidget = new QTableWidget(StructureDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(StructureDialog);

        QMetaObject::connectSlotsByName(StructureDialog);
    } // setupUi

    void retranslateUi(QDialog *StructureDialog)
    {
        StructureDialog->setWindowTitle(QApplication::translate("StructureDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        newButton->setText(QApplication::translate("StructureDialog", "\346\226\260\345\273\272", 0, QApplication::UnicodeUTF8));
        delRowButton->setText(QApplication::translate("StructureDialog", "\345\210\240\350\241\214", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("StructureDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        printButton->setText(QApplication::translate("StructureDialog", "\346\211\223\345\215\260", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("StructureDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StructureDialog", "\345\237\272\347\241\200", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StructureDialog", "\345\210\266\345\215\225\344\272\272\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StructureDialog", "\350\217\234\345\223\201\345\215\225\344\275\215:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StructureDialog", "\350\217\234\345\223\201\350\247\204\346\240\274:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StructureDialog", "\350\217\234\345\223\201\345\220\215\347\247\260:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("StructureDialog", "\346\230\257\345\220\246\345\200\222\346\216\250:", 0, QApplication::UnicodeUTF8));
        reckonCheckBox->setText(QApplication::translate("StructureDialog", "\350\276\223\345\205\245\345\272\223\345\255\230\345\200\222\346\216\250\347\256\227\345\216\237\346\226\231\346\215\237\350\200\227\351\207\217", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StructureDialog", "\351\203\250\351\227\250:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StructureDialog: public Ui_StructureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRUCTUREDIALOG_H
