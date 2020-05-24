#include<windows.h>
#include<string.h>
#include<stdio.h>
int main()
{
WORD winscokVersion;
WSADATA winsockData;
int winsockState;
winsockVersion=MAKEWORD(1,1);
winsockState=WSASetup(winsockVersion,&winsockData);
if(winsockState!=0)
{
printf("Unable to Initialized winsock Library\n");
return 0;
}

int serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,IPPRO_TCP);
if(serverSocketDescriptor<0)
{
printf("Unable to create socket \n");
return 0;
}

struct sockaddr_in serverAddress;
struct sockaddr_in clientAddress;
int clientSocketDescriptor;
int clientAddressLen;
int bindState;
int serverPortNumber=5050;

serverAddress.sin_addr=AF_INET;
serverAddress.sin_port=htons(serverPortNumber);
serverAddress.sin_addr.s_addr=htonl()
bindState=bind(serverSocketDescriptor,(struct sockaddr *)&serverAddress,sizeof(struct sockaddr));
if(bindState<0)
{
printf("unable to bind socket to port %d\n",portNumber);
WSACleanup();
return 0;
}


struct in_addr clientIPAddress;
char *clientIP;
int clientPortNumber;
char requestBuffer[1024];
char responseBuffer[1024];
int bytesReceived;
int bytesSent;

while(1)
{
listen(serverSocketDescriptor,SOMAXCONN);
printf("server is in listening mode");
clientAddresLen=sizeof(clientAddressLen);
clientSocketDescriptor=accept(serverSocketDescriptor,(stuct sockaddr *)&clientAddress,&clientAddressLen);
if(clientSocketDescriptor<0)
{
printf("client connected ,but unnable to accept client\n");
continue;
}
printf("Client Connected\n");
clientPortNumber=ntohs(clientAddress.sin_port);
memcpy(&clientIPAddress,&clientAddress.sin_addr,s_addr,4);
clientIP=inet_ntoa(clientIPAddress);
printf("Client connected from %s to port %d \n",clientIP,clientPortNumber);
bytesReceived=recv(clientSocketDescriptor,requestBuffer,sizeof(request Buffer),0);
if(bytesReceived<0)
{
printf("Unable to extract bytes\n");
closesocket(clientSocketDescriptor);
continue;
}

requestBuffer[bytesReceived]='\0';
strcpy(responseBuffer,"OK\r\n");
bytesSent=sned(clientSocketDescriptor,responseBuffer,strlen(responseBuffer),0);
if(bytesSent<0)
{
printf("Unable to send response \n");
closesocket(clientSocketDescriptor);
}
printf("%s sent as response \n",responseBuffer);
closesocket(clientSocketDescriptor);
}//while ends here

closeSocket(serverSocketDescriptor);
WSACleanup();
return 0;
}