add_executable(
        chel
        main.cpp
        process/Subprocess.cpp
        process/Subprocess.hpp
)

target_include_directories(chel PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(chel PRIVATE Threads::Threads)

