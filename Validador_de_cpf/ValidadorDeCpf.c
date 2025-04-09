#include <stdio.h>

int validarCpf(char cpf[]){
    int num[11];
    int resto, soma = 0;
    int digVer1, digVer2;


    for (int i = 0; i < 11; i++){
        if(cpf[i] < '0' || cpf[i] > '9');
        num[i] = cpf[i] - '0';
    }

    for (int i = 0, j = 10; i < 9; i++, j--){
            soma += num[i] * j;
    } 

    resto = soma % 11;

    if(resto < 2){
        digVer1 = 0;
    }
    else{
        digVer1 = 11 - resto;
    }

    soma = 0;
    for(int i = 0, j = 11; i < 10; i++, j--){
            soma += num[i] * j;
    }
    resto = soma % 11;

    if(resto < 2){
        digVer2 = 0;
    }
    else{
        digVer2 = 11 - resto;
    }

    if(digVer1 == num[9] && digVer2 == num[10]){
        printf("O CPF digitado está validado\n");
    }
    else{
        printf("O CPF digitado é inválido\n");
    }

}

int main() { 
    int numero;
    char cpf[12];

    printf("Digite quantos CPFS deseja verificar: ");
    scanf("%d", &numero);
    
    while(numero != 0){
        printf("Digite o CPF que deseja verificar: ");
        scanf("%s", cpf);
        validarCpf(cpf);
        numero -= 1;
    }

    return 0;
}