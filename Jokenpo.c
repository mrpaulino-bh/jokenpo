#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para gerar a jogada do computador
int gerarJogadaComputador() {
    // Gera um número aleatório entre 0 e 2 (0: Pedra, 1: Papel, 2: Tesoura)
    return rand() % 3;
}

// Função para determinar o vencedor
int determinarVencedor(int jogadaJogador, int jogadaComputador) {
    switch (jogadaJogador) {
        case 0: // Pedra
            if (jogadaComputador == 0) return 0; // Empate
            else if (jogadaComputador == 2) return 1; // Jogador vence
            else return -1; // Computador vence
        case 1: // Papel
            if (jogadaComputador == 1) return 0; // Empate
            else if (jogadaComputador == 0) return 1; // Jogador vence
            else return -1; // Computador vence
        case 2: // Tesoura
            if (jogadaComputador == 2) return 0; // Empate
            else if (jogadaComputador == 1) return 1; // Jogador vence
            else return -1; // Computador vence
        default:
            return -2; // Jogada inválida (este caso não deve acontecer)
    }
}

// Função principal do jogo
int main() {
    int jogadaJogador, jogadaComputador, resultado;
    char jogadaNome[3][10] = {"Pedra", "Papel", "Tesoura"}; // Nomes para mostrar a jogada
    int continuar = 1;

    setlocale(LC_ALL, "Portuguese");

    // Inicializa a seed para números aleatórios
    srand(time(NULL));

    // Loop principal do jogo
    while (continuar) {
        // Pede a jogada do jogador
        printf("\nEscolha a sua jogada:\n");
        printf("0 - Pedra\n");
        printf("1 - Papel\n");
        printf("2 - Tesoura\n");
        printf("Opção: ");
        scanf("%d", &jogadaJogador);

        // Valida a jogada do jogador
        if (jogadaJogador < 0 || jogadaJogador > 2) {
            printf("Jogada inválida. Por favor, escolha 0, 1 ou 2.\n");
            continue; // Volta ao início do loop
        }

        // Gera a jogada do computador
        jogadaComputador = gerarJogadaComputador();

        // Determina o vencedor
        resultado = determinarVencedor(jogadaJogador, jogadaComputador);

        // Mostra as jogadas
        printf("\nVocê escolheu: %s\n", jogadaNome[jogadaJogador]);
        printf("O computador escolheu: %s\n", jogadaNome[jogadaComputador]);

        // Mostra o resultado
        switch (resultado) {
            case 0:
                printf("Empate!\n");
                break;
            case 1:
                printf("Você venceu!\n");
                break;
            case -1:
                printf("O computador venceu!\n");
                break;
            default:
                printf("Erro: Jogada inválida!\n"); // Este caso não deve acontecer
        }

        // Pergunta se o jogador quer continuar
        printf("Jogar novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
    }

    printf("\nObrigado por jogar!\n");
    return 0;
}

