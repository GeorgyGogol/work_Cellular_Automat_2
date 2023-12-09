#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(AUTOMATCORE_LIB)
#  define AUTOMATCORE_EXPORT Q_DECL_EXPORT
# else
#  define AUTOMATCORE_EXPORT Q_DECL_IMPORT
# endif
#else
# define AUTOMATCORE_EXPORT
#endif
