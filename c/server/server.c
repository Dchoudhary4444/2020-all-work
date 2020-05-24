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
printf("Unable to initialized winsock library\n");
return 0;
}

int serverSocketDescriptor;
serverSocketDescriptor=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if(serverSocketDescriptor<0)
{
printf("Unable to create socket\n");
WSACleanup();
return 0;
}


struct sockaddr_in serverAddress;
int serverPortNumber=5500;
int bindState;
serverAddress.sin_family=AF_INET;
serverAddress.sin_port=htons(serverPortNumber);
serverAddress.sin_addr.s_addr=htonl(INADDR_ANY);
bindState=bind(serverSocketDescriptor,(struct sockaddr *)&serverAddress,sizeof(struct sockaddr));
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
char *clientIP;
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
clientSocketDescriptor=accept(serverSocketDescriptor,(struct sockaddr*)&clientAddress,&clientAddressLen);
if(clientSocketDescriptor<0)
{
printf("Client connected, but unable to accept client\n");
continue;
}
printf("Client connected\n");

clientPortNumber=ntohs(clientAddress.sin_port);
memcpy(&clientIPAddress,&clientAddress.sin_addr.s_addr,4);
clientIP=inet_ntoa(clientIPAddress);
printf("Client connected from : %s to port %d\n",clientIP,clientPortNumber);


bytesReceived=recv(clientSocketDescriptor,requestBuffer,sizeof(requestBuffer),0);
if(bytesReceived<0)
{
printf("Unable to extract bytes\n");
closesocket(clientSocketDescriptor);
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
printf("%s sent as response\n",responseBuffer);
closesocket(clientSocketDescriptor);
}//while ends here




closesocket(serverSocketDescriptor);
WSACleanup();


return 0;
}