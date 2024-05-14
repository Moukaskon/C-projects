#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

void inputArray(int tab[], int N);
void inputNumbers(int *a, int *b);
void performCaclulations(int *greater, int *smaller, int *middle, int tab[], int n, int A, int B);
void ShowResults(int n, int tab[], int A, int B, int smaller, int middle, int greater);

int main(){
    int array[100], A, B, greater=0, smaller=0, middle=0;
    int N=(printf("Give n:"),GetInteger());
    inputArray(array, N);
    inputNumbers(&A, &B);
    performCaclulations(&greater, &smaller, &middle, array, N, A, B);
    ShowResults(N, array, A, B, smaller, middle, greater);




return 0;
}


void inputArray(int tab[], int N){
    for(int i=0;i<N;i++){
        tab[i]=(printf("Give element [%d]: ",i),GetInteger());
    }
}

void inputNumbers(int *a, int *b){
    *a=(printf("Give A: "),GetInteger());
    *b=(printf("Give B: "),GetInteger());
}

void performCaclulations(int *greater, int *smaller, int *middle, int tab[], int n, int A, int B){
    for(int i=0;i<n;i++){
       if(tab[i]<=A){
            *smaller+=1;
       }
       if(tab[i]>A && tab[i]<B){
            *middle+=1;
       }
       if(tab[i]>=B){
            *greater+=1;
       }
    }
}


void ShowResults(int n, int tab[], int A, int B, int smaller, int middle, int greater){
    printf("\n----The numbers of the array-----\n");
    for(int i=0;i<n;i++){
        printf("%d ",tab[i]);
    }
    printf("\nA = %d\n",A);
    printf("B = %d\n",B);
    printf("Numbers smaller or equal to A: %d\n",smaller);
    printf("Numbers bigger or equal to B: %d\n",greater);
    printf("Numbers bigger than A and smaller than B: %d\n",middle);

}
