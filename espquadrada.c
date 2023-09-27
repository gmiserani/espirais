#include <stdio.h>
#include <math.h>

void coordQuadradPerf(int n, int *x, int *y){
    if (n%2 != 0){
        *x = floor(sqrt(n)/2);
        *y = ceil(sqrt(n)/2);
    }
    else{
        *x = -1 * (sqrt(n)/2);
        *y = -1 * (sqrt(n)/2);
    }
}

void coordenada(int n, int quadradprox, int x, int y, int* coordx, int* coordy){
    int diferenca;
    if (quadradprox % 2 != 0){
        if(n < quadradprox){
            *coordx = x;
            diferenca = quadradprox - n;
            *coordy = y - diferenca;
        }
        else if(quadradprox < n){
            diferenca = n - quadradprox;
            *coordx = x - diferenca;
            *coordy = y;
        }
        else{
            *coordx = x;
            *coordy = y;
        }
    }else{
        if(n > quadradprox){
            diferenca = n - quadradprox;
            *coordx = x + diferenca;
            *coordy = y;
        }
        else if(n < quadradprox){
            diferenca = quadradprox - n;
            *coordx = x;
            *coordy = y + diferenca;
        }
        else{
            *coordx = x;
            *coordy = y;
        }
    }
}

int main(){
    int n;
    int raizprox;
    int quadradprox;
    int x;
    int y;
    int coordx;
    int coordy;
    scanf("%d", &n);
    raizprox = round(sqrt(n));
    quadradprox = pow(raizprox, 2);
    coordQuadradPerf(quadradprox, &x, &y);
    coordenada(n, quadradprox, x, y, &coordx, &coordy);
    printf("(%d,%d)", coordx, coordy);
    return 0;
}