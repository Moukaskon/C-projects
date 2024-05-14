#include<stdio.h>
#include"genlib.h"
#include"simpio.h"

typedef struct{
    int width, height, depth, area;
    long volume;

}box;

box insertData(box a_box);
void calc_box_area(box *a_box);
void calc_box_volume(box *a_box);

int main(){
    box a_box;
    a_box=insertData(a_box);
    calc_box_area(&a_box);
    calc_box_volume(&a_box);
    printf("To emvadon tou koutiou einai %d cm2\n", a_box.area);
    printf("O ogos tou koutiou einai %ld cm3", a_box.volume);



return 0;
}

box insertData(box a_box){
    a_box.width=(printf("Dose to mikos tou koutiou se cm: "), GetInteger());
    a_box.height=(printf("Dose to ypsos tou koutiou se cm: "), GetInteger());
    a_box.depth=(printf("Dose to vathos tou koutiou se cm: "), GetInteger());
return a_box;
}

void calc_box_area(box *a_box){
    a_box->area=2*(a_box->width * a_box->depth + a_box->width * a_box->height + a_box->depth * a_box->height);
}

void calc_box_volume(box *a_box){
    a_box->volume=a_box->width * a_box->depth * a_box->height;
}
