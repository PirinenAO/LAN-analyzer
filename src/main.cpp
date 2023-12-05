#include "../include/device.h"
#include "../include/session.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

void quickRun();

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "quick") == 0)
    {
        quickRun();
    }

    SESSION *session;
    session = new SESSION;

    session->set_info();

    char c;
    session->scan_devices();

    cout << "   __   ___   _  __  ___             __                " << endl;
    cout << "  / /  / _ | / |/ / / _ | ___  ___ _/ /_ _____ ___ ____" << endl;
    cout << " / /__/ __ |/    / / __ |/ _ \\/ _ `/ / // /_ // -_) __/" << endl;
    cout << "/____/_/ |_/_/|_/ /_/ |_/_//_/\\_,_/_/\\_, //__/.\\__/_/   " << endl;
    cout << "                                    /___/              " << endl;

    while (true)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "Currently " << session->return_number_of_devices() << " devices connected" << endl;
        cout << "C to display current devices in this LAN" << endl;
        cout << "H to display past devices in this LAN" << endl;
        cout << "Q to quit" << endl;
        cout << "--------------------------------------------------------" << endl;

        c = getchar();
        c = toupper(c);

        if (c == 'C')
        {
            session->scan_devices();
            cout << endl
                 << "List of devices connected to this LAN:" << endl;
            session->print_devices();
        }
        else if (c == 'H')
        {
            cout << endl
                 << "List of past devices in this LAN" << endl;
            session->print_history();
        }
        else if (c == 'Q')
        {
            delete[] session;
            break;
        }

        cin.ignore();
    }

    return 0;
}

void quickRun()
{
    SESSION *session;
    session = new SESSION;
    session->set_info();
    cout << "   __   ___   _  __  ___             __                " << endl;
    cout << "  / /  / _ | / |/ / / _ | ___  ___ _/ /_ _____ ___ ____" << endl;
    cout << " / /__/ __ |/    / / __ |/ _ \\/ _ `/ / // /_ // -_) __/" << endl;
    cout << "/____/_/ |_/_/|_/ /_/ |_/_//_/\\_,_/_/\\_, //__/.\\__/_/   " << endl;
    cout << "                                    /___/              " << endl;
    session->scan_devices();
    cout << endl;
    cout << "Currently " << session->return_number_of_devices() << " devices connected" << endl;
    session->print_devices();
    delete[] session;
    exit(0);
}
