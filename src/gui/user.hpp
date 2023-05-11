#ifndef USER_H
#define USER_H
#include <string>
#include <utility>
struct User {
private:
    std::string name;
    unsigned long long balance;
public:
    User(std::string  login) : name(std::move(login)) {
        updateBalane();
    }
    User() {};

    [[nodiscard]] const std::string& get_name() const {
        return name;
    }
    [[nodiscard]] uint64_t get_balance() const {
        return balance;
    }
    void updateBalane() {
        balance = 100;
    }
};

#endif // USER_H
