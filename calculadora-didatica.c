/**

 * Created on Aug, 22th 2024
 * Author: Paulo Rosado - 3ºB
 * Questão 1 - 24/08/2024 15:57
 * Questão 2 - 24/08/2024 18:07
 * Questão 3 - 24/08/2024 20:48

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
char* floatToBinary(float num);
char* doubleToBinary(double num);
char* complementoA2(char * binary);
int getExpoF(char * binary, float num);
int getExpoD(char * binary, double num);
char* intToBinary(int num, int numBits);
char* notacaoCientificaF(char * binary, int fracao);
char* notacaoCientificaD(char * binary, int fracao);

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

            case 3:
                system("clear");

                printf("Digite [1] para converter em Float\nDigite [2] para converter em Double\n\nDigite: ");

                scanf("%d", &choise);

                printf("\nDigite o número para ser convertido: ");

                switch (choise) {
                    case 1:
                        float number;

                        scanf("%f", &number);

                        system("clear");

                        sleep(1);

                        printf("Convertendo %f em Float...\n\n", number);

                        sleep(1);

                        printf("Float possui 32 bits:\n              1 bit para o Sinal\n              8 bits para o Expoente\n             23 bits para a Fração\n\n");

                        sleep(1);

                        printf("Construindo bit de Sinal...\n\n");

                        char sinal;

                        if (number >= 0) {
                            printf("%f é positivo então o bit de Sinal é 0\n\n", number);
                            sinal = '0';
                        } else {
                            printf("%f é negativo então o bit de Sinal é 1\n\n", number);
                            sinal = '1';
                        }

                        sleep(1);

                        printf("Convertendo números em Binário...\n\n");

                        sleep(1);

                        printf("%d -> %s\n\n", abs((int) number), intToBinary(abs((int) number), 8));
                        printf("%f -> %s\n\n", fabs(number - ((int)number)), floatToBinary(fabs(number) - abs((int)number)));

                        sleep(1);

                        char binaryNumber[32];

                        strcpy(binaryNumber, intToBinary(abs((int) number), 8));
                        binaryNumber[8] = '.';
                        strcat(binaryNumber, floatToBinary(fabs(number) - abs((int)number)));

                        printf("Número Binário: %s\n\n", binaryNumber);

                        sleep(1);

                        printf("Flutuando o ponto para o formato de Notação Científica...\n\n");

                        sleep(1);

                        printf("%s x 2^%d\n\n", notacaoCientificaF(binaryNumber, 0), getExpoF(binaryNumber, number));

                        sleep(1);

                        printf("Calculando a representação enviesada do expoente (BIASED)...\n\n");

                        sleep(1);

                        printf("%d + 127 = %d\n\n", getExpoF(binaryNumber, number), getExpoF(binaryNumber, number) + 127);

                        sleep(1);

                        printf("Convertendo expoente em Binário...\n\n");

                        sleep(1);

                        printf("%d -> %s\n\n", getExpoF(binaryNumber, number) + 127, intToBinary(getExpoF(binaryNumber, number) + 127, 8));

                        sleep(1);

                        printf("Juntando elementos [Sinal + Expoente + Fração]...\n\n");

                        sleep(1);

                        printf("Resultado: %c %s %s00\n\n", sinal, intToBinary(getExpoF(binaryNumber, number) + 127, 8), notacaoCientificaF(binaryNumber, 1));

                        break;

                    case 2:
                        double numero;

                        scanf("%lf", &numero);

                        system("clear");

                        sleep(1);

                        printf("Convertendo %lf em Double...\n\n", numero);

                        sleep(1);

                        printf("Double possui 64 bits:\n   1 bit para o Sinal\n   11 bits para o Expoente\n   52 bits para a Fração\n\n");

                        sleep(1);

                        printf("Construindo bit de Sinal...\n\n");

                        if (numero >= 0) {
                            printf("%f é positivo então o bit de Sinal é 0\n\n", numero);
                            sinal = '0';
                        } else {
                            printf("%f é negativo então o bit de Sinal é 1\n\n", numero);
                            sinal = '1';
                        }

                        sleep(1);

                        printf("Convertendo números em Binário...\n\n");

                        sleep(1);

                        printf("%d -> %s\n\n", abs((int) numero), intToBinary(abs((int) numero), 8));
                        printf("%f -> %s\n\n", fabs(numero - ((int)numero)), doubleToBinary(fabs(numero) - abs((int)numero)));

                        sleep(1);

                        char binarynumero[32];

                        strcpy(binarynumero, intToBinary(abs((int) numero), 8));
                        binarynumero[8] = '.';
                        strcat(binarynumero, doubleToBinary(fabs(numero) - abs((int)numero)));

                        printf("Número Binário: %s\n\n", binarynumero);

                        sleep(1);

                        printf("Flutuando o ponto para o formato de Notação Científica...\n\n");

                        sleep(1);

                        printf("%s x 2^%d\n\n", notacaoCientificaD(binarynumero, 0), getExpoD(binarynumero, numero));

                        sleep(1);

                        printf("Calculando a representação enviesada do expoente (BIASED)...\n\n");

                        sleep(1);

                        printf("%d + 1023 = %d\n\n", getExpoD(binarynumero, numero), getExpoD(binarynumero, numero) + 1023);

                        sleep(1);

                        printf("Convertendo expoente em Binário...\n\n");

                        sleep(1);

                        printf("%d -> %s\n\n", getExpoD(binarynumero, numero) + 1023, intToBinary(getExpoD(binarynumero, numero) + 1023, 11));

                        sleep(1);

                        printf("Juntando elementos [Sinal + Expoente + Fração]...\n\n");

                        sleep(1);

                        printf("Resultado: %c %s %s00\n\n", sinal, intToBinary(getExpoD(binarynumero, numero) + 1023, 11), notacaoCientificaD(binarynumero, 1));

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

char* floatToBinary(float num) {

    char* binaryStr = (char*)malloc(24);

    binaryStr[23] = '\0';

    for (int i = 0; i < 23; i++) {
        if (num*2 >= 1) {
            binaryStr[i] = '1';
            num = (num*2) - 1;
        } else {
            binaryStr[i] = '0';
            num = num*2;
        }
    }

    return binaryStr;
}

char* doubleToBinary(double num) {
    char* binaryStr = (char*)malloc(53 + 1);
    if (!binaryStr) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    binaryStr[53] = '\0';

    for (int i = 0; i < 52; i++) {
        num *= 2;
        if (num >= 1) {
            binaryStr[i] = '1';
            num -= 1;
        } else {
            binaryStr[i] = '0';
        }
    }
    return binaryStr;
}

char* notacaoCientificaF(char * binary, int fracao) {
    int indexFirst1 = 0, indexPoint = 0;
    int achou1 = 0;

    for (int i = 0; i < 23; i++) {
        if (binary[i] == '1' && !achou1) {
            achou1 = 1;
            indexFirst1 = i;
        }
        if (binary[i] == '.') {
            indexPoint = i;
        }
    }

    char* binaryNotacao = (char*)malloc(24);

    binaryNotacao[0] = '1';
    binaryNotacao[1] = '.';

    int i = 2; 
    int bitCount = 0; 
    int x = indexFirst1 + 1; 

    while (x < 23 && bitCount < 23) { 
        if (x == indexPoint) {
            x++; 
        }
        binaryNotacao[i++] = binary[x++];
        bitCount++;
    }
    while (i < 23) {
        binaryNotacao[i++] = '0';
    }

    binaryNotacao[23] = '\0';

    if (fracao) {
        char* ctx = (char*)malloc(24);

        strncpy(ctx, binaryNotacao + 2, 23);

        return ctx;
    }

    return binaryNotacao;

}

int getExpoF(char * binary, float num) {
    int indexFirst1 = 0, indexPoint = 0;
    int expoente = 0;
    int achou1 = 0;

    for (int i = 0; i < 23; i++) {
        if (binary[i] == '1' && !achou1) {
            achou1 = 1;
            indexFirst1 = i;
        }
        if (binary[i] == '.') {
            indexPoint = i;
        }
    }

    if ((int) num != 0) {
        expoente = indexPoint - indexFirst1 - 1;
    } else {
        expoente = indexPoint - indexFirst1;
    }


    return expoente;
}

int getExpoD(char * binary, double num) {
    int indexFirst1 = 0, indexPoint = 0;
    int expoente = 0;
    int achou1 = 0;

    for (int i = 0; i < 52; i++) {
        if (binary[i] == '1' && !achou1) {
            achou1 = 1;
            indexFirst1 = i;
        }
        if (binary[i] == '.') {
            indexPoint = i;
        }
    }

    if ((int) num != 0) {
        expoente = indexPoint - indexFirst1 - 1;
    } else {
        expoente = indexPoint - indexFirst1;
    }


    return expoente;
}

char* notacaoCientificaD(char * binary, int fracao) {
    int indexFirst1 = 0, indexPoint = 0;
    int achou1 = 0;

    for (int i = 0; i < 52; i++) {
        if (binary[i] == '1' && !achou1) {
            achou1 = 1;
            indexFirst1 = i;
        }
        if (binary[i] == '.') {
            indexPoint = i;
        }
    }

    char* binaryNotacao = (char*)malloc(53);

    binaryNotacao[0] = '1';
    binaryNotacao[1] = '.';

    int i = 2; 
    int bitCount = 0; 
    int x = indexFirst1 + 1; 

    while (x < 52 && bitCount < 52) { 
        if (x == indexPoint) {
            x++; 
        }
        binaryNotacao[i++] = binary[x++];
        bitCount++;
    }
    while (i < 52) {
        binaryNotacao[i++] = '0';
    }

    binaryNotacao[52] = '\0';

    if (fracao) {
        char* ctx = (char*)malloc(53);

        strncpy(ctx, binaryNotacao + 2, 52);

        return ctx;
    }

    return binaryNotacao;
}