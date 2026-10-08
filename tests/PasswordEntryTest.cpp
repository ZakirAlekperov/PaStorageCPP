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
#include "core/ValidationError.h"

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


/**
 * @test PasswordEntryTest.RejectsEmptyTitleWithoutUsername
 * @brief Проверяет валидацию конструктора с одним аргументом.
 *
 * @details
 * Убеждается, что конструктор без имени пользователя
 * также запрещает пустое название сервиса.
 *
 * Это подтверждает, что делегирование конструктора
 * сохраняет установленный инвариант класса.
 */
TEST(PasswordEntryTest, RejectsEmptyTitleWithoutUsername) {
    EXPECT_THROW(
        PasswordEntry entry{""},
        std::invalid_argument
    );
}


/**
 * @test PasswordEntryTest.RejectsEmptyTitleWithUsername
 * @brief Проверяет запрет пустого названия сервиса
 *        при создании записи с именем пользователя.
 *
 * @details
 * Создаёт объект PasswordEntry с двумя аргументами:
 * пустым названием сервиса и непустым именем пользователя.
 *
 * Ожидается, что конструктор выбросит исключение
 * std::invalid_argument, поскольку название сервиса
 * не может быть пустым.
 *
 * Тест подтверждает соблюдение инварианта класса
 * при использовании конструктора с двумя параметрами.
 */
TEST(PasswordEntryTest, RejectsEmptyTitleWithUsername) {
    EXPECT_THROW(
        (PasswordEntry{"", "user@example.com"}),
        std::invalid_argument
    );
}


/**
 * @test PasswordEntryTest.RejectsWhitespaceOnlyTitle
 * @brief Проверяет запрет названия, состоящего из пробелов.
 *
 * @details
 * Создаёт запись с названием, содержащим только
 * пробелы ASCII.
 *
 * Ожидается исключение std::invalid_argument,
 * поскольку такое название не содержит
 * значимых символов.
 *
 * @note
 * Этот тест проверяет обычные пробелы.
 * Другие пробельные символы будут проверены
 * отдельными тестами.
 */
TEST(PasswordEntryTest, RejectsWhitespaceOnlyTitle) {
    EXPECT_THROW(
        (PasswordEntry{"   ", "user@example.com"}),
        std::invalid_argument
    );
}


/**
 * @test PasswordEntryTest.EmptyTitleHasSpecificError
 * @brief Проверяет сообщение об ошибке для пустого названия.
 *
 * @details
 * Убеждается, что исключение содержит именно сообщение
 * о пустом названии, а не о пробельных символах.
 */
TEST(PasswordEntryTest, EmptyTitleHasSpecificError) {
    try {
        PasswordEntry entry{""};
        FAIL() << "Ожидалось исключение std::invalid_argument";
    }
    catch (const std::invalid_argument& e) {
        EXPECT_STREQ(
            e.what(),
            "Название сервиса не может быть пустым."
        );
    }
}


/**
 * @test PasswordEntryTest.RejectsMixedWhitespaceTitle
 * @brief Проверяет запрет названия из разных пробельных символов.
 *
 * @details
 * Название содержит пробел, горизонтальную табуляцию
 * и перевод строки, но не содержит значимых символов.
 *
 * Конструктор должен выбросить std::invalid_argument.
 */
TEST(PasswordEntryTest, RejectsMixedWhitespaceTitle) {
    EXPECT_THROW(
        (PasswordEntry{" \t\n ", "user@example.com"}),
        std::invalid_argument
    );
}



/**
 * @test PasswordEntryTest.PreservesTitleWithSurroundingSpaces
 * @brief Проверяет сохранение допустимого названия с пробелами.
 *
 * @details
 * Название содержит значимые символы и пробелы
 * в начале и конце строки.
 *
 * Конструктор должен успешно создать объект.
 * Метод title() должен вернуть исходную строку
 * без удаления или изменения пробелов.
 */
TEST(PasswordEntryTest, PreservesTitleWithSurroundingSpaces) {
    PasswordEntry entry{"  GitHub  ", "user@example.com"};

    EXPECT_EQ(entry.title(), "  GitHub  ");
}



/**
 * @test PasswordEntryTest.RejectsWhitespaceUsernameOnCreation
 * @brief Проверяет валидацию имени при создании записи.
 *
 * @details
 * Попытка создать запись с логином из пробелов
 * должна завершиться исключением ValidationError.
 */
TEST(PasswordEntryTest, RejectsWhitespaceUsernameOnCreation) {
    EXPECT_THROW(
        (PasswordEntry{"GitHub", "   "}),
        ValidationError
    );
}



/**
 * @test PasswordEntryTest.RejectsWhitespaceUsernameOnUpdate
 * @brief Проверяет отклонение некорректного нового логина.
 *
 * @details
 * Создаёт корректную запись и пытается заменить
 * имя пользователя строкой из пробелов.
 *
 * Ожидается исключение ValidationError.
 *
 * Дополнительно проверяется, что прежнее значение
 * username не изменилось после неудачной операции.
 */
TEST(PasswordEntryTest, RejectsWhitespaceUsernameOnUpdate) {
    PasswordEntry entry{"GitHub", "old@example.com"};

    EXPECT_THROW(
        entry.setUsername("   "),
        ValidationError
    );

    EXPECT_EQ(
        entry.username(),
        "old@example.com"
    );
}
