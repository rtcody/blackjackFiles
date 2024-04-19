#include "Server.h"

// Initialize Winsock
void initializeSocket(WSADATA& wsaData)
{
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
    }
}

// Create socket
void createSocket(SOCKET& serverSocket)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error: Couldn't create socket\n";
        WSACleanup();
    }
}

// Bind socket to IP and port
void bindSocket(sockaddr_in& serverAddr, SOCKET& serverSocket)
{
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on any interface
    serverAddr.sin_port = htons(8080); // Listen on port 8080
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't bind socket\n";
        closesocket(serverSocket);
        WSACleanup();
    }
}

// Listen for incoming connections
void listen(SOCKET& serverSocket)
{
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't listen on socket\n";
        closesocket(serverSocket);
        WSACleanup();
    }

    std::cout << "Server listening on port 8080...\n";  
}

// Accept incoming connection
SOCKET acceptConnection(SOCKET& serverSocket) 
{
    SOCKET clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error: Couldn't accept incoming connection\n";
        closesocket(serverSocket);
        WSACleanup();
    }
    
    std::cout << "Client connected\n"; 

    return clientSocket;   
} 

// Receive data from client until the client stops sending
void recieveData(SOCKET& clientSocket, SOCKET& serverSocket)
{
    char buffer[1024];
    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesReceived == 0) {
        // Client has closed the connection
        std::cout << "Client disconnected\n";
    }
    else if (bytesReceived == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't receive data from client\n";
        closesocket(clientSocket);
        closesocket(serverSocket); 
        WSACleanup();

    }
    else {
        // Process received data (in this example, just print it)
        buffer[bytesReceived] = '\0'; // Null-terminate the received data 
        std::cout << "Received data from client: " << buffer << std::endl;
    }


    // Close client socket
    closesocket(clientSocket);
}

void closeServer(SOCKET& serverSocket)
{
    // Close server socket
    closesocket(serverSocket);
    WSACleanup();
}
