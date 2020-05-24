#include<windows.h>
#include<string.h>
#include<stdio.h>
int main()
{
WORD winsockVersion;
WSADATA winsockData;
int winsockState;
winsockVersion=MAKEWORD(1,1);
winsockState=WSAStartup(winsockVersion,&winsockData);
if(winsockState!=0)
{
printf("Unable to Intialized winsock library \n");
return 0;
}



int serverSocketDescriptor;
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(serverSocketDescriptor<0)
{
printf("Unable to create socket \n");
WSACleanup();
return 0;
}

struct sockaddr_in serverAddress;
struct sockaddr_in clientAddress;
int clientSocketDescriptor;
int clientAddressLen;
int serverPortNumber=5050;
int bindState;
serverAddress.sin_family=AF_INET;
serverAddress.sin_port=htons(serverPortNumber);
serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
bindState=bind(serverSocketDescriptor,(struct sockaddr*)&serverAddress,sizeof(struct sockaddr));
if(bindState<0)
{
printf("Unable to bind socket to port %d\n",serverPortNumber);
WSACleanup();
return 0;
}


return 0;
}