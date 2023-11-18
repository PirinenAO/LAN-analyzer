#include "../include/device.h"
#include "../include/session.h"

void SESSION::set_info()
{
    this->devices = new DEVICE;
}

void SESSION::add_device(string address)
{
    this->number_of_devices++;

    DEVICE *temp;

    try
    {
        temp = new DEVICE[number_of_devices];
    }
    catch (bad_alloc &xa)
    {
        cout << "memory allocation failed for room" << endl;
        return;
    }

    temp[0].setAddress(address);

    for (int i = 1; i < number_of_devices; i++)
    {
        temp[i] = this->devices[i - 1];
    }

    devices = temp;
}

void SESSION::remove_device(string address)
{
    int indexToRemove = -1;
    for (int i = 0; i < number_of_devices; i++)
    {
        if (devices[i].returnAddress() == address)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1)
    {
        // Call the destructor for the specific device
        devices[indexToRemove].~DEVICE();

        // Decrement the number of devices
        number_of_devices--;

        // Create a temporary array to hold the remaining devices
        DEVICE *temp = new DEVICE[number_of_devices];

        // Copy devices before the removed index
        for (int i = 0; i < indexToRemove; i++)
        {
            temp[i] = devices[i];
        }

        // Copy devices after the removed index
        for (int i = indexToRemove; i < number_of_devices; i++)
        {
            temp[i] = devices[i + 1];
        }

        // Update the devices array
        delete[] devices;
        devices = temp;
    }
    else
    {
        cout << "Device with address " << address << " not found." << endl;
    }
}

void SESSION::print_devices()
{
    cout << endl;
    for (int i = 0; i < number_of_devices; i++)
    {
        if (check_if_added(devices[i].returnAddress()))
        {
            cout << devices[i].returnAddress() << endl;
        }
    }
    cout << endl;
}

void SESSION::scan_devices()
{
    vector<string> addresslist;

    FILE *pipe = popen(COMMAND, "r");
    if (!pipe)
    {
        perror("Error opening pipe");
        exit(EXIT_FAILURE);
    }

    // Read the output from the command
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        // Check if the line contains an IP address
        char *ipAddressStart = strstr(buffer, "Nmap scan report for ");

        if (ipAddressStart != nullptr)
        {
            // Extract and print the IP address
            ipAddressStart += strlen("Nmap scan report for ");
            string ipAddress(ipAddressStart);
            ipAddress.erase(ipAddress.length() - 1);

            addresslist.push_back(ipAddress);

            if (!this->check_if_added(ipAddress))
            {
                this->add_device(ipAddress);
            }

            if (!check_history(ipAddress))
            {
                cout << endl
                     << "NEW ADDRESS FOUND: " << ipAddress << endl;

                add_to_history(ipAddress);
            }
        }
    }

    remove_inactive(addresslist);

    // Close the pipe
    if (pclose(pipe) == -1)
    {
        perror("Error closing pipe");
        exit(EXIT_FAILURE);
    }
}

bool SESSION::check_history(string ipAddress)
{
    fstream file(FILEPATH);
    string line;

    // cout << "Searching for " << ipAddress << endl;
    while (getline(file, line))
    {
        int found = line.compare(ipAddress);

        if (found == 0)
        {
            return true;
        }
    }

    return false;
}

void SESSION::add_to_history(string ipAddress)
{
    ofstream outputFile;
    outputFile.open(FILEPATH, ios::app); // Use "app" mode for append

    if (outputFile.is_open())
    {
        outputFile << ipAddress << endl; // Append the IP address and add a newline
    }
    else
    {
        cerr << "Error opening text file" << endl;
    }
}

bool SESSION::check_if_added(string Address)
{
    for (int i = 0; i < number_of_devices; i++)
    {
        if (devices[i].returnAddress() == Address)
        {
            return true;
        }
    }

    return false;
}

void SESSION::remove_inactive(vector<string> addresslist)
{

    for (int i = 0; i < number_of_devices; i++)
    {
        bool found = false;

        for (int j = 0; j < addresslist.size(); j++)
        {
            if (devices[i].returnAddress() == addresslist[j])
            {
                found = true;
            }
        }

        if (!found)
        {
            remove_device(devices[i].returnAddress());
        }
    }
}

void SESSION::print_history()
{
    fstream file(FILEPATH);
    string line;
    cout << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    cout << endl;
}