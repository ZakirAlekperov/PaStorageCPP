
# ============================================================
# PaStorage — система сборки проекта
# ============================================================
#
# Назначение:
#   Настройка компиляции ядра приложения и модульных тестов.
#
# Поддерживаемые платформы:
#   macOS, Linux, Windows.
#
# Стандарт языка:
#   C++20.
#
# Зависимости:
#   GoogleTest — модульное тестирование.
#
# ============================================================

# Минимальная версия CMake для конфигурации проекта.
cmake_minimum_required(VERSION 3.20)

# Объявление проекта с поддержкой языка C++.
project(PaStorage LANGUAGES CXX)

# Использование стандарта C++20.
set(CMAKE_CXX_STANDARD 20)

# Запрет автоматического перехода на старый стандарт.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Отключение нестандартных расширений компилятора.
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================
# Подключение GoogleTest
# ============================================================

# Модуль для получения внешних зависимостей.
include(FetchContent)

# Фиксируем версию GoogleTest конкретным Git-коммитом.
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Настройка совместимости runtime-библиотек на Windows.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Загрузка и подключение GoogleTest.
FetchContent_MakeAvailable(googletest)

# ============================================================
# Библиотека ядра PaStorage
# ============================================================

# Библиотека бизнес-логики PaStorage.
#
# PasswordEntry:
#   Хранение данных учётной записи.
#
# TitleValidator:
#   Проверка названий сервисов.
add_library(pastorage_core
    src/core/PasswordEntry.cpp
    src/core/TitleValidator.cpp
)

# Публичный путь к заголовочным файлам ядра.
# PUBLIC передаёт путь зависимым целям.
target_include_directories(pastorage_core PUBLIC src)

# ============================================================
# Основное приложение
# ============================================================

# Создаём исполняемый файл приложения.
add_executable(PaStorage src/main.cpp)

# Подключаем бизнес-логику к приложению.
target_link_libraries(PaStorage PRIVATE pastorage_core)


# ============================================================
# Модульные тесты
# ============================================================

# Включаем поддержку CTest.
enable_testing()

# Создаём отдельный исполняемый файл тестов.
add_executable(pastorage_tests
    tests/PasswordEntryTest.cpp
    tests/TitleValidatorTest.cpp
)


# Подключаем ядро и GoogleTest.
# gtest_main предоставляет точку входа тестовой программы.
target_link_libraries(pastorage_tests PRIVATE
    pastorage_core
    GTest::gtest_main
)

# Подключаем интеграцию GoogleTest с CMake.
include(GoogleTest)


# Автоматически регистрируем тесты в CTest.
gtest_discover_tests(pastorage_tests)
