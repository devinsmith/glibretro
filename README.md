# glib 1.x

A fork of glib 1.2.10, mostly for retro projects, using CMake on modern systems.

The original glib 1.x targeted many different platforms. In order to reduce
the maintenance burden, support for anything non-Posix has been removed. This
means there is very little configuration support for checking for the presence
of basic headers like string.h, sys/time.h, etc. The build currently assumes
they exist. As such this fork is likely to only compile and work on Linux and
BSD systems. It currently also requires a C89 or higher compiler.

This fork compiles gthread (pthread) and gmodule (libdl) directly into the
glib library.

# Dependencies

The glib library requires the following:
* pthreads

# Building

The current project uses CMake to build the library:

```
mkdir build
cd build
cmake ..
make
make install
```

# License

glib is licensed under version 2.1 of the LGPL.
