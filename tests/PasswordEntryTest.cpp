
#include <gtest/gtest.h>
#include "core/PasswordEntry.h"

TEST(PasswordEntryTest, StoresTitle) {
    PasswordEntry entry{"GitHub"};

    EXPECT_EQ(entry.title(), "GitHub");
}
