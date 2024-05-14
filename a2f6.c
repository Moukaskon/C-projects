#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int readData(int numbers[]);
void findMinMax(int numbers[], int limit, int *max, int *min);

int main(){
    int numbers[100],max,min,limit;
    printf("Enter the elements of the array, one per line.\nUse -1 to signal the end of the list.\n");
    limit=readData(numbers);
    findMinMax(numbers, limit, &max, &min);
    printf("The range of values is %d-%d",min, max);

return 0;
}



int readData(int numbers[]){
    int counter=0;
    int x;
    printf("?");
    x=GetInteger();
    while(x!=-1){
        numbers[counter]=x;
        counter+=1;
        printf("?");
        x=GetInteger();
    }
return counter;
}

void findMinMax(int numbers[], int limit, int *max, int *min){
    int i;
    *max=numbers[0];
    *min=numbers[0];
    for(i=1;i<limit;i++){
        if(numbers[i]>*max){
            *max=numbers[i];
        }
        if(numbers[i]<*min){
            *min=numbers[i];
        }
    }


}
