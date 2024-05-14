#include<stdio.h>
#include<string.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    int L, length, diff, i;
    char *string, *helpingstring;
    long number;
    L=(printf("Dwse to mhkos tou arithmou: "),GetInteger());
    string=(char *)malloc(L * sizeof(char));
    helpingstring=(char *)malloc(L * sizeof(char));
    number=(printf("Dwse ton arithmo: "),GetLong());
    sprintf(string, "%ld", number);
    length=strlen(string);
    if(length!=L){
        diff=L-length;
        for(i=0; i < diff; i++){
            helpingstring[i]= '0' ;
        }
        strcat(helpingstring, string);
        helpingstring[i+length]= '\0';
        puts(helpingstring);
    }else{
        puts(string);
        }


return 0;
}
