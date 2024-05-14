#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    long totalinteriorfees=0;
    long totalextfees=0;
    long alltotal;
    while(1){
        long interiorPar=(printf("Kibwtia eswterikou?"),GetLong());
        if(interiorPar<0) break;
        long exteriorPar=(printf("Kibwtia exwterikou?"),GetLong());
        if(exteriorPar<0) break;
        long interfees=interiorPar*10;
        long extfees=exteriorPar*15;
        long daytotal=extfees+interfees;
        printf("%10d%10d%10d\n",interfees,extfees,daytotal);
        totalinteriorfees+=interfees;
        totalextfees+=extfees;

    }
    alltotal=totalextfees+totalinteriorfees;
    printf("%10d%10d%10d",totalinteriorfees,totalextfees,alltotal);

return 0;
}
