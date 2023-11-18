#ifndef SESSION_H
#define SESSION_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

class SESSION
{
    int number_of_devices;
    const char *COMMAND = "nmap -sn 192.168.1.0/24";
    const char *FILEPATH = "device_list.txt";
    const int BUFFER_SIZE = 1024;
    DEVICE *devices;

public:
    void
    set_info();

    void add_device(string address);
    void print_devices();
    void scan_devices();
    bool check_history(string address);
    void add_to_history(string address);
    void remove_device(string address);
    bool check_if_added(string address);
    void remove_inactive(vector<string> addresslist);
    void print_history();
    inline int return_number_of_devices()
    {
        return number_of_devices;
    }
};

#endif