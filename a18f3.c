#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    int max,min;
    int counter=0;
    long total=0;
    while(total<100000){
        long amount=(printf("Dwse poso:"),GetInteger());
        counter++;
        if(counter==1){
            max=amount;
            min=amount;
        }
        if(amount>max){
            max=amount;
        }
        if(amount<min){
            min=amount;
        }
        total+=amount;
    }

    printf("Plithos atomwn: %d",counter);
    printf("\nSynoliko poso: %ld",total);
    printf("\nMegalytero poso: %d  ",max);
    printf("Mikrotero poso: %d",min);

return 0;
}
