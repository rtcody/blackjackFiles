#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS   
#pragma comment(lib, "WS2_32.lib")
#include <iostream>
#include <fstream>
#include <cstring>
#include <winsock2.h>
#include <thread> // Include for threading support 

using std::string;

void initializeWSA(WSADATA& wsaData);
void createSocket(SOCKET& serverSocket);
void bindIPAddr(sockaddr_in& serverAddr, SOCKET& serverSocket);
void listen(SOCKET& serverSocket);
SOCKET acceptCommunications(SOCKET& serverSocket);
string recieveData(SOCKET& serverSocket, SOCKET& clientSocket); 
void closeSocket(SOCKET& serverSocket, SOCKET& clientSocket);

void writeToFile(std::ofstream& file, string message);

