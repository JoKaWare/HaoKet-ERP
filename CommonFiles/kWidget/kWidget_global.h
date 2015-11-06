#ifndef KWIDGET_GLOBAL_H
#define KWIDGET_GLOBAL_H

#include <QtCore/qglobal.h>


#if defined(KWIDGET_LIBRARY)
#  define KWIDGETSHARED_EXPORT Q_DECL_EXPORT
#else
#  define KWIDGETSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // KWIDGET_GLOBAL_H
