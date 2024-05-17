#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "struct_test.c"

/*
ATALHOS ÚTEIS:

Alt + setinha = move blocos de código.
shift + alt + setinha = duplicar uma linha.
Ctrl + d = seleciona várias palavras iguais para serem mudadas ao mesmo tempo.
Ctrl + ; = comenta um bloco de código.
Ctrl + Alt + N = compila e executa o código.
*/

void game_title();
void introduction_text();
void first_map();
void second_map();

//----------------------------MAIN------------------------------------
int main()
{	
	struct game_text level1_completed;

	strcpy(level1_completed.text, "LEVEL 1 COMPLETED");
	level1_completed.length = strlen(level1_completed.text);

	char name[15];
	char menu_selection[10];
	int loop = 1;
	int i;

	//first_map();
	//second_map();

    game_title();

	system("cls");
	printf("Enter your name: ");
	scanf("%s", &name);
	fflush(stdin);

	system("cls");
	printf("Now prove your courage, %s...", name);
	Sleep(2000);

	while(loop){

        system("cls");
		printf("> Play\n");
		printf("> Tutorial\n");
		printf("> Exit\n\n");
		printf("Select an option: ");
        fflush(stdin);
		scanf("%s", &menu_selection);

        if(strcmp(menu_selection, "play") == 0 || strcmp(menu_selection, "Play") == 0 || strcmp(menu_selection, "PLAY") == 0){
		    system("cls");
		
		    introduction_text();
		    getch();

            first_map();
			system("cls");

			for(i = 0; i < level1_completed.length; i++){
				printf("%c", level1_completed.text[i]);
				Sleep(60);
			}
			printf("\n\n");
            printf(">>Press any key to continue<<");
            getch();
			printf("\n");

			system("cls");
			printf("Loading next level");

			for(i = 0; i < 3; i++){
				printf(".");
				Sleep(400);
			}

			Sleep(1000);

			second_map();
			system("cls");
			printf("LEVEL 2 COMPLETED");
			printf("\n\n");
            printf(">>Press any key to continue<<");
			getch();

        } else if(strcmp(menu_selection, "Tutorial") == 0 || strcmp(menu_selection, "tutorial") == 0 || strcmp(menu_selection, "TUTORIAL") == 0){
			system("cls");
			printf("> Basic movements:                 > During the game:\n\n");

			printf("W - to move forward                # - Spikes: Be careful, or you will die if you touch it.\n");
			printf("A - to move left                   @ - Keys: You have to collect them if you want to conclude the dungeon.\n");
			printf("S - to move backward               X - Level 1 monster: It moves randomly everytime you make a move.\n");
			printf("D - to move right                  V - Level 2 monster: It will chase you around the dungeon ignoring anything in it\'s way.\n");
			printf("I - to interact with something     D - Doors: Only can be opened if you have a key.\n");
			printf("                                   O - Button: Press to intereact with the map.\n");
			printf("                                   = - Open door: You can pass through it.\n\n");

			printf("                    >> Press any key to go back <<");
			getch();
			continue;

		} else if(strcmp(menu_selection, "Exit") == 0 || strcmp(menu_selection, "exit") == 0 || strcmp(menu_selection, "EXIT") == 0){
			system("cls");

			printf("leaving");

			for(i = 0; i < 3; i++){
			printf(".");
			Sleep(400);
			}

			Sleep(1000);
			break;

		} else {

			system("cls");
			printf("Invalid option. Try again.");
			getch();
			continue;

		}
		
		break;
	}
	
	return 0;
}

//título do game.
void game_title(){
	
	int i;
	char title[] = "DUNGEON\'S CLAWS";
	int length = strlen(title);
	
	system("cls");
	printf("----------------------------\n");
	printf("      ");
	
	for(i = 0; i < length; i++){
		printf("%c", title[i]);
		Sleep(100);
	}
	
	printf("\n");
	printf("----------------------------\n\n");
	
	printf(">> Press start to continue <<");
	getch();
}

//texto que inicializa a história do jogo.
void introduction_text(){
	
	struct game_text p1;
	struct game_text p2;

    int i;

    strcpy(p1.text, "During the great war, many warriors died\nfighting on the battle fields.");
	fflush(stdin);
	strcpy(p2.text, "The ruins of this dark past\nremain inside the dungeons.");
	fflush(stdin);

    p1.length = strlen(p1.text);

    for(i = 0; i <= p1.length; i++){
    	printf("%c", p1.text[i]);
        Sleep(60);
    }

	system("cls");

	p2.length = strlen(p2.text);

	for(i = 0; i <= p2.length; i++){
		printf("%c", p2.text);
		Sleep(60);
	}
	Sleep(1000);
}

