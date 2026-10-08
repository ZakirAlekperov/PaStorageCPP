
/**
 * @file TitleValidator.h
 * @brief Объявление валидатора названий сервисов.
 *
 * @details
 * Содержит независимый от графического интерфейса
 * компонент проверки названий в PaStorage.
 */

#ifndef PASTORAGE_TITLE_VALIDATOR_H
#define PASTORAGE_TITLE_VALIDATOR_H

#include <string_view>

/**
 * @class TitleValidator
 * @brief Проверяет корректность названия сервиса.
 *
 * @details
 * Предоставляет статический метод проверки строки.
 *
 * Класс не хранит состояние и не создаёт объекты
 * для выполнения валидации.
 */
class TitleValidator {
public:
    /**
     * @brief Проверяет название сервиса.
     *
     * @details
     * Допустимое название должно содержать хотя бы
     * один символ, отличный от ASCII-пробельных.
     *
     * Метод не изменяет переданную строку.
     *
     * @param title Проверяемое название сервиса.
     *
     * @throws std::invalid_argument
     *         Если название пустое или состоит
     *         исключительно из ASCII-пробельных символов.
     */
    static void validate(std::string_view title);
};

#endif // PASTORAGE_TITLE_VALIDATOR_H
