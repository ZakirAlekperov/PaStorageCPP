
/**
 * @file ValidationError.cpp
 * @brief Реализация типизированных исключений валидации.
 *
 * @details
 * Реализует конструктор ValidationError и метод
 * получения программного кода ошибки.
 *
 * Диагностическое сообщение передаётся базовому
 * классу std::invalid_argument.
 */

#include "ValidationError.h"

/**
 * @brief Создаёт исключение валидации.
 *
 * @param code Код ошибки валидации.
 * @param message Диагностическое сообщение.
 */
ValidationError::ValidationError(
    ValidationErrorCode code,
    const std::string& message
)
    : std::invalid_argument{message},
      code_{code} {
}

/**
 * @brief Возвращает программный код ошибки.
 *
 * @return Код ошибки, сохранённый при создании.
 */
ValidationErrorCode ValidationError::code() const noexcept {
    return code_;
}
