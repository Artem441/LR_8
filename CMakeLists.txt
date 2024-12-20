cmake_minimum_required(VERSION 3.10)

# Укажите имя проекта
project(Task_1)

# Установите стандарт C++ на 17 или выше
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
  AddStructures.cpp
  ChangeStructure.cpp
  DeleteStructure.cpp
  FindStructure.cpp
  InicialisationArrOfStructures.cpp
  OutArrOfStructures.cpp
  SortingAndOut.cpp
)

# Опция для включения санитайзеров
option(ENABLE_SANITIZERS "Enable Address and Thread Sanitizers" ON)

if (ENABLE_SANITIZERS)
    message(STATUS "Sanitizers enabled")

    # Установите флаги для санитайзеров
    set(SANITIZER_FLAGS "-fsanitize=address -fno-omit-frame-pointer -g")

    # Добавьте флаги к компиляции и линковке
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${SANITIZER_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${SANITIZER_FLAGS}")
endif()

# Добавьте исходный файл
add_executable(Task_1 Task_1.cpp)


