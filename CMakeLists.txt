cmake_minimum_required(VERSION 3.25)

project(UIN-Campus VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(UIN_ACTIVER_SANITIZERS "Activer ASan et UBSan" OFF)

add_library(options_projet INTERFACE)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(options_projet INTERFACE
            -Wall
                    -Wextra
                            -Wpedantic
                                    -Wshadow
                                            -Wconversion
                                                )

                                                    if(UIN_ACTIVER_SANITIZERS)
                                                            target_compile_options(options_projet INTERFACE
                                                                        -fsanitize=address,undefined
                                                                                    -fno-omit-frame-pointer
                                                                                            )

                                                                                                    target_link_options(options_projet INTERFACE
                                                                                                                -fsanitize=address,undefined
                                                                                                                        )
                                                                                                                            endif()
                                                                                                                            endif()

                                                                                                                            add_library(uincampus
                                                                                                                                src/version.cpp
                                                                                                                                )

                                                                                                                                target_include_directories(uincampus PUBLIC
                                                                                                                                    ${PROJECT_SOURCE_DIR}/include
                                                                                                                                    )

                                                                                                                                    target_compile_definitions(uincampus PUBLIC
                                                                                                                                        UIN_VERSION="${PROJECT_VERSION}"
                                                                                                                                        )

                                                                                                                                        target_link_libraries(uincampus PRIVATE
                                                                                                                                            options_projet
                                                                                                                                            )

                                                                                                                                            add_executable(uin-campus
                                                                                                                                                app/main.cpp
                                                                                                                                                )

                                                                                                                                                target_link_libraries(uin-campus PRIVATE
                                                                                                                                                    uincampus
                                                                                                                                                        options_projet
                                                                                                                                                        )