
/**
 * @file ValidationError.cpp
 * @brief Реализация типизированных исключений.
 *
 * @details
 * Обеспечивает хранение кода ошибки и передачу
 * диагностического сообщения базовому классу.
 */

#include "ValidationError.h"

/**
 * @brief Инициализирует исключение валидации.
 *
 * @details
 * Передаёт текст ошибки конструктору
 * std::invalid_argument и сохраняет код ошибки.
 */
ValidationError::ValidationError(
    ValidationErrorCode code,
    const std::string& message
)
    : std::invalid_argument{message},
      code_{code} {
}

/**
 * @brief Возвращает код ошибки.
 *
 * @return Сохранённое значение ValidationErrorCode.
 */
ValidationErrorCode ValidationError::code() const noexcept {
    return code_;
}
