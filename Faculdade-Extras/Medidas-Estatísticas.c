int calcularSoma(int vetor[], int tamanho) {
    int soma
    int i;
    for (i = 0; i < tamanho; i++) {
        resultado += vetor[i];
    }
    return soma;
}
int calcularmedia(int soma, int tamanho) {
    int media = 0;
    media = soma / tamanho;
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
int calcularmoda(int v[], int tamanho, int *moda, int *frequencia) {
    int i, j, contador, frequenciaMax = 0, modaAtual = v[0];
    for(i = 0; i < tamanho - 1; i++) {
        contador = 0;
        for(j = 0; j < tamanho; j++) {
            if(v[i] == v[j]) {
                contador++;
            }
        }
        if(contador > frequenciaMax) {
            frequenciaMax = contador;
            modaAtual = v[i];
        }
    }
    *frequencia = frequenciaMax;
    *moda = modaAtual;
    return modaAtual;
}
int calcularamplitude(int v[],int tamanho) {
    int amplitude = v[tamanho - 1] - v[0];
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
    int i;
    for(i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    int media = soma / tamanho;
    int CV = (std / media) * 100;
    return CV;
}
