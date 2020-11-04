//Trabalho Final
//Pedro Duarte Alvim - 180108042
//Heitor Magalhães Vieira - 180121821


#include "BatalhaNaval.h"


#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "3000"

int __cdecl main(void) 
{
	char t1[10][10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char t2[10][10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	
    gerartabuleiro(t1);
	
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;
    //hints.ai_addr = ADDR;

    // Resolve the server address and port	
	//iResult = getaddrinfo("192.168.43.105", DEFAULT_PORT, &hints, &result);		//para jogar em maquinas diferentes   e colocar o ip da proprica maquina
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);				//para jogar na mesma maquina
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n");
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    else{
    	std::cout  << "Connected!\n";
	}

    // No longer need server socket
    closesocket(ListenSocket);
    
    
    //Ja conectado, agora começa o jogo.
    
jogada:
   
	int recebido = 0, recebido2 = 0;
	int x,y;
    std::vector<int>coordenada;
	std::vector<int>::iterator it;
    int v,w;
    int cont = 0;
	int victory = 0;	
	for(int i = 1; victory != 1 ; i++){
		regra(1);
		tabuleiro(t1, t2);
		do{
			x = jogadalinha(t2);
			y = jogadacoluna(t2);
		}while(t2[x-1][y-1] != ' ');
	
		send( ClientSocket, recvbuf, x, 0 );
		send( ClientSocket, recvbuf, y, 0 );
	
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);   
		recebido = (int)iResult;   
		if(recebido == 100){
			t2[x-1][y-1] = 207;
		}
		else if(recebido == 101){
			t2[x-1][y-1] = 176;
			system("cls");
			goto receber;
		}
		recebido = 0;
	
		victory = vitoria(t2);
			if(victory == 1){
			std::cout<<"					*****************************************************************************************************\n";
			std::cout<<"									     	    VOCE GANHOU!!!\n";
			std::cout<<"					*****************************************************************************************************\n";
			int ganhou = 12;
			send(ClientSocket, recvbuf, ganhou, 0);
			system("PAUSE");
			goto fim;
		}
		else{
		}
		std::cout << victory; 
		system("cls");	 
		
}
    
     
	receber:

	
    do{
		tabuleiro(t1, t2);
				iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        			recebido2 = (int)iResult;
        			cont++;
        			coordenada.push_back(recebido2);
        			//std::cout << (int)recebido2 << std::endl;
        			if(cont%2 == 0){
        				it = coordenada.begin();
        				v = *it;
        				it++;
        				w = *it; 
        				coordenada.pop_back();
        				coordenada.pop_back();
        				if(t1[v-1][w-1] != ' '){
        					t1[v-1][w-1] = 207;
        					int acertou = 100;
        					send(ClientSocket, recvbuf, acertou, 0);				//falar que acertou
						}
						else{
							t1[v-1][w-1] = 176;
							int errou = 101;
							send(ClientSocket, recvbuf, errou, 0);
							system("cls");
							goto jogada;
						}
					}
					
					else if(recebido2 == 12){
			std::cout<<"					****************************************************************************************************\n";
			std::cout<<"									     	    VOCE PERDEU!!!\n";
			std::cout<<"					****************************************************************************************************\n";
			system("PAUSE");
			goto fim;
		}
					
					
					
					
		system("cls");
	}while(iResult > 0);
    
    fim:
    	
    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}
