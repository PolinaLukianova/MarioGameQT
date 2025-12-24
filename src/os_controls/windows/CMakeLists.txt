target_sources(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/os_control_settings.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/user_input.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)
