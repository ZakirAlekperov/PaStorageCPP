
/**
 * @file UsernameValidator.h
 * @brief Объявление валидатора имён пользователей.
 *
 * @details
 * Компонент проверяет допустимость username.
 *
 * Не зависит от графического интерфейса,
 * операционной системы или способа хранения данных.
 */

#ifndef PASTORAGE_USERNAME_VALIDATOR_H
#define PASTORAGE_USERNAME_VALIDATOR_H

#include <string_view>

/**
 * @class UsernameValidator
 * @brief Проверяет корректность имени пользователя.
 *
 * @details
 * Допускает пустые имена пользователей.
 *
 * Непустое имя должно содержать хотя бы один
 * символ, отличный от ASCII-пробельных.
 *
 * Класс не хранит состояние.
 */
class UsernameValidator {
public:
    /**
     * @brief Проверяет допустимость username.
     *
     * @param username Проверяемое имя пользователя.
     *
     * @throws ValidationError
     *         Если непустое имя состоит исключительно
     *         из ASCII-пробельных символов.
     *
     * @note Метод не изменяет исходную строку.
     */
    static void validate(std::string_view username);
};

#endif // PASTORAGE_USERNAME_VALIDATOR_H
