add_library(
        lib_impl STATIC
        display_builder/DisplayBuilder.cpp
        impl/ConsoleDisplay.cpp impl/LCDDisplay.cpp
)

target_include_directories(lib_impl PUBLIC ../include ./display_builder ./impl)

