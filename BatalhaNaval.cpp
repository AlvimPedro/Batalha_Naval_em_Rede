#include "BatalhaNaval.h"

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>
#include <ctype.h>


char gerartabuleiro(char t[10][10]){
	srand(time(NULL));
	char barco = 220, barcox=219;
	for(int k = 0; k < 7; k++){
		
			int tamanho;
			if(k==0)
				tamanho = 4;		//1 de tamanho 4
			if(k == 1 || k == 2)
				tamanho = 3;		//2 de tamanho 3
			if(k == 3 || k == 4)
				tamanho = 2;		//2 de tamanho 2
			if(k == 5 || k == 6)
				tamanho = 1;		//2 de tamanho 1
			
			int plinha, pcoluna, pvh;
			inicio:
			//plinha = rand() % 9 + 0;
			pcoluna = rand() % 9 +0;
			pvh = rand() % 2 + 1;
			do{		
			plinha = rand() % 9 + 0;
			pcoluna = rand() % 9 +0;
			pvh = rand() % 2 + 1;
			}while(t[plinha][pcoluna] != ' ');
			int a = 10 - tamanho;
			if(tamanho == 1){
				if(t[plinha+1][pcoluna] != ' ' || t[plinha-1][pcoluna] != ' ' || t[plinha][pcoluna-1] != ' ' || t[plinha][pcoluna+1] != ' '){
				goto inicio;
				}
			}
				
			if(pvh == 1){		//vertical
				if(plinha > a)
					goto inicio;
					
				for(int ta = tamanho ; ta > 0; ta--){					//ver se a partir da casa sorteada as proximas da embarcação tem algo na frente,se sim nao vai entrar nos if do pvh
					if(t[plinha+ta-1][pcoluna] != ' ')		
					goto inicio;
				}
			}
			else if(pvh == 2){		//horizontal	
				if(pcoluna > a)
					goto inicio;
				
				for(int ta = tamanho; ta > 0; ta--){					
					if(t[plinha][pcoluna+ta-1] != ' ')
					goto inicio;	
				}
			}
			if(pvh == 1){			//vertical
				for(int i = plinha; i < (plinha + tamanho); i++ ){
					 t[i][pcoluna] = 219;
				}
			}
			else if(pvh == 2){			//horizontal
				for(int i = pcoluna; i < (pcoluna + tamanho); i++ ){
					 t[plinha][i] = 220;
				}
			}
		}
	return t[10][10];
}

