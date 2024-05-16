#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "struct_test.c"

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
int first_map();
int second_map();

//----------------------------MAIN------------------------------------
int main()
{	

	char name[15];
	char menu_selection[10];
	int loop = 1;
	int i;

	second_map();

    // game_title();

	// system("cls");
	// printf("Enter your name: ");
	// scanf("%s", &name);
	// fflush(stdin);

	// system("cls");
	// printf("Now prove your courage, %s...", name);
	// Sleep(2000);

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

            if(first_map()){
                printf("CONGRATS!!!\n\n");
                getch();
            }

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

//t��tulo do game.
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

	getch();

}

//mapa 1.
int first_map(){

	struct player player;
	struct monster monster;

	player.coord_x = 1; player.coord_y = 1;
	monster.coord_x = 5; monster.coord_y = 10;
	int key = 0;
    int HP = 3;
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

            for(y = 0; y < 15; y++){
				  for(x = 0; x < 15; x++){
		  		       if(x == player.coord_x && y == player.coord_y){		
				  	   printf("  &");
			           } else if (x == monster.coord_x && y == monster.coord_y) {
	  		 		   	 	printf("  X");
 	          		     } else {
							printf("  %c", mapa[y][x]);
						 }

	              }
				   printf("\n\n");
            }
//----------------------------------------------MONSTRO----------------------------------------------------------------------------------

			monster.movement_keys = rand() % 4;
		
		    switch(monster.movement_keys){

				  case 0:
				  	if(mapa[monster.coord_y-1][monster.coord_x] != '*' && mapa[monster.coord_y-1][monster.coord_x] != 'D' && mapa[monster.coord_y-1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){
							monster.coord_y--;
						}
				  break;
				  
				  case 1:
				  	if(mapa[monster.coord_y+1][monster.coord_x] != '*' && mapa[monster.coord_y+1][monster.coord_x] != 'D' && mapa[monster.coord_y+1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){							
							monster.coord_y++;
						}
				  break;
				  
				  case 2:
				  	if(mapa[monster.coord_y][monster.coord_x+1] != '*' && mapa[monster.coord_y][monster.coord_x+1] != 'D' && mapa[monster.coord_y][monster.coord_x+1] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){
							monster.coord_x++;
						}
				  break;
				  
				  case 3:
				  	if(mapa[monster.coord_y][monster.coord_x-1] != '*' && mapa[monster.coord_y][monster.coord_x-1] != 'D' && mapa[monster.coord_y][monster.coord_x-1] != '#' && mapa[monster.coord_y-1][monster.coord_x] != '='){
							monster.coord_x--;
						}
				  break;

		 	}

			//----------------------------------------PLAYER------------------------------------------------------------
            
		    player.movement_keys = toupper(getch());
		
		    switch(player.movement_keys){

				  case 'W':
				  	if(mapa[player.coord_y-1][player.coord_x] != '*' && mapa[player.coord_y-1][player.coord_x] != 'D'){
						if(mapa[player.coord_y-1][player.coord_x] == '#' || player.coord_y-1 == monster.coord_y && player.coord_x == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;
						} else {
							player.coord_y--;
						}
					}
				  break;
				  
				  case 'S':
				  	if(mapa[player.coord_y+1][player.coord_x] != '*' && mapa[player.coord_y+1][player.coord_x] != 'D'){
				  		if(mapa[player.coord_y+1][player.coord_x] == '#' || player.coord_y+1 == monster.coord_y && player.coord_x == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;							
						} else {
							player.coord_y++;
						}
					  }
				  break;
				  
				  case 'D':
				  	if(mapa[player.coord_y][player.coord_x+1] != '*' && mapa[player.coord_y][player.coord_x+1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x+1] == '#' || player.coord_y == monster.coord_y && player.coord_x+1 == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;
						} else {
							player.coord_x++;
						}
					  }
				  break;
				  
				  case 'A':
				  	if(mapa[player.coord_y][player.coord_x-1] != '*' && mapa[player.coord_y][player.coord_x-1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x-1] == '#' || player.coord_y == monster.coord_y && player.coord_x-1 == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;
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

			if(HP == 0){
				system("cls");
				printf("GAME OVER\n\n");
				printf(">> Press any key to try again <<");
				getch();
				HP = 3;
				
				if(mapa[14][5] == '='){
					if(mapa[8][3] == ' '){
						mapa[8][3] = '@';
						mapa[14][5] = 'D';
						monster.coord_y = 11; monster.coord_x = 5;
					}
				}
				continue;
			}
	}

	system("cls");
	printf("LEVEL 1 COMPLETED\n\n");
	printf("CONGRATULATIONS!!!!!");
	getch();

    return 0;
}

//mapa 2.
int second_map(){

	struct monster monster;
	struct player player;

	player.coord_y = 1; monster.coord_y = 16;
	player.coord_x = 2; monster.coord_x = 12;
	int x, y;
	int HP = 3;

	char mapa[30][30] = {{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
                         {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'o', ' ', '*'},
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

            for(y = 0; y < 30; y++){
				  for(x = 0; x < 30; x++){
		  		       if(x == player.coord_x && y == player.coord_y){		
				  	   printf("  &");
			           } else if (x == monster.coord_x && y == monster.coord_y) {
	  		 		   	 	printf("  V");
 	          		     } else {
							printf("  %c", mapa[y][x]);
						 }

	              }
				   printf("\n");
            }
//----------------------------------------------MONSTRO----------------------------------------------------------------------------------

			if (monster.coord_x > player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)){

				if (mapa[monster.coord_y][monster.coord_x-1] != '*' && mapa[monster.coord_y][monster.coord_x-1] != '#' && mapa[monster.coord_y][monster.coord_x-1] != 'D')
					monster.coord_x -= 1;

			} else if (monster.coord_x < player.coord_x && abs(monster.coord_x-player.coord_x) >= abs(monster.coord_y-player.coord_y)){

				if (mapa[monster.coord_y][monster.coord_x+1] != '*' && mapa[monster.coord_y][monster.coord_x+1] != '#' && mapa[monster.coord_y][monster.coord_x+1] != 'D')
					monster.coord_x += 1;

			} else if (monster.coord_y > player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){

				if (mapa[monster.coord_y-1][monster.coord_x] != '*' && mapa[monster.coord_y-1][monster.coord_x] != '#' && mapa[monster.coord_y-1][monster.coord_x] != 'D')
					monster.coord_y -= 1;

			} else if (monster.coord_y < player.coord_y && abs(monster.coord_y-player.coord_y) >= abs(monster.coord_x-player.coord_x)){

				if (mapa[monster.coord_y+1][monster.coord_x] != '*' && mapa[monster.coord_y+1][monster.coord_x] != '#' && mapa[monster.coord_y+1][monster.coord_x] != 'D')
					monster.coord_y += 1;
			}

			//----------------------------------------PLAYER------------------------------------------------------------
            
		    player.movement_keys = toupper(getch());
		
		    switch(player.movement_keys){

				  case 'W':
				  	if(mapa[player.coord_y-1][player.coord_x] != '*' && mapa[player.coord_y-1][player.coord_x] != 'D'){
						if(mapa[player.coord_y-1][player.coord_x] == '#' || player.coord_y-1 == monster.coord_y && player.coord_x == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;
						} else {
							player.coord_y--;
						}
					}
				  break;
				  
				  case 'S':
				  	if(mapa[player.coord_y+1][player.coord_x] != '*' && mapa[player.coord_y+1][player.coord_x] != 'D'){
				  		if(mapa[player.coord_y+1][player.coord_x] == '#' || player.coord_y+1 == monster.coord_y && player.coord_x == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;							
						} else {
							player.coord_y++;
						}
					  }
				  break;
				  
				  case 'D':
				  	if(mapa[player.coord_y][player.coord_x+1] != '*' && mapa[player.coord_y][player.coord_x+1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x+1] == '#' || player.coord_y == monster.coord_y && player.coord_x+1 == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;
						} else {
							player.coord_x++;
						}
					  }
				  break;
				  
				  case 'A':
				  	if(mapa[player.coord_y][player.coord_x-1] != '*' && mapa[player.coord_y][player.coord_x-1] != 'D'){
				  		if(mapa[player.coord_y][player.coord_x-1] == '#' || player.coord_y == monster.coord_y && player.coord_x-1 == monster.coord_x){
							player.coord_x = 1, player.coord_y = 1;
							HP--;
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

					} else if(mapa[player.coord_y][player.coord_x] == 'o'){
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

			if(HP == 0){
				system("cls");
				printf("GAME OVER\n\n");
				printf(">> Press any key to try again <<");
				getch();
				HP = 3;
				
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

	system("cls");
	printf("LEVEL 2 COMPLETED\n\n");
	printf("CONGRATULATIONS!!!!!");
	getch();


	return 0;
}
