cmake_minimum_required(VERSION 3.24)

include(pico_sdk_import.cmake)

project(pico-projects)

pico_sdk_init()

add_executable(robot 
    robot.cpp 
    logic.cpp 
    logic2.cpp 
    u_s_sensor.cpp 
    motors.cpp
    init+test.cpp
)

target_link_libraries(robot
    pico_stdlib
    pico_multicore
    hardware_adc
    hardware_i2c
    hardware_gpio
    hardware_timer
    hardware_pwm
)
pico_enable_stdio_usb(robot 1)
pico_enable_stdio_uart(robot 0)

pico_add_extra_outputs(robot)