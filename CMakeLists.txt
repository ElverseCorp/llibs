
cmake_minimum_required(VERSION 3.10)
project(
    "Ellipse Framework"
    VERSION 2.0
    DESCRIPTION "Cross-platform for high-perfomance low-level and system functions."
    LANGUAGES C
)

set(LLIBS_SRC_FILES 
	src/memory.c
	src/str.c
	src/main.c
)
set(LLIBS_INCLUDE_PATH include/)


add_library(llibs STATIC)

target_include_directories(llibs PUBLIC ${LLIBS_INCLUDE_PATH})
target_sources(llibs PRIVATE ${LLIBS_SRC_FILES})

target_compile_options(llibs PRIVATE
    -Wall                    # Базовые предупреждения
    -Wextra                  # Дополнительные предупреждения
    -Wpedantic               # Строгое соответствие стандарту ISO C/C++
    -Werror                  # Любое предупреждение = ошибка
    -Wshadow                 # Предупреждение, если переменная перекрывает другую
    -Wcast-align             # Предупреждение при приведении типов с нарушением выравнивания
    -Wunused                 # Поиск неиспользуемого кода
    -Wconversion             # Предупреждение при потере точности (например, double -> int)
    -Wsign-conversion        # Предупреждение при смешивании signed/unsigned
    -Wnull-dereference       # Поиск потенциальных разыменований NULL
    -Wdouble-promotion       # Если float неявно превращается в double
    -Wformat=2               # Усиленная проверка printf/scanf
    -Wmisleading-indentation # Проверка подозрительных отступов (как в стиле Apple goto fail)
    -Wduplicated-cond        # Поиск дублирующихся условий в if/else
    -Wduplicated-branches    # Поиск одинакового кода в разных ветках if/else
    -Wlogical-op             # Подозрительные логические операции
    -fno-strict-aliasing	 # Без агрессивной оптимизации с указателями
)
