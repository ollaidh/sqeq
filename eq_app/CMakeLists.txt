project(eq_app)

add_executable(eq_app main.cpp)

target_link_libraries(eq_app PRIVATE eq_lib)
