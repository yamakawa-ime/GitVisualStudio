cmake_minimum_required(VERSION 3.26)
# projectのNAMEはソリューションの名前
project(YMRentalCompany 
        VERSION 1.2.3 
        DESCRIPTION "My yamakawa First project"
        HOMEPAGE_URL "http://yamakawa.com"
        )
message(${PROJECT_NAME})
message(${PROJECT_VERSION})
message(${PROJECT_DESCRIPTION})
message(${PROJECT_HOMEPAGE_URL})
include(cars/cars.cmake)
# add_executableの名前は,プロジェクトファイルの名前になる
add_executable(RentalSystem
               main.cpp
               ${cars_sources})

               