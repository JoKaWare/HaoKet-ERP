#ifndef ABSTRACTSETTINGSDIALOG_H
#define ABSTRACTSETTINGSDIALOG_H

#include <QDialog>

class AbstractSettingsPage;
class QListWidget;
class QListWidgetItem;
class QPushButton;
class QStackedWidget;

class AbstractSettingsDialog : public QDialog
{
    Q_OBJECT
public:
    AbstractSettingsDialog(QWidget *parent = 0);
    void setPage(int page = 0);
signals:
    void reset(int page);
    void save();

protected:
    void showEvent(QShowEvent *event);

public slots:
    void accept();
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
    void reset();

protected:
    void createPage(const QIcon &icon, const QString &text, AbstractSettingsPage *page);

    bool m_badSize;
    QListWidget *m_contentsWidget;
    QPushButton *m_cancelButton;
    QPushButton *m_okButton;
    QPushButton *m_resetButton;
    QStackedWidget *m_pagesWidget;
    
};

class AbstractSettingsPage : public QWidget
{
  Q_OBJECT

public:
  AbstractSettingsPage(int id, QWidget *parent = 0);

public slots:
  void reset(int /*page*/) {}
  void save()              {}

protected:
  int m_id;
};

#endif // ABSTRACTSETTINGSDIALOG_H
