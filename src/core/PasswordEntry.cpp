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
 * @brief Создаёт запись с названием и логином.
 *
 * @details
 * Инициализирует поля объекта посредством
 * перемещения переданных строк.
 *
 * Проверка названия делегируется TitleValidator.
 * При некорректном названии конструктор выбрасывает
 * исключение и объект не создаётся.
 *
 * @param title Название сервиса.
 * @param username Имя пользователя.
 *
 * @throws std::invalid_argument
 *         Если название сервиса некорректно.
 */
PasswordEntry::PasswordEntry(
    std::string title,
    std::string username
)
    : title_{std::move(title)},
      username_{std::move(username)} {

    TitleValidator::validate(title_);
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
