#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "struct_test.c"
#include "Menu.c"

/*
ATALHOS �TEIS:

Alt + setinha = move blocos de c�digo.
shift + alt + setinha = duplicar uma linha.
Ctrl + d = seleciona v�rias palavras iguais para serem mudadas ao mesmo tempo.
Ctrl + ; = comenta um bloco de c�digo.
Ctrl + Alt + N = compila e executa o c�digo.
*/

void game_title();
void introduction_text();
void first_map();
void second_map();
void third_map();

//----------------------------MAIN------------------------------------
int main(){	
	struct game_text level1_completed;
	struct game_text courage;

	strcpy(level1_completed.text, "LEVEL 1 COMPLETED");
	level1_completed.length = strlen(level1_completed.text);

	char name[15];
	char lista[3][40] = {"> Play", "> Tutorial", "> Exit"};
	int i, opc;

	// first_map();
	// second_map();
	third_map();
	textColor(YELLOW, _BLACK);
    game_title();

	system("cls");
	printf("Enter your name: ");
	scanf("%s", &name);
	fflush(stdin);

	system("cls");
	
	printf("Now prove your courage, %s...", name);
	Sleep(2000);

	while(1){

		opc = menu(10, 10, 3, lista);

        if(opc == 0){
			break;
        } 
		else if(opc == 1){
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

		} 
		else if(opc == 2){
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
		} 
		else if(opc == 3){
			system("cls");
			printf("leaving");

			for(i = 0; i < 3; i++){
				printf(".");
				Sleep(400);
			}

			Sleep(1000);
			break;
		}
	}
	textColor(WHITE, _BLACK);

	return 0;
}

//t�tulo do game.
void game_title(){

		

		system("cls");
		printf(" ______   _______           _______  _        ______         _______  _______  _______ _________ _______  _______ _________ \n");
    	printf("(  ___ \\ (  ____ \\|\\     /|(  ___  )( (    /|(  __  \\       (  ____ )(  ____ )(  ___  )\\__    _/(  ____ \\(  ____ \\\\__   __/\n");
    	printf("| (   ) )| (    \\/( \\   / )| (   ) ||  \\  ( || (  \\  )      | (    )|| (    )|| (   ) |   )  (  | (    \\/| (    \\/   ) (   \n");
    	printf("| (__/ / | (__     \\ (_) / | |   | ||   \\ | || |   ) |      | (____)|| (____)|| |   | |   |  |  | (__    | |         | |   \n");
    	printf("|  __ (  |  __)     \\   /  | |   | || (\\ \\) || |   | |      |  _____)|     __)| |   | |   |  |  |  __)   | |         | |   \n");
    	printf("| (  \\ \\ | (         ) (   | |   | || | \\   || |   ) |      | (      | (\\ (   | |   | |   |  |  | (      | |         | |   \n");
    	printf("| )___) )| (____/\\   | |   | (___) || )  \\  || (__/  )      | )      | ) \\ \\__| (___) ||\\_)  )  | (____/\\| (____/\\   | |   \n");
    	printf("|/ \\___/ (_______/   \\_/   (_______)|/    )_)(______/       |/       |/   \\__/(_______)(____/   (_______/(_______/   )_(   \n");
    	printf("                                                                                                                           \n");

		printf("\n");

		printf("                                                  >> Press start to continue <<");
		getch();
}

//texto que inicializa a hist�ria do jogo.
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

			textColor(MAGENTA, _BLACK);
			
            for(y = 0; y < 15; y++){
				for(x = 0; x < 15; x++){
		  		    if(x == player.coord_x && y == player.coord_y){	
						textColor(CYAN, _BLACK);
				  	   	printf("  &");
						textColor(MAGENTA, _BLACK);
			        } else {
						printf("  %c", mapa[y][x]);	
					}

	            }
				printf("\n\n");
            }

			textColor(YELLOW, _BLACK);
			
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

			textColor(MAGENTA, _BLACK);

            for(y = 0; y < 30; y++){
				for(x = 0; x < 30; x++){
		  		    if(x == player.coord_x && y == player.coord_y){		
					   		textColor(CYAN, _BLACK);
				  	   		printf("  &");
							textColor(MAGENTA, _BLACK);
			        } else if (x == monster.coord_x && y == monster.coord_y) {
	  		 		   	 	printf("  V");
 	          		} else {
							printf("  %c", mapa[y][x]);
					}
	            }
				printf("\n");
            }

			textColor(YELLOW, _BLACK);

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


