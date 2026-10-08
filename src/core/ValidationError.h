
/**
 * @file ValidationError.h
 * @brief Объявление типов ошибок валидации PaStorage.
 *
 * @details
 * Содержит перечисление кодов ошибок и класс
 * исключения для обработки некорректных данных.
 *
 * Позволяет различать ошибки по программному коду,
 * независимо от языка диагностического сообщения.
 */

#ifndef PASTORAGE_VALIDATION_ERROR_H
#define PASTORAGE_VALIDATION_ERROR_H

#include <stdexcept>
#include <string>

/**
 * @enum ValidationErrorCode
 * @brief Коды ошибок проверки входных данных.
 */
enum class ValidationErrorCode {
    EmptyTitle,         ///< Пустое название сервиса.
    WhitespaceTitle,    ///< Название состоит из пробелов.
    WhitespaceUsername  ///< Логин состоит из пробелов.
};

/**
 * @class ValidationError
 * @brief Исключение при некорректных входных данных.
 *
 * @details
 * Наследуется от std::invalid_argument.
 *
 * Содержит диагностическое сообщение и
 * программный код ошибки.
 */
class ValidationError : public std::invalid_argument {
public:
    /**
     * @brief Создаёт исключение валидации.
     *
     * @param code Программный код ошибки.
     * @param message Диагностическое сообщение.
     */
    ValidationError(
        ValidationErrorCode code,
        const std::string& message
    );

    /**
     * @brief Возвращает код ошибки.
     *
     * @return Значение ValidationErrorCode.
     */
    ValidationErrorCode code() const noexcept;

private:
    /// Код ошибки, сохранённый при создании.
    ValidationErrorCode code_;
};

#endif // PASTORAGE_VALIDATION_ERROR_H
