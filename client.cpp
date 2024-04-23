#include "Client.h" 

void initializeSocket(WSADATA& wsaData)
{
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
    }
}

void createSocket(SOCKET& clientSocket)
{
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error: Couldn't create socket\n";
        WSACleanup();
    }
}

void connectToServer(sockaddr_in& serverAddr, SOCKET& clientSocket)
{
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address
    serverAddr.sin_port = htons(8080); // Server port
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't connect to server\n";
        closesocket(clientSocket);
        WSACleanup();
    }
}

void initCreateConnect(WSADATA& wsaData, SOCKET& clientSocket, sockaddr_in& serverAddr)
{
    initializeSocket(wsaData);
    createSocket(clientSocket);
    connectToServer(serverAddr, clientSocket);
}

string promptForInput(void)
{
    std::cout << "Enter a message to send to the server: ";
    std::string userInput;
    getline(std::cin, userInput);

    return userInput;
}

void sendToServer(string message, SOCKET& clientSocket)
{
    int bytesSent = send(clientSocket, message.c_str(), message.length(), 0);
    if (bytesSent == SOCKET_ERROR) {
        std::cerr << "Error: Couldn't send data to server\n";
        closesocket(clientSocket);
        WSACleanup();
    }
}

void closeSocket(SOCKET& clientSocket)
{
    closesocket(clientSocket);
    WSACleanup();
}
