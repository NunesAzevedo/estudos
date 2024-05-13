#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>

#define TAMANHO_TABULEIRO 20
#define TAMANHO_INICIAL_COBRA 4

typedef struct {
    int x;
    int y;
} Posicao;

typedef struct {
    Posicao cabeca;
    Posicao corpo[TAMANHO_TABULEIRO * TAMANHO_TABULEIRO];
    int tamanho;
} Cobra;

typedef struct {
    int x;
    int y;
} Comida;

typedef enum {
    ESQUERDA,
    DIREITA,
    CIMA,
    BAIXO
} Direcao;

typedef struct {
    int pontuacao;
    bool jogo_em_andamento;
} Jogo;

void InicializarJogo(Jogo* jogo, Cobra* cobra, Comida* comida);
void MovimentarCobra(Cobra* cobra, Direcao direcao, Comida* comida, Jogo* jogo);
void MudarDirecao(Direcao* direcao);
void VerificarColisao(Cobra* cobra, Comida* comida, Jogo* jogo);
void AtualizarTabuleiro(Cobra* cobra, Comida* comida, char tabuleiro[][TAMANHO_TABULEIRO]);
void ExibirTabuleiro(char tabuleiro[][TAMANHO_TABULEIRO]);
void ExibirPontuacao(Jogo* jogo);
void FinalizarJogo(Jogo* jogo);
void LoopPrincipal(Cobra* cobra, Direcao* direcao, Comida* comida, Jogo* jogo);
void RodarJogo();

int main() {
    initscr(); 
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    RodarJogo();

    endwin();
    return 0;
}

void InicializarJogo(Jogo* jogo, Cobra* cobra, Comida* comida) {
    jogo->pontuacao = 0;
    jogo->jogo_em_andamento = true;

    cobra->cabeca.x = TAMANHO_TABULEIRO / 2;
    cobra->cabeca.y = TAMANHO_TABULEIRO / 2;
    cobra->tamanho = TAMANHO_INICIAL_COBRA;

    for (int i = 0; i < TAMANHO_INICIAL_COBRA; i++) {
        cobra->corpo[i].x = cobra->cabeca.x;
        cobra->corpo[i].y = cobra->cabeca.y + i + 1;
    }

    comida->x = rand() % TAMANHO_TABULEIRO;
    comida->y = rand() % TAMANHO_TABULEIRO;
}

void MovimentarCobra(Cobra* cobra, Direcao direcao, Comida* comida, Jogo* jogo) {
    Posicao nova_cabeca;
    nova_cabeca = cobra->cabeca;

    switch (direcao) {
        case ESQUERDA:
            nova_cabeca.x--;
            break;
        case DIREITA:
            nova_cabeca.x++;
            break;
        case CIMA:
            nova_cabeca.y--;
            break;
        case BAIXO:
            nova_cabeca.y++;
            break;
    }

    // Verificao colisão com bordas
    if (nova_cabeca.x < 0 || nova_cabeca.x >= TAMANHO_TABULEIRO || nova_cabeca.y < 0 || nova_cabeca.y >= TAMANHO_TABULEIRO) {
        jogo->jogo_em_andamento = false;
        return;
    }

    // Verificao colisão com o próprio corpo
    for (int i = 0; i < cobra->tamanho; i++) {
        if (nova_cabeca.x == cobra->corpo[i].x && nova_cabeca.y == cobra->corpo[i].y) {
            jogo->jogo_em_andamento = false;
            return;
        }
    }

    // Movimento
    for (int i = cobra->tamanho - 1; i > 0; i--) {
        cobra->corpo[i] = cobra->corpo[i - 1];
    }
    cobra->corpo[0] = cobra->cabeca;

    cobra->cabeca = nova_cabeca;

    VerificarColisao(cobra, comida, jogo);
}

void MudarDirecao(Direcao* direcao) {
    int ch = getch();
    switch (ch) {
        case KEY_LEFT:
            *direcao = ESQUERDA;
            break;
        case KEY_RIGHT:
            *direcao = DIREITA;
            break;
        case KEY_UP:
            *direcao = CIMA;
            break;
        case KEY_DOWN:
            *direcao = BAIXO;
            break;
    }
}

void VerificarColisao(Cobra* cobra, Comida* comida, Jogo* jogo) {
    if (cobra->cabeca.x == comida->x && cobra->cabeca.y == comida->y) {
        cobra->tamanho++;
        jogo->pontuacao++;

        comida->x = rand() % TAMANHO_TABULEIRO;
        comida->y = rand() % TAMANHO_TABULEIRO;
    }
}

void AtualizarTabuleiro(Cobra* cobra, Comida* comida, char tabuleiro[][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    // Atualizao do tabuleiro cobra 
    for (int i = 0; i < cobra->tamanho; i++) {
        tabuleiro[cobra->corpo[i].y][cobra->corpo[i].x] = 'o';
    }
    tabuleiro[cobra->cabeca.y][cobra->cabeca.x] = 'O';

    // Atualizao do tabuleiro comida
    tabuleiro[comida->y][comida->x] = 'X';
}

void ExibirTabuleiro(char tabuleiro[][TAMANHO_TABULEIRO]) {
    clear();
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printw("%c ", tabuleiro[i][j]);
        }
        printw("\n");
    }
    refresh();
}

void ExibirPontuacao(Jogo* jogo) {
    printw("Pontuacao: %d\n", jogo->pontuacao);
}

void FinalizarJogo(Jogo* jogo) {
    printw("Fim de Jogo! Pontuacao final: %d\n", jogo->pontuacao);
    jogo->jogo_em_andamento = false;
}

void LoopPrincipal(Cobra* cobra, Direcao* direcao, Comida* comida, Jogo* jogo) {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    while (jogo->jogo_em_andamento) {
        MudarDirecao(direcao);
        MovimentarCobra(cobra, *direcao, comida, jogo);
        AtualizarTabuleiro(cobra, comida, tabuleiro);
        ExibirTabuleiro(tabuleiro);
        ExibirPontuacao(jogo);

        // Aguarda um tempo para a próxima interação
        napms(100);
    }
}

void RodarJogo() {
    srand(time(NULL));

    Jogo jogo;
    Cobra cobra;
    Comida comida;
    Direcao direcao = DIREITA;

    InicializarJogo(&jogo, &cobra, &comida);
    LoopPrincipal(&cobra, &direcao, &comida, &jogo);
    FinalizarJogo(&jogo);
}

