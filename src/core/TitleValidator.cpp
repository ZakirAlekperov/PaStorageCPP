
/**
 * @file TitleValidator.cpp
 * @brief Реализация валидации названий сервисов.
 *
 * @details
 * Выполняет проверку допустимости названия.
 *
 * При обнаружении ошибки выбрасывает
 * типизированное исключение ValidationError.
 */

#include "TitleValidator.h"
#include "ValidationError.h"

/**
 * @brief Проверяет корректность названия сервиса.
 *
 * @details
 * Сначала проверяет полностью пустую строку.
 * Затем проверяет строку на наличие символов,
 * отличных от ASCII-пробельных.
 *
 * @throws ValidationError
 *         Если название пустое или состоит
 *         исключительно из ASCII-пробельных символов.
 *
 * @see ValidationErrorCode
 */
void TitleValidator::validate(std::string_view title) {
    if (title.empty()) {
        throw ValidationError{
            ValidationErrorCode::EmptyTitle,
            "Название сервиса не может быть пустым."
        };
    }

    if (title.find_first_not_of(" \t\n\r\f\v")
        == std::string_view::npos) {
        throw ValidationError{
            ValidationErrorCode::WhitespaceTitle,
            "Название сервиса не может состоять из пробелов."
        };
    }
}
