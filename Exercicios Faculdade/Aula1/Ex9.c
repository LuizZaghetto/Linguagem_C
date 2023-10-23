// Uma certa importância será dividida entre três ganhadores de um concurso. 

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {

    float valorconcurso, ven1, ven2, ven3;
    printf("Qual o prêmio total? ");
    scanf("%f", &valorconcurso);

    ven1 = valorconcurso * 0.46;
    ven2 = valorconcurso * 0.32;
    ven3 = valorconcurso * 0.22;

    printf("O primeiro ganhador recebeu %f, o segundo recebeu %f e o terceiro recebeu %f, de um prêmio total de %f", ven1, ven2, ven3, valorconcurso);
    







}