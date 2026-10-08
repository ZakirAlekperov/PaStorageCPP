
/**
 * @file VaultHeader.h
 * @brief Объявление фиксированного заголовка хранилища.
 *
 * @details
 * Определяет начальные 16 байт бинарного файла PaStorage.
 *
 * Заголовок позволяет распознать формат файла
 * и проверить совместимость его версии.
 *
 * Класс не реализует шифрование и не работает с диском.
 */

#ifndef PASTORAGE_VAULT_HEADER_H
#define PASTORAGE_VAULT_HEADER_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <span>

/**
 * @class VaultHeader
 * @brief Представляет фиксированный заголовок файла .vault.
 *
 * @details
 * Предоставляет сериализацию и десериализацию
 * заголовка первой версии формата PaStorage.
 *
 * Бинарный размер фиксирован и составляет 16 байт.
 */
class VaultHeader {
public:
    /// Размер заголовка в байтах.
    static constexpr std::size_t SIZE{16};

    /// Поддерживаемая версия формата.
    static constexpr std::uint16_t VERSION{1};

    /**
     * @brief Сериализует заголовок.
     *
     * @return Массив из 16 байт в формате PaStorage.
     */
    std::array<std::uint8_t, SIZE> serialize() const;

    /**
     * @brief Восстанавливает заголовок из байтов.
     *
     * @param bytes Последовательность байтов заголовка.
     *
     * @return Проверенный объект VaultHeader.
     *
     * @throws std::invalid_argument
     *         Если размер, сигнатура, версия,
     *         флаги или значение размера некорректны.
     */
    static VaultHeader deserialize(
        std::span<const std::uint8_t> bytes
    );
};

#endif // PASTORAGE_VAULT_HEADER_H
