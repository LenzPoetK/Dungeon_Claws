#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <locale.h>

// #ifndef MENU.H
// #define MENU.H

enum { BLACK,
       BLUE,
       GREEN,
       CYAN,
       RED,
       MAGENTA,
       BROWN,
       LIGHTGRAY,
       DARKGRAY,
       LIGHTBLUE,
       LIGHTGREEN,
       LIGHTCYAN,
       LIGHTRED,
       LIGHTMAGENTA,
       YELLOW,
       WHITE    
};

enum {_BLACK = 0,
      _BLUE = 16,
      _GREEN = 32,
      _CYAN = 48,
      _RED = 64,
      _MAGENTA = 80,
      _BROWN = 96,
      _LIGHTGRAY = 112,
      _DARKGRAY = 128,
      _LIGHTBLUE = 144,
      _LIGHTGREEN = 160,
      _LIGHTCYAN = 176,
      _LIGHTRED = 192,
      _LIGHTMAGENTA = 208,
      _YELLOW = 224,
      _WHITE = 240    
};

void linhaCol(int lin, int col);
void box(int lin1, int lin2, int col1, int col2);
int perg(char pergunta[40]);
void textColor(int font, int background);
int menu(int linl, int coll, int qtd, char lista[][40]);
/////////////////////////////////////////////////////////////////////////////////

//FUNÇÃO LINHA COL - posiciona o cursor em alguma linha da tela
void linhaCol(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){col-1, lin-1});
    //Função para deixar o cursor invisível.
    CONSOLE_CURSOR_INFO info;
    info.bVisible = 0;
    info.dwSize = 100;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
/////////////////////////////////////////////////////////////////////////////////

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
/////////////////////////////////////////////////////////////////////////////////

int perg(char pergunta[40]){
    int tecla; //Armazena a tecla digitada pelo usuário
    int simnao = 1; //Armazena o valor de retorno

    //Monta a tela
    box(10, 55, 16, 77);
    linhaCol(12, 57); printf("%s", pergunta);
    linhaCol(14, 59); printf("YES");
    linhaCol(14, 69); printf("NO");

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
            linhaCol(14, 59); printf("YES");
            linhaCol(14, 69); printf("NO");
            simnao = 1;
        }
        else if(tecla == 77){
            linhaCol(14, 59); printf("YES");
            linhaCol(14, 69); printf("NO");
            simnao = 0;
        }
    }
    return(simnao);
}
/////////////////////////////////////////////////////////////////////////////////

void textColor(int font, int background){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), font + background);
}
/////////////////////////////////////////////////////////////////////////////////

int menu(int lin1, int col1, int qtd, char lista[][40]){
    system("cls");
    int lin2, col2, linha, i, tamMaxItem, tecla;
    int opc = 1;

    //Calcula as coordenadas
    tamMaxItem = strlen(lista[0]);

    for(i = 1; i < qtd; i++){
        if(strlen(lista[i]) > tamMaxItem){
            tamMaxItem = strlen(lista[i]);
        }
    }
    lin2 = lin1 + (qtd*2+2);
    col2 = col1 + tamMaxItem + 4;

    //Monta a tela
    textColor(YELLOW, _BLACK);
    setlocale(LC_ALL, "C");
    box(lin1, col1, lin2, col2);
    setlocale(LC_ALL, "");

    //Laço das opções
    while(1){
        //Remonta a tela com opção "acesa"
        linha = lin1 + 2;

        for(i = 0; i < qtd; i++){
            if(i+1 == opc){
                textColor(MAGENTA, _BLACK);
            } else{
                textColor(YELLOW, _BLACK);
            }
            linhaCol(linha, col1+2);
            printf("%s", lista[i]);
            linha += 2;
        }
        //Aguarda uma tecla
        tecla = getch();

        //Consiste na opção
        if(tecla == 27){ //Esc
            opc = 0;
            break;
        }
        else if(tecla == 13){ //Enter
            break;
        }
        else if(tecla == 72){ //Seta para cima, ilumina o item anterior, se possível
            if(opc > 1){
                opc--;
            }
        }
        else if(tecla == 80){ //Seta para baixo, ilumina o próximo item, se possível
            if(opc < qtd){
                opc++;
            }
        }
    }
    return opc;
}

// #endif