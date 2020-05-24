#include<windows.h>
#include<string.h>
#include<stdio.h>
int main()
{
WORD winsockVersion;
WSADATA winsockData;
int winsockState;
winscokVersion=MAKEWORD(1,1);
winsockState=WSAStartup(winsockVersion,&winsockData);
if(winsockSate!=0)
{
printf("unable to intialize winsock library":\n);
return 0;
}

int serverSocketDescriptor;
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)
if(serverSocketDescriptor<0)
{
printf("Unable to create socket :\n");
WSACleanup();
return 0;
}

struct sockaddr_in serverAddress;
int serverPortNumber=5050;
int bindState;
serverAddress.sin_family=AF_INET;
serverAddress.sin_port=htons(serverPortNumber);
serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
bindState=bind(serverSocketDescriptor,(struct sockaddr *)&serverAddress,sizeof(struct serveraddr))
if(bindState<0)
{
printf("Unable to bind socket to port %d\n",serverPortNumber);
WSACleanup();
return 0;
}	


struct sockaddr_in clientAddress;
int clientSocketDescriptor;
int clientAddressLen;
struct in_addr clientIPAddress;
char *cleintIP;
int clientPortNumber;
char requestBuffer[1024];
char responseBuffer[1024];
int bytesReceived;
int bytesSent;

while(1)
{
listen(serverSocketDescriptor,SOMAXCONN);
printf("Server is in listening mode");
clientAddressLen=sizeof(clientAddress);
clientSocketDescriptor=accept(serverSocketDescriptor,(struct sockaddr *)&clientAddress,&clientAddressLen);
if(clientSocketDescriptor<0)
{
printf("client connected but unable to accept client\n");
continue;
}
printf("client connected\n");

clientPortNumber=ntoh(clientAddress.sin_port);
memcpy(&clientIPAddress,&clientAddress.sin_addr.s_addr,4);
clientIP=inet_ntoa(clientIPAddress);
printf("Client connected from :%s to port %d \n",clientIp,clientPortNumber);


bytesReceived=recv(clientSocketDescriptor,requestBuffer,sizeof(requestBuffer),0);
if(bytesReceived<0)
{
printf("Unable to extract bytes\n");
closeSocket(clientSocketDescriptor);
continue;
}
requestBuffer[bytesReceived]='\0';


strcpy(responseBuffer,"OK\r\n");
bytesSent=send(cleintSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
if(bytesSent<0)
{
printf("Unable to send response \n");
closesocket(clientSocketeDescriptor);
}//while loop ends here

closesocket(serverSocketDescriptor);
WSACleanup();

return 0;
}