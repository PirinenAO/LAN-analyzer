# LAN monitoring program

C++ program to keep track of devices connected to your local area network.
Program creates a shell process performing nmap ping scan from address range 192.168.1.0/24.
After the scan it will parse the addresses, and print them out. It also maintains a devices.txt file where all the seen addresses are stored.
The program will notify you if a new address is found, providing a great way to keep track of potential intruders in your LAN.

You can also give "quick" as a command-line argument, to get a quick scan and overview.

**Unauthorized scanning of networks that you do not own or have explicit permission to scan is generally considered unethical and may be illegal.
So do not use this program in networks you don't own.**
