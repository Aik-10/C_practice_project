cmake_minimum_required(VERSION 3.26)
project(personProject C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(personProject src/main.c
        includes/person.h
        includes/blood_type_handler.h
        includes/file_handler.h
        src/blood_type_handler.c
        src/file_handler.c
        src/navigation.c
        includes/navigation.h
        src/create_person.c
        includes/create_person.h
)
