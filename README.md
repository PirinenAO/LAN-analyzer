# LAN monitoring program


C++ program to keep track of devices connected to your local area network.
Program creates a shell process performing nmap ping scan from address range 192.168.1.0/24.
After the scan it will parse the addresses, and print them out. It also maintains a devices.txt file where all the seen addresses are stored.
The program will notify you if a new address is found, providing a great way to keep track of potential intruders in your LAN.

<br>

![image](https://github.com/PirinenAO/LAN-analyzer/assets/119351375/c648b9cd-f53a-4df6-a80f-5fd4636a796e)
<br>

## You can also give "quick" as a command-line argument, to get a quick overview of the devices:

<br>

![image](https://github.com/PirinenAO/LAN-analyzer/assets/119351375/d57706d8-d3fd-47c4-9a20-c914d90f2e4f)

<br>

## Unauthorized scanning of networks that you do not own or have explicit permission to scan is generally considered unethical and may be illegal.
## So do not use this program in networks you don't own.
