add_library(UserInterface STATIC
    mainwindow.h mainwindow.cpp)

target_link_libraries(UserInterface PRIVATE Qt6::Widgets)
target_include_directories(UserInterface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
