#ifndef ACCOUNTWIZARD_H
#define ACCOUNTWIZARD_H

#include <QWizard>
#include "log4qt/logger.h"
#include "lib_global.h"

namespace Ui {
class AccountWizard;
}

class LIBSHARED_EXPORT AccountWizard : public QWizard
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    explicit AccountWizard(QWidget *parent = 0);
    ~AccountWizard();

private slots:

    void sFinished(int id);
private:
    Ui::AccountWizard *ui;
    QString mAccountId;
    QString mDatabaseName;
    bool validateCurrentPage();
    bool createDatabase();
    bool createTable();
};

#endif // ACCOUNTWIZARD_H
