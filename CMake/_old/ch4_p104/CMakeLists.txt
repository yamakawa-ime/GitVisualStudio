cmake_minimum_required(VERSION 3.26)
project(YMRentalCompany CXX)
add_executable(YMRentalSystem main.cpp)
add_subdirectory(cars)
target_link_libraries(YMRentalSystem PRIVATE CarsSystem)