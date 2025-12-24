add_subdirectory(os_api)

if(WIN32)
	add_subdirectory(windows)
else()
	add_subdirectory(unix)
endif()