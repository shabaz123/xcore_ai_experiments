cmake_minimum_required(VERSION 3.21)
include($ENV{XMOS_CMAKE_PATH}/xcommon.cmake)
project(first_example)

set(APP_HW_TARGET XK-EVK-XU316)

XMOS_REGISTER_APP()
