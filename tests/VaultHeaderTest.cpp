
/**
 * @file VaultHeaderTest.cpp
 * @brief Модульные тесты заголовка хранилища PaStorage.
 *
 * @details
 * Проверяет бинарное представление заголовка,
 * корректность сериализации и обработку
 * неподдерживаемых или повреждённых данных.
 *
 * Тесты не выполняют криптографических операций.
 */

#include <gtest/gtest.h>

#include <array>
#include <cstdint>
#include <stdexcept>

#include "core/VaultHeader.h"

/**
 * @test VaultHeaderTest.SerializesVersionOneHeader
 * @brief Проверяет сериализацию заголовка первой версии.
 *
 * @details
 * Создаёт стандартный заголовок и сравнивает
 * его с ожидаемой последовательностью из 16 байт.
 *
 * Это закрепляет бинарный формат независимо
 * от платформы и порядка байтов процессора.
 */
TEST(VaultHeaderTest, SerializesVersionOneHeader) {
    VaultHeader header;

    const std::array<std::uint8_t, 16> expected{
        'P', 'A', 'S', 'T', 'O', 'R', '0', '1',
        1, 0,
        0, 0,
        16, 0, 0, 0
    };

    EXPECT_EQ(header.serialize(), expected);
}

/**
 * @test VaultHeaderTest.DeserializesValidHeader
 * @brief Проверяет чтение корректного заголовка.
 *
 * @details
 * Создаёт заголовок, сериализует его,
 * затем восстанавливает из полученных байтов.
 *
 * Ожидается сохранение бинарного представления.
 */
TEST(VaultHeaderTest, DeserializesValidHeader) {
    VaultHeader original;

    auto bytes = original.serialize();
    VaultHeader restored = VaultHeader::deserialize(bytes);

    EXPECT_EQ(restored.serialize(), bytes);
}


/**
 * @test VaultHeaderTest.RejectsInvalidMagic
 * @brief Проверяет отклонение неверной сигнатуры.
 *
 * @details
 * Изменяет первый байт сигнатуры файла.
 * Ожидается отказ десериализации.
 */
TEST(VaultHeaderTest, RejectsInvalidMagic) {
    VaultHeader header;
    auto bytes = header.serialize();

    bytes[0] = 'X';

    EXPECT_THROW(
        VaultHeader::deserialize(bytes),
        std::invalid_argument
    );
}

/**
 * @test VaultHeaderTest.RejectsUnsupportedVersion
 * @brief Проверяет отклонение неизвестной версии.
 *
 * @details
 * Изменяет младший байт поля версии с 1 на 2.
 * Файл с неподдерживаемой версией не должен
 * восприниматься как корректный.
 */
TEST(VaultHeaderTest, RejectsUnsupportedVersion) {
    VaultHeader header;
    auto bytes = header.serialize();

    bytes[8] = 2;

    EXPECT_THROW(
        VaultHeader::deserialize(bytes),
        std::invalid_argument
    );
}

/**
 * @test VaultHeaderTest.RejectsTruncatedHeader
 * @brief Проверяет отклонение неполного заголовка.
 *
 * @details
 * Передаёт только первые 8 байт вместо 16.
 * Парсер должен отклонить недостаточный размер.
 */
TEST(VaultHeaderTest, RejectsTruncatedHeader) {
    const std::array<std::uint8_t, 8> bytes{
        'P', 'A', 'S', 'T', 'O', 'R', '0', '1'
    };

    EXPECT_THROW(
        VaultHeader::deserialize(bytes),
        std::invalid_argument
    );
}

/**
 * @test VaultHeaderTest.RejectsUnknownFlags
 * @brief Проверяет отклонение неизвестных флагов.
 *
 * @details
 * Устанавливает один из зарезервированных битов.
 * В первой версии допустимо только нулевое
 * значение поля flags.
 */
TEST(VaultHeaderTest, RejectsUnknownFlags) {
    VaultHeader header;
    auto bytes = header.serialize();

    bytes[10] = 1;

    EXPECT_THROW(
        VaultHeader::deserialize(bytes),
        std::invalid_argument
    );
}
