#ifndef HAOKEMENUINTERFACE_H
#define HAOKEMENUINTERFACE_H
class QString;
class QIcon;
class QWidget;

class HaoKeMenuInterface
{
public:
    virtual ~HaoKeMenuInterface(){}
    virtual QString name() const = 0;
    virtual QString group() const = 0;
    virtual QString toolTip() const = 0;
    virtual QString whatsThis() const = 0;

    virtual bool createMenus(QWidget *parent) = 0;
    virtual bool createNavigation(QWidget *parent) = 0;
};

Q_DECLARE_INTERFACE(HaoKeMenuInterface,
                    "com.haokel.HaoKeMenuInterface/1.0")
#endif // HAOKEMENUINTERFACE_H
