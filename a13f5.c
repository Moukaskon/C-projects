#include<stdio.h>
#include"genlib.h"
#include"simpio.h"
#include<math.h>

void populate_data(int R,int C,int array[10][10]);
void print_array(int R,int C,int array[10][10]);
void change_array(int R,int C,int array[10][10]);

int main(){
    int R,C,array[10][10];
    R=(printf("Dwse ton arithmo twn grammwn: "),GetInteger());
    C=(printf("Dwse ton arithmo twn sthlwn: "),GetInteger());
    populate_data(R,C,array);
    printf("ARXIKOS PINAKAS\n");
    print_array(R,C,array);
    change_array(R,C,array);
    printf("ALLAGMENOS PINAKAS\n");
    print_array(R,C,array);
return 0;
}

void populate_data(int R,int C,int array[10][10]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            array[i][j]=rand()%100;
        }
    }
}

void print_array(int R,int C,int array[10][10]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }

}

void change_array(int R,int C,int array[10][10]){
    int max[R],pos[R];
    int i,j;
    for(i=0;i<R;i++){
        max[i]=array[i][0];
        pos[i]=0;
    }

    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if(array[i][j]>max[i]){
                max[i]=array[i][j];
                pos[i]=j;
            }
        }
    }

    for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            if(array[i][j]<max[i] && j<pos[i]){
                array[i][j]=max[i];
            }
        }
    }
}
