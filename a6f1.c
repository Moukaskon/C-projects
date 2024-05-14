#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    int workdays;
    long salary;
    double presentrate;
    double totalPresent;
    printf("Dwse tis hmeres ergasias tou etous: ");
    workdays=GetInteger();
    printf("\nDwse thn hmerhsia amoibh: ");
    salary=GetLong();
    printf("\nDwse to pososto dwroy: ");
    presentrate=GetReal();
    totalPresent=(workdays*salary)*presentrate;
    printf("\nTo dwro einai:%g ",totalPresent);
    return 0;
}
