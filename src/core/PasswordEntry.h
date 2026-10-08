
#ifndef PASTORAGE_PASSWORD_ENTRY_H
#define PASTORAGE_PASSWORD_ENTRY_H

#include <string>

class PasswordEntry {
public:
    explicit PasswordEntry(std::string title);

    std::string title() const;

    private:
        std::string title_;

};


#endif // PASTORAGE_PASSWORD_ENTRY_H
