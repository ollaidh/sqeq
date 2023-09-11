project(eq_lib)

add_library(eq_lib queq.cpp utils.h utils.cpp eq_params.cpp eq_params.h solve.cpp solve.h)

target_include_directories(eq_lib PUBLIC .)


