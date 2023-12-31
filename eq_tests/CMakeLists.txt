project(eq_tests)

add_executable(${PROJECT_NAME}
        tests.cpp
        parse_tests.cpp
        eq_factory_tests.cpp
        queq_tests.cpp lneq_tests.cpp cbeq_tests.cpp cmd_reader_tests.cpp file_reader_tests.cpp printer_tests.cpp reader_factory_tests.cpp)

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.13.0
        GIT_SHALLOW    TRUE
        GIT_PROGRESS   TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(
        ${PROJECT_NAME}
        eq_lib
        GTest::gtest_main
)

file(
        COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/coeffs.txt
        DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}
        )
