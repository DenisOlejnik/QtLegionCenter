qt_add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(ui)

target_link_libraries(${PROJECT_NAME} PRIVATE
    UserInterface
    Qt6::Widgets)
