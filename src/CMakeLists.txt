# glib library build system

set(HEADERS
  ../include/glib.h
  ../include/glibconfig.h
  ../include/gmodule.h
  ../include/gmoduleconf.h
)

set(SOURCES
  garray.c
  gcompletion.c
  gdate.c
  ghash.c
  giochannel.c
  glist.c
  gmem.c
  gmutex.c
  gprimes.c
  gscanner.c
  gstrfuncs.c
  gtimer.c
  gutils.c
  gcache.c
  gdataset.c
  gerror.c
  ghook.c
  giounix.c
  gmain.c
  gmessages.c
  gnode.c
  grel.c
  gslist.c
  gstring.c
  gtree.c

  gthread.c

  gmodule.c
)

# libdir name to allow overriding to lib32 / lib64
set(CMAKE_INSTALL_LIBDIR "lib" CACHE STRING "Specify the name of the directory where libraries are meant to be installed")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

set(LIBS ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(${PROJECT_NAME} ${LIBS})


add_compile_definitions(HAVE_CONFIG_H)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_BINARY_DIR})


# Enable all warnings/errors
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${VERSION} SOVERSION ${GLIB_PATCH_LEVEL})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME glib-${GLIB_MAJOR_VERSION}.${GLIB_MINOR_VERSION})

install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} )
install(FILES ${HEADERS} DESTINATION include/glib-${GLIB_MAJOR_VERSION}.${GLIB_MINOR_VERSION})