void monsterXMovement(char mapa[60][60], struct monster monster, int* ptr_monster_x, int* ptr_monster_y, struct monster monster1, struct monster monster2, struct monster monster3, struct monster monster4)
{
	int colisaoMonstro1 = monster.coord_y == monster1.coord_y && monster.coord_x == monster1.coord_y;
	int colisaoMonstro2 = monster.coord_y == monster2.coord_y && monster.coord_x == monster2.coord_y;
	int colisaoMonstro3 = monster.coord_y == monster3.coord_y && monster.coord_x == monster3.coord_y;
	int colisaoMonstro4 = monster.coord_y == monster4.coord_y && monster.coord_x == monster4.coord_y;

	


	int naoColisaoCima =mapa[monster.coord_y-1][monster.coord_x] != '*' && mapa[monster.coord_y-1][monster.coord_x] != 'D' && mapa[monster.coord_y-1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '=';
	int naoColisaoBaixo = mapa[monster.coord_y+1][monster.coord_x] != '*' && mapa[monster.coord_y+1][monster.coord_x] != 'D' && mapa[monster.coord_y+1][monster.coord_x] != '#' && mapa[monster.coord_y+1][monster.coord_x] != '=';
	int naoColisaoDireita =mapa[monster.coord_y][monster.coord_x+1] != '*' && mapa[monster.coord_y][monster.coord_x+1] != 'D' && mapa[monster.coord_y][monster.coord_x+1] != '#' && mapa[monster.coord_y][monster.coord_x+1] != '=';
	int naoColisaoEsquerda = mapa[monster.coord_y][monster.coord_x-1] != '*' && mapa[monster.coord_y][monster.coord_x-1] != 'D' && mapa[monster.coord_y][monster.coord_x-1] != '#' && mapa[monster.coord_y][monster.coord_x-1] != '=';

	monster.movement_keys = rand() % 4;
		
	switch(monster.movement_keys){

		case 0:
			if(naoColisaoCima){
				*ptr_monster_y -= 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_y += 1;
			}
			break;
				  
		case 1:
			if(naoColisaoBaixo){
				*ptr_monster_y += 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_y -= 1;
			}
			break;
				  
		case 2:
			if(naoColisaoDireita){
				*ptr_monster_x += 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_x -= 1;
			}
			break;
				  
		case 3:
			if(naoColisaoEsquerda){
				*ptr_monster_x -= 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_x += 1;
			}
			break;

		 	}
}

void monsterVmovement(char mapa[60][60], struct monster monster, int* ptr_monster_x, int* ptr_monster_y, struct player player, struct monster monster1, struct monster monster2, struct monster monster3, struct monster monster4){
	int colisaoMonstro1 = monster.coord_y == monster1.coord_y && monster.coord_x == monster1.coord_y;
	int colisaoMonstro2 = monster.coord_y == monster2.coord_y && monster.coord_x == monster2.coord_y;
	int colisaoMonstro3 = monster.coord_y == monster3.coord_y && monster.coord_x == monster3.coord_y;
	int colisaoMonstro4 = monster.coord_y == monster4.coord_y && monster.coord_x == monster4.coord_y;

	


	int naoColisaoCima =mapa[monster.coord_y-1][monster.coord_x] != '*' && mapa[monster.coord_y-1][monster.coord_x] != 'D' && mapa[monster.coord_y-1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '=';
	int naoColisaoBaixo = mapa[monster.coord_y+1][monster.coord_x] != '*' && mapa[monster.coord_y+1][monster.coord_x] != 'D' && mapa[monster.coord_y+1][monster.coord_x] != '#' && mapa[monster.coord_y+1][monster.coord_x] != '=';
	int naoColisaoDireita =mapa[monster.coord_y][monster.coord_x+1] != '*' && mapa[monster.coord_y][monster.coord_x+1] != 'D' && mapa[monster.coord_y][monster.coord_x+1] != '#' && mapa[monster.coord_y][monster.coord_x+1] != '=';
	int naoColisaoEsquerda = mapa[monster.coord_y][monster.coord_x-1] != '*' && mapa[monster.coord_y][monster.coord_x-1] != 'D' && mapa[monster.coord_y][monster.coord_x-1] != '#' && mapa[monster.coord_y][monster.coord_x-1] != '=';

	if (monster.coord_x > player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)){
		monster.movement_keys = 3;
	} else if (monster.coord_x < player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)) {
		monster.movement_keys = 2;
	} else if (monster.coord_y > player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){
		monster.movement_keys = 0;
	} else if (monster.coord_y < player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){
		monster.movement_keys = 1;
	}

		
	switch(monster.movement_keys){

		case 0:
			if(naoColisaoCima){
				*ptr_monster_y -= 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_y += 1;
			}
			break;
				  
		case 1:
			if(naoColisaoBaixo){
				*ptr_monster_y += 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_y -= 1;
			}
			break;
				  
		case 2:
			if(naoColisaoDireita){
				*ptr_monster_x += 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_x -= 1;
			}
			break;
				  
		case 3:
			if(naoColisaoEsquerda){
				*ptr_monster_x -= 1;
			}
			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4) {
				*ptr_monster_x += 1;
			}
			break;

		 	}
}

