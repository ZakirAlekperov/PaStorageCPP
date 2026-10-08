
#include "core/PasswordEntry.h"

#include <utility>

PasswordEntry::PasswordEntry(std::string title)
    : title_{std::move(title)} {
}

std::string PasswordEntry::title() const {
    return title_;
}
