#include "bamenuaction.h"
#include "haokeapp.h"

#include "base/depform.h"
#include "base/supplieform.h"
#include "base/employeeform.h"
#include "base/marketypeform.h"
#include "base/typeform.h"
#include "base/areaform.h"
#include "base/dinnerform.h"
#include "base/dishesform.h"
#include "base/tasteform.h"
#include "base/warehouseform.h"
#include "base/producttypeform.h"
#include "base/productform.h"
#include "base/positionform.h"
#include "base/supplietypeform.h"
#include "base/custypeform.h"
#include "base/cusform.h"
#include "base/unitform.h"
#include "baplugin.h"

BaMenuAction::BaMenuAction(HaoKeGUI *praent):
    mParent(praent)
{
    //mParent = qobject_cast<HaoKeGUI *>(parent) ;
    baseMenu = new QMenu(tr("Base Info(&B)"),mParent);
    baseMenu->setObjectName("menu.base");
    mainOrgMenu = new QMenu(tr("Organization Sub"),mParent);
    mainCusMenu = new QMenu(tr("Merchants Sub"),mParent);
    mainProMenu = new QMenu(tr("Products Sub"),mParent);
    mainBusMenu = new QMenu(tr("Business Sub"),mParent);
    QString s = "sysAccount";
    if(HaoKeApp::getInstance()->getAccountName() == s ){}
    else{
        mParent->menuBar()->addMenu(baseMenu);
        actionProperties acts[]= {
            { "menu",tr("&Organization"),(char*)mainOrgMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "base.department",tr("&Department Information"),SLOT(sDep()), mainOrgMenu, "Department Information", QPixmap(":/image/applications.png"), NULL,  true, tr("Department Information"),HaoKeApp::baSubId() + BaPlugin::baDepWinId() },
            { "base.employee",tr("&Employee Information"),SLOT(sEmployee()), mainOrgMenu, "Employee Information", QPixmap(":/image/user_add.png"), NULL,  true, tr("Employee Information"),HaoKeApp::baSubId() + BaPlugin::baEmpWinId() },
            { "menu",tr("&Products"),(char*)mainProMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "base.unit",tr("&Unit"),SLOT(sUnit()), mainProMenu, "Unit", NULL, NULL,  true, tr("Unit"),HaoKeApp::baSubId() + BaPlugin::baUnitWinId() },
            { "base.productType",tr("&Product Type Information"),SLOT(sProductType()), mainProMenu, "Product Type Information", QPixmap(":/image/tree_64.png"), NULL,  true, tr("Product Type Information"),HaoKeApp::baSubId() + BaPlugin::baProTypeWinId() },
            { "base.product",tr("&Product Information"),SLOT(sProduct()), mainProMenu, "Product Information", QPixmap(":/image/behance_64.png"), NULL,  true, tr("Product Information"),HaoKeApp::baSubId() + BaPlugin::baProWinId() },
            { "menu",tr("&Merchants"),(char*)mainCusMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "base.customerType",tr("&Customer Type Information"),SLOT(sCustomerType()), mainCusMenu, "Customer Type Information",NULL, NULL,  true, tr("Customer Type Information"),HaoKeApp::baSubId() + BaPlugin::baCusTypeWinId() },
            { "base.customer",tr("&Customer Information"),SLOT(sCustomer()), mainCusMenu, "Customer Info", QPixmap(":/image/users.png"), NULL,  true, tr("Customer Info"),HaoKeApp::baSubId() + BaPlugin::baCusWinId() },
            { "base.supplieType",tr("&Supplie Type Information"),SLOT(sSupplieType()), mainCusMenu, "Supplie Type Information",NULL, NULL,  true, tr("Supplie Type Information"),HaoKeApp::baSubId() + BaPlugin::baSupTypeWinId() },
            { "base.suppliers",tr("&Suppliers Information"),SLOT(sSuppliers()), mainCusMenu, "Suppliers Information", QPixmap(":/image/car_64.png"), NULL,  true, tr("Suppliers Information"),HaoKeApp::baSubId() + BaPlugin::baSupWinId() },

            { "menu",tr("&Business"),(char*)mainBusMenu,baseMenu,"true",NULL, NULL,true, NULL,"0"},
            { "base.warehouse",tr("&Warehouse Information"),SLOT(sWare()), mainBusMenu, "Warehouse Information", QPixmap(":/image/home.png"), NULL,  true, tr("Warehouse Information"),HaoKeApp::baSubId() + BaPlugin::baWareWinId() },
         };
         addActionsToMenu(acts, sizeof(acts) / sizeof(acts[0]));
    }
}

void BaMenuAction::addActionsToMenu(actionProperties acts[], unsigned int numElems){
    QAction * m = 0;
    for (unsigned int i = 0; i < numElems; i++)
    {
        if (! acts[i].visible){
            continue;
        }else if (acts[i].actionName == QString("menu")){
            m = acts[i].menu->addMenu((QMenu*)(acts[i].slot));
            if(m)
                m->setText(acts[i].actionTitle);
        }else if (acts[i].actionName == QString("separator")) {
            acts[i].menu->addSeparator();
        }else if(acts[i].toolBar !=NULL){
            new KAction( mParent,
                        acts[i].actionName,
                        acts[i].actionTitle,
                        this,
                        acts[i].slot,
                        acts[i].menu,
                        acts[i].visible,
                        acts[i].pixmap,
                        acts[i].toolBar) ;
        }else{
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,"",HaoKeApp::baSubId().toInt(),
                                               acts[i].menuId.toInt(),0,acts[i].toolTip,acts[i].actionName);
            new KAction( mParent,
                        acts[i].actionName,
                        acts[i].actionTitle,
                        this,
                        acts[i].slot,
                        acts[i].menu,
                        acts[i].visible,
                        acts[i].pixmap) ;
        }
   }

}

