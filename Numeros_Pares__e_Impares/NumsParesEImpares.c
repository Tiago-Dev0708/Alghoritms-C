#include <stdio.h>

int main() {

    int vetorNumbers[101];

    for(int i = 0; i < 101; i++){
        vetorNumbers[i] = i;
    }
    

    printf("Os números pares são:");
    for(int i = 1; i < 101; i++){
        if(vetorNumbers[i] % 2 == 0){
            printf("%d", vetorNumbers[i]);
            printf("%s", ", ");
        }
    }
    printf("\n");

    printf("Os números ímpares são:");
    for(int i = 0; i < 101; i++){
        if(vetorNumbers[i] % 2 != 0){
            printf("%d",vetorNumbers[i]);
            printf("%s", ", ");
        }
    }
    printf("\n");

    return 0;
}