/**

 * Created on Aug, 22th 2024
 * Author: Paulo Rosado - 3ºB
 * Questão 1 - 24/08/2024 15:57
 * Questão 2 - 24/08/2024 18:07

**/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void toHexa(int num);
void toOctal(int num);
void toBinary(int num);
void toCodeBCD(int num);
char* complementoA2(char * binary);
char* intToBinary(int num, int numBits);

int main() {

    system("clear");

    printf("Calculadora Didática\n\n");

    int option;

        printf("Digite [1] para converter um número da base 10 para 2, 8, 16 e BCD\nDigite [2] para aplicar Complemento a 2 com 16 bits em um número da base 10\nDigite [3] para converter de real para float e double\n\nDigite: ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                system("clear");

                printf("Digite o número para ser convertido: ");

                int num;

                scanf("%d", &num);

                printf("\nDigite [1] para converter em Binário(2)\nDigite [2] para converter em Octal(8)\nDigite [3] para converter em Hexadecimal(16)\nDigite [4] para exibir o código BCD\n\nDigite: ");

                int choise;

                scanf("%d", &choise);

                switch (choise) {
                    case 1:
                        toBinary(num);
                        break;
                    
                    case 2:
                        toOctal(num);
                        break;

                    case 3:
                        toHexa(num);
                        break;
                    
                    case 4:
                        toCodeBCD(num);
                        break;

                    default:
                        system("clear");

                        printf("Comando Inválido ");

                        fflush(stdout);

                        sleep(1);

                        system("clear");

                        break;
                }

                break;

            case 2:
                system("clear");

                printf("Digite o número para ser convertido em Complemento a 2 (16 bits): ");

                scanf("%d", &num);

                system("clear");

                sleep(1);

                printf("Convertendo %d em Binário de 16 bits...\n\n", num);

                sleep(1);

                printf("%s\n\n", intToBinary(num, 16));

                sleep(1);

                printf("Mantendo todos os bits até o primeiro 1 da Direita para a Esquerda...\n\n");

                sleep(1);

                printf("Invertendo os demais...\n\n");

                sleep(1);

                printf("Resultado: %s\n\n", complementoA2(intToBinary(num, 16)));

                break;

            default:
                system("clear");

                printf("\nComando Inválido\n\n");

                break;
        }

    return 0;
}

void toBinary(int num) {

    system("clear");

    fflush(stdout);

    printf("Convertendo %d em Binário...\n", num);

    printf("\n");

    if (num != 0) {
        int bits[64];

        int cont = 0;

        sleep(1);

        while (num != 0) {
            printf("%d / 2 = %d | Resto: %d\n\n", num, num/2, num%2);

            bits[cont] = num%2;

            num = num / 2;

            cont++;

            usleep(500000);   
        }

        printf("Invertendo os restos...\n\n");

        sleep(1);

        printf("Resultado: ");
        
        for (int i = cont-1; i >= 0; i--) {
            printf("%d", bits[i]);
        }
    } else {
        sleep(1);

        printf("Resultado: 0");
    }
    printf("\n\n");
}

void toOctal(int num) {
    system("clear");

    fflush(stdout);

    printf("Convertendo %d em Octal...\n", num);

    printf("\n");

    if (num != 0) {
        int bits[64];

        int cont = 0;

        sleep(1);

        while (num != 0) {
            printf("%d / 8 = %d | Resto: %d\n\n", num, num/8, num%8);

            bits[cont] = num%8;

            num = num / 8;

            cont++;

            usleep(500000);   
        }

        printf("Invertendo os restos...\n\n");

        sleep(1);

        printf("Resultado: ");
        
        for (int i = cont-1; i >= 0; i--) {
            printf("%d", bits[i]);
        }
    } else {
        sleep(1);

        printf("Resultado: 0");
    }
    printf("\n\n");
}

void toHexa(int num) {
    system("clear");

    fflush(stdout);

    printf("Convertendo %d em Hexadecimal...\n", num);

    printf("\n");

    if (num != 0) {
        int bits[64];

        int cont = 0;

        sleep(1);

        while (num != 0) {
            char letters[] = "ABCDEF";
            if (num%16 > 9) {
                printf("%d / 16 = %d | Resto: %d (%c)\n\n", num, num/16, num%16, letters[(num%16) - 10]);
            } else {
                printf("%d / 16 = %d | Resto: %d\n\n", num, num/16, num%16);
            }

            bits[cont] = num%16;

            num = num / 16;

            cont++;

            usleep(500000);
        }

        printf("Invertendo os restos...\n\n");

        sleep(1);

        printf("Resultado: 0x");
        
        for (int i = cont-1; i >= 0; i--) {
            char letters[] = "ABCDEF";
            if (bits[i] > 9) {
                printf("%c", letters[bits[i] - 10]);
            } else {
                printf("%d", bits[i]);
            }
        }
    } else {
        sleep(1);

        printf("Resultado: 0");
    }
    printf("\n\n");
}

void toCodeBCD(int num) {
    system("clear");

    fflush(stdout);

    int qntAlgarismos = 1;
    int numero = num;

    while(num/10 > 0) {
        qntAlgarismos++;
        num = num / 10;
    }

    int algarismos[qntAlgarismos];

    printf("Exibindo %d em Código BCD...\n\n", numero);

    sleep(1);

    printf("Separando algarismos...\n\n");

    sleep(1);

    for (int i = qntAlgarismos - 1; i >= 0; i--) {
        algarismos[i] = numero % 10;
        numero /= 10;
    }

    for (int i = 0; i < qntAlgarismos; i++) {
        printf("%d ", algarismos[i]);
    }

    printf("\n\n");

    printf("Convertendo algarismos para Binário...\n\n");

    sleep(1);

    printf("Resultado: ");

    for (int i = 0; i < qntAlgarismos; i++) {
        printf("%s ", intToBinary(algarismos[i], 4));
    }

    printf("\n\n");

}

char* intToBinary(int num, int numBits) {
    char* binaryStr = (char*)malloc(numBits+1);
    if (!binaryStr) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    binaryStr[numBits] = '\0';

    for (int i = numBits-1; i >= 0; i--) {
        binaryStr[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }

    return binaryStr;
}

char* complementoA2(char * binary) {
    char* binaryStr = (char*)malloc(17);
    if (!binaryStr) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    binaryStr[16] = '\0';

    int pode = 0;

    for (int i = 15; i >= 0; i--) {
        if (pode) {
            if (binary[i] == '0') {
                binaryStr[i] = '1';
            } else {
                binaryStr[i] = '0';
            }
        } else {
            binaryStr[i] = binary[i];
        }
        if (binary[i] == '1') {
            pode = 1;
        }
    }

    return binaryStr;
}