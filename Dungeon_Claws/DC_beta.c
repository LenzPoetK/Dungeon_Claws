#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
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
int first_map();

//----------------------------MAIN------------------------------------
int main()
{	

	char name[15];
	char menu_selection[10];
	int loop = 1;

    game_title();

	system("cls");
	printf("Enter your name: ");
	scanf("%s", &name);
	fflush(stdin);

	system("cls");
	printf("Now prove your courage, %s...", name);
	sleep(3);

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
			printf("                                   O - Button: Press to intereact with the map.\n\n");

			printf("                    >> Press any key to go back <<");
			getch();
			continue;

		} else if(strcmp(menu_selection, "Exit") == 0 || strcmp(menu_selection, "exit") == 0 || strcmp(menu_selection, "EXIT") == 0){
			system("cls");
			printf("leaving...");
			sleep(2);
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

//tí­tulo do game.
void game_title()
{
	
	int i;
	char title[] = "DUNGEON\'S CLAWS";
	int length = strlen(title);
	
	system("cls");
	printf("----------------------------\n");
	printf("      ");
	
	for(i = 0; i < length; i++)
	{
		printf("%c", title[i]);
		usleep(100000);
	}
	
	printf("\n");
	printf("----------------------------\n\n");
	
	printf(">> Press start to continue <<");
	getch();
}

//texto que inicializa a história do jogo.
void introduction_text(){
	
	struct game_text introduction;

    int i;

    strcpy(introduction.text, "During the great war, many warriors died\nfighting on the battle fields.");

    int length = strlen(introduction.text);

     for(i = 0; i <= length; i++){
        printf("%c", introduction.text[i]);
        Sleep(60);
     }

}

//mapa 1.
int first_map(){

	int key = 0;
    int HP = 3;
	char movement_keys;
	int monster_movement;
	int x, y;
	int monster_px = 5, monster_py = 10;
	int px = 1, py = 1;
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
 				         		 
	while(mapa[py][px] != '='){

			system("cls");

            for(y = 0; y < 15; y++){
				  for(x = 0; x < 15; x++){
		  		       if(x == px && y == py){		
				  	   printf("  &");
			           } else if (x == monster_px && y == monster_py) {
	  		 		   	 	printf("  X");
 	          		     } else {
							printf("  %c", mapa[y][x]);
						 }

	              }
				   printf("\n\n");
            }

			//---------------------------------------MONSTRO--------------------------------------
			monster_movement = rand() % 4;
		
		    switch(monster_movement){

				  case 0:
				  	if(mapa[monster_py-1][monster_px] != '*' && mapa[monster_py-1][monster_px] != 'D' && mapa[monster_py-1][monster_px] != '#'){
							monster_py--;
						}
				  break;
				  
				  case 1:
				  	if(mapa[monster_py+1][monster_px] != '*' && mapa[monster_py+1][monster_px] != 'D' && mapa[monster_py+1][monster_px] != '#'){							
							monster_py++;
						}
				  break;
				  
				  case 2:
				  	if(mapa[monster_py][monster_px+1] != '*' && mapa[monster_py][monster_px+1] != 'D' && mapa[monster_py][monster_px+1] != '#'){
							monster_px++;
						}
				  break;
				  
				  case 3:
				  	if(mapa[monster_py][monster_px-1] != '*' && mapa[monster_py][monster_px-1] != 'D' && mapa[monster_py][monster_px-1] != '#'){
							monster_px--;
						}
				  break;

		 	}

			//----------------------------------PLAYER---------------------------------------------
            
		    movement_keys = toupper(getch());
		
		    switch(movement_keys){

				  case 'W':
				  	if(mapa[py-1][px] != '*' && mapa[py-1][px] != 'D'){
						if(mapa[py-1][px] == '#' || py == monster_py && px == monster_px){
							px = 1, py = 1;
							HP--;
						} else {
							py--;
						}
					}
				  break;
				  
				  case 'S':
				  	if(mapa[py+1][px] != '*' && mapa[py+1][px] != 'D'){
				  		if(mapa[py+1][px] == '#' || py == monster_py && px == monster_px){
							px = 1, py = 1;
							HP--;							
						} else {
							py++;
						}
					  }
				  break;
				  
				  case 'D':
				  	if(mapa[py][px+1] != '*' && mapa[py][px+1] != 'D'){
				  		if(mapa[py][px+1] == '#' || py == monster_py && px == monster_px){
							px = 1, py = 1;
							HP--;
						} else {
							px++;
						}
					  }
				  break;
				  
				  case 'A':
				  	if(mapa[py][px-1] != '*' && mapa[py][px-1] != 'D'){
				  		if(mapa[py][px-1] == '#' || py == monster_py && px == monster_px){
							px = 1, py = 1;
							HP--;
						} else {
							px--;
						}
					  }
				  break;

				  case 'I':
				  	if(mapa[py][px] == '@'){
						mapa[8][3] = ' ';
						mapa[14][5] = '=';
					} else {
						mapa[py][px];
					}
				  break;			

		 	}

			if(HP == 0){
				system("cls");
				printf("GAME OVER\n\n");
				printf(">> Press any key to try again <<");
				getch();
				HP = 3;
				continue;

			}

	}

	system("cls");
	printf("LEVEL 1 COMPLETED\n\n");
	printf("CONGRATULATIONS!!!!!");
	getch();

    return 0;
}

