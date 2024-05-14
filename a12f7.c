#include<stdio.h>
#include<string.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    char thesis[100][20];
    int i, j;
    char ending[]= "----" ;
    i=0;
    while(i < 101){
        printf("Passenger in seat %d :",i+1);
        gets(thesis[i]);
        j=0;
        while(j < i){
            if(strcmp(thesis[j], thesis[i]) == 0){
                printf("Passenger %s already exists.\n",thesis[i]);
                printf("Passenger in seat %d :",i+1);
                gets(thesis[i]);
                j=0;
            }else{
                j++;
            }
        }
        i++;
        if(strcmp(thesis[i-1], ending) == 0){
            break;
        }
    }
    printf("Passenger list\n--------------\n");
    for(j=0;j<i-1;j++){
        printf("In seat %d:%s\n",j+1,thesis[j]);
    }

return 0;
}
