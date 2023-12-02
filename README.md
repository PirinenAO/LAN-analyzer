## LAN-Analyzer

Simple c++ program to keep track of devices connected to your local area network.
Program creates a pipe between terminal, and the program. Then it performs nmap ping scan from address range 192.168.1.0/24.
After the scan it will parse the addresses, and print them out. Its also maintaining a devices.txt file where all the seen addresses are stored.
Program will notify you if new address is found. Which is a great way to keep track if there are intruders in your LAN.

You can also give "quick" as a command-line argument, to get a quick overview about the addresses.

