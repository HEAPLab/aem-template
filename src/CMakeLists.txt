
cmake_minimum_required(VERSION 3.0)

find_library(BBQUE_RTLIB_LIBRARY bbque_rtlib
	HINTS ${BOSP_SYSROOT}
	PATHS ${BOSP_SYSROOT}
	PATH_SUFFIXES lib/bbque
)

# Check for required libs and packages (headers + lib)
find_package(Boost 1.65.0 REQUIRED program_options
	PATHS ${BOSP_SYSROOT})
message (STATUS "Boost libraries: ${Boost_LIBRARIES}")
message (STATUS "Boost include  : ${Boost_INCLUDE_DIRS}")

set(AEM_TEMPLATE_SRC AEMTemplate_exc AEMTemplate_main)
add_executable(aem-template ${AEM_TEMPLATE_SRC})

set_property(TARGET aem-template PROPERTY CXX_STANDARD 11)

target_link_libraries(
	aem-template
	${BBQUE_RTLIB_LIBRARY}
	${Boost_LIBRARIES}
)

# Use link path ad RPATH
set_property(TARGET aem-template PROPERTY INSTALL_RPATH_USE_LINK_PATH TRUE)

install (TARGETS aem-template RUNTIME
	DESTINATION ${CMAKE_INSTALL_PREFIX}/usr/bin)

