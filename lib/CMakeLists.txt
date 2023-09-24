add_library(
        lib_impl STATIC
        peripheral_factory/PeripheralFactory.cpp
        impl/ConsoleDisplay.cpp
        impl/RandomWeatherGeneratorTask.cpp
)

target_include_directories(lib_impl PUBLIC ../include peripheral_factory ./impl)

execute_process(COMMAND uname -m
        OUTPUT_VARIABLE _output OUTPUT_STRIP_TRAILING_WHITESPACE)

message("`uname -m` output was '${_output}'")

if (_output STREQUAL "x86_64")
    target_compile_definitions(lib_impl PRIVATE ON_LINUX=1)
else()
    target_include_directories(lib_impl PUBLIC ./drivers)
    target_sources(lib_impl PRIVATE drivers/LCDDisplay.cpp)

    target_compile_definitions(lib_impl PRIVATE ON_LINUX=0)

    target_link_libraries(lib_impl pigpio)
endif()