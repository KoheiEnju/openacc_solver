cmake_minimum_required(VERSION 3.21)
project(openacc_solver)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(openacc_solver
        src/Grid2D.cpp
        src/Grid2D.h src/main.cpp src/ODE.cpp src/ODE.h src/RK4.cpp src/RK4.h src/RK4Helper.cpp src/RK4Helper.h)
