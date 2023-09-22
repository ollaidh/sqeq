project(eq_lib)

add_library(eq_lib queq.cpp queq.h utils.h utils.cpp eq_params.cpp eq_params.h   lneq.cpp lneq.h cbeq.cpp cbeq.h visitor_sandbox.cpp visitor_sandbox.h
    eq.cpp
    eq.h
    inheritance_test.h
    inheritance_test.cpp
)

target_include_directories(eq_lib PUBLIC .)


