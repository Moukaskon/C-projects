#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

int main(){
    int maxweight,maxage,maxcode,maxheight=0;
    int pentades=(printf("Dwse to plhthos: "),GetInteger());
    for(int i=0; i<pentades;i++){
        int code=(printf("Dwse ton kwdiko: "),GetInteger());
        int fyllo=(printf("Dwse to fyllo: "),GetInteger());
        int weight=(printf("Dwse to baros: "),GetInteger());
        int height=(printf("Dwse to ypsos: "),GetInteger());
        int age=(printf("Dwse thn hlikia: "),GetInteger());
        if(fyllo==0){
            if(height>maxheight){
                maxheight=height;
                maxcode=code;
                maxweight=weight;
                maxage=age;


            }
        }


    }
    printf("%d %d %d %d %d",maxcode,0,maxweight,maxheight,maxage);

return 0;
}
