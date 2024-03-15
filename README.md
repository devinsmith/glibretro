# glib 1.x

A fork of glib 1.2.10, mostly for retro projects, using CMake on modern systems.

Probably only works on Linux and POSIX based systems. Requires at least a C89 compiler.

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
