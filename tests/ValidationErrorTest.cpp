
/**
 * @file ValidationErrorTest.cpp
 * @brief Модульные тесты исключений валидации.
 *
 * @details
 * Проверяет возможность получать стабильный
 * программный код ошибки независимо от её сообщения.
 */

#include <gtest/gtest.h>

#include "core/ValidationError.h"
#include "core/TitleValidator.h"

/**
 * @test ValidationErrorTest.StoresErrorCode
 * @brief Проверяет сохранение кода ошибки.
 *
 * @details
 * Создаёт исключение с кодом EmptyTitle.
 *
 * Ожидается, что метод code() возвращает
 * переданный код ошибки.
 */
TEST(ValidationErrorTest, StoresErrorCode) {
    ValidationError error{
        ValidationErrorCode::EmptyTitle,
        "Название сервиса не может быть пустым."
    };

    EXPECT_EQ(
        error.code(),
        ValidationErrorCode::EmptyTitle
    );
}


/**
 * @test TitleValidatorTest.EmptyTitleHasErrorCode
 * @brief Проверяет код ошибки пустого названия.
 *
 * @details
 * Для пустой строки валидатор должен выбрасывать
 * ValidationError с кодом EmptyTitle.
 */
TEST(TitleValidatorTest, EmptyTitleHasErrorCode) {
    try {
        TitleValidator::validate("");
        FAIL() << "Ожидалось исключение ValidationError";
    }
    catch (const ValidationError& error) {
        EXPECT_EQ(
            error.code(),
            ValidationErrorCode::EmptyTitle
        );
    }
}

/**
 * @test TitleValidatorTest.WhitespaceTitleHasErrorCode
 * @brief Проверяет код ошибки названия из пробелов.
 *
 * @details
 * Для строки из пробелов валидатор должен выбрасывать
 * ValidationError с кодом WhitespaceTitle.
 */
TEST(TitleValidatorTest, WhitespaceTitleHasErrorCode) {
    try {
        TitleValidator::validate("   ");
        FAIL() << "Ожидалось исключение ValidationError";
    }
    catch (const ValidationError& error) {
        EXPECT_EQ(
            error.code(),
            ValidationErrorCode::WhitespaceTitle
        );
    }
}
