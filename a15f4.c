#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int menu(){
    int choice;
    printf("1. Metatroph se dollaria\n");
    printf("2. Metatroph se lires\n");
    printf("3. Metatroph se fraga Elbetias\n");
    printf("4. Metatroph se dollaria Canada\n");
    printf("5. Metatroph se gen\n");
    printf("6. Exodos\n");
    choice=(printf("Dwse thn epilogh sou:"),GetInteger());
    return choice;
}

double converter(int choice,double euros){
    double result;
    if (choice==1){
        result=euros/0.89;
    }else if(choice==2){
        result=euros/0.618;
    }else if(choice==3){
        result=euros/1.5465;
    }else if(choice==4){
        result=euros/1.3565;
    }else{
        result=euros/109.22;
    }
    return result;

}

int main(){
    int choice=menu();
    double euros,worth;
    while(choice!=6){
        euros=(printf("Dwse poso se euro: "),GetReal());
        worth=converter(choice,euros);
        if (choice==1){
            printf("To poso se dollaria einai:%.2f\n\n",worth);
        }else if(choice==2){
            printf("To poso se lires einai:%.2f\n\n",worth);
        }else if(choice==3){
            printf("To poso se fraga ELbetias einai:%.2f\n\n",worth);
        }else if(choice==4){
            printf("To poso se dollaria Canada einai:%.2f\n\n",worth);
        }else{
            printf("To poso se gen einai:%.2f\n\n",worth);
        }
        choice=menu();

    }
return 0;
}
