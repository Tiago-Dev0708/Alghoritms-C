#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char musica[104] = {"cara caramba, cara caraô cara caramba, cara caraô cara caramba, cara caraô cara caramba, cara caraô"};
    char palavra[5] = {"cara"};
    char comparar[5];
    char *ponteiro;
    int count = 0;

    ponteiro = strstr(musica, palavra);

    if (ponteiro) {
        for(int i = 0; i < strlen(musica); i++) {
            if (musica[i] == palavra[0]) {
                strncpy(comparar, &musica[i], strlen(palavra));
                if (strcmp(comparar, palavra) == 0) {
                    count++;
                    for (int j = 0; j < strlen(palavra); j++) {
                        comparar[j] = '\0';
                    }
                }
                else {
                    continue;
                }
            }
        }

        printf("A palavra '%s' foi encontrada %d vez(es).\n", palavra, count);
    } else {
        printf("A palavra '%s' não foi encontrada na string.\n", palavra);
    }
}