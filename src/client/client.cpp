#include "client.h"

namespace client {

Client::Client() : m_socket(m_context) {
    m_context_thread = std::thread([this] { m_context.run(); });
}
Client::~Client() {
    disconnect();
}

void Client::disconnect() {
    m_context.stop();
    m_socket.close();
    if (m_context_thread.joinable()) {
        m_context_thread.join();
    }
}

void Client::login_console() {
    std::cout << "Enter your name:\n";
    auto log = receive_name(*this);
    std::cout << "Enter password:\n";
    std::string n;
    std::cin >> n;
    if (!data::DataBase_connector::log_in_client(log, n)) {
        login_console();
    }
    callback_name(log);
}

void Client::registration_console() {
    std::cout << "Enter your name:\n";
    std::string const login = receive_name(*this);
    std::string pass;
    std::string pass_repeated;
    bool completed = false;
    while (!completed) {
        std::cout << "Create password:\n";
        std::cin >> pass;
        std::cout << "Repeate your password:\n";
        std::cin >> pass_repeated;
        if (pass == pass_repeated) {
            completed = true;
        }
    }
    data::DataBase_connector::insert_new_client(login, pass);
    std::cout << "You successfully registered!\n";
}

void Client::callback_name(const std::string &name) {
    nickname = name;
}

std::string Client::receive_name(Client &pl) {
    std::string name;
    std::cin >> name;
    pl.callback_name(name);
    return name;
}

// above here only testing methods (for console)
int Client::get_balance() const {
    return balance;
}

std::string Client::name() const {
    return nickname;
}

std::string Client::move(int balance_a) const {
    std::cout << "Player " << nickname << " make your turn\n";
    std::cout << "Your balance is: " << balance_a << "\n";
    std::string move;
    std::cin >> move;
    return move;
}

std::string Client::optional_move() const {
    std::cout << "Player " << nickname
              << " you may want to look over your cards\n";
    std::string move;
    std::cin >> move;
    return move;
}

void Client::login_with_graphic(
    std::string &nickname_received,
    std::string &password
) {
    // we get hash + salt from server
    // then check
    m_socket.async_send()
}

void Client::registration_with_graphic(
    std::string &nickname_received,
    std::string &password
) {
}

void Client::client_try_to_connect() {
    try {
        boost::asio::connect(
            m_socket, boost::asio::ip::tcp::resolver(m_context).resolve(
                          "127.0.0.1", "291203"
                      )
        );  // here will be server ip
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
        client_try_to_connect();
    }
}
}  // namespace client