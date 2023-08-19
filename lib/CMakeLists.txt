add_library(
        lib_impl STATIC
        display_builder/DisplayBuilder.cpp
        impl/ConsoleDisplay.cpp
)

target_include_directories(lib_impl PUBLIC ../include ./display_builder ./impl)

execute_process(COMMAND uname -m
        OUTPUT_VARIABLE _output OUTPUT_STRIP_TRAILING_WHITESPACE)

message("`uname -m` output was '${_output}'")

# TODO: Why don't limit the
if (_output STREQUAL "x86_64")
    target_compile_definitions(lib_impl PRIVATE ON_LINUX=1)
else()
    target_include_directories(lib_impl PUBLIC ./drivers)
    target_sources(lib_impl PRIVATE drivers/LCDDisplay.cpp)

    target_compile_definitions(lib_impl PRIVATE ON_LINUX=0)

    # Is necessary to include pigpio?
endif()