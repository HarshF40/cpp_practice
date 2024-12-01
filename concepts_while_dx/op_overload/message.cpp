#include "message.hpp"

#define REGISTER_PAIR(msg) {msg,#msg} //function like macro where msg is the parameter and the things inside the curly braces is the things which will be extended when REGISTER_PAIR will be used... #msg concerts the msg to string value...

Message::Message() : map ({
    REGISTER_PAIR(WM_NULL),
    REGISTER_PAIR(WM_ACTIVATE),
    REGISTER_PAIR(WN_ACCESS_DENIED),
    REGISTER_PAIR(WM_APP)
}) {}

std::string Message::operator()(DWORD key){
    return map[key];
}