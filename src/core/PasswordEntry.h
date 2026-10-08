
#ifndef PASTORAGE_PASSWORD_ENTRY_H
#define PASTORAGE_PASSWORD_ENTRY_H

#include <string>

class PasswordEntry {
public:
    explicit PasswordEntry(std::string title);

    PasswordEntry(std::string title, std::string username);

    std::string title() const;
    std::string username() const;

    private:
        std::string title_;
        std::string username_;
};

#endif // PASTORAGE_PASSWORD_ENTRY_H
