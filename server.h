#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS     
#pragma comment(lib, "WS2_32.lib")
#include <iostream>
#include <cstring>
#include <winsock2.h>
#include <thread> // Include for threading support

using std::cin; 
using std::cout; 
using std::string; 
using std::cerr;  

void initializeSocket(WSADATA& wsaData);

void createSocket(SOCKET& serverSocket);

void bindSocket(sockaddr_in& serverAddr, SOCKET& serverSocket);

void listen(SOCKET& serverSocket); 

SOCKET acceptConnection(SOCKET& serverSocket);

void recieveData(SOCKET& clientSocket, SOCKET& serverSocket); 

void closeServer(SOCKET& serverSocket); 
