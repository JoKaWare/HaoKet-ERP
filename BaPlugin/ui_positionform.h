/********************************************************************************
** Form generated from reading UI file 'positionform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSITIONFORM_H
#define UI_POSITIONFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
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
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qksearcheditbox.h"

QT_BEGIN_NAMESPACE

class Ui_PositionForm
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTableView *tableView;
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
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *sumSpinBox;
    QLabel *label_5;
    QLineEdit *memoEdit;
    QLabel *label_6;
    QComboBox *unitComboBox;
    QLineEdit *areaEdit;
    QCheckBox *statusCheckBox;
    QLineEdit *descEdit;
    QkSearchEditBox *qksearcheditbox;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label_8;
    QSpinBox *levelSpinBox;
    QLabel *label;
    QLineEdit *codeEdit;
    QLineEdit *nameEdit;
    QLabel *captionLabel_2;
    QLabel *nameLabel_2;

    void setupUi(QWidget *PositionForm)
    {
        if (PositionForm->objectName().isEmpty())
            PositionForm->setObjectName(QString::fromUtf8("PositionForm"));
        PositionForm->resize(905, 485);
        verticalLayout = new QVBoxLayout(PositionForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(PositionForm);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setTextElideMode(Qt::ElideLeft);
        splitter->addWidget(tableView);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        newButton = new QPushButton(frame_2);
        newButton->setObjectName(QString::fromUtf8("newButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(delButton->sizePolicy().hasHeightForWidth());
        delButton->setSizePolicy(sizePolicy1);
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
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon2);
        cancelButton->setIconSize(QSize(24, 24));
        cancelButton->setDefault(true);
        cancelButton->setFlat(false);

        gridLayout_2->addWidget(cancelButton, 0, 4, 1, 1);

        saveButton = new QPushButton(frame_2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        sizePolicy1.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy1);
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
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 30, 421, 272));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_4, 5, 0, 1, 1);

        sumSpinBox = new QSpinBox(gridLayoutWidget_2);
        sumSpinBox->setObjectName(QString::fromUtf8("sumSpinBox"));
        sizePolicy1.setHeightForWidth(sumSpinBox->sizePolicy().hasHeightForWidth());
        sumSpinBox->setSizePolicy(sizePolicy1);
        sumSpinBox->setMaximum(999999);

        gridLayout_4->addWidget(sumSpinBox, 4, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_5, 6, 0, 1, 1);

        memoEdit = new QLineEdit(gridLayoutWidget_2);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        gridLayout_4->addWidget(memoEdit, 9, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_6, 7, 0, 1, 1);

        unitComboBox = new QComboBox(gridLayoutWidget_2);
        unitComboBox->setObjectName(QString::fromUtf8("unitComboBox"));
        sizePolicy1.setHeightForWidth(unitComboBox->sizePolicy().hasHeightForWidth());
        unitComboBox->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(unitComboBox, 3, 1, 1, 1);

        areaEdit = new QLineEdit(gridLayoutWidget_2);
        areaEdit->setObjectName(QString::fromUtf8("areaEdit"));
        sizePolicy1.setHeightForWidth(areaEdit->sizePolicy().hasHeightForWidth());
        areaEdit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(areaEdit, 5, 1, 1, 1);

        statusCheckBox = new QCheckBox(gridLayoutWidget_2);
        statusCheckBox->setObjectName(QString::fromUtf8("statusCheckBox"));

        gridLayout_4->addWidget(statusCheckBox, 8, 1, 1, 1);

        descEdit = new QLineEdit(gridLayoutWidget_2);
        descEdit->setObjectName(QString::fromUtf8("descEdit"));

        gridLayout_4->addWidget(descEdit, 6, 1, 1, 1);

        qksearcheditbox = new QkSearchEditBox(gridLayoutWidget_2);
        qksearcheditbox->setObjectName(QString::fromUtf8("qksearcheditbox"));
        sizePolicy1.setHeightForWidth(qksearcheditbox->sizePolicy().hasHeightForWidth());
        qksearcheditbox->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(qksearcheditbox, 2, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_7, 8, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_2, 3, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_8, 9, 0, 1, 1);

        levelSpinBox = new QSpinBox(gridLayoutWidget_2);
        levelSpinBox->setObjectName(QString::fromUtf8("levelSpinBox"));
        sizePolicy1.setHeightForWidth(levelSpinBox->sizePolicy().hasHeightForWidth());
        levelSpinBox->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(levelSpinBox, 7, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        codeEdit = new QLineEdit(gridLayoutWidget_2);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy1.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(codeEdit, 0, 1, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy1.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(nameEdit, 1, 1, 1, 1);

        captionLabel_2 = new QLabel(gridLayoutWidget_2);
        captionLabel_2->setObjectName(QString::fromUtf8("captionLabel_2"));
        captionLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(captionLabel_2, 2, 0, 1, 1);

        nameLabel_2 = new QLabel(gridLayoutWidget_2);
        nameLabel_2->setObjectName(QString::fromUtf8("nameLabel_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nameLabel_2->sizePolicy().hasHeightForWidth());
        nameLabel_2->setSizePolicy(sizePolicy2);
        nameLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(nameLabel_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, qksearcheditbox);
        QWidget::setTabOrder(qksearcheditbox, unitComboBox);
        QWidget::setTabOrder(unitComboBox, sumSpinBox);
        QWidget::setTabOrder(sumSpinBox, areaEdit);
        QWidget::setTabOrder(areaEdit, descEdit);
        QWidget::setTabOrder(descEdit, levelSpinBox);
        QWidget::setTabOrder(levelSpinBox, statusCheckBox);
        QWidget::setTabOrder(statusCheckBox, memoEdit);
        QWidget::setTabOrder(memoEdit, newButton);
        QWidget::setTabOrder(newButton, editButton);
        QWidget::setTabOrder(editButton, saveButton);
        QWidget::setTabOrder(saveButton, delButton);
        QWidget::setTabOrder(delButton, cancelButton);
        QWidget::setTabOrder(cancelButton, tableView);

        retranslateUi(PositionForm);

        QMetaObject::connectSlotsByName(PositionForm);
    } // setupUi

    void retranslateUi(QWidget *PositionForm)
    {
        PositionForm->setWindowTitle(QApplication::translate("PositionForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("PositionForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("PositionForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("PositionForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("PositionForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("PositionForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        groupBox->setTitle(QApplication::translate("PositionForm", "Position Information", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PositionForm", "Top Sum:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PositionForm", "Position Area:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PositionForm", "Position Desc:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PositionForm", "Position Level:", 0, QApplication::UnicodeUTF8));
        statusCheckBox->setText(QApplication::translate("PositionForm", "Is Stop", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PositionForm", "Status:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PositionForm", "Position Unit:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("PositionForm", "Memo:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PositionForm", "Position Code:", 0, QApplication::UnicodeUTF8));
        captionLabel_2->setText(QApplication::translate("PositionForm", "Warehouse:", 0, QApplication::UnicodeUTF8));
        nameLabel_2->setText(QApplication::translate("PositionForm", "Position Name:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PositionForm: public Ui_PositionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSITIONFORM_H
