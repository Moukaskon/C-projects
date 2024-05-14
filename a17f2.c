#include<stdio.h>
#include"genlib.h"
#include"simpio.h"


int main(){
    int seats=(printf("Dwse theseis:"),GetInteger());
    int passengers=(printf("\nDwse epibates:"),GetInteger());
    double percent30=seats*0.3;
    double percent50=seats*0.5;
    if(passengers>=percent50){
        printf("Kerdos");
    }else if(passengers<percent30){
        printf("Zimia");
    }else{
        printf("Kostos");

    }
return 0;
}
