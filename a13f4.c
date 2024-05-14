#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
    char username[9];
    char filename[13];

}QueueElementType;           /*ο τύπος των στοιχείων της συνδεδεμένης ουράς
                                        ενδεικτικά τύπου int*/
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);



int main(){
    QueueType Queue1, Queue2;
    FILE *fp;
    QueueElementType AnItem;
    char c;


    fp = fopen("i13f4.dat", "r");
    if(fp == NULL){
        printf("Error oppening file\n");
        return -1;
    }

    CreateQ(&Queue1);
    CreateQ(&Queue2);

    while(!feof(fp)){
        fscanf(fp, "%s", AnItem.username);
        fscanf(fp, "%s", AnItem.filename);

        if((strncmp("USER", AnItem.username, 4) == 0) || (strncmp("FORT", AnItem.username, 4) == 0)){

            AddQ(&Queue1, AnItem);

        }else{

            AddQ(&Queue2, AnItem);

        }
    }


    while(!EmptyQ(Queue2)){
        RemoveQ(&Queue2, &AnItem);
        printf("Printing the job of %s, %s\n", AnItem.username, AnItem.filename);
        printf("Press any key to continue");
        scanf("%c", &c);
    }

    while(!EmptyQ(Queue1)){
        RemoveQ(&Queue1, &AnItem);
        printf("Printing the job of %s, %s\n", AnItem.username, AnItem.filename);
        printf("Press any key to continue.");
        scanf("%c", &c);
    }
    printf("There are no jobs in the printing queue");

return 0;
}



void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}


