#ifndef USER_H
#define USER_H
#include <string>
#include <utility>
struct User {
    User(std::string  login) : name(std::move(login)) {
        updateBalane();
    }
    User() {};
    std::string name;
    unsigned long long balance;
    void updateBalane(){
        balance = 100;
    }
};

#endif // USER_H
