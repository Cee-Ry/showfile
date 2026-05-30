cmake_minimum_required(VERSION 3.10)
project(showfile)

set(CMAKE_CXX_STANDARD 17)        # add this
set(CMAKE_CXX_STANDARD_REQUIRED ON) # add this too

add_executable(show
    main.cpp
)

if (MSVC)
    target_compile_options(show PRIVATE /O1 /GL)      
    target_link_options(show PRIVATE /OPT:REF /OPT:ICF) 
else()
    target_compile_options(show PRIVATE -Os)
    target_link_options(show PRIVATE -s)
endif()

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
