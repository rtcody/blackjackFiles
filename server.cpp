#include "Server.h"

void initializeWSA(WSADATA& wsaData)
{
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed." << std::endl;
    }
}

void createSocket(SOCKET& serverSocket)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error: Couldn't create socket" << std::endl;
        WSACleanup();
    }
}

void bindIPAddr(sockaddr_in& serverAddr, SOCKET& serverSocket)
{
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on any interface 
    serverAddr.sin_port = htons(8080); // Listen on port 8080 
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't bind socket" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
    }
}

void listen(SOCKET& serverSocket)
{
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't listen on socket" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
    }

    std::cout << "Server listening on port 8080..." << std::endl;
}

SOCKET acceptCommunications(SOCKET& serverSocket)
{
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error: Couldn't accept incoming connection" << std::endl;
        closesocket(serverSocket);
        WSACleanup();
    }

    std::cout << "Client connected\n";

    return clientSocket;
}

string recieveData(SOCKET& serverSocket, SOCKET& clientSocket)
{
    char buffer[1024];
    string message;
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived == 0) {
        // Client has closed the connection
        std::cout << "Client disconnected" << std::endl;
    }
    else if (bytesReceived == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't receive data from client\n";
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
    }
    else {
        buffer[bytesReceived] = '\0'; // Null-terminate the received data
        message = buffer;
    }

    return message;
}


void closeSocket(SOCKET& serverSocket, SOCKET& clientSocket)
{
    closesocket(clientSocket);

    // Close server socket
    closesocket(serverSocket);
    WSACleanup();
}

void writeToFile(std::ofstream& file, string message)
{
    file << message;
}
