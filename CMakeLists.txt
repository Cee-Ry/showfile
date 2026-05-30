cmake_minimum_required(VERSION 3.10) 
project(showfile)

add_executable(show
    main.cpp
)

install(TARGETS show
    DESTINATION $ENV{HOME}/.local/bin
)