//mapa 1.
void first_map(){

	struct player player;
	struct monster monster;

	player.coord_x = 1; player.coord_y = 1;
	//monster.coord_x = 5; monster.coord_y = 10;
	player.HP = 3;
	int key = 0;
	int x, y;
	char mapa[15][15] = {{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
 		 			  	 {'*', ' ', '*', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*'},
        		 		 {'*', ' ', '*', ' ', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', '*'},
		         		 {'*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
		         		 {'*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', '*', ' ', '*', ' ', '*'},
		         		 {'*', '*', '*', '*', '*', '*', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
		         		 {'*', '*', '*', '*', '*', ' ', '#', ' ', '*', ' ', '*', ' ', '*', ' ', '*'},
		         		 {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', '*', '*'},
		         		 {'*', ' ', '*', '@', '*', '#', ' ', '#', '*', ' ', '*', ' ', ' ', ' ', '*'},
		         		 {'*', ' ', '*', '#', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'},
		         		 {'*', ' ', '*', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '*'},
		         		 {'*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*', '*', '*', '*', '*'},
		         		 {'*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*'},
		         		 {'*', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*'},
		         		 {'*', '*', '*', '*', '*', 'D', '*', '*', '*', '*', '*', '*', '*', '*', '*'}};
 				         		 
	while(mapa[player.coord_y][player.coord_x] != '='){

			system("cls");

			printf("\033[0;34m");
			
            for(y = 0; y < 15; y++){
				for(x = 0; x < 15; x++){
		  		    if(x == player.coord_x && y == player.coord_y){	
						printf("\033[1;36m");
				  	   	printf("  &");
						printf("\033[0;34m");
			        } else {
						printf("  %c", mapa[y][x]);	
					}

	            }
				printf("\n\n");
            }

			printf("\033[0m");
			
//----------------------------------------------MONSTRO----------------------------------------------------------------------------------

			// monster.movement_keys = rand() % 4;
		
		    // switch(monster.movement_keys){

			// 	  case 0:
			// 	  	if(mapa[monster.coord_y-1][monster.coord_x] != '*' && mapa[monster.coord_y-1][monster.coord_x] != 'D' && mapa[monster.coord_y-1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){
			// 				monster.coord_y--;
			// 			}
			// 	  break;
				  
			// 	  case 1:
			// 	  	if(mapa[monster.coord_y+1][monster.coord_x] != '*' && mapa[monster.coord_y+1][monster.coord_x] != 'D' && mapa[monster.coord_y+1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){							
			// 				monster.coord_y++;
			// 			}
			// 	  break;
				  
			// 	  case 2:
			// 	  	if(mapa[monster.coord_y][monster.coord_x+1] != '*' && mapa[monster.coord_y][monster.coord_x+1] != 'D' && mapa[monster.coord_y][monster.coord_x+1] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){
			// 				monster.coord_x++;
			// 			}
			// 	  break;
				  
			// 	  case 3:
			// 	  	if(mapa[monster.coord_y][monster.coord_x-1] != '*' && mapa[monster.coord_y][monster.coord_x-1] != 'D' && mapa[monster.coord_y][monster.coord_x-1] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){
			// 				monster.coord_x--;
			// 			}
			// 	  break;

		 	// }

			//----------------------------------------PLAYER------------------------------------------------------------
            
		    player.movement_keys = toupper(getch());
		
		    switch(player.movement_keys){

				  case 'W':
				  	if(mapa[player.coord_y-1][player.coord_x] != '*' && mapa[player.coord_y-1][player.coord_x] != 'D'){
						if(mapa[player.coord_y-1][player.coord_x] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;
						} else {
							player.coord_y--;
						}
					}
				  break;
				  
				  case 'S':
				  	if(mapa[player.coord_y+1][player.coord_x] != '*' && mapa[player.coord_y+1][player.coord_x] != 'D'){
				  		if(mapa[player.coord_y+1][player.coord_x] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;							
						} else {
							player.coord_y++;
						}
					  }
				  break;
				  
				  case 'D':
				  	if(mapa[player.coord_y][player.coord_x+1] != '*' && mapa[player.coord_y][player.coord_x+1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x+1] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;
						} else {
							player.coord_x++;
						}
					  }
				  break;
				  
				  case 'A':
				  	if(mapa[player.coord_y][player.coord_x-1] != '*' && mapa[player.coord_y][player.coord_x-1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x-1] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;
						} else {
							player.coord_x--;
						}
					  }
				  break;

				  case 'I':
				  	if(mapa[player.coord_y][player.coord_x] == '@'){
						mapa[8][3] = ' ';
						mapa[14][5] = '=';
					} else {
						mapa[player.coord_y][player.coord_x];
					}
				  break;			
		 	}

			if(player.HP == 0){
				system("cls");
				printf("GAME OVER\n\n");
				printf("\"Just courage wasn\'t enough...\"\n\n");
				printf(">> Press any key to try again <<");
				getch();
				player.HP = 3;
				
				if(mapa[14][5] == '='){
					if(mapa[8][3] == ' '){
						mapa[8][3] = '@';
						mapa[14][5] = 'D';
					}
				}
				continue;
			}
	}
}

//mapa 2.
void second_map(){

	struct monster monster;
	struct player player;

	player.coord_y = 1; monster.coord_y = 16;
	player.coord_x = 1; monster.coord_x = 12;
	player.HP = 3;
	int x, y;

	char mapa[30][30] = {{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', '#', ' ', ' ', '#', '#', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*'},
                         {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'D', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', 'D', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*'},
                         {'*', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '@', '*', '*'},
                         {'*', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*'},
                         {'*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}};


	while(mapa[player.coord_y][player.coord_x] != '='){

			system("cls");

			printf("\033[0;34m");

            for(y = 0; y < 30; y++){
				for(x = 0; x < 30; x++){
		  		    if(x == player.coord_x && y == player.coord_y){		
					   		printf("\033[1;36m");
				  	   		printf("  &");
							printf("\033[0;34m");
			        } else if (x == monster.coord_x && y == monster.coord_y) {
	  		 		   	 	printf("  V");
 	          		} else {
							printf("  %c", mapa[y][x]);
					}
	            }
				printf("\n\n");
            }

			printf("\033[0m");

//----------------------------------------------MONSTRO----------------------------------------------------------------------------------

			if (monster.coord_x > player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)){

				if (mapa[monster.coord_y][monster.coord_x-1] != '*' && mapa[monster.coord_y][monster.coord_x-1] != '#' && mapa[monster.coord_y][monster.coord_x-1] != 'D')
					monster.coord_x -= 1;

				if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
					player.coord_x = 1, player.coord_y = 1;
					player.HP--;
				}

			} else if (monster.coord_x < player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)){

				if (mapa[monster.coord_y][monster.coord_x+1] != '*' && mapa[monster.coord_y][monster.coord_x+1] != '#' && mapa[monster.coord_y][monster.coord_x+1] != 'D')
					monster.coord_x += 1;

				if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
					player.coord_x = 1, player.coord_y = 1;
					player.HP--;
				}

			} else if (monster.coord_y > player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){

				if (mapa[monster.coord_y-1][monster.coord_x] != '*' && mapa[monster.coord_y-1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != 'D')
					monster.coord_y -= 1;

				if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
					player.coord_x = 1, player.coord_y = 1;
					player.HP--;
				}

			} else if (monster.coord_y < player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){

				if (mapa[monster.coord_y+1][monster.coord_x] != '*' && mapa[monster.coord_y+1][monster.coord_x] != '#' && mapa[monster.coord_y+1][monster.coord_x] != 'D')
					monster.coord_y += 1;

				if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
					player.coord_x = 1, player.coord_y = 1;
					player.HP--;
				}
			}

			//----------------------------------------PLAYER------------------------------------------------------------
            
		    player.movement_keys = toupper(getch());
		
		    switch(player.movement_keys){

				  case 'W':
				  	if(mapa[player.coord_y-1][player.coord_x] != '*' && mapa[player.coord_y-1][player.coord_x] != 'D'){
						if(mapa[player.coord_y-1][player.coord_x] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;
						} else {
							player.coord_y--;
						}
					}
				  break;
				  
				  case 'S':
				  	if(mapa[player.coord_y+1][player.coord_x] != '*' && mapa[player.coord_y+1][player.coord_x] != 'D'){
				  		if(mapa[player.coord_y+1][player.coord_x] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;							
						} else {
							player.coord_y++;
						}
					  }
				  break;
				  
				  case 'D':
				  	if(mapa[player.coord_y][player.coord_x+1] != '*' && mapa[player.coord_y][player.coord_x+1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x+1] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;
						} else {
							player.coord_x++;
						}
					  }
				  break;
				  
				  case 'A':
				  	if(mapa[player.coord_y][player.coord_x-1] != '*' && mapa[player.coord_y][player.coord_x-1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x-1] == '#'){
							player.coord_x = 1, player.coord_y = 1;
							player.HP--;
						} else {
							player.coord_x--;
						}
					  }
				  break;

				  case 'I':
				  	if(mapa[player.coord_y][player.coord_x] == '@'){
						mapa[26][27] = ' ';
						mapa[16][0] = '=';
						mapa[16][13] = '='; 

					} else if(mapa[player.coord_y][player.coord_x] == 'O'){
						mapa[27][26] = ' ';
						mapa[26][26] = ' ';
						mapa[25][26] = ' ';
						mapa[27][28] = ' ';
						mapa[26][28] = ' ';
						mapa[25][28] = ' ';
						mapa[27][27] = ' ';
						mapa[25][27] = ' ';
					} else{
						mapa[player.coord_y][player.coord_x];
					}
				  break;			
		 	}

			if(player.HP == 0){
				system("cls");
				printf("GAME OVER\n\n");
				printf(">> Press any key to try again <<");
				getch();
				player.HP = 3;
				
				if(mapa[16][0] == '='){
					if(mapa[26][27] == ' '){
						mapa[26][27] = '@';
						mapa[16][0] = 'D';
						monster.coord_y = 16; monster.coord_x = 12;
					}
				}
				continue;
			}
	}
}