void tabuleiro(char t1[10][10], char t2[10][10]){
	std::cout << "					 ___________________________________________ ";																																		std::cout << "		 ___________________________________________ " << std::endl;
	std::cout << "					|   | A | B | C | D | E | F | G | H | I | J |";																																		std::cout << "		|   | A | B | C | D | E | F | G | H | I | J |" << std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 1 | "<<t1[0][0]<<" | "<<t1[0][1]<<" | "<<t1[0][2]<<" | "<<t1[0][3]<<" | "<<t1[0][4]<<" | "<<t1[0][5]<<" | "<<t1[0][6]<<" | "<<t1[0][7]<<" | "<<t1[0][8]<<" | "<<t1[0][9]<<" |";		std::cout << "		| 1 | "<<t2[0][0]<<" | "<<t2[0][1]<<" | "<<t2[0][2]<<" | "<<t2[0][3]<<" | "<<t2[0][4]<<" | "<<t2[0][5]<<" | "<<t2[0][6]<<" | "<<t2[0][7]<<" | "<<t2[0][8]<<" | "<<t2[0][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 2 | "<<t1[1][0]<<" | "<<t1[1][1]<<" | "<<t1[1][2]<<" | "<<t1[1][3]<<" | "<<t1[1][4]<<" | "<<t1[1][5]<<" | "<<t1[1][6]<<" | "<<t1[1][7]<<" | "<<t1[1][8]<<" | "<<t1[1][9]<<" |";		std::cout << "		| 2 | "<<t2[1][0]<<" | "<<t2[1][1]<<" | "<<t2[1][2]<<" | "<<t2[1][3]<<" | "<<t2[1][4]<<" | "<<t2[1][5]<<" | "<<t2[1][6]<<" | "<<t2[1][7]<<" | "<<t2[1][8]<<" | "<<t2[1][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 3 | "<<t1[2][0]<<" | "<<t1[2][1]<<" | "<<t1[2][2]<<" | "<<t1[2][3]<<" | "<<t1[2][4]<<" | "<<t1[2][5]<<" | "<<t1[2][6]<<" | "<<t1[2][7]<<" | "<<t1[2][8]<<" | "<<t1[2][9]<<" |";		std::cout << "		| 3 | "<<t2[2][0]<<" | "<<t2[2][1]<<" | "<<t2[2][2]<<" | "<<t2[2][3]<<" | "<<t2[2][4]<<" | "<<t2[2][5]<<" | "<<t2[2][6]<<" | "<<t2[2][7]<<" | "<<t2[2][8]<<" | "<<t2[2][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 4 | "<<t1[3][0]<<" | "<<t1[3][1]<<" | "<<t1[3][2]<<" | "<<t1[3][3]<<" | "<<t1[3][4]<<" | "<<t1[3][5]<<" | "<<t1[3][6]<<" | "<<t1[3][7]<<" | "<<t1[3][8]<<" | "<<t1[3][9]<<" |";		std::cout << "		| 4 | "<<t2[3][0]<<" | "<<t2[3][1]<<" | "<<t2[3][2]<<" | "<<t2[3][3]<<" | "<<t2[3][4]<<" | "<<t2[3][5]<<" | "<<t2[3][6]<<" | "<<t2[3][7]<<" | "<<t2[3][8]<<" | "<<t2[3][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 5 | "<<t1[4][0]<<" | "<<t1[4][1]<<" | "<<t1[4][2]<<" | "<<t1[4][3]<<" | "<<t1[4][4]<<" | "<<t1[4][5]<<" | "<<t1[4][6]<<" | "<<t1[4][7]<<" | "<<t1[4][8]<<" | "<<t1[4][9]<<" |";		std::cout << "		| 5 | "<<t2[4][0]<<" | "<<t2[4][1]<<" | "<<t2[4][2]<<" | "<<t2[4][3]<<" | "<<t2[4][4]<<" | "<<t2[4][5]<<" | "<<t2[4][6]<<" | "<<t2[4][7]<<" | "<<t2[4][8]<<" | "<<t2[4][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 6 | "<<t1[5][0]<<" | "<<t1[5][1]<<" | "<<t1[5][2]<<" | "<<t1[5][3]<<" | "<<t1[5][4]<<" | "<<t1[5][5]<<" | "<<t1[5][6]<<" | "<<t1[5][7]<<" | "<<t1[5][8]<<" | "<<t1[5][9]<<" |";		std::cout << "		| 6 | "<<t2[5][0]<<" | "<<t2[5][1]<<" | "<<t2[5][2]<<" | "<<t2[5][3]<<" | "<<t2[5][4]<<" | "<<t2[5][5]<<" | "<<t2[5][6]<<" | "<<t2[5][7]<<" | "<<t2[5][8]<<" | "<<t2[5][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 7 | "<<t1[6][0]<<" | "<<t1[6][1]<<" | "<<t1[6][2]<<" | "<<t1[6][3]<<" | "<<t1[6][4]<<" | "<<t1[6][5]<<" | "<<t1[6][6]<<" | "<<t1[6][7]<<" | "<<t1[6][8]<<" | "<<t1[6][9]<<" |";		std::cout << "		| 7 | "<<t2[6][0]<<" | "<<t2[6][1]<<" | "<<t2[6][2]<<" | "<<t2[6][3]<<" | "<<t2[6][4]<<" | "<<t2[6][5]<<" | "<<t2[6][6]<<" | "<<t2[6][7]<<" | "<<t2[6][8]<<" | "<<t2[6][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 8 | "<<t1[7][0]<<" | "<<t1[7][1]<<" | "<<t1[7][2]<<" | "<<t1[7][3]<<" | "<<t1[7][4]<<" | "<<t1[7][5]<<" | "<<t1[7][6]<<" | "<<t1[7][7]<<" | "<<t1[7][8]<<" | "<<t1[7][9]<<" |";		std::cout << "		| 8 | "<<t2[7][0]<<" | "<<t2[7][1]<<" | "<<t2[7][2]<<" | "<<t2[7][3]<<" | "<<t2[7][4]<<" | "<<t2[7][5]<<" | "<<t2[7][6]<<" | "<<t2[7][7]<<" | "<<t2[7][8]<<" | "<<t2[7][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					| 9 | "<<t1[8][0]<<" | "<<t1[8][1]<<" | "<<t1[8][2]<<" | "<<t1[8][3]<<" | "<<t1[8][4]<<" | "<<t1[8][5]<<" | "<<t1[8][6]<<" | "<<t1[8][7]<<" | "<<t1[8][8]<<" | "<<t1[8][9]<<" |";		std::cout << "		| 9 | "<<t2[8][0]<<" | "<<t2[8][1]<<" | "<<t2[8][2]<<" | "<<t2[8][3]<<" | "<<t2[8][4]<<" | "<<t2[8][5]<<" | "<<t2[8][6]<<" | "<<t2[8][7]<<" | "<<t2[8][8]<<" | "<<t2[8][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					|10 | "<<t1[9][0]<<" | "<<t1[9][1]<<" | "<<t1[9][2]<<" | "<<t1[9][3]<<" | "<<t1[9][4]<<" | "<<t1[9][5]<<" | "<<t1[9][6]<<" | "<<t1[9][7]<<" | "<<t1[9][8]<<" | "<<t1[9][9]<<" |";		std::cout << "		|10 | "<<t2[9][0]<<" | "<<t2[9][1]<<" | "<<t2[9][2]<<" | "<<t2[9][3]<<" | "<<t2[9][4]<<" | "<<t2[9][5]<<" | "<<t2[9][6]<<" | "<<t2[9][7]<<" | "<<t2[9][8]<<" | "<<t2[9][9]<<" |"<<std::endl;
	std::cout << "					|-------------------------------------------|";																																		std::cout << "		|-------------------------------------------|" << std::endl;
	std::cout << "					|___________________________________________|";																																		std::cout << "		|___________________________________________|" << std::endl;
return;
}
int vitoria(char t1[10][10]){
	int cont = 0;
	char bomba = 207;
	for(int l = 0; l < 10; l++){
	    for(int c = 0; c < 10; c++){
	    	//cout << contu++ << "	"<< cont << endl;
	    		if(t1[l][c]==bomba){
	    			cont++;
				}
		}
	}
	if(cont == 16){
		return 1;			//vitoria
	}
	else{
		return 2;			//Ainda não
	}
}
int jogadalinha(char t[10][10]){
	int x;
	std::cout << "					Digite a coordenada da Linha de ( 1-10 ) : ";
	fflush(stdin);
	std::cin >> x;
	
	while ( x < 1 || x > 10 ){        //x>10 || x<1                             
		std::cout << "					Coordenada invalida ( 1-10 ) "<<std::endl;
		std::cout << "					Digite a coordenada da Linha de ( 1-10 ) : ";
		
		if (std::cin.fail()){
			// get rid of failure state
     		std::cin.clear(); 
     		// discard 'bad' character(s) 
     		std::cin.ignore(200, '\n');
  		}
  		
		std::cin >> x;
	}
	return x;
}
int jogadacoluna(char t[10][10]){
	int y;
	char letra;
	std::cout << "					Digite a coordenada da Coluna de ( A-J ) : ";
	fflush(stdin);
	std::cin >> letra;
				if(isupper(letra)== true)						
					letra = tolower(letra);					
	y = int(letra)-96;		
	char a = 207, b = 176;
	while ( y>10 || y<1 ){                                     
		std::cout << "					Coordenada invalida ( A-J ) "<<std::endl;
		std::cout << "					Digite a coordenada da Coluna de ( A-J ) : ";
		
			if (std::cin.fail()){
     		// get rid of failure state
     		std::cin.clear(); 
     		// discard 'bad' character(s) 
     		std::cin.ignore(200, '\n');
  		}
  		
		std::cin >> letra;
				if(isupper(letra)== true)						
					letra = tolower(letra);				
	y = int(letra)-96;
	}
	return y;
}
void regra(int x){
	char a = 207, b = 176;
	std::cout << "										      JOGADOR "<<x << "!"<<std::endl;
	std::cout << "					*****************************************************************************************************\n";
	std::cout << "										    BATALHA NAVAL\n";
	std::cout << "					NA TELA MOSTRA-SE A ESQUERDA O SEU TABULEIRO COM OS SEUS BARCOS E A DIREITA O TABULEIRO QUE A  MEDIDA\n";
	std::cout << "					QUE E JOGADO VAI MOSTRAR SE VOCE ACERTOU AGUA< "<<b<<" > OU BARCO< "<<a<<" >. O PRIMEIRO A JOGAR, JOGADOR 1 VAI DI-\n";
	std::cout << "					GITAR AS COORDENADAS DA LINHA E COLUNA, EM SEGUIDA SE ACERTAR UM BARCO JOGUE NOVAMENTE, CASO CONTRARIO,\n";
	std::cout << "					ELE PERDE SUA VEZ, PASSANDO A JOGADA PARA O JOGADOR 2. GANHA QUEM ACERTAR TODOS OS 7 BARCOS, SENDO\n";
	std::cout << "					ELES 1 DE TAMANHO 4, 2 DE TAMANHO 3, 2 DE TAMANHO 2, 2 DE TAMANHO 1\n";
	std::cout << "					*****************************************************************************************************\n";
	
}
