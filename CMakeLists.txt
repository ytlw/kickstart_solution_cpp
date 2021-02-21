cmake_minimum_required(VERSION 3.17)
project(kickstart)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS
        ${CMAKE_CXX_FLAGS}
        -fsanitize=address,undefined)

FUNCTION(build_all_cpp DIRECTORY INPUT_FROM_FILE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${DIRECTORY})
    FILE(GLOB_RECURSE SRC_FILES "${DIRECTORY}/*.cpp")
    FOREACH(FILE_PATH ${SRC_FILES})
        STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
        add_executable(${FILE_NAME} "${DIRECTORY}/${FILE_NAME}.cpp")
        IF(INPUT_FROM_FILE)
            target_compile_definitions(${FILE_NAME} PRIVATE -DINPUT_FILE="${PROJECT_SOURCE_DIR}/${DIRECTORY}/${FILE_NAME}.in")
        ENDIF()
    ENDFOREACH(FILE_PATH)
endfunction()

set(COMPILE_DIRECTORIES
        archive/2013/practice
        archive/2020/h)

FOREACH(DIRECTORY ${COMPILE_DIRECTORIES})
    build_all_cpp(${DIRECTORY} true)
ENDFOREACH()