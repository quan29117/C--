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

add_executable(Test
    ./src/Test.cpp
    ${HEADERS}
    ${SOURCES}
)

add_executable(Hoc
    ./src/Danh_sach_lien_ket_don.cpp
)

add_executable(Data
    ./Data/Data.cpp
)   

target_include_directories(Meo1 PUBLIC include)
target_include_directories(Test PUBLIC include)
