cmake_minimum_required(VERSION 3.0)
project(Meo)

set(HEADERS
    ./include/mylibrary.h
)

set(SOURCES
    ./src/mylibrary.cpp
)

add_executable(Meo1
    ./src/21-10.cpp
    ${HEADERS}
    ${SOURCES}
)

add_executable(Meo2
    ./src/22-10.cpp
    ${HEADERS}
    ${SOURCES}
)

add_executable(Data
    ./Data/Data.cpp
)   

target_include_directories(Meo1 PUBLIC include)
target_include_directories(Meo2 PUBLIC include)
