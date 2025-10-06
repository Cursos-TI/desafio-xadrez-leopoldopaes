include <stdio.h>


int main() {
    printf("Desafio Xadrez!\n");

    // torre: move-se em linha reta horizontalmente ou verticalmente
    printf("movimento da torre:\n");
    int casastorre = 5;
    for (int i = 0; i < casastorre; i++){
        printf("Direita\n");
    }

    //  Bispo: move-se na diagonal
    printf("nMovimneto do bispo:\n");
    int casasBispo = 5;
    int i = 0;
    while (i < casasBispo){
        printf("cima, direita\n");
        i++;
    }

     // Rainha: Move-se em todas as diresções
     printf("\nMovimento da Rainha:\n");
     int casasRainha = 8;
     int j = 0;
     do {
        printf("Esquerda\n");
        j++;  
     } while (j < casasRainha);

    return 0;
}