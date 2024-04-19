#pragma once
#include "card.hpp"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "WS2_32.lib")
#include <cstring> 
#include <winsock2.h>
using std::cin;
using std::cout;
using std::string;

void initializeSocket(WSADATA& wsaData);

void createSocket(SOCKET& clientSocket);

void connectToServer(sockaddr_in& serverAddr, SOCKET& clientSocket);

void initCreateConnect(WSADATA& wsaData, SOCKET& clientSocket, sockaddr_in& serverAddr);

string promptForInput(void);

void sendToServer(string message, SOCKET& clientSocket);

void closeSocket(SOCKET& clientSocket);
