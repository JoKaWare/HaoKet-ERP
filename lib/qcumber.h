/****************************************************************************
**
** Copyright (C) 2006-2009 fullmetalcoder <fullmetalcoder@hotmail.fr>
**
** This file is part of the Edyuk project <http://edyuk.org>
** 
** This file may be used under the terms of the GNU General Public License
** version 3 as published by the Free Software Foundation and appearing in the
** file GPL.txt included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef _QCUMBER_H_
#define _QCUMBER_H_

#ifdef _QCUMBER_BUILD_
	#if (defined(QT_DLL) || defined(QT_SHARED)) && !defined(QT_PLUGIN)
		#define QCUMBER_EXPORT Q_DECL_EXPORT
	#else
		#define QCUMBER_EXPORT
	#endif
#else
		#define QCUMBER_EXPORT Q_DECL_IMPORT
#endif

#include <QEvent>

namespace QCumber
{
	enum Events
	{
		FirstEvent = QEvent::User + 100,
		
		SystemRequestEvent = FirstEvent,
		CustomRequestEvent,
		
		LastEvent
	};
	
}

#include <QtDebug>

#endif // _QCUMBER_H_
