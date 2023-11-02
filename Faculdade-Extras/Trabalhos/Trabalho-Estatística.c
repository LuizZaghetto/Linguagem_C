#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define tam 20

int calcularSoma(int vetor[], int tamanho) {
    int resultado = 0;
    int i;
    for (i = 0; i < tamanho; i++) {
        resultado += vetor[i];
    }
    return resultado;
}
int calcularmedia(int soma2, int tamanho) {
    int media = 0;
    media = soma2 / tamanho;
    return media;
}   
int calcularmediana(int v[], int tamanho) {
    int mediana;
    if(tamanho % 2 ==0) {
        mediana = (v[(tamanho / 2) - 1] + v[tamanho / 2]) / 2;
    }
    else{
        mediana = v[tam / 2];
    }
    return mediana;
}
void calcularmoda(int vetor[tam]){
    int contadormin=0,contadormax=0,contador=0,numultimo=0,contador2=-1,pos=0, moda[tam] = {0};
    for (int i = 0;i<tam;i++){
            contador=0;
        for(int j = 0;j<tam;j++){
            if(vetor[i] == vetor[j] && i != j){
                contador ++;
            }
        }
        if (i == 0) {
            contadormin = contadormax = contador;
        }else{
            if (contador > contadormax) {
                contadormax = contador;
            }else{
                if (contadormin > contador){
                    contadormin = contador;
                }
            }
        }
    }
    printf("A moda é: ");
    if(contadormax != contadormin){
        for(int i = 0;i<tam;i++){
            contador=0;
            for(int j = 0;j<tam;j++){
                if(vetor[i] == vetor[j] && i != j){
                    contador++;
            if(contador == contadormax && numultimo != vetor[i]){
                    if (moda[0] == 0){
                        numultimo =  vetor[i];
                        moda[pos] = numultimo;
                    }else{
                        for(int k=0;k<tam;k++){
                            if(moda[k] == vetor[i]){
                                contador2 = -1;
                                break;
                            }else{
                                contador2 = 0;
                            }
                        }
                        if(contador2 != -1){
                            pos++;
                            numultimo =  vetor[i];
                            moda[pos] = vetor[i];
                        }
                    }
                    }
                }

            }
        }

    }else{
        if(contadormax == contadormin && contadormin == tam-1){
            printf("%d ",vetor[0]);
        }else{
            printf("NAO EXISTE MODA\n");
        }
    }
    for (int i=0;i<tam;i++){
        if(moda[i] != 0 && i==0){
            printf("[%d",moda[i]);
        }
        if(moda[i] != 0 && i!=0){
            printf(",%d",moda[i]);
        }
        if(i == tam -1){
            printf("]\n");
        }
    }
}
int calcularamplitude(int v[],int tamanho) {
    int amplitude = v[0] - v[tamanho - 1];
    return amplitude;
}
int calcularvar(int v[], int tamanho,int media) {
    int i;
    int somadif = 0, var = 0;
    for(i = 0; i < tamanho; i++) {
        int dif= v[i] - media;
        somadif += dif * dif; 
    }
    var = somadif / tamanho;
    return var;
}
int calcularstd(int var) {
    int std = 0;
    std = sqrt(var);
    return std;
}
int calcularCV(int vetor[], int tamanho, int std) {
    int soma = 0.0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    int media = soma / tamanho;

    int somadif = 0.0;
    for (int i = 0; i < tamanho; i++) {
        int dif = vetor[i] - media;
        somadif += dif * dif;
    }
    float cv = ((float)std / media) * 100;
    int resultCV = (int)cv;

    return resultCV;
}
int main() {

    int vetor[tam] = {83, 78, 78, 76, 73, 73, 69, 67, 68, 65, 65, 65, 64, 63, 63, 62, 62, 61, 56, 56};
    int tamanho;

    tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int soma = calcularSoma(vetor, tamanho);
    int media = calcularmedia(soma, tamanho);
    int mediana = calcularmediana(vetor, tamanho);
    int amplitude = calcularamplitude(vetor, tamanho);
    int var = calcularvar(vetor, tamanho, media);
    int std = calcularstd(var);
    int cv = calcularCV(vetor, tamanho, std);

    
    printf("A soma dos elementos do vetor é: %d\n", soma);
    printf("A média dos valores do vetor é de %d\n", media);
    printf("A mediana é de %d\n", mediana);
    calcularmoda(vetor);
    printf("A amplitude do seu vetor é de %d\n", amplitude);
    printf("A variância do vetor é de %d\n", var);
    printf("O desvio padrão do vetor é de %d\n", std);
    printf("O coeficiente de variação é igual a %d\n", cv);

    return 0;
}