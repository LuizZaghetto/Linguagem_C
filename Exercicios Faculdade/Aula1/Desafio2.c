// Crie um programa que leia um valor de hora e informe quantos minutos se passaram desde o início do dia.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {

    int horatual, minutoatual, totalminutos, totaldia, totalrestante;
    
    printf("Digite a hora atual, não use AM/PM ");
    scanf("%d", &horatual);

    printf("Digite o minuto atual ");
    scanf("%d", &minutoatual);

    totalminutos = (horatual * 60) + minutoatual;
    totaldia = 24 * 60;
    totalrestante = totaldia - totalminutos;

    printf("Tendo em mente que um dia completo tem %d minutos, e já se passaram %d min desse dia, se restam %d min", totaldia, totalminutos, totalrestante);






}