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
        eq_factory.cpp
        eq_factory.h
        eq.cpp
        cmd_reader.h
        cmd_reader.cpp
        file_reader.h
        file_reader.cpp
        printer.cpp
        printer.h
        reader.h
        reader_factory.cpp
        reader_factory.h)

target_include_directories(eq_lib PUBLIC .)
target_compile_definitions(eq_lib PUBLIC _USE_MATH_DEFINES)


