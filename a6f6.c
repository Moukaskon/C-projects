#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
#define ROWS 5

void readData(int N,int data[][4]);
void findMean(int rows,int data[][4],int col,double *manavg,double *wmnavg);

int main(){
    int data[ROWS][4];
    double manavg,wmnavg,pin[6];
    readData(ROWS,data);
    for(int i=1;i<4;i++){
        manavg=0;
        wmnavg=0;
        findMean(ROWS,data,i,&manavg,&wmnavg);
        pin[i-1]=manavg;
        pin[i+2]=wmnavg;
    }

    printf("Mesos oros barous andrwn: %.1f\n",pin[0]);
    printf("Mesos oros barous gynaikwn: %.1f\n\n",pin[3]);
    printf("Mesos oros ypsous andrwn: % .1f\n",pin[1]);
    printf("Mesos oros ypsous gynaikwn: %.1f\n\n",pin[4]);
    printf("Mesos oros hlikias andrwn: % .1f\n",pin[2]);
    printf("Mesos oros hlikias gynaikwn: % .1f",pin[5]);

return 0;
}

void readData(int N,int data[][4]){
    for(int i=0;i<N;i++){
        data[i][0]=(printf("Dwse fyllo:"),GetInteger());
        data[i][1]=(printf("Dwse baros:"),GetInteger());
        data[i][2]=(printf("Dwse ypsos:"),GetInteger());
        data[i][3]=(printf("Dwse ilikia:"),GetInteger());
        printf("-----\n");
    }
}


void findMean(int rows,int data[rows][4],int col,double *manavg,double *wmnavg){
    int mancntr=0,womancntr=0;
    for(int i=0;i<rows;i++){
        if(data[i][0]){
            *wmnavg+=data[i][col];
            womancntr++;
        }else{
            *manavg+=data[i][col];
            mancntr++;
        }
    }

    if(mancntr){
        *manavg=*manavg/mancntr;
    }
    if(womancntr){
        *wmnavg=*wmnavg/womancntr;
    }
}
