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

#include <string>
#include <utility>

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
 * @brief Инициализирует поля записи.
 *
 * @details
 * Перемещает строковые значения из параметров
 * конструктора в поля объекта.
 *
 * Использование std::move позволяет применять
 * перемещающие конструкторы std::string.
 */
PasswordEntry::PasswordEntry(
    std::string title,
    std::string username
)
    : title_{std::move(title)},
      username_{std::move(username)} {
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
 * @brief Заменяет сохранённое имя пользователя.
 *
 * @details
 * Использует перемещающее присваивание std::string,
 * чтобы по возможности избежать лишнего копирования.
 */
void PasswordEntry::setUsername(std::string username){
    username_ = std::move(username);
}
