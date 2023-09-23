project(eq_lib)

add_library(eq_lib
        queq.cpp
        queq.h
        utils.h
        utils.cpp
        eq_params.cpp
        eq_params.h
        lneq.cpp
        lneq.h
        cbeq.cpp
        cbeq.h
        eq.cpp
        eq.h
        parse.h)

target_include_directories(eq_lib PUBLIC .)


