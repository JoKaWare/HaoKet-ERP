/********************************************************************************
** Form generated from reading UI file 'ReportBand.ui'
**
** Created: Thu Jul 10 16:17:56 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTBAND_H
#define UI_REPORTBAND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../CommonFiles/qlabelex.h"

QT_BEGIN_NAMESPACE

class Ui_ReportBand
{
public:
    QVBoxLayout *verticalLayout;
    QLabelEx *lblBandType;
    QWidget *conWidget;

    void setupUi(QWidget *ReportBand)
    {
        if (ReportBand->objectName().isEmpty())
            ReportBand->setObjectName(QString::fromUtf8("ReportBand"));
        ReportBand->resize(673, 65);
        ReportBand->setContextMenuPolicy(Qt::ActionsContextMenu);
        ReportBand->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayout = new QVBoxLayout(ReportBand);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lblBandType = new QLabelEx(ReportBand);
        lblBandType->setObjectName(QString::fromUtf8("lblBandType"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblBandType->sizePolicy().hasHeightForWidth());
        lblBandType->setSizePolicy(sizePolicy);
        lblBandType->setAutoFillBackground(false);
        lblBandType->setStyleSheet(QString::fromUtf8(""));
        lblBandType->setFrameShape(QFrame::NoFrame);
        lblBandType->setText(QString::fromUtf8("TextLabel"));
        lblBandType->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblBandType);

        conWidget = new QWidget(ReportBand);
        conWidget->setObjectName(QString::fromUtf8("conWidget"));
        conWidget->setAcceptDrops(true);
        conWidget->setAutoFillBackground(false);
        conWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(conWidget);


        retranslateUi(ReportBand);

        QMetaObject::connectSlotsByName(ReportBand);
    } // setupUi

    void retranslateUi(QWidget *ReportBand)
    {
        Q_UNUSED(ReportBand);
    } // retranslateUi

};

namespace Ui {
    class ReportBand: public Ui_ReportBand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTBAND_H
