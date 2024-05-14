#include<stdio.h>

void getting_hours(int celebarrival[100],int celebdeparture[100],int NumberOfCeleb,char celebrity[100][30]);
void setting_presence(int IsThere[100][6],int celebarrival[100],int celebdeparture[100],int freq[100],int NumberOfCeleb);
void setting_freq(int freq[5],int IsThere[100][6],int NumberOfCeleb);
void find_max_hour(int NumberOfCeleb,int freq[5],int *index,int *max);
void getting_names_of_celebrities(char celebrity[100][30],int NumberOfCeleb);
void printing_the_celebrities(char celebrity[100][30],int IsThere[100][6],int index,int NumberOfCeleb);


int main(){
    int IsThere[100][6], freq[5], NumberOfCeleb;
    char celebrity[100][30];
    int max, index;
    int celebarrival[100];
    int celebdeparture[100];
    printf("Dwse ton arithmo twn celebrities:");
    scanf("%d",&NumberOfCeleb);
    printf("Dwse ta onomata twn celebrities:\n");

    getting_names_of_celebrities(celebrity,NumberOfCeleb);
    getting_hours(celebarrival,celebdeparture,NumberOfCeleb,celebrity);

    setting_presence(IsThere,celebarrival,celebdeparture,freq,NumberOfCeleb);
    setting_freq(freq,IsThere,NumberOfCeleb);
    find_max_hour(NumberOfCeleb,freq,&index,&max);

    printf("H kalyterh wra einai stis: %.2f mexri %.2f pou tha einai oi exhs %d celebrities:\n",(double)index+18,(double)index+19,max);
    printing_the_celebrities(celebrity,IsThere,index,NumberOfCeleb);

return 0;
}

void getting_hours(int celebarrival[100],int celebdeparture[100],int NumberOfCeleb,char celebrity[100][30]){
/*Διαβαζει την ώρα άφηξης και αναχώρησης της καθε διασημότητας*/
    for(int i=0;i<NumberOfCeleb;i++){
        printf("Dwse wra afixis twn %s",celebrity[i]);
        scanf("%d",&celebarrival[i]);
        printf("Dwse wra anaxwrhshs twn %s",celebrity[i]);
        scanf("%d",&celebdeparture[i]);

    }

}

void setting_presence(int IsThere[100][6],int celebarrival[100],int celebdeparture[100],int freq[100],int NumberOfCeleb){
/*Αρχικοποιεί τα στοιχεία του πίνακα IsThere με 0 σε ολες τις θέσεις
και στη συνέχεια βαζει τη μονάδα στο κελί του συγροτήματος
που βρισκεται στην εκδήλωση την συγκεκριμένη ώρα*/

    for(int i=0;i<NumberOfCeleb;i++){
        for(int j=0;j<6;j++){
            IsThere[i][j]=0;
        }
    }


    for(int i=0;i<NumberOfCeleb;i++){
        for(int j=celebarrival[i]-18;j<celebdeparture[i]-18;j++){
            IsThere[i][j]=1;
        }
    }
}


void setting_freq(int freq[5],int IsThere[100][6],int NumberOfCeleb){

/*Προσδιορίζει πόσες διασημότητες θα υπάρχουν στο πάρτυ καθε ώρα*/

    for(int j=0;j<6;j++){
        freq[j]=0;
    }

    for(int j=0;j<6;j++){
        freq[j]=0;
        for(int i=0;i<NumberOfCeleb;i++){
            if(IsThere[i][j]){
                freq[j]+=1;
            }
        }
    }

}

void find_max_hour(int NumberOfCeleb,int freq[5],int *index,int *max){
/*Βρίσκει τον αριθμο των περισσότερων διασημοτήτων σε μια ώρα*/
    *max=freq[0];
    *index=0;
    for(int i=1;i<6;i++){
        if(freq[i]>*max){
            *max=freq[i];
            *index=i;
        }
    }
}

void getting_names_of_celebrities(char celebrity[100][30],int NumberOfCeleb){
/*Διαβάζει τα ονόματα όλων των διασημοτήτων που θα
παραυρεθούν στο party*/

    for(int i= -1; i<NumberOfCeleb; i++){
        fgets(celebrity[i], sizeof(celebrity[i]),stdin);
    }

}
void printing_the_celebrities(char celebrity[100][30],int IsThere[100][6],int index,int NumberOfCeleb){
    for(int i=0;i<NumberOfCeleb;i++){
        if(IsThere[i][index]){
            puts(celebrity[i]);
        }
    }

}