void third_map(){
	int i, j;
	int y, x;
	struct monster monsterX1;
	monsterX1.coord_x = 38;
	monsterX1.coord_y = 10;
	int *ptr_monsterX_x1 = &monsterX1.coord_x;
	int *ptr_monsterX_y1 = &monsterX1.coord_y;

	struct monster monsterX2;
	monsterX2.coord_x = 38;
	monsterX2.coord_y = 15;
	int *ptr_monsterX_x2 = &monsterX2.coord_x;
	int *ptr_monsterX_y2 = &monsterX2.coord_y;

	struct monster monsterX3;
	monsterX3.coord_x = 46;
	monsterX3.coord_y = 20;
	int *ptr_monsterX_x3 = &monsterX3.coord_x;
	int *ptr_monsterX_y3 = &monsterX3.coord_y;



	struct monster monsterV1;
	monsterV1.coord_x = 20;
	monsterV1.coord_y = 18;
	int *ptr_monsterV_x1 = &monsterV1.coord_x;
	int *ptr_monsterV_y1 = &monsterV1.coord_y;

	struct monster monsterV2;
	monsterV2.coord_x = 42;
	monsterV2.coord_y = 51;
	int *ptr_monsterV_x2 = &monsterV2.coord_x;
	int *ptr_monsterV_y2 = &monsterV2.coord_y;

	struct player player;
	player.coord_x = 5;
	player.coord_y = 5;
	player.HP = 3;



	char mapa[60][60] = {{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ','<','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','*','*',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*',' ','*','*','*',' ',' ',' ',' ',' ','#','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ',' ','*',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*',' ',' ','*',' ','#','#','#',' ',' ',' ','#','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ','#','#','#',' ',' ',' ','#','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ','*','*','*','*','*','*','*','*','*','*','*',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ','*',' ','@',' ',' ','*','*','*','#','#','#','#','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','#','#','#','#','#','#','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','#','#','#','#','#','#','#','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ','#','#','#','#','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#','#','#','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#','#','#',' ',' ',' ','#','#',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','#','#',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ','>','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ','V',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*',' ',' ','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ','O',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        				 {'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}};


	int coordenadaMonstroX1;
	int coordenadaMonstroX2;
	int coordenadaMonstroX3;
	int coordenadaMonstroV1;
	int coordenadaMonstroV2;

	int alcanceCamera = 10;




	while(mapa[player.coord_y][player.coord_x] != '='){

			system("cls");

			textColor(MAGENTA, _BLACK);

            for(y = player.coord_y-alcanceCamera; y < player.coord_y+alcanceCamera ; y++){
				for(x = player.coord_x-alcanceCamera; x < player.coord_x+alcanceCamera; x++){

					coordenadaMonstroX1 = y == monsterX1.coord_y && x == monsterX1.coord_x;
					coordenadaMonstroX2 = y == monsterX2.coord_y && x == monsterX2.coord_x;
					coordenadaMonstroX3 = y == monsterX3.coord_y && x == monsterX3.coord_x;
					coordenadaMonstroV1 = y == monsterV1.coord_y && x == monsterV1.coord_x;
					coordenadaMonstroV2 = y == monsterV2.coord_y && x == monsterV2.coord_x;



		  		    if(x == player.coord_x && y == player.coord_y){		
					   	textColor(CYAN, _BLACK);
				  	   	printf("  &");
						textColor(MAGENTA, _BLACK);
			        } else if (coordenadaMonstroX1 || coordenadaMonstroX2 || coordenadaMonstroX3) {
	  		 		   	printf("  X");
 	          		} else if (coordenadaMonstroV1 || coordenadaMonstroV2){
						printf("  V");
					} else {
						printf("  %c", mapa[y][x]);
					}
	            }
				printf("\n");
            }

			textColor(YELLOW, _BLACK);





	monsterXMovement(mapa, monsterX1, ptr_monsterX_x1, ptr_monsterX_y1, monsterV1, monsterV2, monsterX2, monsterX3);
	monsterXMovement(mapa, monsterX2, ptr_monsterX_x2, ptr_monsterX_y2, monsterV1, monsterV2, monsterX1, monsterX3);
	monsterXMovement(mapa, monsterX3, ptr_monsterX_x3, ptr_monsterX_y3, monsterV1, monsterV2, monsterX2, monsterX3);
	monsterVmovement(mapa, monsterV1, ptr_monsterV_y1, ptr_monsterV_y1, player, monsterX1, monsterV2, monsterX2, monsterX3);
	monsterVmovement(mapa, monsterV2, ptr_monsterV_y2, ptr_monsterV_y2, player, monsterX1, monsterV1, monsterX2, monsterX3);

	



//----------------------------------------------MONSTRO NIVEL II----------------------------------------------------------------------------------

			// if (monster.coord_x > player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)){

			// 	if (mapa[monster.coord_y][monster.coord_x-1] != '*' && mapa[monster.coord_y][monster.coord_x-1] != '#' && mapa[monster.coord_y][monster.coord_x-1] != 'D')
			// 		monster.coord_x -= 1;

			// 	if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
			// 		player.coord_x = 1, player.coord_y = 1;
			// 		player.HP--;
			// 	}

			// } else if (monster.coord_x < player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)){

			// 	if (mapa[monster.coord_y][monster.coord_x+1] != '*' && mapa[monster.coord_y][monster.coord_x+1] != '#' && mapa[monster.coord_y][monster.coord_x+1] != 'D')
			// 		monster.coord_x += 1;

			// 	if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
			// 		player.coord_x = 1, player.coord_y = 1;
			// 		player.HP--;
			// 	}

			// } else if (monster.coord_y > player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){

			// 	if (mapa[monster.coord_y-1][monster.coord_x] != '*' && mapa[monster.coord_y-1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != 'D')
			// 		monster.coord_y -= 1;

			// 	if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
			// 		player.coord_x = 1, player.coord_y = 1;
			// 		player.HP--;
			// 	}

			// } else if (monster.coord_y < player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){

			// 	if (mapa[monster.coord_y+1][monster.coord_x] != '*' && mapa[monster.coord_y+1][monster.coord_x] != '#' && mapa[monster.coord_y+1][monster.coord_x] != 'D')
			// 		monster.coord_y += 1;

			// 	if (monster.coord_x == player.coord_x && monster.coord_y == player.coord_y){
			// 		player.coord_x = 1, player.coord_y = 1;
			// 		player.HP--;
			// 	}
			// }

			//----------------------------------------PLAYER------------------------------------------------------------

			int colisaoMonstro1 = player.coord_y == monsterX1.coord_y && player.coord_x == monsterX1.coord_x;
			int colisaoMonstro2 = player.coord_y == monsterX2.coord_y && player.coord_x == monsterX2.coord_x;
			int colisaoMonstro3 = player.coord_y == monsterX3.coord_y && player.coord_x == monsterX3.coord_x;
			int colisaoMonstro4 = player.coord_y == monsterV1.coord_y && player.coord_x == monsterV1.coord_x;
			int colisaoMonstro5 = player.coord_y == monsterV2.coord_y && player.coord_x == monsterV2.coord_x;

			if (colisaoMonstro1 || colisaoMonstro2 || colisaoMonstro3 || colisaoMonstro4 || colisaoMonstro5) {
				player.HP--;
				player.coord_x = 5;
				player.coord_y = 5;
			}

            
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
						// monster.coord_y = 16; monster.coord_x = 12;
					}
				}
				continue;
			}
	}

}
