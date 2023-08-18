project(sqeq_app)

add_executable(sqeq_app main.cpp)

target_link_libraries(sqeq_app PRIVATE sqeq_lib)
