#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void iniciaTabuleiro();
void montaTabuleiro();
char tiroEmbarcacao(char opcao, int jogador);
void jogadaTabuleiro();

char tabuleiro[20][20][2];
char pontuacao[2];

int main(){
	setlocale(LC_ALL, "Portuguese");
	char sair = 'N';
	
	montaTabuleiro();
	
	/* AQUI JÁ COMEÇA O BOM DO GAME :D */
	jogadaTabuleiro();
	
	
	system("Pause");
	  	   
}

void iniciaTabuleiro () {
  int x, y, jogador;
  
	for(jogador = 1; jogador <= 2; jogador++)
  		for(x = 0; x < 20; x++)
  			for(y = 0; y < 20; y++)
  	 			tabuleiro[x][y][jogador] = 'A';  
}

void montaTabuleiro () {
	int jogador = 1;
	
	do{	
		int posicao_1 = 0, posicao_2 = 0, fimTabuleiro = 0;
		char opcao;
		
		/* INICIA O TABULEIRO COM AGUA*/
		iniciaTabuleiro();
		
		printf("\n***** Bem vindo ao Jogo Batalha Naval *****\n");
		printf("\nJogador %d preencha seu tabuleiro \n\n", jogador);
		
		do{
			printf("\nOpção : \n S - Subimarino \t C - Couraçado \n P - Porta Avião \t R - Resgate \n\n Você pode escolher até duas opções de cada embarcação! \n");
			scanf("%c", &opcao);
			
			/* VERIFICA QUANTIDADE DE EMBARCAÇÕES */
			int verificaEmbarcacao = 0, i = 1;
			
			for(int x = 0; x < 20; x++)
			  	for(int y = 0; y < 20; y++)
			  		if(tabuleiro[x][y][jogador] == opcao)
			  			verificaEmbarcacao++;
			  
			/* MONTA O TABULEIRO DE ACORDO COM O PREENCHIMENTO DOS JOGADORES */
			
		 	if(opcao == 'S'){
		 		if(verificaEmbarcacao < 4){
			 		while(i <= 2){
			 			printf("\nDigite a %d posição da embarcação ** Submarino ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'S';
							i++;
						}  else {
							printf("\nA posição que você digitou já possui uma embarcação.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
		 		} else {
					printf("\nVocê atingiu o máximo da embarcação ** Submarino **.! \n");
				}
			} 
			
			else if(opcao == 'C'){
				if(verificaEmbarcacao < 6){
			 		while(i <= 3){
			 			printf("\nDigite a %d posição da embarcação ** Couraçado ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'C';
							i++;
						}  else {
							printf("\nA posição que você digitou já possui uma embarcação.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
				} else {
					printf("\nVocê atingiu o máximo da embarcação ** Couraçado **.! \n");
				}
			}
			
			else if(opcao == 'P'){
				if(verificaEmbarcacao < 8){
			 		while(i <= 4){
			 			printf("\nDigite a %d posição da embarcação ** Porta Avião ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'P';
							i++;
						}  else {
							printf("\nA posição que você digitou já possui uma embarcação.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
				} else {
					printf("\nVocê atingiu o máximo da embarcação ** Porta Avião **.! \n");
				}
			}
			
			else if(opcao == 'R'){
				if(verificaEmbarcacao < 2){
			 		while(i <= 1){
			 			printf("\nDigite a %d posição da embarcação ** Resgate ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'R';
							i++;
						} else {
							printf("\nA posição que você digitou já possui uma embarcação.! \n");
						}  
						system("cls");	 					
			 		}
			 		fimTabuleiro++;
				}  else {
					printf("\nVocê atingiu o máximo da embarcação ** Resgate **.! \n");
				}
			}
			
			else {
				printf("\nOpção da embarcação inválida \n");
			}
			
			fflush(stdin);
		
		}while(fimTabuleiro < 8);

		jogador++;
		
	}while(jogador <= 2);
}

char tiroEmbarcacao (char opcao, int jogador) {
	switch(opcao){
		case 'S':
			return printf("\n Parabéns Jogador %d, você atingiu a embarcação ** Submarino ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 10;
		break;
		case 'C':
			return printf("\n Parabéns Jogador %d, você atingiu a embarcação ** Couraçado ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 20;
		break;
		case 'P':
			return printf("\n Parabéns Jogador %d, você atingiu a embarcação ** Porta Avião ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 30;
		break;
		case 'R':
			return printf("\n Parabéns Jogador %d, você atingiu a embarcação ** Resgate ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 5;
		break;
		default:
			return printf("\n Ah não! Jogador %d, você atingiu ** Água **, aprimore a sua mira na proxíma jogada! %c \n", jogador, opcao);
		break;
	}
}

void jogadaTabuleiro () {
	int sair = 0, jogador = 1, i, winner;
	int posicao_1 = 0, posicao_2 = 0;
	
	/* LET'S GO A JOGADAS  */
	system("cls");
	printf("\nVocê pode desistir de jogar a qualquer momento apenas digitando a letra ** F ** na sua jogada, mais a vitoria fica com seu adversário!!! Nunca desista \n\n ");
	printf("\nVamos começar o show e destruir a todas embarcações!! \n\n ");
	
	do{
		
		i = 1;
		
		if((jogador % 2) != 0){
			/* VERIFICA SE TODAS AS EMBARCAÇÕES FORAM DESTRUIDAS QUANTIDADE DE PONTOS = 410 */
			if(pontuacao[jogador] == 410){
				winner = jogador; sair = 2;
			}
			
			/* JOGADOR 1 ATACA A EMBARCAÇÃO DA MATRIZ DO JOGADOR 2*/
			jogador++;
			
			while(i <= 2){
				printf("\nJogador %d Digite a %d posição de sua jogada: \n", jogador - 1, i);
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
						printf("\nVocê atingiu uma jogada feita anteriormente, tente novamente.! \n");
					}
					
				}
			}
			
			
		} else {
			/* VERIFICA SE TODAS AS EMBARCAÇÕES FORAM DESTRUIDAS QUANTIDADE DE PONTOS = 410 */
			if(pontuacao[jogador] == 410){
				winner = jogador; sair = 2;
			}
			
			/* JOGADOR 2 ATACA A EMBARCAÇÃO DA MATRIZ DO JOGADOR 1*/
			jogador--;
			
			while(i <= 2){
				printf("\nJogador %d Digite a %d posição de sua jogada: \n", jogador + 1, i);
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
						printf("\nVocê atingiu uma jogada feita anteriormente, tente novamente.! \n");
					}
					
				}
			}
		}
		
	}while(sair < 1);
	
	/* GANHADOR DO JOGO WINNER */
	system("cls");
	printf("\n\n****** Jogador %d Venceu a Batalha Naval parabéns pela conquista.!!!! ******** \n\n", winner);
	
}
// Correção da escrita dos metodos


