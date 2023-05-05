#ifndef USER_H
#define USER_H
#include <string>
struct User {
    User(std::string login) : name(login) {
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
