/********************************************************************************
** Form generated from reading UI file 'employeeform.ui'
**
** Created: Fri Nov 6 10:49:42 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEFORM_H
#define UI_EMPLOYEEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeForm
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *depComboBox;
    QComboBox *nationComBox;
    QDateEdit *birthEdit;
    QLineEdit *memoEdit;
    QLineEdit *propertyEdit;
    QLabel *label;
    QLineEdit *codeEdit;
    QLineEdit *homeEdit;
    QLabel *codeLabel;
    QLabel *nameLabel;
    QLabel *dateLabel;
    QLineEdit *nameEdit;
    QLabel *heightLabel;
    QLabel *propertyLabel;
    QLabel *memoLabel;
    QLabel *TheirLabel;
    QLabel *hometownLabel;
    QComboBox *sexComBox;
    QLabel *birthLabel;
    QLineEdit *weightEdit;
    QLabel *weihtLabel;
    QLineEdit *heightEdit;
    QDateEdit *dateEdit;
    QLabel *sexLabel;
    QLabel *nationLabel;
    QLabel *label_3;
    QCheckBox *statusCheckBox;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QLineEdit *guarantorEdit;
    QLabel *telLabel;
    QLabel *guarantorTelLabel;
    QLineEdit *rAddrEdit;
    QLabel *guarantorAddrLabel;
    QLineEdit *guarantorNumberEdit;
    QLineEdit *guarantorAddrEdit;
    QLabel *shcoolLabel;
    QLineEdit *phoneEdit;
    QLineEdit *guarantorTelEdit;
    QLineEdit *addrEdit;
    QLineEdit *eduEdit;
    QLabel *guarantorNumberLabel;
    QLineEdit *shcoolEdit;
    QLabel *graduationDateLabel;
    QLineEdit *cNumberEdit;
    QLabel *phoneLabel;
    QLineEdit *telEdit;
    QLabel *rAddrLabel;
    QLineEdit *zipEdit;
    QLabel *educationalLabel;
    QLabel *zipLabel;
    QLabel *guarantorRelationLabel;
    QLabel *guarantorLabel;
    QLabel *addrLabel;
    QLabel *numberLabel;
    QDateEdit *graduaDateEdit;
    QComboBox *relationComboBox;

    void setupUi(QWidget *EmployeeForm)
    {
        if (EmployeeForm->objectName().isEmpty())
            EmployeeForm->setObjectName(QString::fromUtf8("EmployeeForm"));
        EmployeeForm->resize(963, 583);
        verticalLayout = new QVBoxLayout(EmployeeForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(EmployeeForm);
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

        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setIconSize(QSize(24, 24));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 431, 330));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_2, 7, 2, 1, 1);

        depComboBox = new QComboBox(gridLayoutWidget);
        depComboBox->setObjectName(QString::fromUtf8("depComboBox"));
        sizePolicy2.setHeightForWidth(depComboBox->sizePolicy().hasHeightForWidth());
        depComboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(depComboBox, 3, 1, 1, 1);

        nationComBox = new QComboBox(gridLayoutWidget);
        nationComBox->setObjectName(QString::fromUtf8("nationComBox"));
        sizePolicy2.setHeightForWidth(nationComBox->sizePolicy().hasHeightForWidth());
        nationComBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(nationComBox, 9, 1, 1, 1);

        birthEdit = new QDateEdit(gridLayoutWidget);
        birthEdit->setObjectName(QString::fromUtf8("birthEdit"));
        sizePolicy2.setHeightForWidth(birthEdit->sizePolicy().hasHeightForWidth());
        birthEdit->setSizePolicy(sizePolicy2);
        birthEdit->setCalendarPopup(true);

        gridLayout->addWidget(birthEdit, 11, 1, 1, 1);

        memoEdit = new QLineEdit(gridLayoutWidget);
        memoEdit->setObjectName(QString::fromUtf8("memoEdit"));

        gridLayout->addWidget(memoEdit, 12, 1, 1, 2);

        propertyEdit = new QLineEdit(gridLayoutWidget);
        propertyEdit->setObjectName(QString::fromUtf8("propertyEdit"));
        sizePolicy1.setHeightForWidth(propertyEdit->sizePolicy().hasHeightForWidth());
        propertyEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(propertyEdit, 4, 1, 1, 2);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label, 8, 2, 1, 1);

        codeEdit = new QLineEdit(gridLayoutWidget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        sizePolicy2.setHeightForWidth(codeEdit->sizePolicy().hasHeightForWidth());
        codeEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(codeEdit, 0, 1, 1, 1);

        homeEdit = new QLineEdit(gridLayoutWidget);
        homeEdit->setObjectName(QString::fromUtf8("homeEdit"));
        sizePolicy1.setHeightForWidth(homeEdit->sizePolicy().hasHeightForWidth());
        homeEdit->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(homeEdit, 10, 1, 1, 2);

        codeLabel = new QLabel(gridLayoutWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));
        codeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(codeLabel, 0, 0, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy1.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy1);
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nameLabel, 1, 0, 1, 1);

        dateLabel = new QLabel(gridLayoutWidget);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));
        sizePolicy1.setHeightForWidth(dateLabel->sizePolicy().hasHeightForWidth());
        dateLabel->setSizePolicy(sizePolicy1);
        dateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(dateLabel, 5, 0, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        sizePolicy2.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(nameEdit, 1, 1, 1, 1);

        heightLabel = new QLabel(gridLayoutWidget);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));
        heightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(heightLabel, 7, 0, 1, 1);

        propertyLabel = new QLabel(gridLayoutWidget);
        propertyLabel->setObjectName(QString::fromUtf8("propertyLabel"));
        sizePolicy1.setHeightForWidth(propertyLabel->sizePolicy().hasHeightForWidth());
        propertyLabel->setSizePolicy(sizePolicy1);
        propertyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(propertyLabel, 4, 0, 1, 1);

        memoLabel = new QLabel(gridLayoutWidget);
        memoLabel->setObjectName(QString::fromUtf8("memoLabel"));
        sizePolicy1.setHeightForWidth(memoLabel->sizePolicy().hasHeightForWidth());
        memoLabel->setSizePolicy(sizePolicy1);
        memoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(memoLabel, 12, 0, 1, 1);

        TheirLabel = new QLabel(gridLayoutWidget);
        TheirLabel->setObjectName(QString::fromUtf8("TheirLabel"));
        sizePolicy1.setHeightForWidth(TheirLabel->sizePolicy().hasHeightForWidth());
        TheirLabel->setSizePolicy(sizePolicy1);
        TheirLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(TheirLabel, 3, 0, 1, 1);

        hometownLabel = new QLabel(gridLayoutWidget);
        hometownLabel->setObjectName(QString::fromUtf8("hometownLabel"));
        hometownLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(hometownLabel, 10, 0, 1, 1);

        sexComBox = new QComboBox(gridLayoutWidget);
        sexComBox->setObjectName(QString::fromUtf8("sexComBox"));
        sizePolicy2.setHeightForWidth(sexComBox->sizePolicy().hasHeightForWidth());
        sexComBox->setSizePolicy(sizePolicy2);
        sexComBox->setInsertPolicy(QComboBox::InsertAtBottom);

        gridLayout->addWidget(sexComBox, 6, 1, 1, 1);

        birthLabel = new QLabel(gridLayoutWidget);
        birthLabel->setObjectName(QString::fromUtf8("birthLabel"));
        birthLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(birthLabel, 11, 0, 1, 1);

        weightEdit = new QLineEdit(gridLayoutWidget);
        weightEdit->setObjectName(QString::fromUtf8("weightEdit"));
        sizePolicy2.setHeightForWidth(weightEdit->sizePolicy().hasHeightForWidth());
        weightEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(weightEdit, 8, 1, 1, 1);

        weihtLabel = new QLabel(gridLayoutWidget);
        weihtLabel->setObjectName(QString::fromUtf8("weihtLabel"));
        weihtLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(weihtLabel, 8, 0, 1, 1);

        heightEdit = new QLineEdit(gridLayoutWidget);
        heightEdit->setObjectName(QString::fromUtf8("heightEdit"));
        sizePolicy2.setHeightForWidth(heightEdit->sizePolicy().hasHeightForWidth());
        heightEdit->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(heightEdit, 7, 1, 1, 1);

        dateEdit = new QDateEdit(gridLayoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        sizePolicy2.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy2);
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 5, 1, 1, 1);

        sexLabel = new QLabel(gridLayoutWidget);
        sexLabel->setObjectName(QString::fromUtf8("sexLabel"));
        sexLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(sexLabel, 6, 0, 1, 1);

        nationLabel = new QLabel(gridLayoutWidget);
        nationLabel->setObjectName(QString::fromUtf8("nationLabel"));
        nationLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(nationLabel, 9, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        statusCheckBox = new QCheckBox(gridLayoutWidget);
        statusCheckBox->setObjectName(QString::fromUtf8("statusCheckBox"));

        gridLayout->addWidget(statusCheckBox, 2, 1, 1, 1);

        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/table_green_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 431, 391));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        guarantorEdit = new QLineEdit(gridLayoutWidget_2);
        guarantorEdit->setObjectName(QString::fromUtf8("guarantorEdit"));
        sizePolicy2.setHeightForWidth(guarantorEdit->sizePolicy().hasHeightForWidth());
        guarantorEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(guarantorEdit, 9, 1, 1, 1);

        telLabel = new QLabel(gridLayoutWidget_2);
        telLabel->setObjectName(QString::fromUtf8("telLabel"));
        telLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(telLabel, 8, 0, 1, 1);

        guarantorTelLabel = new QLabel(gridLayoutWidget_2);
        guarantorTelLabel->setObjectName(QString::fromUtf8("guarantorTelLabel"));
        guarantorTelLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(guarantorTelLabel, 10, 0, 1, 1);

        rAddrEdit = new QLineEdit(gridLayoutWidget_2);
        rAddrEdit->setObjectName(QString::fromUtf8("rAddrEdit"));

        gridLayout_4->addWidget(rAddrEdit, 7, 1, 1, 1);

        guarantorAddrLabel = new QLabel(gridLayoutWidget_2);
        guarantorAddrLabel->setObjectName(QString::fromUtf8("guarantorAddrLabel"));
        guarantorAddrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(guarantorAddrLabel, 11, 0, 1, 1);

        guarantorNumberEdit = new QLineEdit(gridLayoutWidget_2);
        guarantorNumberEdit->setObjectName(QString::fromUtf8("guarantorNumberEdit"));

        gridLayout_4->addWidget(guarantorNumberEdit, 12, 1, 1, 1);

        guarantorAddrEdit = new QLineEdit(gridLayoutWidget_2);
        guarantorAddrEdit->setObjectName(QString::fromUtf8("guarantorAddrEdit"));

        gridLayout_4->addWidget(guarantorAddrEdit, 11, 1, 1, 1);

        shcoolLabel = new QLabel(gridLayoutWidget_2);
        shcoolLabel->setObjectName(QString::fromUtf8("shcoolLabel"));
        shcoolLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(shcoolLabel, 2, 0, 1, 1);

        phoneEdit = new QLineEdit(gridLayoutWidget_2);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        sizePolicy2.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(phoneEdit, 3, 1, 1, 1);

        guarantorTelEdit = new QLineEdit(gridLayoutWidget_2);
        guarantorTelEdit->setObjectName(QString::fromUtf8("guarantorTelEdit"));
        sizePolicy2.setHeightForWidth(guarantorTelEdit->sizePolicy().hasHeightForWidth());
        guarantorTelEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(guarantorTelEdit, 10, 1, 1, 1);

        addrEdit = new QLineEdit(gridLayoutWidget_2);
        addrEdit->setObjectName(QString::fromUtf8("addrEdit"));

        gridLayout_4->addWidget(addrEdit, 5, 1, 1, 1);

        eduEdit = new QLineEdit(gridLayoutWidget_2);
        eduEdit->setObjectName(QString::fromUtf8("eduEdit"));

        gridLayout_4->addWidget(eduEdit, 0, 1, 1, 1);

        guarantorNumberLabel = new QLabel(gridLayoutWidget_2);
        guarantorNumberLabel->setObjectName(QString::fromUtf8("guarantorNumberLabel"));
        guarantorNumberLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(guarantorNumberLabel, 12, 0, 1, 1);

        shcoolEdit = new QLineEdit(gridLayoutWidget_2);
        shcoolEdit->setObjectName(QString::fromUtf8("shcoolEdit"));

        gridLayout_4->addWidget(shcoolEdit, 2, 1, 1, 1);

        graduationDateLabel = new QLabel(gridLayoutWidget_2);
        graduationDateLabel->setObjectName(QString::fromUtf8("graduationDateLabel"));
        graduationDateLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(graduationDateLabel, 1, 0, 1, 1);

        cNumberEdit = new QLineEdit(gridLayoutWidget_2);
        cNumberEdit->setObjectName(QString::fromUtf8("cNumberEdit"));

        gridLayout_4->addWidget(cNumberEdit, 4, 1, 1, 1);

        phoneLabel = new QLabel(gridLayoutWidget_2);
        phoneLabel->setObjectName(QString::fromUtf8("phoneLabel"));
        phoneLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(phoneLabel, 3, 0, 1, 1);

        telEdit = new QLineEdit(gridLayoutWidget_2);
        telEdit->setObjectName(QString::fromUtf8("telEdit"));
        sizePolicy2.setHeightForWidth(telEdit->sizePolicy().hasHeightForWidth());
        telEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(telEdit, 8, 1, 1, 1);

        rAddrLabel = new QLabel(gridLayoutWidget_2);
        rAddrLabel->setObjectName(QString::fromUtf8("rAddrLabel"));
        rAddrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(rAddrLabel, 7, 0, 1, 1);

        zipEdit = new QLineEdit(gridLayoutWidget_2);
        zipEdit->setObjectName(QString::fromUtf8("zipEdit"));
        sizePolicy2.setHeightForWidth(zipEdit->sizePolicy().hasHeightForWidth());
        zipEdit->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(zipEdit, 6, 1, 1, 1);

        educationalLabel = new QLabel(gridLayoutWidget_2);
        educationalLabel->setObjectName(QString::fromUtf8("educationalLabel"));
        educationalLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(educationalLabel, 0, 0, 1, 1);

        zipLabel = new QLabel(gridLayoutWidget_2);
        zipLabel->setObjectName(QString::fromUtf8("zipLabel"));
        zipLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(zipLabel, 6, 0, 1, 1);

        guarantorRelationLabel = new QLabel(gridLayoutWidget_2);
        guarantorRelationLabel->setObjectName(QString::fromUtf8("guarantorRelationLabel"));
        guarantorRelationLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(guarantorRelationLabel, 13, 0, 1, 1);

        guarantorLabel = new QLabel(gridLayoutWidget_2);
        guarantorLabel->setObjectName(QString::fromUtf8("guarantorLabel"));
        guarantorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(guarantorLabel, 9, 0, 1, 1);

        addrLabel = new QLabel(gridLayoutWidget_2);
        addrLabel->setObjectName(QString::fromUtf8("addrLabel"));
        addrLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(addrLabel, 5, 0, 1, 1);

        numberLabel = new QLabel(gridLayoutWidget_2);
        numberLabel->setObjectName(QString::fromUtf8("numberLabel"));
        numberLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(numberLabel, 4, 0, 1, 1);

        graduaDateEdit = new QDateEdit(gridLayoutWidget_2);
        graduaDateEdit->setObjectName(QString::fromUtf8("graduaDateEdit"));
        sizePolicy2.setHeightForWidth(graduaDateEdit->sizePolicy().hasHeightForWidth());
        graduaDateEdit->setSizePolicy(sizePolicy2);
        graduaDateEdit->setCalendarPopup(true);

        gridLayout_4->addWidget(graduaDateEdit, 1, 1, 1, 1);

        relationComboBox = new QComboBox(gridLayoutWidget_2);
        relationComboBox->setObjectName(QString::fromUtf8("relationComboBox"));
        sizePolicy2.setHeightForWidth(relationComboBox->sizePolicy().hasHeightForWidth());
        relationComboBox->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(relationComboBox, 13, 1, 1, 1);

        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/tabs_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon6, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 1);

        splitter->addWidget(frame);

        verticalLayout->addWidget(splitter);

        QWidget::setTabOrder(nameEdit, propertyEdit);
        QWidget::setTabOrder(propertyEdit, dateEdit);
        QWidget::setTabOrder(dateEdit, sexComBox);
        QWidget::setTabOrder(sexComBox, heightEdit);
        QWidget::setTabOrder(heightEdit, weightEdit);
        QWidget::setTabOrder(weightEdit, nationComBox);
        QWidget::setTabOrder(nationComBox, homeEdit);
        QWidget::setTabOrder(homeEdit, birthEdit);
        QWidget::setTabOrder(birthEdit, memoEdit);
        QWidget::setTabOrder(memoEdit, eduEdit);
        QWidget::setTabOrder(eduEdit, graduaDateEdit);
        QWidget::setTabOrder(graduaDateEdit, shcoolEdit);
        QWidget::setTabOrder(shcoolEdit, phoneEdit);
        QWidget::setTabOrder(phoneEdit, cNumberEdit);
        QWidget::setTabOrder(cNumberEdit, addrEdit);
        QWidget::setTabOrder(addrEdit, zipEdit);
        QWidget::setTabOrder(zipEdit, rAddrEdit);
        QWidget::setTabOrder(rAddrEdit, telEdit);
        QWidget::setTabOrder(telEdit, guarantorEdit);
        QWidget::setTabOrder(guarantorEdit, guarantorTelEdit);
        QWidget::setTabOrder(guarantorTelEdit, guarantorAddrEdit);
        QWidget::setTabOrder(guarantorAddrEdit, guarantorNumberEdit);
        QWidget::setTabOrder(guarantorNumberEdit, treeView);
        QWidget::setTabOrder(treeView, saveButton);
        QWidget::setTabOrder(saveButton, tabWidget);
        QWidget::setTabOrder(tabWidget, newButton);
        QWidget::setTabOrder(newButton, editButton);
        QWidget::setTabOrder(editButton, delButton);
        QWidget::setTabOrder(delButton, cancelButton);

        retranslateUi(EmployeeForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EmployeeForm);
    } // setupUi

    void retranslateUi(QWidget *EmployeeForm)
    {
        EmployeeForm->setWindowTitle(QApplication::translate("EmployeeForm", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("EmployeeForm", "New", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        delButton->setToolTip(QApplication::translate("EmployeeForm", "Del", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        delButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("EmployeeForm", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("EmployeeForm", "Save", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        editButton->setToolTip(QApplication::translate("EmployeeForm", "Edit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        editButton->setText(QString());
        label_2->setText(QApplication::translate("EmployeeForm", "cm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EmployeeForm", "Kg", 0, QApplication::UnicodeUTF8));
        codeLabel->setText(QApplication::translate("EmployeeForm", "Staff Code:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("EmployeeForm", "Staff Name:", 0, QApplication::UnicodeUTF8));
        dateLabel->setText(QApplication::translate("EmployeeForm", "Entry Date:", 0, QApplication::UnicodeUTF8));
        heightLabel->setText(QApplication::translate("EmployeeForm", "Height:", 0, QApplication::UnicodeUTF8));
        propertyLabel->setText(QApplication::translate("EmployeeForm", "Staff Property:", 0, QApplication::UnicodeUTF8));
        memoLabel->setText(QApplication::translate("EmployeeForm", "memo:", 0, QApplication::UnicodeUTF8));
        TheirLabel->setText(QApplication::translate("EmployeeForm", "Their Departments:", 0, QApplication::UnicodeUTF8));
        hometownLabel->setText(QApplication::translate("EmployeeForm", "Hometown:", 0, QApplication::UnicodeUTF8));
        birthLabel->setText(QApplication::translate("EmployeeForm", "Birth:", 0, QApplication::UnicodeUTF8));
        weihtLabel->setText(QApplication::translate("EmployeeForm", "Weight:", 0, QApplication::UnicodeUTF8));
        sexLabel->setText(QApplication::translate("EmployeeForm", "Sex:", 0, QApplication::UnicodeUTF8));
        nationLabel->setText(QApplication::translate("EmployeeForm", "Nation:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("EmployeeForm", "Is Start:", 0, QApplication::UnicodeUTF8));
        statusCheckBox->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("EmployeeForm", "Employee Base", 0, QApplication::UnicodeUTF8));
        telLabel->setText(QApplication::translate("EmployeeForm", "Tel:", 0, QApplication::UnicodeUTF8));
        guarantorTelLabel->setText(QApplication::translate("EmployeeForm", "Guarantor Tel:", 0, QApplication::UnicodeUTF8));
        guarantorAddrLabel->setText(QApplication::translate("EmployeeForm", "Guarantor Addr:", 0, QApplication::UnicodeUTF8));
        shcoolLabel->setText(QApplication::translate("EmployeeForm", "Graduation Shcool:", 0, QApplication::UnicodeUTF8));
        guarantorNumberLabel->setText(QApplication::translate("EmployeeForm", "Guarantor Number:", 0, QApplication::UnicodeUTF8));
        graduationDateLabel->setText(QApplication::translate("EmployeeForm", "Graduation Date:", 0, QApplication::UnicodeUTF8));
        phoneLabel->setText(QApplication::translate("EmployeeForm", "Phone:", 0, QApplication::UnicodeUTF8));
        rAddrLabel->setText(QApplication::translate("EmployeeForm", "Residence Addr:", 0, QApplication::UnicodeUTF8));
        educationalLabel->setText(QApplication::translate("EmployeeForm", "Educational:", 0, QApplication::UnicodeUTF8));
        zipLabel->setText(QApplication::translate("EmployeeForm", "Zip Code:", 0, QApplication::UnicodeUTF8));
        guarantorRelationLabel->setText(QApplication::translate("EmployeeForm", "Guarantor Relation:", 0, QApplication::UnicodeUTF8));
        guarantorLabel->setText(QApplication::translate("EmployeeForm", "Guarantor:", 0, QApplication::UnicodeUTF8));
        addrLabel->setText(QApplication::translate("EmployeeForm", "Address:", 0, QApplication::UnicodeUTF8));
        numberLabel->setText(QApplication::translate("EmployeeForm", "Card Number:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("EmployeeForm", "Employee Detailed", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EmployeeForm: public Ui_EmployeeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEFORM_H
