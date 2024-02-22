#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client
{
private:

    void setName(std::string name);
    void setLastname(std::string lastname);
    void setId(int id);
    void setPhoneNumber(long long phonenumber);
    
    std::string name;
    std::string lastname;
    int id;
    long long phonenumber;
}

#endif CLIENT_HPP