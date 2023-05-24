#ifndef USER_H
#define USER_H
#include <string>
#include <utility>
class User {
    std::string name;
    unsigned long long balance = 0;
public:
    User() = default;

    [[nodiscard]] const std::string& get_name() const {
        return name;
    }

    [[nodiscard]] uint64_t get_balance() const {
        return balance;
    }

    void setData(const std::string& name_, unsigned long long balance_) {
        name = name_;
        balance = balance_;
    }
};

#endif // USER_H
