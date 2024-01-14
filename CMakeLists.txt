cmake_minimum_required(VERSION 3.12)
project(Calculator)

find_package(pybind11 REQUIRED)

pybind11_add_module(Calculator calculator.cpp)
