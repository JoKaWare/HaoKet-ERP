/********************************************************************************
** Form generated from reading UI file 'rdqueryform.ui'
**
** Created: Fri Nov 6 10:51:11 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RDQUERYFORM_H
#define UI_RDQUERYFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RdQueryForm
{
public:
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer;
    QTableView *tableView;

    void setupUi(QWidget *RdQueryForm)
    {
        if (RdQueryForm->objectName().isEmpty())
            RdQueryForm->setObjectName(QString::fromUtf8("RdQueryForm"));
        RdQueryForm->resize(752, 447);
        verticalLayout = new QVBoxLayout(RdQueryForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton = new QToolButton(RdQueryForm);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        verticalLayout->addWidget(toolButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        tableView = new QTableView(RdQueryForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(RdQueryForm);

        QMetaObject::connectSlotsByName(RdQueryForm);
    } // setupUi

    void retranslateUi(QWidget *RdQueryForm)
    {
        RdQueryForm->setWindowTitle(QApplication::translate("RdQueryForm", "Form", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("RdQueryForm", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RdQueryForm: public Ui_RdQueryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RDQUERYFORM_H
