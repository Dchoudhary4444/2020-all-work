#include<windows.h>
#include<stdio.h>
#include<string.h>
int main()
{
WORD winsockVersion;
WSADATA winsockData;
int winsockState;
winsockVersion=MAKEWORD(1,1);
winsockState=WSAStartup(winsockVersion,&winsockData);
if(winsockState!=0)
{
printf("Unable to intialized winsock library\n");
return 0;
}

int serverSocketDescriptor;
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(serverSocketDescriptor<0)
{
printf("Unable to create socket");
WSACleanup();
return 0;
}


struct sockaddr_in serverAddress;
int serverPortNumber=5500;
int bindState;

serverAddres.sin_family=AF_INET;
serverAddress.sin_port=htons(serverPortNumber);
serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
bindState=bind(serverSocketDescriptor,(struct sockaddr *)&serverAddress,sizeof(struct sockaddr));
if(bindState<0)
{
printf("Unable to bind socket to port %d \n",serverPortNumber);
WSACleanup();
return 0;
}

struct sockaddr_in clientAddress;
int clientSocketDescriptor;
int clientPortNumber;

int clientAddressLen;
struct in_addr clientIPAddress;
char *clientIP;

char requestBuffer[1024];
char responseBuffer[1024];
int bytesReceived;
int bytesSent;

while(1)
{
listen(sevrerSocketDescriptor,SOMAXCONN);
printf("sever  is in listening mode");
clientAddressLen=sizeof(clientAddress);
clientSocketDescriptor=accept(serverSocketDescriptor,(struct sockaddr *)&clientAddress,&clientAddressLen);
if(clientSocketDescriptor<0)
{
printf("Cleint connnected ,but unable to accept client\n");
continue;
}
printf("Client connected\n");


clientePortNumber=ntohs(clientAddress.sin_port);
memcpy(&clientIPAddress,&clientAddress.sin_addr.s_addr,4);
clientIP=inet_ntoa(clientIPAddress);
printf("Client connected from %s to port %d \n",clientIP,clientPortNumber);
bytesReceived=recv(clientSocketDescriptor,requestBuffer,sizeof(requestBuffer),0);
if(bytesReceived<0)
{
printf("Unable to extract bytes\n");
closeSocket(clientSocketDescriptor);
continue;
}
requestBuffer[bytesReceived]='\0';


strcpy(responseBuffer,"OK\r\n");
bytesSent=send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
if(bytesSent<0)
{
printf("Unable to send response\n");
closesocket(clientSocketDescriptor);
}
printf("%s is send as response \n",responseBuffer);
closesocket(clientSocketDescriptor);
}//while loop ends here

closeSocket(serverSocketDescriptor);
WSACleanup();
return 0;
}