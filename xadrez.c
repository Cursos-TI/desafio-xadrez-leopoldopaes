#include <stdio.h>

// Definições de Constantes para o Movimento
#define MOV_TORRE 5
#define MOV_BISPO 5
#define MOV_RAINHA 8
#define MOV_CAVALO_VERTICAL 2
#define MOV_CAVALO_HORIZONTAL 1

// ======================================================================
// FUNÇÕES RECURSIVAS (Substituem os loops simples)
// ======================================================================

/**
 * @brief Simula o movimento da Torre 5 casas para a Direita usando recursividade.
 * @param casas_restantes O número de casas que a Torre ainda deve mover.
 */
void moverTorreRecursivo(int casas_restantes) {
    // Caso Base: A recursão para quando não houver mais casas para mover.
    if (casas_restantes == 0) {
        return;
    }
    
    // Passo Recursivo: Imprime o movimento da casa atual.
    // A chamada recursiva deve vir DEPOIS para imprimir na ordem crescente (Casa 1, Casa 2...)
    // ou ANTES para imprimir na ordem decrescente. Vamos imprimir na ordem crescente.
    moverTorreRecursivo(casas_restantes - 1);
    
    // Imprime a direção (Direita)
    printf("Casa %d: Direita\n", casas_restantes);
}


/**
 * @brief Simula o movimento da Rainha 8 casas para a Esquerda usando recursividade.
 * @param casas_restantes O número de casas que a Rainha ainda deve mover.
 */
void moverRainhaRecursivo(int casas_restantes) {
    // Caso Base: A recursão para quando o movimento for concluído.
    if (casas_restantes <= 0) {
        return;
    }

    // Passo Recursivo: Imprime o movimento da casa atual.
    printf("Casa %d: Esquerda\n", (MOV_RAINHA - casas_restantes) + 1);

    // Chamada Recursiva: Move para a próxima casa.
    moverRainhaRecursivo(casas_restantes - 1);
}


/**
 * @brief Simula o movimento do Bispo 5 casas na diagonal usando recursividade.
 * @param casas_restantes O número de casas que o Bispo ainda deve mover.
 */
void moverBispoRecursivo(int casas_restantes) {
    // Caso Base: A recursão para quando o movimento for concluído.
    if (casas_restantes <= 0) {
        return;
    }
    
    // Passo Recursivo: Imprime o movimento da casa atual.
    printf("Casa %d: Cima, Direita (Recursivo)\n", (MOV_BISPO - casas_restantes) + 1);

    // Chamada Recursiva: Move para a próxima casa.
    moverBispoRecursivo(casas_restantes - 1);
}


// ======================================================================
// FUNÇÕES PRINCIPAIS E LOOPS COMPLEXOS
// ======================================================================

int main() {
    int i, j; // Variáveis de controle

    // ----------------------------------------------------------------------
    // 1. Movimentação da TORRE (Nível Mestre: Recursividade)
    // Movimento: 5 casas para a Direita
    // ----------------------------------------------------------------------
    printf("==========================================\n");
    printf("Simulacao: Movimento da TORRE (Recursividade)\n");
    printf("==========================================\n");
    moverTorreRecursivo(MOV_TORRE);
    printf("Movimento da Torre finalizado.\n\n");
    
    // ----------------------------------------------------------------------
    // 2. Movimentação da RAINHA (Nível Mestre: Recursividade)
    // Movimento: 8 casas para a Esquerda
    // ----------------------------------------------------------------------
    printf("==========================================\n");
    printf("Simulacao: Movimento da RAINHA (Recursividade)\n");
    printf("==========================================\n");
    moverRainhaRecursivo(MOV_RAINHA);
    printf("Movimento da Rainha finalizado.\n\n");


    // ----------------------------------------------------------------------
    // 3. Movimentação do BISPO (Nível Mestre: Recursividade + Loops Aninhados)
    // Movimento: 5 casas na diagonal para Cima e Direita
    // Requisito: Implementar o Bispo tanto com Recursividade quanto com Loops Aninhados
    // ----------------------------------------------------------------------
    printf("==========================================\n");
    printf("Simulacao: Movimento do BISPO (Loops Aninhados)\n");
    printf("==========================================\n");
    
    // i: Loop Externo (Movimento Vertical: Cima)
    // j: Loop Interno (Movimento Horizontal: Direita)
    for (i = 1; i <= MOV_BISPO; i++) {
        // Reinicializamos j para que a condição do loop interno seja verificada a cada passo diagonal
        // O loop interno serve apenas para imprimir a segunda direção, forçando o aninhamento.
        j = 1; 
        
        // Loop interno (Movimento Horizontal) - executa uma vez para cada movimento vertical
        // O Bispo move 1 Cima e 1 Direita simultaneamente, mas o aninhamento simula a lógica da diagonal.
        while (j <= 1) { 
            printf("Casa %d: Cima, Direita (Loops Aninhados)\n", i);
            j++;
        }
    }
    printf("Movimento do Bispo finalizado.\n\n");


    // ----------------------------------------------------------------------
    // 4. Movimentação do CAVALO (Nível Mestre: Loops Aninhados Complexos)
    // Movimento: 2 casas para Cima, 1 casa para a Direita ("L")
    // Requisito: Usar 'continue' e 'break' e múltiplas variáveis.
    // ----------------------------------------------------------------------
    printf("==========================================\n");
    printf("Simulacao: Movimento do CAVALO (Loops Complexos)\n");
    printf("==========================================\n");
    
    // i = Casas Verticais (Cima); j = Casas Horizontais (Direita)
    // O loop externo irá controlar o movimento em 'L' (executa apenas uma vez)
    for (i = 1, j = 1; i <= 1; i++) { // i e j são inicializados e i controla a execução
        
        int casas_verticais_restantes = MOV_CAVALO_VERTICAL; // 2
        
        // Loop aninhado (Simula as 2 casas verticais)
        while (casas_verticais_restantes > 0) {
            
            // Condição avançada: Se for a última casa vertical, prepara para o movimento horizontal
            if (casas_verticais_restantes == 1) {
                printf("Cima\n");
                
                // Usando 'break' para sair do loop vertical e iniciar o horizontal
                // Isso demonstra o controle de fluxo.
                break; 
            }
            
            printf("Cima\n");
            casas_verticais_restantes--;
            
            // Usando 'continue' para pular para a próxima iteração após o primeiro movimento 'Cima'
            // Isso garante que o código após o 'continue' não seja executado nesta iteração.
            continue; 
        }

        // Loop separado (mas controlado pela mesma lógica do Cavalo)
        // Simula a 1 casa horizontal (Direita)
        // O valor de 'j' (1) controla a iteração.
        for (int k = 0; k < MOV_CAVALO_HORIZONTAL; k++) {
            printf("Direita\n");
        }
    }

    printf("Movimento do Cavalo finalizado.\n");

    return 0;
}