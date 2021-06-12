#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 9

int n_bombs (int l, int c, char M[][N], int n) {
    int contador_bombas = 0;
    int i = l, j = c;
    char cima = M[i-1][j], baixo = M[i+1][j], esquerda = M[i][j-1], direita = M[i][j+1];
    char diagonal_superior_esquerda = M[i-1][j-1], diagonal_superior_direita = M[i-1][j+1], diagonal_inferior_esquerda = M[i+1][j-1], diagonal_inferior_direita = M[i+1][j+1];
    if ((i == 0) && (j == 0)) { // Canto Superior Esquerdo
        if (baixo == -1){
            contador_bombas += 1;
        }
        if (direita == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_direita == -1){
            contador_bombas += 1;
        }
    }
    else if ((i == 0) && (j == n - 1)) { // Canto Superior Direito
        if (baixo == -1){
            contador_bombas += 1;
        }
        if (esquerda == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_esquerda == -1){
            contador_bombas += 1;
        }
    }
    else if ((i == n - 1) && (j == 0)) { // Canto Inferior Esquerdo
        if (cima == -1){
            contador_bombas += 1;
        }
        if (direita == -1){
            contador_bombas += 1;
        }
        if(diagonal_superior_direita == -1){
            contador_bombas += 1;
        }
    }
    else if ((i == n - 1) && (j == n - 1)) { // Canto Inferior Direito  
        if (cima == -1){
            contador_bombas += 1;
        }
        if (esquerda == -1){
            contador_bombas += 1;
        }
        if (diagonal_superior_esquerda == -1){
            contador_bombas += 1;
        }
    }
    else if ((i == 0) && (j != 0) && (j != n - 1)) { // Elementos Lado Superior Menos Cantos Superiores
        if (esquerda == -1){
            contador_bombas += 1;
        }
        if (direita == -1){
            contador_bombas += 1;
        }
        if (baixo == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_esquerda == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_direita == -1){
            contador_bombas += 1;
        }
    }
    else if ((i == n - 1) && (j != 0) && (j != n - 1)) { //Elementos do Lado Inferior Menos Cantos Inferiores
        if (esquerda == -1){
            contador_bombas += 1;
        }
        if (direita == -1){
            contador_bombas += 1;
        }
        if (cima == -1){
            contador_bombas += 1;
        }
        if (diagonal_superior_esquerda == -1){
            contador_bombas += 1;
        }
        if (diagonal_superior_direita == -1){
            contador_bombas += 1;
        }
    }
    else if ((i != 0) && (i != n - 1) && (j == 0)) { //Elementos do Lado Esquerdo Menos Cantos Superior e Inferior Esquerdos
        if (baixo == -1){
            contador_bombas += 1;
        }
        if (direita == -1){
            contador_bombas += 1;
        }
        if (cima == -1){
            contador_bombas += 1;
        }
        if (diagonal_superior_direita == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_direita == -1){
            contador_bombas += 1;
        }
    }
    else if ((i != 0) && (i != n - 1) && (j == n - 1)) { //Elementos do Lado Direito Menos Cantos Superior e Inferior Direitos
        if (esquerda == -1){
            contador_bombas += 1;
        }
        if (baixo == -1){
            contador_bombas += 1;
        }
        if (cima == -1){
            contador_bombas += 1;
        }
        if (diagonal_superior_esquerda == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_esquerda == -1){
            contador_bombas += 1;
        }
    }
    else { // Elementos Centro da Matriz
        if (baixo == -1){
            contador_bombas += 1;
        }
        if (cima == -1){
            contador_bombas += 1;
        }
        if (direita == -1){
            contador_bombas += 1;
        }
        if (esquerda == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_direita == -1){
            contador_bombas += 1;
        }
        if (diagonal_inferior_esquerda == -1){
            contador_bombas += 1;
        }
        if (diagonal_superior_direita == -1){
            contador_bombas += 1;
        }
        if (diagonal_superior_esquerda == -1){
            contador_bombas += 1;
        }
    }
    return contador_bombas;
}     


void gera_campo (char M[][N], int n) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            M[i][j] = -2;
        }
    }
    int linha, coluna;
    int quantidade_bombas = 0.2*n*n;
    srand(time(NULL));
    while (quantidade_bombas != 0) {
        linha = rand() % n;
        coluna = rand() % n;
        if (M[linha][coluna] == -2){
            M[linha][coluna] = -1;
            quantidade_bombas--;
        } 
    }
} 

void mostrar_campo_real (char M[][N], int n){
    int linha, coluna;
    for (linha = 0; linha < n; linha++){
        for (coluna = 0; coluna < n; coluna++){
            if (M[linha][coluna] == -1){
                M[linha][coluna] = -3;
            }
        }
    }
} 

void imprime_matriz (char M[][N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%d | ", i + 1);
        for (j = 0; j < n; j++) {
            if (M[i][j] == -2) {
                printf("?  ");
            }
            if (M[i][j] == -1){
                printf("?  ");
            }
            else if (M[i][j] == -3) {
                printf("*  ");
            }
            if (M[i][j] >= 0) {   
                printf("%d  ", M[i][j]);
            }
        }
        printf("\n");
    }
    printf("   ");
    for (j = 0; j < (n + 2*n); j++) {
        printf("-");
    }
    printf("\n  ");
    for (j = 0; j < n; j++) {
        printf("  %d", j + 1);
    }
}

int executar_jogo (char M[][N], int n) {
    int linha, coluna, contador_bombas;
    static int finalizar_exito = 0;
    int jogadas_maximo = (n*n) - (0.2*n*n) + 1;
    imprime_matriz(M,n);
    printf("\n\nDigite a linha e a coluna desejada: ");
    scanf("%d %d", &linha, &coluna);
    printf("\n");
    linha--; 
    coluna--;

    if((linha < n) && (linha >= 0) && (coluna < n) && (coluna >= 0)) {
        if(M[linha][coluna] == -1){
            mostrar_campo_real(M, n);
            printf("VOCE PERDEU! FIM DO JOGO.\n\n");                    
            imprime_matriz(M, n);
            printf("\n");
            return 0;
        }
        if(M[linha][coluna] == -2){
            contador_bombas = n_bombas(linha, coluna, M, n);
            finalizar_exito++;
            M[linha][coluna] = contador_bombas;
        }
        if(finalizar_exito == jogadas_maximo){
            mostrar_campo_real(M, n);
            printf("PARABENS! VOCE VENCEU!\n\n");    
            imprime_matriz(M, n);
            printf("\n");
            return 0;
        }
        return 1;
    }
    else {
        printf("Entrada invalida.\n\n");
        return 1;
    }
}

void main() {
    int n_matriz, jogando;
    char matriz_base[N][N];
    printf("Digite o tamanho da matriz desejada: ");
    scanf("%d", &n_matriz);
    printf("\n");
    gera_campo(matriz_base, n_matriz);
    do {
        jogando = executar_jogo(matriz_base, n_matriz);
    } while (jogando);
}
