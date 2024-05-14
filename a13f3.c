#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    int n=(printf("Dwse orio: "),GetInteger());
    int i=1;
    float sum=0;
    while (i<=n){
        sum += 1.0/i;
        i++;
    }
    printf("To athroisma einai %.2f",sum);


return 0;
}
