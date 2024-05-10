#include <stdio.h>

char atualizarVetor(char v[3][3], int rodada){
    int linha;
    int coluna;

    printf("Em qual linha sua marca deve estar?(Comeca do 0 e vai ate o 2):");
    scanf("%d", &linha);

    printf("Em qual coluna sua marca deve estar?(Comeca do 0 e vai ate o 2):");
    scanf("%d", &coluna);

    if(rodada % 2 == 0 && rodada <= 9 && v[linha][coluna] == ' '){
        v[linha][coluna] = 'X';
        return 'c';

    }else if(rodada % 2 != 0 && rodada <=9 && v[linha][coluna] == ' '){
        v[linha][coluna] = 'O';
        return 'c';
    }else{
        printf("deu errado, faz de novo\n");
        return 'e';
    }
}

void imprimirTabuleiro(char v[3][3], int rodada){
    printf("rodada:%d\n", rodada + 1);

    printf("  %c  |  %c  |  %c   \n", v[0][0], v[0][1], v[0][2]);
    printf("-----+-----+-----\n");
    printf("  %c  |  %c  |  %c   \n", v[1][0], v[1][1], v[1][2]);
    printf("-----+-----+-----\n");
    printf("  %c  |  %c  |  %c   \n", v[2][0], v[2][1], v[2][2]);
}

int checarVitoria(char v[3][3], int rodada, char erro){
    if(erro == 'e'){
        return rodada;
    }
    if(v[0][0] == v[0][1] && v[0][1] == v[0][2] && v[0][0] != ' '){
        if(v[0][0] == 'X'){
            return 11;
        }else{return 12;}
    }else if(v[1][0] == v[1][1] && v[1][1] == v[1][2] && v[1][0] != ' '){
        if(v[1][0] == 'X'){
            return 11;
        }else{return 12;}
    }else if(v[2][0] == v[2][1] && v[2][1] == v[2][2] && v[2][0] != ' '){
        if(v[2][0] == 'X'){
            return 11;
        }else{return 12;}
    }else if(v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][0] != ' '){
        if(v[0][0] == 'X'){
            return 11;
        }else{return 12;}
    }else if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][1] != ' '){
        if(v[0][1] == 'X'){
            return 11;
        }else{return 12;}
    }else if(v[0][2] == v[1][2] && v[1][2] == v[2][2] && v[0][2] != ' '){
        if(v[0][2] == 'X'){
            return 11;
        }else{return 12;}
    }else if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != ' '){
        if(v[0][0] == 'X'){
            return 11;
        }else{return 12;}
    }else if(v[2][0] == v[1][1] && v[1][1] == v[0][2] && v[2][0] != ' '){
        if(v[0][0] == 'X'){
            return 11;
        }else{return 12;}
    }else{
        return rodada = rodada + 1;
    }



}


int main(){
    printf("Bem-vindo ao verificador de jogo-da-velha!\n");
    printf("\n");

    char marca[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int rodada = 0;

    while(rodada < 9){
        imprimirTabuleiro(marca, rodada);
        char erro = atualizarVetor(marca, rodada);
        rodada = checarVitoria(marca, rodada, erro);

    }

    if(rodada == 11) printf("O jogador X ganhou!!!");
    if(rodada == 12) printf("O jogador O ganhou!!!");
    else if(rodada == 9) printf("Ninguem ganhou!!!");


    return 0;
}