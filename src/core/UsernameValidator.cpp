
/**
 * @file UsernameValidator.cpp
 * @brief Реализация валидации имён пользователей.
 *
 * @details
 * Выполняет проверку username на допустимость.
 *
 * При обнаружении нарушения выбрасывает
 * типизированное исключение ValidationError.
 */

#include "UsernameValidator.h"
#include "ValidationError.h"

/**
 * @brief Проверяет корректность имени пользователя.
 *
 * @details
 * Пустое имя допускается.
 *
 * Если строка непустая, она должна содержать
 * хотя бы один непробельный ASCII-символ.
 */
void UsernameValidator::validate(std::string_view username) {
    if (username.empty()) {
        return;
    }

    if (username.find_first_not_of(" \t\n\r\f\v")
        == std::string_view::npos) {

        throw ValidationError{
            ValidationErrorCode::WhitespaceUsername,
            "Имя пользователя не может состоять из пробелов."
        };
    }
}
