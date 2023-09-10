project(eq_lib)

add_library(eq_lib sqeq.cpp utils.h utils.cpp)

target_include_directories(eq_lib PUBLIC .)


