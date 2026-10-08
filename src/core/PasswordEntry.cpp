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
 * @brief Создаёт запись с названием и именем пользователя.
 *
 * @details
 * Инициализирует внутренние поля переданными
 * значениями с использованием семантики перемещения.
 *
 * После инициализации проверяет название сервиса.
 * Если оно пустое, создание объекта прерывается
 * исключением std::invalid_argument.
 *
 * @param title Название сервиса.
 * @param username Имя пользователя.
 *
 * @pre Название сервиса должно содержать хотя бы
 *      один символ, отличный от ASCII-пробельных.
 *
 * @throws std::invalid_argument
 *         Если название сервиса пустое.
 *         Если название состоит из пробелов.
 */
PasswordEntry::PasswordEntry(
    std::string title,
    std::string username
)
    : title_{std::move(title)},
      username_{std::move(username)} {
          if (title_.empty()) {
              throw std::invalid_argument{
                  "Название сервиса не может быть пустым."
              };
          }

          if (title_.find_first_not_of(" \t\n\r\f\v") == std::string::npos){
              throw std::invalid_argument{
                  "Название сервиса не может состоять из пробелов."
              };
          }
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
