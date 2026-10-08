
/**
 * @file VaultHeader.cpp
 * @brief Бинарная сериализация заголовка PaStorage.
 *
 * @details
 * Реализует фиксированный 16-байтовый формат.
 *
 * Все многобайтовые числовые поля записываются
 * в порядке little-endian.
 *
 * При чтении недопустимые значения отклоняются.
 */

#include "core/VaultHeader.h"

#include <stdexcept>

/**
 * @brief Преобразует заголовок в бинарное представление.
 *
 * @details
 * Возвращает сигнатуру, версию, нулевые флаги
 * и размер фиксированного заголовка.
 */
std::array<std::uint8_t, VaultHeader::SIZE>
VaultHeader::serialize() const {
    return {
        'P', 'A', 'S', 'T', 'O', 'R', '0', '1',
        1, 0,
        0, 0,
        16, 0, 0, 0
    };
}

/**
 * @brief Проверяет и восстанавливает заголовок.
 *
 * @details
 * Сравнивает входную последовательность с
 * фиксированным представлением первой версии.
 *
 * Такое сравнение проверяет одновременно размер,
 * сигнатуру, версию, флаги и размер заголовка.
 *
 * @throws std::invalid_argument
 *         Если последовательность не соответствует
 *         поддерживаемому формату.
 */
VaultHeader VaultHeader::deserialize(
    std::span<const std::uint8_t> bytes
) {
    VaultHeader header;

    const auto expected = header.serialize();

    if (bytes.size() != expected.size()) {
        throw std::invalid_argument{
            "Некорректный размер заголовка хранилища."
        };
    }

    for (std::size_t i{0}; i < expected.size(); ++i) {
        if (bytes[i] != expected[i]) {
            throw std::invalid_argument{
                "Некорректный или неподдерживаемый заголовок."
            };
        }
    }

    return header;
}
