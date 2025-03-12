# glibretro master makefile

.PHONY: all install install-static install-shared clean
.SUFFIXES: .c .o .lo

include config.mak

UNAME_S := $(shell uname -s)

LIB_PREFIX = lib
STATIC_EXT = .a
SHARED_EXT = .so
SHARED_VER = .1
VERSION_MAJOR = 1
VERSION_MINOR = 2
SHARED_NAME = $(LIB_PREFIX)glib-$(VERSION_MAJOR).$(VERSION_MINOR)$(SHARED_EXT)
STATIC_NAME = $(LIB_PREFIX)glib-$(VERSION_MAJOR).$(VERSION_MINOR)$(STATIC_EXT)

CFLAGS += -Wall -Iinclude -DHAVE_CONFIG_H -O2
CFLAGS_SHARED += -fPIC
CPPFLAGS += -MMD -MP -MT $@

ifeq ($(UNAME_S),Darwin)
	SHARED_EXT = .dylib
	LDFLAGS_SHARED = -dynamiclib -install_name @rpath/$(SHARED_NAME)
else
	LDFLAGS_SHARED?=-shared -Wl,-soname,$(LIB_PREFIX)glib.$(SHARED_EXT).$(VERSION_MAJOR)
endif

SRCS = src/garray.c \
  src/gcompletion.c \
  src/gdate.c \
  src/ghash.c \
  src/giochannel.c \
  src/glist.c \
  src/gmem.c \
  src/gmutex.c \
  src/gprimes.c \
  src/gscanner.c \
  src/gstrfuncs.c \
  src/gtimer.c \
  src/gutils.c \
  src/gcache.c \
  src/gdataset.c \
  src/gerror.c \
  src/ghook.c \
  src/giounix.c \
  src/gmain.c \
  src/gmessages.c \
  src/gnode.c \
  src/grel.c \
  src/gslist.c \
  src/gstring.c \
  src/gtree.c \
  src/gthread.c \
  src/gmodule.c

OBJS = $(SRCS:.c=.o)
LOBJS = $(OBJS:.o=.lo)
DEPS = $(SRCS:.c=.d)

all: $(STATIC_NAME) $(SHARED_NAME)

$(STATIC_NAME): $(OBJS)
	$(AR) cr $@ $(OBJS)

$(SHARED_NAME): $(LOBJS)
	$(CC) $(LDFLAGS) $(LDFLAGS_SHARED) -o $@ $(LOBJS) $(LDLIBS)

.c.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

.c.lo:
	$(CC) $(CFLAGS) $(CFLAGS_SHARED) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(STATIC_NAME) $(SHARED_NAME) $(OBJS) $(LOBJS) $(DEPS)

# Include automatically generated dependency files
-include $(wildcard *.d)
