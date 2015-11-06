/********************************************************************************
** Form generated from reading UI file 'sasetdialog.ui'
**
** Created: Fri Nov 6 10:53:11 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SASETDIALOG_H
#define UI_SASETDIALOG_H

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

class Ui_SaSetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *arrivalMrdChk;
    QCheckBox *hathOrderChk;
    QCheckBox *overtopChk;
    QSpacerItem *verticalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *okButton;
    QToolButton *cancelButton;

    void setupUi(QDialog *SaSetDialog)
    {
        if (SaSetDialog->objectName().isEmpty())
            SaSetDialog->setObjectName(QString::fromUtf8("SaSetDialog"));
        SaSetDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(SaSetDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(SaSetDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        arrivalMrdChk = new QCheckBox(groupBox);
        arrivalMrdChk->setObjectName(QString::fromUtf8("arrivalMrdChk"));
        arrivalMrdChk->setCheckable(true);

        gridLayout->addWidget(arrivalMrdChk, 1, 0, 1, 1);

        hathOrderChk = new QCheckBox(groupBox);
        hathOrderChk->setObjectName(QString::fromUtf8("hathOrderChk"));

        gridLayout->addWidget(hathOrderChk, 0, 0, 1, 1);

        overtopChk = new QCheckBox(groupBox);
        overtopChk->setObjectName(QString::fromUtf8("overtopChk"));

        gridLayout->addWidget(overtopChk, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 56, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);

        frame = new QFrame(SaSetDialog);
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


        retranslateUi(SaSetDialog);

        QMetaObject::connectSlotsByName(SaSetDialog);
    } // setupUi

    void retranslateUi(QDialog *SaSetDialog)
    {
        SaSetDialog->setWindowTitle(QApplication::translate("SaSetDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SaSetDialog", " \351\224\200\345\224\256\344\270\232\345\212\241\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
        arrivalMrdChk->setText(QApplication::translate("SaSetDialog", "\345\217\221\350\264\247\345\256\241\346\240\270\347\224\237\346\210\220\345\205\245\345\272\223", 0, QApplication::UnicodeUTF8));
        hathOrderChk->setText(QApplication::translate("SaSetDialog", "\351\224\200\345\224\256\344\270\232\345\212\241\345\277\205\346\234\211\350\256\242\345\215\225", 0, QApplication::UnicodeUTF8));
        overtopChk->setText(QApplication::translate("SaSetDialog", "\345\205\201\350\256\270\350\266\205\345\225\206\345\223\201\345\217\257\347\224\250\351\207\217\345\217\221\350\264\247", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("SaSetDialog", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("SaSetDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SaSetDialog: public Ui_SaSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SASETDIALOG_H
