#include<windows.h>
#include<string.h>
#include<stdio.h>
int main()
{
WORD winsockVersion;
WSADATA winsockData;
int winsockState;
winsockVersion=MAKEWORD(1,1);
winsockState=WSASetup(winsockVersion,&winsockData);
if(winsockState!=0)
{
printf("unable to initialize windows library\n");
return 0;
}


int serverSocketDescriptor;
serverSocketDescriptor=socket(,SERVER_SOCKET,IPPRO_TCP);
if(serverSocketDescriptor<0)
{
printf("unable to create socket\n");
WSACleanup();
return 0;
}

struct sockaddr_in serverAddress;
struct sockaddr_in clientAddress;
int clinetSocketDescriptor;
int clinetAddressLen;
int serverPortNumber=5050;
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


struct in_addr clientIPAddress;
char *clientIP;
int clientPortNumber;
char requestBuffer[1024];
char responseBuffer[1024];
int bytesReceived;
int bytesSent;
while(1)
{
listen(severSocketDescriptor,SOMAXCONN);
printf("Server is listening mode");
clientAddressLen=sizeof(clientAddress);
clientAddressDescriptor=accept(serverSocketDesciptor,(struct sockaddr *)&clinetAddress,&clientAddressLen);
if(clientSocketDescriptor<0)
{
printf("Client connected,but unable to accept client\n");
continue;
}
printf("Client connected \n");
clientPortNumber=ntohs(cleintAddress.sin_port);
memcpy(&clientIPAddress,&clinetAddress.sin_addr.s_addr,4);
cleintIP=inet_ntoa(clientIPAddress);
printf("Client connected from :%s to port %d\n",clientIP,clientPortNumber);
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
printf("Unable to send response \n");
closesocket(clientSocketDescriptor);
}
printf("%s sent as response \n",responseBuffer);
closesocket(clientSocketDescriptor);

}//while ends here


closesocket(serverSocketDescriptor);
WSACleanup();
return 0;
}