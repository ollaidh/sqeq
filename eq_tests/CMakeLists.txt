project(eq_tests)

add_executable(${PROJECT_NAME}
        tests.cpp
        parse_tests.cpp
        factory_tests.cpp)

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
