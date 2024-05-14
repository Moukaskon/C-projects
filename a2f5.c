#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

#define CL1 5220
#define CL2 7320
#define CL3 9720
#define CL4 17000
#define CL5 21950
#define CL6 29550
#define CL7 42450
#define CL8 52250

int main(){
    long income=GetLong();
    printf("%ld Euro\n",income);
    long tax,totaltax;
    if(income<=10000){
        printf("%ld",0);
        tax=0;
        totaltax=0;
    }else if(income<=39000){
        printf("%ld",0);
        tax=(income-10000)*0.18;
        totaltax=(income-10000)*0.18;
    }else if(income<=49000){
        printf("%ld",CL1);
        tax=(income-39000)*0.21;
        totaltax=CL1+(income-39000)*0.21;
    }else if(income<=59000){
        printf("%ld",CL2);
        tax=(income-49000)*0.24;
        totaltax=CL2+(income-49000)*0.24;
    }else if(income<=85000){
        printf("%ld",CL3);
        tax=(income-59000)*0.28;
        totaltax=CL3+(income-59000)*0.28;
    }else if(income<=100000){
        printf("%ld",CL4);
        tax=(income-85000)*0.33;
        totaltax=CL4+(income-85000)*0.33;
    }else if(income<=120000){
        printf("%ld",CL5);
        tax=(income-100000)*0.38;
        totaltax=CL5+(income-100000)*0.38;
    }else if(income<=150000){
        printf("%ld",CL6);
        tax=(income-120000)*0.43;
        totaltax=CL6+(income-120000)*0.43;
    }else if(income<=170000){
        printf("%ld",CL7);
        tax=(income-150000)*0.49;
        totaltax=CL7+(income-150000)*0.49;
    }else{
        printf("%ld",CL8);
        tax=(income-170000)*0.5;
        totaltax=CL8+(income-170000)*0.5;
    }
    printf(" Euro\n%ld Euro\n%ld Euro",tax,totaltax);

return 0;
}
