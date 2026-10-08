/**
 * @file PasswordEntry.cpp
 * @brief Реализация класса PasswordEntry.
 *
 * @details
 * Определяет конструкторы и методы управления
 * данными учётной записи.
 *
 * Для передачи строк во внутренние поля используется
 * семантика перемещения C++.
 *
 * Реализация не зависит от платформенных API.
 */

#include "PasswordEntry.h"
#include "TitleValidator.h"
#include "UsernameValidator.h"

#include <exception>
#include <string>
#include <utility>
#include <stdexcept>

/**
 * @brief Создаёт запись без имени пользователя.
 *
 * @details
 * Делегирует инициализацию основному конструктору,
 * передавая пустую строку в качестве username.
 */
PasswordEntry::PasswordEntry(std::string title)
    : PasswordEntry{std::move(title), ""} {
}



/**
 * @brief Создаёт запись сервиса.
 *
 * @details
 * Инициализирует поля title и username.
 *
 * Перед завершением создания объекта вызывает
 * независимые валидаторы для проверки обоих значений.
 *
 * @param title Название сервиса.
 * @param username Имя пользователя.
 *
 * @throws ValidationError
 *         Если название или имя пользователя
 *         не соответствуют правилам валидации.
 */
PasswordEntry::PasswordEntry(
    std::string title,
    std::string username
)
    : title_{std::move(title)},
      username_{std::move(username)} {

    TitleValidator::validate(title_);
    UsernameValidator::validate(username_);
}



/**
 * @brief Предоставляет копию названия сервиса.
 */
std::string PasswordEntry::title() const {
    return title_;
}

/**
 * @brief Предоставляет копию имени пользователя.
 */
std::string PasswordEntry::username() const{
    return username_;
}


/**
 * @brief Изменяет имя пользователя.
 *
 * @details
 * Сначала проверяет новое значение через
 * UsernameValidator.
 *
 * Только после успешной проверки заменяет
 * сохранённое имя пользователя.
 *
 * Если проверка завершается исключением,
 * прежнее значение username сохраняется.
 *
 * @param username Новое имя пользователя.
 *
 * @throws ValidationError
 *         Если новое значение состоит
 *         исключительно из ASCII-пробельных символов.
 */
void PasswordEntry::setUsername(std::string username) {
    UsernameValidator::validate(username);

    username_ = std::move(username);
}
