#pragma once

#include<string>
#include<unordered_map>
#include<windows.h>

class Message {
    public:
        Message();
        std::string operator ()(DWORD key);
    private:
        std::unordered_map<DWORD,std::string> map;
};