void BaMenuAction::sDep(){
    if(!mParent->subWinIsOpen(tr("Department Information"))){
        DepForm *depForm = new DepForm(mParent);
        depForm->setWindowTitle(tr("Department Information"));
        mParent->addSubWin(depForm);
        depForm->showMaximized();
    }
}

void BaMenuAction::sSuppliers(){
    if(!mParent->subWinIsOpen(tr("Suppliers Information"))){
        SupplieForm *sForm = new SupplieForm(mParent);
        sForm->setWindowTitle(tr("Suppliers Information"));
        mParent->addSubWin(sForm);
        sForm->showMaximized();
    }
}

void BaMenuAction::sSupplieType(){
    if(!mParent->subWinIsOpen(tr("Supplie Type Information"))){
        SupplieTypeForm *sForm = new SupplieTypeForm(mParent);
        sForm->setWindowTitle(tr("Supplie Type Information"));
        mParent->addSubWin(sForm);
        sForm->showMaximized();
    }
}


void BaMenuAction::sCustomer(){
    if(!mParent->subWinIsOpen(tr("Customer Info"))){
        CusForm *sForm = new CusForm(mParent);
        sForm->setWindowTitle(tr("Customer Info"));
        mParent->addSubWin(sForm);
        sForm->showMaximized();
    }
}

void BaMenuAction::sCustomerType(){
    if(!mParent->subWinIsOpen(tr("Customer Type Information"))){
        CusTypeForm *sForm = new CusTypeForm(mParent);
        sForm->setWindowTitle(tr("Customer Type Information"));
        mParent->addSubWin(sForm);
        sForm->showMaximized();
    }
}

void BaMenuAction::sEmployee(){
    if(!mParent->subWinIsOpen(tr("Employee Information"))){
        EmployeeForm *eForm = new EmployeeForm(mParent);
        eForm->setWindowTitle(tr("Employee Information"));
        mParent->addSubWin(eForm);
        eForm->showMaximized();
    }
}

void BaMenuAction::sMarketType(){
    if(!mParent->subWinIsOpen(tr("Market Type"))){
        MarkeTypeForm *tForm = new MarkeTypeForm(mParent);
        tForm->setWindowTitle(tr("Market Type"));
        mParent->addSubWin(tForm);
        tForm->showMaximized();
    }
}

void BaMenuAction::sType(){
    if(!mParent->subWinIsOpen(tr("Dishes Type"))){
        TypeForm *tForm = new TypeForm(mParent);
        tForm->setWindowTitle(tr("Dishes Type"));
        mParent->addSubWin(tForm);
        tForm->showMaximized();
    }
}

void BaMenuAction::sArea(){
    if(!mParent->subWinIsOpen(tr("Dinner Area"))){
        AreaForm *aForm = new AreaForm(mParent);
        aForm->setWindowTitle(tr("Dinner Area"));
        mParent->addSubWin(aForm);
        aForm->showMaximized();
    }
}

void BaMenuAction::sDinner(){
    if(!mParent->subWinIsOpen(tr("Dinner"))){
        DinnerForm * dForm = new DinnerForm(mParent);
        dForm->setWindowTitle(tr("Dinner"));
        mParent->addSubWin(dForm);
        dForm->showMaximized();
    }
}

void BaMenuAction::sDishes(){
    if(!mParent->subWinIsOpen(tr("Dishes"))){
        DishesForm * dForm = new DishesForm(mParent);
        dForm->setWindowTitle(tr("Dishes"));
        mParent->addSubWin(dForm);
        dForm->showMaximized();
    }
}

void BaMenuAction::sTaste(){
    if(!mParent->subWinIsOpen(tr("Taste"))){
        TasteForm *from = new TasteForm(mParent);
        from->setWindowTitle("Taste");
        mParent->addSubWin(from);
        from->showMaximized();
    }
}

void BaMenuAction::sUnit(){
    if(!mParent->subWinIsOpen(tr("Unit"))){
        UnitForm *from = new UnitForm(mParent);
        from->setWindowTitle("Unit");
        mParent->addSubWin(from);
        from->showMaximized();
    }
}

void BaMenuAction::sWare(){
    if(!mParent->subWinIsOpen(tr("Warehouse"))){
        WareHouseForm * wForm = new WareHouseForm(mParent);
        wForm->setWindowTitle(tr("Warehouse"));
        mParent->addSubWin(wForm);
        wForm->showMaximized();
    }
}

void BaMenuAction::sPosition(){
    if(!mParent->subWinIsOpen(tr("Position"))){
        PositionForm *pForm = new PositionForm(mParent);
        pForm->setWindowTitle(tr("Position"));
        mParent->addSubWin(pForm);
        pForm->showMaximized();
    }
}

void BaMenuAction::sProductType(){
    if(!mParent->subWinIsOpen(tr("Product Type"))){
        ProductTypeForm * wForm = new ProductTypeForm(mParent);
        wForm->setWindowTitle(tr("Product Type"));
        mParent->addSubWin(wForm);
        wForm->showMaximized();
    }
}

void BaMenuAction::sProduct(){
    if(!mParent->subWinIsOpen(tr("Product"))){
        ProductForm * wForm = new ProductForm(mParent);
        wForm->setWindowTitle(tr("Product"));
        mParent->addSubWin(wForm);
        wForm->showMaximized();
    }
}

void BaMenuAction::sExit(){
    mParent->close();
}

