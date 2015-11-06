#ifndef LIBGLOBAL_H
#define LIBGLOBAL_H

#include <QtCore/qglobal.h>

#if defined(RPTLIB_LIBRARY)
#  define LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBGLOBAL_H
