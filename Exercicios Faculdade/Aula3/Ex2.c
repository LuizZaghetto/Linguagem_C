// Elabore um algoritmo, da forma mais eficiente possível, que imprima
// os 10 primeiros números pares. 

#include <stdlib.h>
#include <stdio.h>




    int main()
    {
        int num = 1;
        int i = 0;



        for(i = 0; i <= 20; i++){

            if (num % 2 == 0) {
                printf("%d\n", num);
            }
            num++;
        }


}