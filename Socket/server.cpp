#include <iostream>
#include <Windows.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

#define PORT 8080
#define IP_ADDRESS "127.0.0.1"

DWORD WINAPI ClientThread(LPVOID IpParameter)
{
    SOCKET CientSocket = (SOCKET)IpParameter;
	int Ret = 0;
	char RecvBuffer[MAX_PATH];

	while(true)
	{
	    memset(RecvBuffer, 0x00, sizeof(RecvBuffer));
		Ret = recv(CientSocket, RecvBuffer, MAX_PATH, 0);
		if(Ret == 0 || Ret == SOCKET_ERROR)
		{
		    cout<<"客户端退出！"<<endl;
			exit(0);
		}
		cout<<"接收到客户信息为：\n"<<RecvBuffer<<endl;
	}

	return 0;
}

int main(int argc, char *argv[])
{
    WSADATA Ws;
	SOCKET ServerSocket, CientSocket;
	struct sockaddr_in LocalAddr, ClientAddr;
	int Ret = 0;
	int AddrLen = 0;
	HANDLE hThread = NULL;

	//Init Windows Socket
	if(WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
	    cout<<"Init Windows Socket Failed::"<<GetLastError()<<endl;
		return -1;
	}

	//create socket
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(ServerSocket == INVALID_SOCKET)
	{
	    cout<<"create socket failed::"<<GetLastError()<<endl;
		return -1;
	}

	LocalAddr.sin_family = AF_INET;
	LocalAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
	LocalAddr.sin_port = htons(PORT);
	memset(LocalAddr.sin_zero, 0x00, 8);

	//Bind Socket
	Ret = bind(ServerSocket, (struct sockaddr *)&LocalAddr, sizeof(LocalAddr));
	if(Ret != 0)
	{
	    cout<<"Bind Scoket Failed::"<<GetLastError()<<endl;
		return -1;
	}

	Ret = listen(ServerSocket, 10);
	if(Ret != 0)
	{
	    cout<<"Listen Scoket Failed::"<<GetLastError()<<endl;
		return -1;
	}

	//服务器端已经启动
	while(true)
	{
	    AddrLen = sizeof(ClientAddr);
		CientSocket = accept(ServerSocket, (struct sockaddr *)&ClientAddr, &AddrLen);
		if(CientSocket == INVALID_SOCKET)
		{
		    cout<<"Accept Failed"<<GetLastError<<endl;
			break;
		}

		cout<<"客户端连接：："<<inet_ntoa(ClientAddr.sin_addr)<<":"<<ClientAddr.sin_port<<endl;

		hThread = CreateThread(NULL, 0, ClientThread, (LPVOID)CientSocket, 0, NULL);
		if(hThread == NULL)
		{
		    cout<<"Create Thread Failed1"<<endl;
			break;
		}
		
		CloseHandle(hThread);
	}

	closesocket(ServerSocket);
	closesocket(CientSocket);
	WSACleanup();

	return 0;
}