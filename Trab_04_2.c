#include <stdio.h>
#include <string.h>

struct treino_int {
    char pergunta[102]; 
    char alt1[10];
    char alt2[10];
    char alt3[10];
    char resposta[10];
};

struct treino_float {
    char pergunta[102]; 
    float alt1;
    float alt2;
    float alt3;
    float resposta;
};

struct teste {
    char pergunta[102]; 
};

int main() {
    char tipo[10], treino[6];
    char resp1[] = "INT\n", resp2[] = "FLOAT\n", resp3[] = "SIM\n", resp4[] = "FIM";
    int a, b, e=0;

// etapa de treinamento 
    printf("---Etapa de treinamento---\n");

    //como irá agir
    struct treino_int questao[15];
    struct treino_float q2[15];
    for (a = 0; a < 15; a++) {
        fgets(tipo, sizeof(tipo), stdin);
        if (strcmp(tipo, resp1) == 0) {
            fgets(questao[a].pergunta, sizeof(questao[a].pergunta), stdin);
            questao[a].pergunta[strcspn(questao[a].pergunta, "\n")] = '\0';
            fgets(questao[a].alt1, sizeof(questao[a].alt1), stdin);
            questao[a].alt1[strcspn(questao[a].alt1, "\n")] = '\0';
            fgets(questao[a].alt2, sizeof(questao[a].alt2), stdin);
            questao[a].alt2[strcspn(questao[a].alt2, "\n")] = '\0';
            fgets(questao[a].alt3, sizeof(questao[a].alt3), stdin);
            questao[a].alt3[strcspn(questao[a].alt3, "\n")] = '\0';

            printf("Alternativa correta eh %s?\n", questao[a].alt1);
            fgets(treino, sizeof(treino), stdin);
            if (strcmp(treino, resp3) == 0) {
                strcpy(questao[a].resposta, questao[a].alt1);
                continue;
            } 
            else {
                printf("Alternativa correta eh %s?\n", questao[a].alt2);
                fgets(treino, sizeof(treino), stdin);
                if (strcmp(treino, resp3) == 0) {
                    strcpy(questao[a].resposta, questao[a].alt2);
                    continue;
                } 
                else {
                    printf("Alternativa correta eh %s?\n", questao[a].alt3);
                    fgets(treino, sizeof(treino), stdin);
                    if (strcmp(treino, resp3) == 0) {
                        strcpy(questao[a].resposta, questao[a].alt3);
                        continue;
                    }
                }
            }
        } 
        else{
            if (strcmp(tipo, resp2) == 0){
                fgets(q2[a].pergunta, 102, stdin);
                q2[a].pergunta[strcspn(q2[a].pergunta, "\n")] = '\0';
                scanf("%f", &q2[a].alt1);
                scanf("%f", &q2[a].alt2);
                scanf("%f", &q2[a].alt3);
                getchar();

                printf("Alternativa correta eh %0.2f?\n", q2[a].alt1);
                fgets(treino, sizeof(treino), stdin);
                if (strcmp(treino, resp3) == 0) {
                    q2[a].resposta = q2[a].alt1;
                    continue;
                } 
                else {
                    printf("Alternativa correta eh %0.2f?\n", q2[a].alt2);
                    fgets(treino, sizeof(treino), stdin);
                    if (strcmp(treino, resp3) == 0) {
                        q2[a].resposta = q2[a].alt2;
                        continue;
                    } 
                    else {
                        printf("Alternativa correta eh %0.2f?\n", q2[a].alt3);
                        fgets(treino, sizeof(treino), stdin);
                        if (strcmp(treino, resp3) == 0) {
                            q2[a].resposta = q2[a].alt3;
                            continue;
                        }
                    }
                }               
            }
            
            else
                break;
        }
    }

// etapa de testes
    printf("---Etapa de testes---\n");
    struct teste q[15];
    for (a = 0; a < 15; a++) {
        fgets(q[a].pergunta, sizeof(q[a].pergunta), stdin);
        q[a].pergunta[strcspn(q[a].pergunta, "\n")] = '\0';
        if (strcmp(q[a].pergunta, resp4) != 0) {
            e = 0;
            for (b = 0; b < 15; b++) {
                if (strcmp(q[a].pergunta, questao[b].pergunta) == 0) {
                    printf("A resposta eh: %s\n", questao[b].resposta);
                    e = 1;
                    break;
                }
                else{
                        if (strcmp(q[a].pergunta, q2[b].pergunta) == 0){
                            printf("A resposta eh: %0.2f\n", q2[b].resposta);
                            e = 1;
                            break;
                }
                }
            }
            if (e == 0) {
                printf("Me desculpe, ainda não fui treinado para responder essa pergunta.\n");
            }
        } 
        else 
            break;
        
    }
    
    return 0;
}
