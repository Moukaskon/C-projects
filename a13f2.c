#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    int coffies=(printf("Dose kafedes:"),GetInteger());
    int totalWorth=coffies*70;
    if(totalWorth>500){
        printf("Sfalma");
    }else{
        int change=500-totalWorth;
        int coins2=change/200;
        int change2=change%200;
        int coins1=change2/100;
        int change3=change2%100;
        int coins50=change3/50;
        int change4=change3%50;
        int coins20=change4/20;
        int change5=change4%20;
        int coins10=change5/10;
        printf("Resta");
        printf("\nKermata 2E :%d",coins2);
        printf("\nKermata 1E :%d",coins1);
        printf("\nKermata 50L :%d",coins50);
        printf("\nKermata 20L :%d",coins20);
        printf("\nKermata 10L :%d",coins10);
    }
return 0;
}
