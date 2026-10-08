
#include "PasswordEntry.h"

#include <utility>


PasswordEntry::PasswordEntry(std::string title)
    : PasswordEntry{std::move(title), ""} {
}

PasswordEntry::PasswordEntry(
    std::string title,
    std::string username
)
    : title_{std::move(title)},
      username_{std::move(username)} {
}

std::string PasswordEntry::title() const {
    return title_;
}

std::string PasswordEntry::username() const{
    return username_;
}
