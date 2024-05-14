#include<stdio.h>
#include<string.h>
#include"genlib.h"
#include"simpio.h"

void DateString(int day, int month, int year, char date[]);

int main(){
    int day, month, year;
    char date[10];
    day=(printf("Dwse thn hmera: "),GetInteger());
    month=(printf("Dwse ton mhna: "),GetInteger());
    year=(printf("Dwse ton xrono: "),GetInteger());
    DateString(day, month, year, date);
    puts(date);




return 0;
}


void DateString(int day, int month, int year, char date[]){
    int next;
    char helpingstring[10];
    sprintf(date, "%d", day);
    if(day > 9){
        date[2]= '-' ;
        next=3;
    }else{
        date[1]= '-' ;
        next=2;
    }

    if(month == 1){
        strcat(date, "Jan");
    }else if(month == 2){
        strcat(date, "Feb");
    }else if(month == 3){
        strcat(date, "Mar");
    }else if(month == 4){
        strcat(date, "Apr");
    }else if(month == 5){
        strcat(date, "May");
    }else if(month == 6){
        strcat(date, "Jun");
    }else if(month == 7){
        strcat(date, "Jul");
    }else if(month == 8){
        strcat(date, "Aug");
    }else if(month == 9){
        strcat(date, "Sep");
    }else if(month == 10){
        strcat(date, "Oct");
    }else if(month == 11){
        strcat(date, "Nov");
    }else{
        strcat(date, "Dec");
    }

    date[next+3]= '-' ;
    next+=4;
    sprintf(helpingstring, "%d", year);
    date[next]=helpingstring[2];
    date[next+1]=helpingstring[3];
    date[next+2]= '\0';

}

