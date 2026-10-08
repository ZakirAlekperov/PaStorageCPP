
/**
 * @file TitleValidator.cpp
 * @brief Реализация проверки названий сервисов.
 *
 * @details
 * Проверяет пустые строки и строки, состоящие
 * исключительно из ASCII-пробельных символов.
 *
 * Для различных ошибок предусмотрены
 * отдельные диагностические сообщения.
 */

#include "TitleValidator.h"

#include <stdexcept>

/**
 * @brief Проверяет название сервиса.
 *
 * @details
 * Сначала проверяет отсутствие символов.
 * Затем проверяет наличие хотя бы одного символа,
 * не входящего в набор ASCII whitespace.
 *
 * @throws std::invalid_argument
 *         При нарушении правил валидации.
 */
void TitleValidator::validate(std::string_view title) {
    if (title.empty()) {
        throw std::invalid_argument{
            "Название сервиса не может быть пустым."
        };
    }

    if (title.find_first_not_of(" \t\n\r\f\v")
        == std::string_view::npos) {
        throw std::invalid_argument{
            "Название сервиса не может состоять из пробелов."
        };
    }
}
