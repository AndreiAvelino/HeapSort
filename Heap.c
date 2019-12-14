#include <stdio.h>

void heapsort(int *vet, int tam){
    
    int aux;
    
    for (int i = tam/2-1; i >= 0; i--){
        ordenar(vet, i, tam);
    }
    
    for (int i = tam-1; i>=0; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        ordenar(vet, 0, i-1);
    }
    
    for (int i = 0; i <= tam-1; i++){
        printf("%d ", vet[i]);
    }
    
}

void ordenar(int *vet, int pai, int ultimo){
    
    int aux;
    int filho;
    
    if (pai*2+1 <= ultimo){
        if (pai*2+1 == ultimo){
            filho = pai*2+1;
        }
        else if (vet[pai*2+1] > vet[pai*2+2]){
            filho = pai*2+1;
        }
        else{
            filho = pai*2+2;
        }
        
        if (vet[filho] > vet[pai]){
            aux = vet[pai];
            vet[pai] = vet[filho];
            vet[filho] = aux;
            pai = filho;
            ordenar(vet, pai, ultimo);
        }
        
    }
    
}

int main()
{
    int vet[10] = {3,2,1,6,5,4,9,8,7,0};
    int k = 10;
    
    heapsort(vet, k);

    return 0;
}

