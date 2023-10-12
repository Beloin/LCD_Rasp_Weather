cmake_minimum_required(VERSION 3.18)
project(lcd_dht11 CXX C)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        lcd_dht11 
        src/main.cpp
)

add_library(
        utils_lib STATIC
        src/utils/defin.c
)
target_include_directories(utils_lib PUBLIC src/utils)

# Include drivers lib
target_include_directories(lcd_dht11 PUBLIC include/)

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

add_subdirectory(lib)

find_package(spdlog REQUIRED)
target_link_libraries(lcd_dht11 PUBLIC utils_lib lib_impl pthread)
target_link_libraries(lcd_dht11 PRIVATE spdlog::spdlog_header_only)
#target_link_libraries(lcd_dht11 PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)

add_compile_definitions(SPDLOG_DEBUG_ON)
#target_compile_definitions(lcd_dht11 PUBLIC SPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_DEBUG)
#add_compile_definitions(TEST="TEST")

#target_compile_definitions(lib_impl PRIVATE ON_RASP=1)
