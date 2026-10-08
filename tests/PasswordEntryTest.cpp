
#include <gtest/gtest.h>
#include "core/PasswordEntry.h"

TEST(PasswordEntryTest, StoresTitle) {
    PasswordEntry entry{"GitHub"};

    EXPECT_EQ(entry.title(), "GitHub");
}

TEST(PasswordEntryTest, StoresUsername) {
    PasswordEntry entry{"GitHub", "test@example.com"};

    EXPECT_EQ(entry.username(), "test@example.com");
}
