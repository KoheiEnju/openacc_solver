cmake_minimum_required(VERSION 3.21)
project(openacc_solver)

set(CMAKE_CXX_STANDARD 14)

if(OPENACC)
    set(CMAKE_CXX_COMPILER /opt/nvidia/hpc_sdk/Linux_x86_64/22.7/compilers/bin/nvc++)
    if(OPENACC STREQUAL "GPU")
        set(CMAKE_CXX_FLAGS "-acc -Minfo=accel -gpu=managed")
    elseif(OPENACC STREQUAL "CPU")
        set(CMAKE_CXX_FLAGS "-acc=multicore -Minfo=accel")
    endif()
endif()

include_directories(src)

add_executable(openacc_solver
        src/Grid2D.cpp
        src/Grid2D.h src/main.cpp src/ODE.cpp src/ODE.h src/RK4.cpp src/RK4.h src/RK4Helper.cpp src/RK4Helper.h src/common.h src/Particle.cpp src/Particle.h)
