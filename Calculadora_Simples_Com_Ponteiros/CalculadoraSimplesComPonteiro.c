#include <stdio.h>

void somar(float num1, float num2, float *resultado), subtrair(float num1, float num2, float *resultado), dividir(float num1, float num2, float *resultado), multiplicar(float num1, float num2, float *resultado);

int main() {
    
    int escolha;
    while(1){
        float num1, num2, resultado;
        printf("-----------------Calculadora-----------------\n1 - Somar\n2 - Subtrair\n3 - Dividir\n4 - Multiplicar\n5 - Sair\nDigite a opcao desejada: \n");
        scanf("%d", &escolha);
        if(escolha == 5){
            break;
        }
        else if(escolha == 1){
                printf("Digite o primeiro numero: \n");
                scanf("%f", &num1);
                printf("Digite o segundo numero: \n");
                scanf("%f", &num2);
                somar(num1, num2, &resultado);
                printf("Resultado: %.2f\n", resultado);
        }
        else if(escolha == 2){
                printf("Digite o primeiro numero: \n");
                scanf("%f", &num1);
                printf("Digite o segundo numero: \n");
                scanf("%f", &num2);
                subtrair(num1, num2, &resultado);
                printf("Resultado: %.2f\n", resultado);
            }
            else if(escolha == 3){
                printf("Digite o primeiro numero: \n");
                scanf("%f", &num1);
                printf("Digite o segundo numero: \n");
                scanf("%f", &num2);
                dividir(num1, num2, &resultado);
                printf("Resultado: %.2f\n", resultado);
            }
            else if(escolha == 4){
                printf("Digite o primeiro numero: \n");
                scanf("%f", &num1);
                printf("Digite o segundo numero: \n");
                scanf("%f", &num2);
                multiplicar(num1, num2, &resultado);
                printf("Resultado: %.2f\n", resultado);
            }
            else{
                printf("Opcao invalida\n");
            }
        
    }

   return 0;

}


void somar(float num1, float num2, float *resultado) {
    *resultado = num1 + num2;
}

void subtrair(float num1, float num2, float *resultado) {
    *resultado = num1 - num2;
}

void dividir(float num1, float num2, float *resultado) {
    *resultado = num1 / num2;
}

void multiplicar(float num1, float num2, float *resultado) {
    *resultado = num1 * num2;
}

