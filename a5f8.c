#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

#define POLEIS 4

typedef struct{
    int code;
    char name[16];
    long sold;
    int location;
}salesmenT;

void insertData(salesmenT allsalesmen[], int N);
long calcTotals(salesmenT allsalesmen[], int N, long totals[]);
void showData(int N, long alltotal, long totals[]);

int main(){
    salesmenT allsalesmen[20];
    long totals[POLEIS], alltotal;
    int count;
    count=(printf("Dwse to plhthos twn pwlhtwn?"),GetInteger());
    insertData(allsalesmen, count);
    alltotal=calcTotals(allsalesmen, count, totals);
    showData(count, alltotal, totals);



return 0;
}

void insertData(salesmenT allsalesmen[], int N){
    int i=0;
    for(i=0; i < N; i++){
        allsalesmen[i].code=(printf("Kwdikos? "), GetInteger());
        (printf("Onomatepwnhmo? "), fgets(allsalesmen[i].name,sizeof(allsalesmen[i].name),stdin));
        allsalesmen[i].sold=(printf("Poso pwlhsewn? "), GetLong());
        allsalesmen[i].location=(printf("Kwdikos (1= Thes/niki, 2= Athens, 3= Volos, 4= Hrakleio)? "), GetInteger());
    }

}

long calcTotals(salesmenT allsalesmen[], int N, long totals[]){
    int i,j;
    long alltotal=0;
    for(i=0; i < POLEIS; i++){
        totals[i]=0;
        for(j=0; j < N; j++){
            if(allsalesmen[j].location==i+1){
                totals[i]+=allsalesmen[j].sold;
            }
        }
        alltotal+=totals[i];
    }

return alltotal;
}

void showData(int N, long alltotal, long totals[]){
    int i;
    printf("%11s %-24s\n", "PERIOXH", "SYN.PWLHSEWN");
    printf("------------------------\n");
    for(i=0; i < POLEIS; i++){
        if(i==0){
            printf("%11s %12ld\n", "Thes/niki", totals[i]);
        }else if(i==1){
            printf("%11s %12ld\n", "Athens", totals[i]);
        }else if(i==2){
            printf("%11s %12ld\n", "Volos", totals[i]);
        }else{
            printf("%11s %12ld\n", "Hrakleio", totals[i]);
        }

    }
    printf("------------------------\n");
    printf("%11s %12ld", "SYNOLO:", alltotal);

}
