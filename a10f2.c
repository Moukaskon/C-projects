#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

/*Δινεις τον κωδικο τιμολογίου 1,2,3 και την παρούσα οπως και την προηγούμενη ένδειξη του μετρητη.

Εμφανιζει την καταναλωση ρευματος,την αξια ρευματος,το παγιο,τον ΦΠΑ και το συνολικο ποσο.
*/

int main(){
    int code=(printf("Dwse ton kwdiko katigorias timologiou:"),GetInteger());
    long clockNow=(printf("Dwse thn parousa endeixh toy metrhth:"),GetLong());
    long clockBefore=(printf("Dwse thn prohgounrnh endeixh toy metrhth:"),GetLong());
    long consumption=clockNow-clockBefore;
    double telikhAxia;
    if(consumption<=200){
        telikhAxia=consumption*12;
    }else if(consumption<=500){
        telikhAxia=200*12+(consumption-200)*15;
    }else if(consumption<=1500){
        telikhAxia=200*12+300*15+(consumption-500)*20;
    }else{
        telikhAxia=200*12+300*15+1000*20+(consumption-1500)*30;
    }
    int pagio;
    if(code==1 || code==2){
        pagio=20;
    }else{
        pagio=100;
    }
    double totalNoFpa=(double)telikhAxia/100+pagio;
    double fpa=totalNoFpa*0.18;
    double total=totalNoFpa+fpa;
    printf("Katanalwsh reumatos se monades:%ld",consumption);
    printf("\nAxia reumatos(cent):%g",telikhAxia);
    printf("\nPagio(euro):%d",pagio);
    printf("\nFPA(euro):%g",fpa);
    printf("\nSynolikio poso plhrwmhs:%g",total);

return 0;
}
