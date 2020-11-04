//Trabalho Final
//Pedro Duarte Alvim - 180108042
//Heitor Magalhães Vieira - 180121821

#include "BatalhaNaval.h"

#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "3000"

int __cdecl main(int argc, char **argv) //int argc, char **argv
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct  addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    const char *sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    
   // Validate the parameters
   //if (argc != 2) {
     //   printf("usage: %s server-name\n", argv[0]);
       // return 1;
    //}

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
   // iResult = getaddrinfo("192.168.43.105", DEFAULT_PORT, &hints, &result);//para jogar em maquinas diferentes e colocar o mesmo ip da maquina do server
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result); 			//para jogar na mesma maquina
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }
int j = 0;
    // Attempt to connect to an address until one succeeds
    for(ptr=result; j < 10 ;ptr=ptr->ai_next) {		//ptr != NULL 
		//std::cout << "*";
		j++;
        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        //iResult = connect( ConnectSocket, (sockaddr*)&hints, sizeof(hints)); //teste
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            //std::cout << "Erro aqui";
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }
    else{
    	std::cout<<"Connected!\n";
	}
    
    std::string userinput ;
	int i = 0;
	int recebido; 
	int cont = 0;
	std::vector<int>coordenada;
	std::vector<int>::iterator it;
	char t3[10][10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	char t4[10][10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	
    gerartabuleiro(t3);
	//system("pause"); 		//intervalo entre gerar os arrays para gerar diferentes para nao ficarem iguais
	int x,y;
	std::cout<<"Jogador 2"<<std::endl;
	int victory = 0;
	int recebido2 = 0;
	int v,w;
	receber:
			do
			{
				regra(2);
				tabuleiro(t3, t4);
				iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        			if (iResult > 0) {
        			recebido = (int)iResult;
        			cont++;
        			coordenada.push_back(recebido);
        			
        			if(recebido == 12){
						std::cout<<"					****************************************************************************************************\n";
						std::cout<<"									     	    VOCE PERDEU!!!\n";
						std::cout<<"					****************************************************************************************************\n";
						system("pause");
						goto fim;
					}
        			if(cont%2 == 0){
        				it = coordenada.begin();
        				x = *it;
        				it++;
        				y = *it; 
        				coordenada.pop_back();
        				coordenada.pop_back();
        				if(t3[x-1][y-1] != ' '){
        					t3[x-1][y-1] = 207;
        					int acertou = 100;
        					send(ConnectSocket, recvbuf, acertou, 0);				//falar que acertou
						}
						else{
							t3[x-1][y-1] = 176;
							int errou = 101;
							send(ConnectSocket, recvbuf, errou, 0);
							system("cls");
							goto jogada;
						}
					}	
        			}
        			
        			
        			
        			
        			
        		system("cls");
			}while(iResult > 0);
			
	jogada:
   

		
for(int i = 1; victory != 1; i++){
	regra(2);
	tabuleiro(t3, t4);
	do{
		v = jogadalinha(t4);
		w = jogadacoluna(t4);
	}while(t4[v-1][w-1] != ' ');
	
	send( ConnectSocket, recvbuf, v, 0 );
	send( ConnectSocket, recvbuf, w, 0 );
	
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);   
	recebido2 = (int)iResult;   
	if(recebido2 == 100){
		t4[v-1][w-1] = 207;
	}
	else if(recebido2 == 101){
		t4[v-1][w-1] = 176;
		system("cls");
		goto receber;
	}
	
	recebido2 = 0;
	
	victory = vitoria(t4);
	if(victory == 1){
		std::cout<<"					*****************************************************************************************************\n";
		std::cout<<"									     	    VOCE GANHOU!!!\n";
		std::cout<<"					*****************************************************************************************************\n";
		int ganhou = 12;
		send(ConnectSocket, recvbuf, ganhou, 0);
		system("pause");
		goto fim;
	}
	else{
	}
	std::cout << victory; 
	system("cls");	 
		
}

fim:
    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // Receive until the peer closes the connection
    do {
    	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);
            std::cout << "Server> " << std::string(recvbuf, 0, iResult)<< std::endl;
            //system("pause");
             int iSendResult = send( ConnectSocket, recvbuf, iResult, 0 );
        }
        

        //iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 )
            printf("Bytes received: %d\n", iResult);
        else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while( iResult > 0 );

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}
