#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <Windows.h>
#include <locale.h>

int main(){

    setlocale(LC_ALL, "portuguese");
    
    int i, loop = 1;
    float temp;
    char menu_option;

    while(loop){

        system("cls");
        printf("-------------------------------\n");
        printf("    MEDIDOR DE TEMPERATURA\n");
        printf("-------------------------------\n\n");

        printf("A. Analisar temperatura\n");
        printf("B. Sair\n\n");

        printf("Selecione uma opção: ");
        menu_option = toupper(getch());

        if(menu_option == 'A'){
            while(1){
                system("cls");
                printf("Informe a temperatura em graus celsius: ");
                fflush(stdin);
                scanf("%f", &temp);

                if(temp < 18){
                    system("cls");
                    printf("%.1f °C é considerado frio.\n\n", temp);
                    getch();
                    } else if(temp >= 18 && temp <= 28){
                        system("cls");
                        printf("%.1f °C é considerado agradável.\n\n", temp);
                        getch();
                        } else if(temp > 28){
                            system("cls");
                            printf("%.1f °C é considerado quente.\n\n", temp);
                            getch();
                            } else {
                                system("cls");
                                printf("Tente novamente.");
                                getch();
                                continue;
                            }
                break;
            }
            continue;
        } else if(menu_option == 'B'){
            system("cls");
            printf("Saindo");

            for(i = 0; i < 3; i++){
                printf(".");
                Sleep(400);
            }
        } else {
            system("cls");
            printf("Tente novamente.");
            getch();
            continue;
        }
        break;
    }

    return 0;
}