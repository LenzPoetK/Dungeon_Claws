#include <stdio.h>
#include <stdlib.h>

int main(){
    float temp;

    printf("Informe a temperatura em graus celsius: ");
    fflush(stdin);
    scanf("%f", &temp);

    if(temp < 18){
        system("cls");
        printf("%.1f°C é considerado frio.\n\n", temp);
        } else if(temp >= 18 && temp <= 28){
            system("cls");
            printf("%.1f°C é considerado agradável.\n\n", temp);
            } else if(temp > 28){
                system("cls");
                printf("%.1f°C é considerado quente.\n\n", temp);
                }

    system("pause");
    return 0;
}