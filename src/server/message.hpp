#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <vector>

namespace message {

enum class message_types {LOGIN, REGISTRATION};

struct Message_header {
    message_types id;
    long long size;
};

struct Message {
    Message_header header;
    std::vector<unsigned int> message;
};

}

#endif  // MESSAGE_HPP
