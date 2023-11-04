#include "funcoes-8Puzzle.h"
int main() {
<<<<<<< HEAD
    jogar();
}
=======

    int **matrizona;
    matrizona = criaMatriz();
    matrizona = prencheMatriz();
    printaMatriz(matrizona);


    //Libera o espaço ocupado pela matriz na memória
    for (int i = 0; i < 3; i++) {
    free(matrizona[i]);
    }
    free(matrizona);
    
    
    return 0;
}
>>>>>>> c820a1edb907ae6e2a543d521a3bda7508fc7069
