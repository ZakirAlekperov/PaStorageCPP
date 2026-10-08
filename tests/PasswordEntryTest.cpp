/**
 * @file PasswordEntryTest.cpp
 * @brief Модульные тесты класса PasswordEntry.
 *
 * @details
 * Проверяет корректность хранения и изменения
 * данных учётной записи.
 *
 * Тестирование выполняется с помощью GoogleTest.
 *
 * Каждый тест проверяет отдельное требование
 * к публичному интерфейсу PasswordEntry.
 */
#include <gtest/gtest.h>
#include "core/PasswordEntry.h"
#include <stdexcept>

/**
 * @test PasswordEntryTest.StoresTitle
 * @brief Проверяет сохранение названия сервиса.
 *
 * @details
 * Создаёт запись с названием "GitHub".
 *
 * Ожидается, что метод title() вернёт
 * переданное при создании название.
 */
TEST(PasswordEntryTest, StoresTitle) {
    PasswordEntry entry{"GitHub"};

    EXPECT_EQ(entry.title(), "GitHub");
}

/**
 * @test PasswordEntryTest.StoresUsername
 * @brief Проверяет сохранение имени пользователя.
 *
 * @details
 * Создаёт запись с названием сервиса и логином.
 *
 * Ожидается, что метод username() вернёт
 * переданное при создании имя пользователя.
 */
TEST(PasswordEntryTest, StoresUsername) {
    PasswordEntry entry{"GitHub", "test@example.com"};

    EXPECT_EQ(entry.username(), "test@example.com");
}

/**
 * @test PasswordEntryTest.UpdatesUsername
 * @brief Проверяет изменение имени пользователя.
 *
 * @details
 * Создаёт запись с первоначальным логином,
 * затем заменяет его новым через setUsername().
 *
 * Ожидается, что username() вернёт новое значение.
 */
TEST(PasswordEntryTest, UpdatesUsername) {
    PasswordEntry entry{"GitHub", "old@example.com"};

    entry.setUsername("new@example.com");

    EXPECT_EQ(entry.username(), "new@example.com");
}


/**
 * @test PasswordEntryTest.RejectsEmptyTitle
 * @brief Проверяет запрет пустого названия сервиса.
 *
 * @details
 * При попытке создать запись с пустым названием
 * конструктор должен выбросить исключение
 * std::invalid_argument.
 *
 * Тест защищает инвариант: название сервиса
 * не может быть пустым.
 */
TEST(PasswordEntryTest, RejectsEmptyTitle) {
    EXPECT_THROW(
        PasswordEntry entry{""},
        std::invalid_argument
    );
}
