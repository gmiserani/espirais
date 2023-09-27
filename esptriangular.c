#include <stdio.h>
#include <math.h>

void coordQuadradoPerfeito(int qp, int* x, int* y){
    if(qp % 2 != 0){
        *x = sqrt(qp);
        *y = -1*(floor(sqrt(qp)/2));
    }
    else{
        *x = -1*sqrt(qp);
        *y = -1*(sqrt(qp)/2);
    }
}
void coordNumero(int numero, int quadradProx, int x, int y, int *coordx, int *coordy){
    int diferenca;
    if(quadradProx %2 != 0){
        if (numero < quadradProx){
            diferenca = quadradProx - numero;
            *coordy = y;
            *coordx = x - diferenca;
        }
        else if(numero == quadradProx){
            *coordy = y;
            *coordx = x;
        }
        else{
            diferenca = numero - quadradProx;
            *coordy = y + diferenca;
            *coordx = x - diferenca;
        }
    }
    else{
        if (numero < quadradProx){
            diferenca = quadradProx - numero;
            *coordy = y + diferenca;
            *coordx = x + diferenca;
        }
        else if(numero == quadradProx){
            *coordx = x;
            *coordy = y;
        }
        else{
            diferenca = numero - quadradProx;
            *coordx = x + diferenca;
            *coordy = y;
        }
    }
}

int main(){
    int x;
    int y;
    int coordx;
    int coordy;
    int numero;
    int raizProx;
    int quadradoProx;

    scanf("%d", &numero);
    raizProx = round(sqrt(numero));
    quadradoProx = pow(raizProx, 2);
    coordQuadradoPerfeito(quadradoProx, &x, &y);
    coordNumero(numero, quadradoProx, x, y, &coordx, &coordy);
    printf("(%d,%d)", coordx, coordy);
}