/*
Name: CommonFiles
Version: 1.3.4
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2014
*/

#ifndef TCONTAINER_H
#define TCONTAINER_H

#include <QtDebug>
#include <QWidget>
#include <QMenu>
#include <QVBoxLayout>

enum modes{
    NONE = 0,
    MOVE = 1,
    RESIZETL = 2,
    RESIZET = 3,
    RESIZETR = 4,
    RESIZER = 5,
    RESIZEBR = 6,
    RESIZEB = 7,
    RESIZEBL = 8,
    RESIZEL = 9
};

class TContainer : public QWidget {
    Q_OBJECT
public:
    TContainer(QWidget *parent, QPoint p, QWidget *cWidget = 0);
    ~TContainer();
    QWidget *childWidget;
    QMenu *menu;
    void setChildWidget(QWidget *cWidget);
    void setSelected(bool value);
    void setPasted(bool value);
    bool isSelected();
    static QString colorToString(QColor color);
    static void colorFromString(QColor &color, QString value);
    qreal scale;
    void setScale(qreal scale);

protected:
    int mode;
    QPoint position;
    QVBoxLayout* vLayout;
    void setCursorShape(const QPoint &e_pos);
    bool eventFilter( QObject *obj, QEvent *evt );
    void keyPressEvent(QKeyEvent *);
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void resizeEvent(QResizeEvent *e);
    bool m_selected;
    bool m_pasting;
    bool m_showMenu;
    bool m_isEditing;
    void popupShow(const QPoint &pt);
    QWidget *clone();

private:


signals:
    void inFocus(bool mode);
    void outFocus(bool mode);
    void newGeometry(QRect oldRect, QRect newRect);

public slots:

};

#endif // TCONTAINER_H
