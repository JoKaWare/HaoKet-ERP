/********************************************************************************
** Form generated from reading UI file 'dinnerform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINNERFORM_H
#define UI_DINNERFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DinnerForm
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
    QLabel *lostLabel;
    QLabel *addrLabel;
    QLabel *personLabel;
    QLineEdit *codeEdit;
    QCheckBox *checkBox;
    QLabel *serviceLabel;
    QComboBox *areaComboBox;
    QSpinBox *numberSpin;
    QLineEdit *nameEdit;
    QLabel *telLabel;
    QLabel *nameLabel;
    QComboBox *typeComboBox;
    QLabel *codeLabel;
    QLabel *memoLabel;
    QLineEdit *memoEdit;
    QDoubleSpinBox *lostSpinBox;

    void setupUi(QWidget *DinnerForm)
    {
        if (DinnerForm->objectName().isEmpty())
            DinnerForm->setObjectName(QString::fromUtf8("DinnerForm"));
        DinnerForm->resize(789, 405);
        verticalLayout = new QVBoxLayout(DinnerForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(DinnerForm);
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
        gridLayoutWidget->setGeometry(QRect(10, 30, 371, 197));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lostLabel = new QLabel(gridLayoutWidget);
        lostLabel->setObjectName(QString::fromUtf8("lostLabel"));
        sizePolicy2.setHeightForWidth(lostLabel->sizePolicy().hasHeightForWidth());
        lostLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(lostLabel, 8, 0, 1, 1);

        addrLabel = new QLabel(gridLayoutWidget);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));
        sizePolicy2.setHeightForWidth(addrLabel->sizePolicy().hasHeightForWidth());
        addrLabel->setSizePolicy(sizePolicy2);
        addrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(addrLabel, 4, 0, 1, 1);

        personLabel = new QLabel(gridLayoutWidget);
        personLabel->setObjectName(QString::fromUtf8("personLabel"));
        sizePolicy2.setHeightForWidth(personLabel->sizePolicy().hasHeightForWidth());
        personLabel->setSizePolicy(sizePolicy2);
        personLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(personLabel, 2, 0, 1, 1);

        codeEdit = new QLineEdit(gridLayoutWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy2.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(false);

        gridLayout->addWidget(checkBox, 7, 1, 1, 1);

        serviceLabel = new QLabel(gridLayoutWidget);
        serviceLabel->setObjectName(QString::fromUtf8("serviceLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(serviceLabel->sizePolicy().hasHeightForWidth());
        serviceLabel->setSizePolicy(sizePolicy3);
        serviceLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(serviceLabel, 7, 0, 1, 1);

        areaComboBox = new QComboBox(gridLayoutWidget);
        areaComboBox->setObjectName(QString::fromUtf8("areaComboBox"));
        sizePolicy2.setHeightForWidth(areaComboBox->sizePolicy().hasHeightForWidth());
        areaComboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(areaComboBox, 2, 1, 1, 1);

        numberSpin = new QSpinBox(gridLayoutWidget);
        numberSpin->setObjectName(QString::fromUtf8("numberSpin"));
        sizePolicy2.setHeightForWidth(numberSpin->sizePolicy().hasHeightForWidth());
        numberSpin->setSizePolicy(sizePolicy2);
        numberSpin->setValue(8);

        gridLayout->addWidget(numberSpin, 4, 1, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        telLabel = new QLabel(gridLayoutWidget);
        telLabel->setObjectName(QString::fromUtf8("telLabel"));
        sizePolicy2.setHeightForWidth(telLabel->sizePolicy().hasHeightForWidth());
        telLabel->setSizePolicy(sizePolicy2);
        telLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(telLabel, 3, 0, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy2.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy2);
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        typeComboBox = new QComboBox(gridLayoutWidget);
        typeComboBox->setObjectName(QString::fromUtf8("typeComboBox"));
        sizePolicy2.setHeightForWidth(typeComboBox->sizePolicy().hasHeightForWidth());
        typeComboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(typeComboBox, 3, 1, 1, 1);

        codeLabel = new QLabel(gridLayoutWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        sizePolicy2.setHeightForWidth(codeLabel->sizePolicy().hasHeightForWidth());
        codeLabel->setSizePolicy(sizePolicy2);
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        memoLabel = new QLabel(gridLayoutWidget);
        memoLabel->setObjectName(QString::fromUtf8("memoLabel"));
        sizePolicy2.setHeightForWidth(memoLabel->sizePolicy().hasHeightForWidth());
        memoLabel->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(memoLabel, 9, 0, 1, 1);

        memoEdit = new QLineEdit(gridLayoutWidget);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        gridLayout->addWidget(memoEdit, 9, 1, 1, 1);

        lostSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        lostSpinBox->setObjectName(QString::fromUtf8("lostSpinBox"));
        sizePolicy2.setHeightForWidth(lostSpinBox->sizePolicy().hasHeightForWidth());
        lostSpinBox->setSizePolicy(sizePolicy2);
        lostSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        lostSpinBox->setMaximum(9999.99);

        gridLayout->addWidget(lostSpinBox, 8, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, areaComboBox);
        QWidget::setTabOrder(areaComboBox, typeComboBox);
        QWidget::setTabOrder(typeComboBox, numberSpin);
        QWidget::setTabOrder(numberSpin, checkBox);
        QWidget::setTabOrder(checkBox, cancelButton);
        QWidget::setTabOrder(cancelButton, treeView);
        QWidget::setTabOrder(treeView, delButton);
        QWidget::setTabOrder(delButton, saveButton);
        QWidget::setTabOrder(saveButton, editButton);
        QWidget::setTabOrder(editButton, newButton);

        retranslateUi(DinnerForm);

        QMetaObject::connectSlotsByName(DinnerForm);
    } // setupUi

    void retranslateUi(QWidget *DinnerForm)
    {
        DinnerForm->setWindowTitle(QApplication::translate("DinnerForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("DinnerForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("DinnerForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("DinnerForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("DinnerForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("DinnerForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        groupBox->setTitle(QApplication::translate("DinnerForm", "Dinner", 0, QApplication::UnicodeUTF8));
        lostLabel->setText(QApplication::translate("DinnerForm", "Lost Consumption:", 0, QApplication::UnicodeUTF8));
        addrLabel->setText(QApplication::translate("DinnerForm", "Number:", 0, QApplication::UnicodeUTF8));
        personLabel->setText(QApplication::translate("DinnerForm", "Dinner Area:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        serviceLabel->setText(QApplication::translate("DinnerForm", "Is Service:", 0, QApplication::UnicodeUTF8));
        telLabel->setText(QApplication::translate("DinnerForm", "Dinner Type:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("DinnerForm", "Dinner Name:", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("DinnerForm", "Dinner Code:", 0, QApplication::UnicodeUTF8));
        memoLabel->setText(QApplication::translate("DinnerForm", "Memo:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DinnerForm: public Ui_DinnerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINNERFORM_H
