/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created: Sat Jun 29 09:35:15 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *groupPolicy;

    void setupUi(QWidget *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(299, 208);
        vboxLayout = new QVBoxLayout(About);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        label = new QLabel(About);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));

        vboxLayout->addWidget(label);

        label_3 = new QLabel(About);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(label_3);

        label_4 = new QLabel(About);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setWordWrap(true);

        vboxLayout->addWidget(label_4);

        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setOpenExternalLinks(true);

        vboxLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(About);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        groupPolicy = new QComboBox(About);
        groupPolicy->setObjectName(QString::fromUtf8("groupPolicy"));

        horizontalLayout->addWidget(groupPolicy);


        vboxLayout->addLayout(horizontalLayout);


        retranslateUi(About);

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QWidget *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About wwWidgets", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_3->setText(QApplication::translate("About", "Version 1.0.0", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("About", "A set of useful widgets and a Qt Designer plugin for Qt4.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Copyright &copy; 2007-2010 by Witold Wysota</p><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://www.wysota.eu.org/wwwidgets\">http://www.wysota.eu.org/wwwidgets</a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("About", "Display wwWidgets as:", 0, QApplication::UnicodeUTF8));
        groupPolicy->clear();
        groupPolicy->insertItems(0, QStringList()
         << QApplication::translate("About", "Separate groups", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("About", "Default groups", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("About", "One custom group", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
