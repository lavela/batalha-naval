#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char tabuleiro[20][20][2];
char pontuacao[2];

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
		
      /* START TRAY WITH WATER*/
		iniciaTabuleiro();
		
		printf("\n***** Welcome to Game Naval Battle *****\n");
		printf("\nPlayer %d Fill in your board \n\n", jogador);
		
		do{
			printf("\nOp��o : \n S - Subimarine \t C - Couraado \n P - Aircraft carrier \t R - Rescue \n\n You can choose even two options from each boat! \n");
			scanf("%c", &opcao);
			
			/* VERIFY QUANTITY OF BOATS */
			int verificaEmbarcacao = 0, i = 1;
			
			for(int x = 0; x < 20; x++)
			  	for(int y = 0; y < 20; y++)
			  		if(tabuleiro[x][y][jogador] == opcao)
			  			verificaEmbarcacao++;
			  
			/* ASSEMBLE THE BOARD ACCORDING TO THE COMPLETION OF THE PLAYERS */
			
		 	if(opcao == 'S'){
		 		if(verificaEmbarcacao < 4){
			 		while(i <= 2){
			 			printf("\nDEnter the %d position of the vessel ** Submarine ** : \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'S';
							i++;
						}  else {
							printf("\nA position you have already entered has a vessel.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
		 		} else {
					printf("\nYou have reached the maximum of the ** Submarine ** boat.! \n");
				}
			} 
			
			else if(opcao == 'C'){
				if(verificaEmbarcacao < 6){
			 		while(i <= 3){
			 			printf("\nEnter the %d position of the vessel ** Coupling **: \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'C';
							i++;
						}  else {
							printf("\nThe position you entered already has a boat.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
				} else {
					printf("\nYou reached the maximum of the vessel ** Courageous **! \n");
				}
			}
			
			else if(opcao == 'P'){
				if(verificaEmbarcacao < 8){
			 		while(i <= 4){
			 			printf("\nEnter the %d position of the vessel ** Aircraft carrier **: \n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'P';
							i++;
						}  else {
							printf("\nThe position you entered already has a boat.! \n");
						}
						system("cls");	  					
			 		}
			 		fimTabuleiro++;
				} else {
					printf("\nYou have reached the maximum of the ship ** Aircraft carrier **.! \n");
				}
			}
			
			else if(opcao == 'R'){
				if(verificaEmbarcacao < 2){
			 		while(i <= 1){
			 			printf("\nEnter the %d position of the vessel Rescue ** **:\n", i);
			 			scanf("%d %d", &posicao_1, &posicao_2);
			 			
						if(tabuleiro[posicao_1][posicao_2][jogador] == 'A'){
							tabuleiro[posicao_1][posicao_2][jogador] = 'R';
							i++;
						} else {
							printf("\nThe position you entered already has a boat! \n");
						}  
						system("cls");	 					
			 		}
			 		fimTabuleiro++;
				}  else {
					printf("\nYou have reached the maximum of the vessel ** Rescue **.! \n");
				}
			}
			
			else {
				printf("\nOption of invading vesseln");
			}
			
			fflush(stdin);
		
		}while(fimTabuleiro < 8);

		jogador++;
		
	}while(jogador <= 2);
}

char tiroEmbarcacao(char opcao, int jogador){
	switch(opcao){
		case 'S':
			return printf("\n Congratulations Player %d, you hit the boat ** Submarine **\n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 10;
		break;
		case 'C':
			return printf("\n Congratulations Player %d, you hit the boat ** Courageous ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 20;
		break;
		case 'P':
			return printf("\n Congratulations Player %d, you hit the boat ** Aircraft Carrier ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 30;
		break;
		case 'R':
			return printf("\n Congratulations Player %d, you hit the boat ** Rescue ** \n", jogador);
			pontuacao[jogador] = pontuacao[jogador] + 5;
		break;
		default:
			return printf("\n Player %d, you have hit ** water **, sharpen your aim in the next move! %c \n", jogador, opcao);
		break;
	}
}

void jogadaTabuleiro(){
	int sair = 0, jogador = 1, i, winner;
	int posicao_1 = 0, posicao_2 = 0;
	
	/* LET'S GO TO GAMES  */
	system("cls");
	printf("\nYou can quit playing at any time by just typing the letter ** F ** in your move, but the victory is with your opponent !!! Never give up \n\n ");
	printf("\nLet's start the show and destroy all boats.!! \n\n ");
	
	do{
		
		i = 1;
		
		if((jogador % 2) != 0){
			/* CHECK IF ALL SHIPS WERE DESTROYED POINT QUANTITY = 410 */
			if(pontuacao[jogador] == 410){
				winner = jogador; sair = 2;
			}
			
			/* PLAYER 1 ATTACKS THE PLAYER MATRIX 2*/
			jogador++;
			
			while(i <= 2){
				printf("\nPlayer %d Enter %d position of your move: \n", jogador - 1, i);
				scanf("%c %c", &posicao_1, &posicao_2);
				
				/* CHECK IF PLAYER WANTS TO EXIT */
				if((char) posicao_1 == 'F' || (char)posicao_2 == 'F'){
					i = 9; winner = jogador; sair = 9;
				} else {

					if(tabuleiro[posicao_1][posicao_2][jogador] != '*'){
						tiroEmbarcacao(tabuleiro[posicao_1][posicao_2][jogador], jogador - 1);
						
						tabuleiro[posicao_1][posicao_2][jogador] = '*';
						i++;
					} else {
						printf("\nYou have reached a previous move, try again..! \n");
					}
					
				}
			}
			
			
		} else {
			/* CHECK IF ALL SHIPS WERE DESTROYED POINT QUANTITY = 410 */
			if(pontuacao[jogador] == 410){
				winner = jogador; sair = 2;
			}
			
			/* PLAYER 2 ATTACKS THE PLAYER MATRIX PITCH 1*/
			jogador--;
			
			while(i <= 2){
				printf("\nPlayer %d Enter %d position of your move: \n", jogador + 1, i);
				scanf("%c %c", &posicao_1, &posicao_2);
				
				/* CHECK IF PLAYER WANTS TO EXIT */
				if((char) posicao_1 == 'F' || (char) posicao_2 == 'F'){
					i = 9; winner = jogador; sair = 9;
				} else {
					
					if(tabuleiro[posicao_1][posicao_2][jogador] != '*'){
						tiroEmbarcacao(tabuleiro[posicao_1][posicao_2][jogador], jogador + 1);
						
						tabuleiro[posicao_1][posicao_2][jogador] = '*';
						i++;
					} else {
						printf("\nYou have reached a previous move, try again.! \n");
					}
					
				}
			}
		}
		
	}while(sair < 1);
	
	/* WINNER GAME WINNER */
	system("cls");
	printf("\n\n****** Player %d Won the Naval Battle congratulations to the achievement.!!!! ******** \n\n", winner);
	
}

int main(){
	setlocale(LC_ALL, "English");
	char sair = 'N';
	
	montaTabuleiro();
	
	/* HERE J EAT THE GOOD OF THE GAME: D */
	jogadaTabuleiro();
	
	
	system("Pause");
	  	   
}


