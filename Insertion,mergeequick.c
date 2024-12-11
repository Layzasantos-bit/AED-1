#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define max 10

int dividir(int vetor[], int esq, int dir){
    int aux;
    int cont=esq;

    for(int i=esq+1; i<=dir; i++){
        if(vetor[i]<vetor[esq]){
            cont++;
            aux=vetor[i];
            vetor[i]=vetor[cont];
            vetor[cont]=aux;
        }
    }
    aux=vetor[esq];
    vetor[esq]=vetor[cont];
    vetor[cont]=aux;

    return cont;
}

void quick(int vetor[], int esq, int dir){
    int pos;
    if(esq<dir){
        pos=dividir(vetor, esq, dir);
        quick(vetor, esq, pos-1);
        quick(vetor, pos+1, dir);
    }
}

void insertion(int vetor[], int n){
    int i, j, aux;

    for(j=1; j<n; j++){
        aux=vetor[j];
     
     for(i=j-1; i>=0 && vetor[i]>aux; i--){
        vetor[i+1]=vetor[i];
        
     }
     vetor[i+1]=aux;
}
}

void intercala(int p, int q, int r, int vetor[]){
    int i, j, k, *w;

    w=malloc((r-p)*sizeof(int));
    i=p; j=q; k=0;

    while(i<q && j<r){
        if(vetor[i]<=vetor[j]){
            w[k++]=vetor[i++];
        }else{
            w[k++]=vetor[j++];
        }
        
    }

    while(i<q){ 
        w[k++]=vetor[i++];
    }
    while(j<r){ 
        w[k++]=vetor[j++];
    }
    for(i=p; i<r; i++){
        vetor[i]=w[i-p];
    }
    free(w);

}

void mergesort(int p, int r, int vetor[]){
    if(p< r-1){
        int q=(p+r)/2;
        mergesort(p, q, vetor); 
        mergesort(q, r, vetor); 
        intercala(p, q, r, vetor); 
    }
}





int main(void){
    clock_t start, end;
    double cpu_time_used;
    srand(time(NULL));
    
    int vector[max];
    
    for(int i=0; i<max; i++){
    vector[i]=rand()%100000;
   }

    printf("vetor original quick:\n");
    for(int i=0; i<max; i++){
        
    }
    
    printf("\n");
    
    start=clock();

    quick(vector, 0, max-1);
    
    end=clock();

    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("vetor ordenado quick:\n");
    for(int i=0; i<max; i++){
    
    }
    
    printf("\n");
    
    printf("tempo de cpu usado: %.6f segundos\n", cpu_time_used);
    
    printf("\n");

    for(int i=0; i<max; i++){
    vector[i]=rand()%100000;
   }
    
    printf("vetor original insertion:\n");
    for(int i=0; i<10; i++){
        
    }
    printf("\n");
    
    start=clock();
    
    insertion(vector, max);

    end=clock();

    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("vetor ordenado insertion:\n");
     for(int i=0; i<10; i++){
        
    }

    printf("\n");
    
    printf("tempo de cpu usado: %.6f segundos\n", cpu_time_used);
    
    printf("\n");
    
    for(int i=0; i<max; i++){
        vector[i]=rand() % 100000;
    }

    
    printf("vetor original merge:\n");
    for(int i=0; i<10; i++){
        
    }

    printf("\n");

    start=clock();

    mergesort(0, max, vector); 

   

    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("vetor ordenado merge:\n");
     for(int i=0; i<10; i++){
        
    }

    printf("\n");
    
    printf("tempo de cpu usado: %.6f segundos\n", cpu_time_used);
}
