project(eq_lib)

add_library(eq_lib
        queq.cpp
        queq.h
        utils.h
        utils.cpp
        lneq.cpp
        lneq.h
        cbeq.cpp
        cbeq.h
        eq.h
        parse.h
        factory.cpp
        factory.h
        eq.cpp
        )

target_include_directories(eq_lib PUBLIC .)


