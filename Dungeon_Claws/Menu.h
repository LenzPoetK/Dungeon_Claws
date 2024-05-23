#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <locale.h>

void linhaCol(int lin, int col);
void box(int lin1, int lin2, int col1, int col2);
int perg(char pergunta[40]);

//FUNÇÃO LINHA COL - posiciona o cursor em alguma linha da tela
void linhaCol(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){col-1, lin-1});
}

//FUNÇÃO BOX
void box(int lin1, int col1, int lin2, int col2){
    int i, tamlin, tamcol;

    //Acha o tamanho da box - largura e altura da box
    tamlin = lin2 - lin1;
    tamcol = col2 - col1;

    //Monta a box - faz as duas linhas da box
    for(i = col1; i <= col2; i++){ //Linhas
        linhaCol(lin1, i);
        printf("%c", 196);
        linhaCol(lin2, i);
        printf("%c", 196);
    }

    //Monta a box - as duas colunas da box
    for(i = lin1; i <= lin2; i++){ //Laterais
        linhaCol(i, col1);
        printf("%c", 179);
        linhaCol(i, col2);
        printf("%c", 179);
    }

    //Posições dos cantos
    linhaCol(lin1, col1); printf("%c", 218);
    linhaCol(lin1, col2); printf("%c", 191);
    linhaCol(lin2, col1); printf("%c", 192);
    linhaCol(lin2, col2); printf("%c", 217);
}

int perg(char pergunta[40]){
    int tecla; //Armazena a tecla digitada pelo usuário
    int simnao = 1; //Armazena o valor de retorno

    //Monta a tela
    box(10, 55, 16, 77);
    linhaCol(12, 57); printf("%s", pergunta);
    linhaCol(14, 59); printf("SIM");
    linhaCol(14, 69); printf("NAO");

    while(1){
        fflush(stdin);
        tecla = getch();

        if(tecla == 27){ //ESC
            simnao = 0;
            break;
        }
        else if(tecla == 13){ //ENTER
            break;
        }
        //Colocou S ou N direto?
        if(tecla == 83 || 115) return(1); //Sim!
        if(tecla == 78 || 110) return(0); //Não!

        //Alterna entre o sim e o não
        if(tecla == 75){
            linhaCol(14, 59); printf("SIM");
            linhaCol(14, 69); printf("NAO");
            simnao = 1;
        }
        else if(tecla == 77){
            linhaCol(14, 59); printf("SIM");
            linhaCol(14, 69); printf("NAO");
            simnao = 0;
        }
    }
    return(simnao);
}