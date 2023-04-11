#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <vector>

namespace message {

template<typename T>
struct Message_header {
    T id;
    long long size;
};

template<typename T>
struct Message {
    Message_header<T> header;
    std::vector<unsigned int> message;
};

}

#endif  // MESSAGE_HPP
