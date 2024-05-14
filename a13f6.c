#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

void decompose(long number,double *average,int *digits,int *maxdig);

int main(){
    long number=(printf("Please insert non-negative number:"),GetLong());
    double average;
    int digits,maxdig=-1;
    decompose(number,&average,&digits,&maxdig);
    printf("Digits: %d\n",digits);
    printf("Average: %.3f\n",average);
    printf("Max: %d\n",maxdig);


return 0;
}


void decompose(long number,double *average,int *digits,int *maxdig){
    int sum=0,yp;
    while(number){
        yp=number%10;
        sum+=yp;
        if(yp>*maxdig){
            *maxdig=yp;
        }
        *digits+=1;
        number/=10;
    }
    *average=(double)sum/ *digits;

}
