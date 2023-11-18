#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
using namespace std;

class DEVICE
{
    string address;
    string name;

public:
    inline void setAddress(string address)
    {
        this->address = address;
    }

    inline string returnAddress()
    {
        return this->address;
    }
};

#endif