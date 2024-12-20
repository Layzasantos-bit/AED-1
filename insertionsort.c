#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max 400000

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

int main(void){
   clock_t start, end;
   double cpu_time_used;
   srand(time(NULL));

   int n=max;
   int vector[max];

   for(int i=0; i<n; i++){
    vector[i]=rand()%100000;
   }
    
    printf("vetor original:\n");
    for(int i=0; i<10; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    start=clock();
    
    insertion(vector, n);

    end=clock();

    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    
    printf("vetor ordenado:\n");
     for(int i=0; i<10; i++){
        printf("%d ", vector[i]);
    }

    printf("\n");
    
    printf("tempo de cpu usado: %.6f segundos\n", cpu_time_used);
    

}
