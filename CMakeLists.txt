cmake_minimum_required(VERSION 3.24)
project(lcd_dht11 CXX C)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lcd_dht11 
        src/main.cpp
        src/drivers/RowBasedDisplay.h)

add_library(
        utils_lib STATIC
        src/utils/defin.c
)
target_include_directories(utils_lib PUBLIC src/utils)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest) # This makes available the lib `gtest_main`

option(TESTS_ "Should Tests" ON)
if (TESTS_)
    add_subdirectory(tests)
endif ()

target_link_libraries(lcd_dht11 PUBLIC utils_lib)
