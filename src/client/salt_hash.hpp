#pragma once

#include <string>

struct salt_hash {
private:
    static std::string sha_hash(const std::string &phrase);
    static std::string generate_salt(int length);

    friend struct client;
};

