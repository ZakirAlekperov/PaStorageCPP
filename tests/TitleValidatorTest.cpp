
/**
 * @file TitleValidatorTest.cpp
 * @brief Модульные тесты валидатора названий сервисов.
 *
 * @details
 * Проверяет, что TitleValidator принимает допустимые
 * названия и отклоняет недопустимые значения.
 *
 * Тесты также проверяют различие сообщений об ошибках.
 */

#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

#include "core/TitleValidator.h"

/**
 * @test TitleValidatorTest.AcceptsValidTitle
 * @brief Проверяет допустимость обычного названия.
 */
TEST(TitleValidatorTest, AcceptsValidTitle) {
    EXPECT_NO_THROW(
        TitleValidator::validate("GitHub")
    );
}

/**
 * @test TitleValidatorTest.RejectsEmptyTitle
 * @brief Проверяет отклонение пустой строки.
 */
TEST(TitleValidatorTest, RejectsEmptyTitle) {
    EXPECT_THROW(
        TitleValidator::validate(""),
        std::invalid_argument
    );
}

/**
 * @test TitleValidatorTest.RejectsWhitespaceTitle
 * @brief Проверяет отклонение названия из пробелов.
 */
TEST(TitleValidatorTest, RejectsWhitespaceTitle) {
    EXPECT_THROW(
        TitleValidator::validate(" \t\n "),
        std::invalid_argument
    );
}

/**
 * @test TitleValidatorTest.AcceptsSurroundingSpaces
 * @brief Проверяет допустимость названия с внешними пробелами.
 */
TEST(TitleValidatorTest, AcceptsSurroundingSpaces) {
    EXPECT_NO_THROW(
        TitleValidator::validate("  GitHub  ")
    );
}

/**
 * @test TitleValidatorTest.DistinguishesValidationErrors
 * @brief Проверяет различные сообщения ошибок.
 *
 * @details
 * Пустая строка и строка из пробелов должны
 * приводить к исключениям с различным текстом.
 */
TEST(TitleValidatorTest, DistinguishesValidationErrors) {
    std::string emptyError;
    std::string whitespaceError;

    try {
        TitleValidator::validate("");
    }
    catch (const std::invalid_argument& error) {
        emptyError = error.what();
    }

    try {
        TitleValidator::validate("   ");
    }
    catch (const std::invalid_argument& error) {
        whitespaceError = error.what();
    }

    EXPECT_EQ(
        emptyError,
        "Название сервиса не может быть пустым."
    );

    EXPECT_EQ(
        whitespaceError,
        "Название сервиса не может состоять из пробелов."
    );
}
