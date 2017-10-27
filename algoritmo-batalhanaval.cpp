#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void montaTabuleiro();
void iniciaTabuleiro();
char tiroEmbarcacao(char opcao, int jogador);
void jogadaTabuleiro();

char tabuleiro[20][20][2];
char pontuacao[2];

int main(){
	setlocale(LC_ALL, "Portuguese");
	char sair = 'N';
	
	montaTabuleiro();
	
	/* AQUI J� COME�A O BOM DO GAME :D */
	jogadaTabuleiro();
	
	
	system("Pause");
	  	   
}

void iniciaTabuleiro(){
  int x, y, jogador;
  
	for(jogador = 1; jogador <= 2; jogador++)
  		for(x = 0; x < 20; x++)
  			for(y = 0; y < 20; y++)
  	 			tabuleiro[x][y][jogador] = 'A';  
}

void montaTabuleiro(){
	int jogador = 1;
	
	do{	
		int posicao_1 = 0, posicao_2 = 0, fimTabuleiro = 0;
		char opcao;
		
		/* INICIA O TABULEIRO COM AGUA*/
		iniciaTabuleiro();
		
		printf("\n***** Bem vindo ao Jogo Batalha Naval *****\n");
		printf("\nJogador %d preencha seu tabuleiro \n\n", jogador);
		
		do{
			printf("\nOp��o : \n S - Subimarino \t C - Coura�ado \n P - Porta Avi�o \t R - Resgate \n\n Voc� pode escolher at� duas op��es de cada embarca��o! \n");
			scanf("%c", &opcao);
			
			/* VERIFICA QUANTIDADE DE EMBARCA��ES */
			int verificaEmbarcacao = 0, i = 1;
			
			for(int x = 0; x < 20; x++)
			  	for(int y = 0; y < 20; y++)
			  		if(tabuleiro[x][y][jogador] == opcao)
			  			verificaEmbarcacao++;
			  
			/* MONTA O TABULEIRO DE ACORDO COM O PREENCHIMENTO DOS JOGADORES */
			
		 	if(opcao == 'S'){
		 		if(verificaEmbarcacao < 4){
			 		while(i <= 2){
			 			printf("\nDigite a %d posi��o da embarca��o ** Submarino ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'S';
							i++;
						}  else {
							printf("\nA posi��o que voc� digitou j� possui uma embarca��o.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
		 		} else {
					printf("\nVoc� atingiu o m�ximo da embarca��o ** Submarino **.! \n");
				}
			} 
			
			else if(opcao == 'C'){
				if(verificaEmbarcacao < 6){
			 		while(i <= 3){
			 			printf("\nDigite a %d posi��o da embarca��o ** Coura�ado ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'C';
							i++;
						}  else {
							printf("\nA posi��o que voc� digitou j� possui uma embarca��o.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
				} else {
					printf("\nVoc� atingiu o m�ximo da embarca��o ** Coura�ado **.! \n");
				}
			}
			
			else if(opcao == 'P'){
				if(verificaEmbarcacao < 8){
			 		while(i <= 4){
			 			printf("\nDigite a %d posi��o da embarca��o ** Porta Avi�o ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'P';
							i++;
						}  else {
							printf("\nA posi��o que voc� digitou j� possui uma embarca��o.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
				} else {
					printf("\nVoc� atingiu o m�ximo da embarca��o ** Porta Avi�o **.! \n");
				}
			}
			
			else if(opcao == 'R'){
				if(verificaEmbarcacao < 2){
			 		while(i <= 1){
			 			printf("\nDigite a %d posi��o da embarca��o ** Resgate ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'R';
							i++;
						} else {
							printf("\nA posi��o que voc� digitou j� possui uma embarca��o.! \n");
						}  
						system("cls");	 					
			 		}
			 		fimTabuleiro++;
				}  else {
					printf("\nVoc� atingiu o m�ximo da embarca��o ** Resgate **.! \n");
				}
			}
			
			else {
				printf("\nOp��o da embarca��o inv�lida \n");
			}
			
			fflush(stdin);
		
		}while(fimTabuleiro < 8);

		jogador++;
		
	}while(jogador <= 2);
}

char tiroEmbarcacao(char opcao, int jogador){
	switch(opcao){
		case 'S':
			return printf("\n Parab�ns Jogador %d, voc� atingiu a embarca��o ** Submarino ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 10;
		break;
		case 'C':
			return printf("\n Parab�ns Jogador %d, voc� atingiu a embarca��o ** Coura�ado ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 20;
		break;
		case 'P':
			return printf("\n Parab�ns Jogador %d, voc� atingiu a embarca��o ** Porta Avi�o ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 30;
		break;
		case 'R':
			return printf("\n Parab�ns Jogador %d, voc� atingiu a embarca��o ** Resgate ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 5;
		break;
		default:
			return printf("\n Ah n�o! Jogador %d, voc� atingiu ** �gua **, aprimore a sua mira na prox�ma jogada! %c \n", jogador, opcao);
		break;
	}
}

void jogadaTabuleiro(){
	int sair = 0, jogador = 1, i, winner;
	int posicao_1 = 0, posicao_2 = 0;
	
	/* LET'S GO A JOGADAS  */
	system("cls");
	printf("\nVoc� pode desistir de jogar a qualquer momento apenas digitando a letra ** F ** na sua jogada, mais a vitoria fica com seu advers�rio!!! Nunca desista \n\n ");
	printf("\nVamos come�ar o show e destruir a todas embarca��es!! \n\n ");
	
	do{
		
		i = 1;
		
		if((jogador % 2) != 0){
			/* VERIFICA SE TODAS AS EMBARCA��ES FORAM DESTRUIDAS QUANTIDADE DE PONTOS = 410 */
			if(pontuacao[jogador] == 410){
				winner = jogador; sair = 2;
			}
			
			/* JOGADOR 1 ATACA A EMBARCA��O DA MATRIZ DO JOGADOR 2*/
			jogador++;
			
			while(i <= 2){
				printf("\nJogador %d Digite a %d posi��o de sua jogada: \n", jogador - 1, i);
				scanf("%c %c", &posicao_1, &posicao_2);
				
				/* VERIFICA SE O JOGADOR DESEJA SAIR */
				if((char) posicao_1 == 'F' || (char)posicao_2 == 'F'){
					i = 9; winner = jogador; sair = 9;
				} else {

					if(tabuleiro[posicao_1][posicao_2][jogador] != '*'){
						tiroEmbarcacao(tabuleiro[posicao_1][posicao_2][jogador], jogador - 1);
						
						tabuleiro[posicao_1][posicao_2][jogador] = '*';
						i++;
					} else {
						printf("\nVoc� atingiu uma jogada feita anteriormente, tente novamente.! \n");
					}
					
				}
			}
			
			
		} else {
			/* VERIFICA SE TODAS AS EMBARCA��ES FORAM DESTRUIDAS QUANTIDADE DE PONTOS = 410 */
			if(pontuacao[jogador] == 410){
				winner = jogador; sair = 2;
			}
			
			/* JOGADOR 2 ATACA A EMBARCA��O DA MATRIZ DO JOGADOR 1*/
			jogador--;
			
			while(i <= 2){
				printf("\nJogador %d Digite a %d posi��o de sua jogada: \n", jogador + 1, i);
				scanf("%c %c", &posicao_1, &posicao_2);
				
				/* VERIFICA SE O JOGADOR DESEJA SAIR */
				if((char) posicao_1 == 'F' || (char) posicao_2 == 'F'){
					i = 9; winner = jogador; sair = 9;
				} else {
					
					if(tabuleiro[posicao_1][posicao_2][jogador] != '*'){
						tiroEmbarcacao(tabuleiro[posicao_1][posicao_2][jogador], jogador + 1);
						
						tabuleiro[posicao_1][posicao_2][jogador] = '*';
						i++;
					} else {
						printf("\nVoc� atingiu uma jogada feita anteriormente, tente novamente.! \n");
					}
					
				}
			}
		}
		
	}while(sair < 1);
	
	/* GANHADOR DO JOGO WINNER */
	system("cls");
	printf("\n\n****** Jogador %d Venceu a Batalha Naval parab�ns pela conquista.!!!! ******** \n\n", winner);
	
}



