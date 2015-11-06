#ifndef KACTION_H
#define KACTION_H
#include <QAction>
#include <system/limitscommon.h>
class LIBSHARED_EXPORT KAction : public QAction
{
public:
    KAction( QWidget *, const char *, const QString &,
            QObject *, const char *,
            QWidget *, bool );

    KAction( QWidget *, const char *, const QString &,
            QObject *, const char *,
            QWidget *, bool ,
            const QPixmap &);

    KAction( QWidget *, const char *, const QString &,
            QObject *, const char *,
            QWidget *, bool,
            const QPixmap &, QWidget *);

    KAction( QWidget *, const char *, const QString &,
            QObject *, const char *,
            QWidget *, bool,
            const QPixmap &, QWidget *,
            const QString &);

    KAction( QWidget *, const char *, const QString &,
            QObject *, const char *,
            QWidget *, const QString & );

    KAction( QWidget *, const char *, const QString &,
            QObject *, const char *,
            QWidget *, const QString &,
            const QPixmap &, QWidget *);

    KAction( QWidget *, const char *, const QString &,
            QObject *, const char *,
            QWidget *, const QString &,
            const QPixmap &, QWidget *,
            const QString &);

  private:
    void init( QWidget *, const char *, const QString &,
               QObject *, const char *,
               QWidget *, const QString & );


};

#endif // KACTION_H
