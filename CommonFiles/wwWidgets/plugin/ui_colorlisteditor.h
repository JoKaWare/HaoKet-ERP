/********************************************************************************
** Form generated from reading UI file 'colorlisteditor.ui'
**
** Created: Sat Jun 29 09:35:15 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORLISTEDITOR_H
#define UI_COLORLISTEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ColorListEditor
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QListView *list;
    QVBoxLayout *vboxLayout1;
    QToolButton *standardColors;
    QToolButton *clear;
    QSpacerItem *spacerItem;
    QToolButton *up;
    QToolButton *down;
    QHBoxLayout *hboxLayout1;
    QHBoxLayout *hboxLayout2;
    QToolButton *plus;
    QToolButton *minus;
    QSpacerItem *spacerItem1;
    QLabel *label;
    QToolButton *chooseColor;
    QLabel *label_2;
    QLineEdit *name;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ColorListEditor)
    {
        if (ColorListEditor->objectName().isEmpty())
            ColorListEditor->setObjectName(QString::fromUtf8("ColorListEditor"));
        ColorListEditor->resize(301, 300);
        vboxLayout = new QVBoxLayout(ColorListEditor);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        list = new QListView(ColorListEditor);
        list->setObjectName(QString::fromUtf8("list"));

        hboxLayout->addWidget(list);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        standardColors = new QToolButton(ColorListEditor);
        standardColors->setObjectName(QString::fromUtf8("standardColors"));
        standardColors->setPopupMode(QToolButton::MenuButtonPopup);

        vboxLayout1->addWidget(standardColors);

        clear = new QToolButton(ColorListEditor);
        clear->setObjectName(QString::fromUtf8("clear"));

        vboxLayout1->addWidget(clear);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);

        up = new QToolButton(ColorListEditor);
        up->setObjectName(QString::fromUtf8("up"));
        up->setAutoRepeat(true);

        vboxLayout1->addWidget(up);

        down = new QToolButton(ColorListEditor);
        down->setObjectName(QString::fromUtf8("down"));
        down->setAutoRepeat(true);

        vboxLayout1->addWidget(down);


        hboxLayout->addLayout(vboxLayout1);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        plus = new QToolButton(ColorListEditor);
        plus->setObjectName(QString::fromUtf8("plus"));

        hboxLayout2->addWidget(plus);

        minus = new QToolButton(ColorListEditor);
        minus->setObjectName(QString::fromUtf8("minus"));

        hboxLayout2->addWidget(minus);


        hboxLayout1->addLayout(hboxLayout2);

        spacerItem1 = new QSpacerItem(16, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        label = new QLabel(ColorListEditor);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout1->addWidget(label);

        chooseColor = new QToolButton(ColorListEditor);
        chooseColor->setObjectName(QString::fromUtf8("chooseColor"));

        hboxLayout1->addWidget(chooseColor);

        label_2 = new QLabel(ColorListEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout1->addWidget(label_2);

        name = new QLineEdit(ColorListEditor);
        name->setObjectName(QString::fromUtf8("name"));

        hboxLayout1->addWidget(name);


        vboxLayout->addLayout(hboxLayout1);

        buttonBox = new QDialogButtonBox(ColorListEditor);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(ColorListEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorListEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorListEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(ColorListEditor);
    } // setupUi

    void retranslateUi(QDialog *ColorListEditor)
    {
        ColorListEditor->setWindowTitle(QApplication::translate("ColorListEditor", "Edit colors", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        list->setWhatsThis(QApplication::translate("ColorListEditor", "This list contains all colors that are to be assigned to the widget", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_TOOLTIP
        standardColors->setToolTip(QApplication::translate("ColorListEditor", "Set a colormap", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        standardColors->setWhatsThis(QApplication::translate("ColorListEditor", "Fills the list with a color map. Hold down for a list of available maps", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        standardColors->setText(QString());
#ifndef QT_NO_TOOLTIP
        clear->setToolTip(QApplication::translate("ColorListEditor", "Clear the list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        clear->setWhatsThis(QApplication::translate("ColorListEditor", "Removes all entries from the list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        clear->setText(QString());
#ifndef QT_NO_TOOLTIP
        up->setToolTip(QApplication::translate("ColorListEditor", "Move item up", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        up->setText(QString());
#ifndef QT_NO_TOOLTIP
        down->setToolTip(QApplication::translate("ColorListEditor", "Move item down", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        down->setText(QString());
#ifndef QT_NO_TOOLTIP
        plus->setToolTip(QApplication::translate("ColorListEditor", "Add new item", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        plus->setText(QString());
#ifndef QT_NO_TOOLTIP
        minus->setToolTip(QApplication::translate("ColorListEditor", "Remove current item", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        minus->setText(QString());
        label->setText(QApplication::translate("ColorListEditor", "Color:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        chooseColor->setToolTip(QApplication::translate("ColorListEditor", "Choose color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        chooseColor->setText(QApplication::translate("ColorListEditor", "?", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ColorListEditor", "Name:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        name->setToolTip(QApplication::translate("ColorListEditor", "Enter color label", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class ColorListEditor: public Ui_ColorListEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORLISTEDITOR_H
