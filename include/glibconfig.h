/* glibconfig.h
 *
 * This is a generated file.  Please modify `configure.in'
 */

#ifndef GLIBCONFIG_H
#define GLIBCONFIG_H

#include <limits.h>
#include <float.h>
#define GLIB_HAVE_SYS_POLL_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define G_MINFLOAT	FLT_MIN
#define G_MAXFLOAT	FLT_MAX
#define G_MINDOUBLE	DBL_MIN
#define G_MAXDOUBLE	DBL_MAX
#define G_MINSHORT	SHRT_MIN
#define G_MAXSHORT	SHRT_MAX
#define G_MININT	INT_MIN
#define G_MAXINT	INT_MAX
#define G_MINLONG	LONG_MIN
#define G_MAXLONG	LONG_MAX

typedef signed char gint8;
typedef unsigned char guint8;
typedef signed short gint16;
typedef unsigned short guint16;
typedef signed int gint32;
typedef unsigned int guint32;
typedef void* gpointer;
typedef long glong;
typedef unsigned long gulong;

#if defined (__GNUC__) && (__GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 8))
#  define G_GNUC_EXTENSION __extension__
#else
#  define G_GNUC_EXTENSION
#endif

#define G_HAVE_GINT64 1

G_GNUC_EXTENSION typedef signed long long gint64;
G_GNUC_EXTENSION typedef unsigned long long guint64;

#define G_GINT64_CONSTANT(val)	(G_GNUC_EXTENSION (val##LL))

#define GPOINTER_TO_INT(p)	((gint)(glong)   (p))
#define GPOINTER_TO_UINT(p)	((guint)(gulong)  (p))

#define GINT_TO_POINTER(i)	((gpointer)(glong)  (i))
#define GUINT_TO_POINTER(u)	((gpointer)(gulong)  (u))

#ifdef NeXT /* @#%@! NeXTStep */
# define g_ATEXIT(proc)	(!atexit (proc))
#else
# define g_ATEXIT(proc)	(atexit (proc))
#endif

#define g_memmove(d,s,n) do { memmove ((d), (s), (n)); } while(0);

#define GLIB_MAJOR_VERSION 1
#define GLIB_MINOR_VERSION 2
#define GLIB_MICRO_VERSION 10


#define G_VA_COPY	va_copy

#ifdef	__cplusplus
#define	G_HAVE_INLINE	1
#else	/* !__cplusplus */

#endif	/* !__cplusplus */

#define G_THREADS_ENABLED
#define G_THREADS_IMPL_POSIX
typedef struct _GStaticMutex GStaticMutex;
struct _GStaticMutex
{
  struct _GMutex *runtime_mutex;
  union {
    char   pad[24];
    double dummy_double;
    void  *dummy_pointer;
    long   dummy_long;
  } aligned_pad_u;
};
#define	G_STATIC_MUTEX_INIT	{ NULL, { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} } }
#define	g_static_mutex_get_mutex(mutex)   (g_thread_use_default_impl ? ((GMutex*) &((mutex)->aligned_pad_u)) :    g_static_mutex_get_mutex_impl (&((mutex)->runtime_mutex)))

#define GINT16_TO_LE(val)	((gint16) (val))
#define GUINT16_TO_LE(val)	((guint16) (val))
#define GINT16_TO_BE(val)	((gint16) GUINT16_SWAP_LE_BE (val))
#define GUINT16_TO_BE(val)	(GUINT16_SWAP_LE_BE (val))
#define GINT32_TO_LE(val)	((gint32) (val))
#define GUINT32_TO_LE(val)	((guint32) (val))
#define GINT32_TO_BE(val)	((gint32) GUINT32_SWAP_LE_BE (val))
#define GUINT32_TO_BE(val)	(GUINT32_SWAP_LE_BE (val))
#define GINT64_TO_LE(val)	((gint64) (val))
#define GUINT64_TO_LE(val)	((guint64) (val))
#define GINT64_TO_BE(val)	((gint64) GUINT64_SWAP_LE_BE (val))
#define GUINT64_TO_BE(val)	(GUINT64_SWAP_LE_BE (val))
#define GLONG_TO_LE(val)	((glong) GINT32_TO_LE (val))
#define GULONG_TO_LE(val)	((gulong) GUINT32_TO_LE (val))
#define GLONG_TO_BE(val)	((glong) GINT32_TO_BE (val))
#define GULONG_TO_BE(val)	((gulong) GUINT32_TO_BE (val))
#define GINT_TO_LE(val)		((gint) GINT32_TO_LE (val))
#define GUINT_TO_LE(val)	((guint) GUINT32_TO_LE (val))
#define GINT_TO_BE(val)		((gint) GINT32_TO_BE (val))
#define GUINT_TO_BE(val)	((guint) GUINT32_TO_BE (val))
#define G_BYTE_ORDER G_LITTLE_ENDIAN

#define GLIB_SYSDEF_POLLIN =1
#define GLIB_SYSDEF_POLLOUT =4
#define GLIB_SYSDEF_POLLPRI =2
#define GLIB_SYSDEF_POLLERR =8
#define GLIB_SYSDEF_POLLHUP =16
#define GLIB_SYSDEF_POLLNVAL =32


#define G_HAVE_WCHAR_H 1
#define G_HAVE_WCTYPE_H 1


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GLIBCONFIG_H */
