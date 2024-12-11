#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 400000

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
   
    
    int n=max;
    int vector[max];

    for(int i=0; i<n; i++){
        vector[i]=rand() % 100000;
    }

    
    printf("vetor original:\n");
    for(int i=0; i<10; i++){
        printf("%d ", vector[i]);
    }

    printf("\n");

    start=clock();

    mergesort(0, n, vector); 

   

    end=clock();
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("vetor ordenado:\n");
     for(int i=0; i<10; i++){
        printf("%d ", vector[i]);
    }

    printf("\n");
    
    printf("tempo de cpu usado: %.6f segundos\n", cpu_time_used);



}
