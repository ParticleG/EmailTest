#include <iostream>
#include <mailio/message.hpp>
#include <mailio/pop3.hpp>
#include <string>

using namespace mailio;
using namespace std;

int main() {
    try {
        message msg;
        msg.line_policy(codec::line_len_policy_t::RECOMMENDED, codec::line_len_policy_t::MANDATORY);
        pop3s conn("outlook.office365.com", 995);
        conn.authenticate("test@26f-studio.org", "Passwd123#", pop3s::auth_method_t::LOGIN);
        conn.fetch(1, msg);

        cout << msg.subject() << endl;
        cout << msg.content() << endl;
    } catch (const exception &e) {
        cout << e.what();
    }
}
