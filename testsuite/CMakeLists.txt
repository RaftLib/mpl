set( CMAKE_INCLUDE_CURRENT_DIR ON )

set( TESTAPPS   dummy
                 )

include_directories( ${PROJECT_SOURCE_DIR}/include )

foreach( APP ${TESTAPPS} )
    add_executable( ${APP} "${APP}.cpp" )
    target_link_libraries( ${APP} mpl ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_RT_LIB} ${CMAKE_NUMA_LIB} )
    add_test( NAME "${APP}_test" COMMAND ${APP} )
endforeach( APP ${TESTAPPS} )
