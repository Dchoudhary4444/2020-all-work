#include<windows.h>
#include<stdio.h>
#include<string.h>
int main()
{
WORD winsockVersion;
WSADATA winsockData;
int winsockState;
winsockVersion=MAKEWORD(1,1);
winsockState=WSAStartup(winsockVersio,&winsockData)l
if(winsockState!=0)
{
printf("Unable to intialize winsock Library\n");
reutrn 0;
}

int serverSocketDescriptor;
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(serverSocketDescriptor<0)
{
printf("Unable to create socket \n");
WSACleanup();
return 0;
}


struct sockddr_in serverAddress;
int serverPortNumber=5500;
serverAddress.sin_addr=AF_INET;
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
int clientPortNumber;
int clientSocketDescriptor;
struct in _addr clientIPAddress;
char *clientIP;
int clientAddressLen;
char requestBuffer[1024];
char responseBuffer[1024];
int bytesSend;
int bytesReceived;

while(1)
{
lisetn(serverSocketDescritpr,SOMAXCONN);
pritnf("server is in listening mode");
clientAddressLen=sizeof(clientAddress);
clientSocketDescriptor=accept(serverSocketDescriptor,(struct sockaddr *)&clientAddres,&clientAddressLen);
if(clientSocketDescriptor<0)
{
printf("client connected ,but unable to accept client\n");
continue;
}
printf("client connected\n");

clientPortNumber=ntohs(clientAddress.sin_port);
memcpy(&clientIPAddress,&clientAddress.sin_addr.s_addr,4);
clientIP=inet_ntoa(clientIPAddress);
printf("Client connected from  :%s to port %d \n",clientIP,clientPortNumber);

bytesReceived=recv(clientSocketDescriptor,requestBuffer,sizeof(requestBuffer),0);
if(bytesReceived<0)
{
printf("Unable to extract bytes\n");
closesocket(clientSocketDescriptor);
continue;
}
requestBuffer[bytesReceived]='\0';
strcpy(responseBuffer,"OK\r\n");
bytesSent=send(clientSocketDescriptor,responseBuffer,strlen(responseBuffer));
if(bytesSent<0)
{
printf("Unable to send response\n");
closesocket(clientSocketDescriptor);
}

printf("%s sent as response \n",responseBuffer);
closesocket(clientSocketDescriptor);
}

closesocket(serverSocketDescriptor);
WSACleanup();


return 0;
}