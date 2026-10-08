
/**
 * @file ValidationError.h
 * @brief Объявление типизированных ошибок валидации.
 *
 * @details
 * Предоставляет перечисление кодов ошибок и
 * собственный класс исключения PaStorage.
 *
 * Позволяет различать ошибки без анализа
 * диагностического текста.
 */

#ifndef PASTORAGE_VALIDATION_ERROR_H
#define PASTORAGE_VALIDATION_ERROR_H

#include <stdexcept>
#include <string>

/**
 * @enum ValidationErrorCode
 * @brief Коды ошибок проверки входных данных.
 *
 * @details
 * Каждый элемент перечисления обозначает
 * определённую причину отказа валидации.
 */
enum class ValidationErrorCode {
    EmptyTitle,       ///< Название сервиса пустое.
    WhitespaceTitle   ///< Название состоит из пробелов.
};

/**
 * @class ValidationError
 * @brief Исключение, возникающее при ошибке валидации.
 *
 * @details
 * Наследуется от std::invalid_argument.
 *
 * Содержит программный код ошибки и текстовое
 * описание, доступное через what().
 */
class ValidationError : public std::invalid_argument {
public:
    /**
     * @brief Создаёт исключение валидации.
     *
     * @param code Программный код ошибки.
     * @param message Диагностическое сообщение.
     */
    ValidationError(
        ValidationErrorCode code,
        const std::string& message
    );

    /**
     * @brief Возвращает программный код ошибки.
     *
     * @return Код, переданный конструктору.
     */
    ValidationErrorCode code() const noexcept;

private:
    /// Программный код ошибки.
    ValidationErrorCode code_;
};

#endif // PASTORAGE_VALIDATION_ERROR_H
