set( CMAKE_INCLUDE_CURRENT_DIR ON )


add_library( mpl mpl.cpp )
install( TARGETS mpl
         ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib )
