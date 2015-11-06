/********************************************************************************
** Form generated from reading UI file 'pusetdialog.ui'
**
** Created: Fri Nov 6 10:52:07 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUSETDIALOG_H
#define UI_PUSETDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PuSetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QCheckBox *arrivalMrdChk;
    QCheckBox *hathOrderChk;
    QSpacerItem *horizontalSpacer;
    QCheckBox *useDefineChk;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *okButton;
    QToolButton *cancelButton;

    void setupUi(QDialog *PuSetDialog)
    {
        if (PuSetDialog->objectName().isEmpty())
            PuSetDialog->setObjectName(QString::fromUtf8("PuSetDialog"));
        PuSetDialog->resize(442, 215);
        verticalLayout = new QVBoxLayout(PuSetDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(PuSetDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        arrivalMrdChk = new QCheckBox(groupBox);
        arrivalMrdChk->setObjectName(QString::fromUtf8("arrivalMrdChk"));
        arrivalMrdChk->setCheckable(true);

        gridLayout->addWidget(arrivalMrdChk, 1, 0, 1, 1);

        hathOrderChk = new QCheckBox(groupBox);
        hathOrderChk->setObjectName(QString::fromUtf8("hathOrderChk"));

        gridLayout->addWidget(hathOrderChk, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        useDefineChk = new QCheckBox(groupBox);
        useDefineChk->setObjectName(QString::fromUtf8("useDefineChk"));

        gridLayout->addWidget(useDefineChk, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 56, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);

        frame = new QFrame(PuSetDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(427, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        okButton = new QToolButton(frame);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon);
        okButton->setIconSize(QSize(24, 24));
        okButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(okButton);

        cancelButton = new QToolButton(frame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/cancel_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon1);
        cancelButton->setIconSize(QSize(24, 24));
        cancelButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addWidget(frame);


        retranslateUi(PuSetDialog);

        QMetaObject::connectSlotsByName(PuSetDialog);
    } // setupUi

    void retranslateUi(QDialog *PuSetDialog)
    {
        PuSetDialog->setWindowTitle(QApplication::translate("PuSetDialog", "\351\207\207\350\264\255\350\256\276\347\275\256\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PuSetDialog", "\351\207\207\350\264\255\344\270\232\345\212\241\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        arrivalMrdChk->setText(QApplication::translate("PuSetDialog", "\345\210\260\350\264\247\345\256\241\346\240\270\347\224\237\346\210\220\345\205\245\345\272\223", 0, QApplication::UnicodeUTF8));
        hathOrderChk->setText(QApplication::translate("PuSetDialog", "\351\207\207\350\264\255\344\270\232\345\212\241\345\277\205\346\234\211\350\256\242\345\215\225", 0, QApplication::UnicodeUTF8));
        useDefineChk->setText(QApplication::translate("PuSetDialog", "\346\230\257\345\220\246\344\275\277\347\224\250\350\207\252\345\256\232\344\271\211\345\255\227\346\256\265", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("PuSetDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("PuSetDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PuSetDialog: public Ui_PuSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUSETDIALOG_H
