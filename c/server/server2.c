#include<windows.h>
#include<string.h>
#include<stdio.h>
int main()
{
WORD winsockVersion;
WSADATA winsockData;
int winsockState;
winsockVersion=MAKEWORD(1,1);
winsockData=WSAStartup(winsockVersion,&winsockData);
if(wisockState!=0)
{
printf("Unabel to Intitalized winosck library\n");
return 0;
}

int serverSockerDescripto;
serverSocketDescriptor=socket(AF_INET,SERVER_SOCKET,IPPRO_TCP);
if(serverSocketDescriptor<0)
{
printf("Unabel to create socket \n");
WSACleanup();
return 0;
}

struct sockaddr_in serverAddress;
stuct sockaddr_in clientAddress;
int clientSocketDescriptor;
int clientAddressLen;
int serverPortNumber=5050;
int bindState;

serverAddress.sin_family=AF_INET;
severAddress.sin_port=htons(serverPortNumber);
serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
bindState=bind(serverSocketDescriptor,(struct sockaddr *)&serverAddress,sizeof(struct sockaddr));
if(bindState<0)
{
printf("Unable to bind socket to port %d\n",portNumber);
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



return 0;
}