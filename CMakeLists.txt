cmake_minimum_required(VERSION 3.10)
project(Llibs)

# Установите стандарт C
set(CMAKE_C_STANDARD 11)

# Включите путь к директориям include
include_directories(cross/include)

# Определите путь в зависимости от операционной системы
if (WIN32)
    set(OS_PATH "native/Windows/src")
elseif (UNIX AND NOT APPLE)
    if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        set(OS_PATH "native/Linux/src")
    elseif (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
        set(OS_PATH "native/FreeBSD/src")
    # Добавьте другие Unix-подобные ОС здесь
    else()
        message(FATAL_ERROR "Unsupported UNIX platform: ${CMAKE_SYSTEM_NAME}")
    endif()
elseif (APPLE)
    set(OS_PATH "native/macOS/src")
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

# Найдите все исходные файлы в директории src
file(GLOB_RECURSE LLIBS_SRC_FILES "${OS_PATH}/*.c" "cross/src/*.c")

# Создайте статическую библиотеку
add_library(llibs STATIC ${LLIBS_SRC_FILES})