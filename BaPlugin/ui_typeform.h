/********************************************************************************
** Form generated from reading UI file 'typeform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TYPEFORM_H
#define UI_TYPEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TypeForm
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
    QLabel *codeLabel;
    QLabel *exLabel;
    QLineEdit *nameEdit;
    QDoubleSpinBox *discSpinBox;
    QCheckBox *discCheckBox;
    QLabel *label_3;
    QLineEdit *explianEdit;
    QLabel *label;
    QCheckBox *endCheckBox;
    QLabel *label_2;
    QLabel *endLabel;
    QLabel *nameLabel;
    QLabel *memoLabel;
    QLineEdit *memoEdit;
    QLineEdit *codeEdit;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *TypeForm)
    {
        if (TypeForm->objectName().isEmpty())
            TypeForm->setObjectName(QString::fromUtf8("TypeForm"));
        TypeForm->resize(902, 464);
        verticalLayout = new QVBoxLayout(TypeForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(TypeForm);
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
        gridLayoutWidget->setGeometry(QRect(10, 30, 411, 167));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        codeLabel = new QLabel(gridLayoutWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        sizePolicy1.setHeightForWidth(codeLabel->sizePolicy().hasHeightForWidth());
        codeLabel->setSizePolicy(sizePolicy1);
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        exLabel = new QLabel(gridLayoutWidget);
        exLabel->setObjectName(QString::fromUtf8("exLabel"));
        sizePolicy1.setHeightForWidth(exLabel->sizePolicy().hasHeightForWidth());
        exLabel->setSizePolicy(sizePolicy1);
        exLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(exLabel, 2, 0, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        discSpinBox = new QDoubleSpinBox(gridLayoutWidget);
        discSpinBox->setObjectName(QString::fromUtf8("discSpinBox"));
        discSpinBox->setMaximum(1);
        discSpinBox->setSingleStep(0.1);

        gridLayout->addWidget(discSpinBox, 5, 1, 1, 1);

        discCheckBox = new QCheckBox(gridLayoutWidget);
        discCheckBox->setObjectName(QString::fromUtf8("discCheckBox"));

        gridLayout->addWidget(discCheckBox, 4, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        explianEdit = new QLineEdit(gridLayoutWidget);
        explianEdit->setObjectName(QString::fromUtf8("explianEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(explianEdit->sizePolicy().hasHeightForWidth());
        explianEdit->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(explianEdit, 2, 1, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        endCheckBox = new QCheckBox(gridLayoutWidget);
        endCheckBox->setObjectName(QString::fromUtf8("endCheckBox"));
        endCheckBox->setCheckable(true);
        endCheckBox->setChecked(false);

        gridLayout->addWidget(endCheckBox, 3, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        endLabel = new QLabel(gridLayoutWidget);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        endLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(endLabel, 3, 0, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy1.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy1);
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        memoLabel = new QLabel(gridLayoutWidget);
        memoLabel->setObjectName(QString::fromUtf8("memoLabel"));
        memoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(memoLabel, 6, 0, 1, 1);

        memoEdit = new QLineEdit(gridLayoutWidget);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));
        memoEdit->setCursorMoveStyle(Qt::VisualMoveStyle);

        gridLayout->addWidget(memoEdit, 6, 1, 1, 2);

        codeEdit = new QLineEdit(gridLayoutWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy2.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);

        QWidget::setTabOrder(codeEdit, nameEdit);
        QWidget::setTabOrder(nameEdit, explianEdit);
        QWidget::setTabOrder(explianEdit, endCheckBox);
        QWidget::setTabOrder(endCheckBox, discCheckBox);
        QWidget::setTabOrder(discCheckBox, discSpinBox);
        QWidget::setTabOrder(discSpinBox, memoEdit);
        QWidget::setTabOrder(memoEdit, saveButton);
        QWidget::setTabOrder(saveButton, delButton);
        QWidget::setTabOrder(delButton, cancelButton);
        QWidget::setTabOrder(cancelButton, treeView);
        QWidget::setTabOrder(treeView, newButton);
        QWidget::setTabOrder(newButton, editButton);

        retranslateUi(TypeForm);

        QMetaObject::connectSlotsByName(TypeForm);
    } // setupUi

    void retranslateUi(QWidget *TypeForm)
    {
        TypeForm->setWindowTitle(QApplication::translate("TypeForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("TypeForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("TypeForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("TypeForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("TypeForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("TypeForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        groupBox->setTitle(QApplication::translate("TypeForm", "Dishes Type", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("TypeForm", "Code:", 0, QApplication::UnicodeUTF8));
        exLabel->setText(QApplication::translate("TypeForm", "Explian:", 0, QApplication::UnicodeUTF8));
        discCheckBox->setText(QString());
        label_3->setText(QApplication::translate("TypeForm", "Low Discount:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TypeForm", "** *** \344\276\213\345\246\202:01001", 0, QApplication::UnicodeUTF8));
        endCheckBox->setText(QString());
        label_2->setText(QApplication::translate("TypeForm", "Is Discount:", 0, QApplication::UnicodeUTF8));
        endLabel->setText(QApplication::translate("TypeForm", "Is End:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("TypeForm", "Type Name:", 0, QApplication::UnicodeUTF8));
        memoLabel->setText(QApplication::translate("TypeForm", "memo:", 0, QApplication::UnicodeUTF8));
        codeEdit->setInputMask(QApplication::translate("TypeForm", "99999; ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TypeForm: public Ui_TypeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TYPEFORM_H
