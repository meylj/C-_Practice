#include <iostream>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define PORT 8080
#define IP_ADDRESS "127.0.0.1"



int main(int argc, char *argv[])
{
    WSADATA Ws;//WSADATA结构被用来储存调用AfxSocketInit全局函数
	             //返回的Windows Sockets初始化信息
	SOCKET CientSocket;
	struct sockaddr_in ServerAddr;
	int Ret = 0;
	int AddrLen = 0;
	HANDLE hThread = NULL;
    char *SendBuffer[] = {"Client Query test\n","Cleint Query\n","Client Query Quit\n"};

	//Init Windows Socket
	if(WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
	    cout<<"Init Windows Socket Failed::"<<GetLastError()<<endl;
		return -1;
	}

	//create socket
	CientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(CientSocket == INVALID_SOCKET)
	{
	    cout<<"create socket failed::"<<GetLastError()<<endl;
		return -1;
	}

	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	ServerAddr.sin_port = htons(PORT);
	memset(ServerAddr.sin_zero, 0x00, 8);

	//connect 
	Ret = connect(CientSocket, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	if(Ret == SOCKET_ERROR)
	{
	    cout<<"Connect Failed::"<<GetLastError()<<endl;
		return -1;
	}
	else
	{
	    cout<<"connet succuss"<<endl;
	}
	
	

    for(int i = 0; i < strlen(*SendBuffer); i++)
	{
	    //cin.getline(SendBuffer, sizeof(SendBuffer));
		Ret = send(CientSocket, SendBuffer[i], (int)strlen(*SendBuffer), 0);
		if(Ret == SOCKET_ERROR)
		{
		    cout<<"Send Info Error!"<<GetLastError<<endl;
			break;
		}
	    
		
	}

//	closesocket(CientSocket);
	WSACleanup();

	return 0;
}