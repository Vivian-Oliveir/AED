//Implemente uma funcao que calcule a area da superfıcie e o volume de uma esfera de
//raio R. Essa funcao deve obedecer ao prototipo:
//void calc_esfera(float R, float *area, float *volume)
//A area da superfıcie e o volume sao dados, respectivamente, por:
//A = 4 ∗ p ∗ R2
//V = 4/3 ∗ p ∗ R3
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846

void calc_esfera(float R, float *area, float *volume);

int main(){
    float R, *area, *volume;
    area = (float*)malloc(sizeof(float));
    volume = (float*)malloc(sizeof(float));
    printf("Digite o tamanho do raio: ");
    scanf("%f",&R);
    calc_esfera(R, area, volume);
    printf("Área: %.2f\nVolume: %.2f", *area, *volume);
    return 0;
}

void calc_esfera(float R, float *area, float *volume){
    *area = 4 * PI * R * R;
    *volume = (4 * PI * R * R * R)/3;
}
