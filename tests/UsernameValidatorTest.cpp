
/**
 * @file UsernameValidatorTest.cpp
 * @brief Модульные тесты проверки имён пользователей.
 *
 * @details
 * Проверяет правила допустимости username.
 *
 * Пустые имена пользователей разрешены.
 * Значения, состоящие исключительно из ASCII-пробельных
 * символов, должны отклоняться.
 */

#include <gtest/gtest.h>

#include <stdexcept>

#include "core/UsernameValidator.h"
#include "core/ValidationError.h"

/**
 * @test UsernameValidatorTest.AcceptsEmptyUsername
 * @brief Проверяет допустимость пустого имени пользователя.
 *
 * @details
 * Отсутствие логина является допустимым состоянием
 * записи PaStorage.
 */
TEST(UsernameValidatorTest, AcceptsEmptyUsername) {
    EXPECT_NO_THROW(
        UsernameValidator::validate("")
    );
}

/**
 * @test UsernameValidatorTest.RejectsWhitespaceUsername
 * @brief Проверяет запрет имени пользователя из пробелов.
 *
 * @details
 * Строка, состоящая только из ASCII-пробельных символов,
 * должна вызывать исключение ValidationError.
 */
TEST(UsernameValidatorTest, RejectsWhitespaceUsername) {
    EXPECT_THROW(
        UsernameValidator::validate("   "),
        ValidationError
    );
}


/**
 * @test UsernameValidatorTest.AcceptsRegularUsername
 * @brief Проверяет допустимость обычного логина.
 */
TEST(UsernameValidatorTest, AcceptsRegularUsername) {
    EXPECT_NO_THROW(
        UsernameValidator::validate("zakir")
    );
}

/**
 * @test UsernameValidatorTest.AcceptsEmailUsername
 * @brief Проверяет допустимость логина в форме email.
 */
TEST(UsernameValidatorTest, AcceptsEmailUsername) {
    EXPECT_NO_THROW(
        UsernameValidator::validate("user@example.com")
    );
}

/**
 * @test UsernameValidatorTest.RejectsMixedWhitespace
 * @brief Проверяет запрет различных пробельных символов.
 */
TEST(UsernameValidatorTest, RejectsMixedWhitespace) {
    EXPECT_THROW(
        UsernameValidator::validate(" \t\n "),
        ValidationError
    );
}

/**
 * @test UsernameValidatorTest.ReturnsWhitespaceUsernameCode
 * @brief Проверяет программный код ошибки username.
 *
 * @details
 * Проверяет, что ошибка имеет код WhitespaceUsername,
 * независимо от локализованного текста сообщения.
 */
TEST(UsernameValidatorTest, ReturnsWhitespaceUsernameCode) {
    try {
        UsernameValidator::validate("   ");
        FAIL() << "Ожидалось исключение ValidationError";
    }
    catch (const ValidationError& error) {
        EXPECT_EQ(
            error.code(),
            ValidationErrorCode::WhitespaceUsername
        );
    }
}
