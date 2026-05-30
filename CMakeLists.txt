cmake_minimum_required(VERSION 3.10)
project(showfile)

add_executable(show
    main.cpp
)

# Only change the install prefix if the user hasn't specified one themselves
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    if(WIN32)
        set(CMAKE_INSTALL_PREFIX
            "$ENV{LOCALAPPDATA}/Programs/showfile"
            CACHE PATH "Default install path for Windows" FORCE)
    else()
        set(CMAKE_INSTALL_PREFIX
            "$ENV{HOME}/.local"
            CACHE PATH "Default install path for UNIX" FORCE)
    endif()
endif()

install(TARGETS show
    RUNTIME DESTINATION bin
)
