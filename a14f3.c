#include<stdio.h>
#include<stdlib.h>
#define QueueLimit 21  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                ενδεικτικά τύπος int */



typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
QueueElementType GetNthElementValueA(QueueType Queue, int n);
QueueElementType GetNthElementValueB(QueueType *Queue, int n);


int main(){
    QueueType Queue;
    int i, incremention, x;
    char bin;
    incremention = 5;
    CreateQ(&Queue);
    for(i = 0; i < QueueLimit - 1; i++){
        AddQ(&Queue, incremention);
        incremention += 5;
        printf("%d ", Queue.Element[i]);
    }
    printf("\n");
    while(TRUE){
        printf("Dwse n:");
        scanf("%d%c", &x, &bin);
        if(x <= QueueLimit - 1){
            break;
        }
    }
    printf("ValueA:%d", GetNthElementValueA(Queue, x));
    printf("\nValueB:%d\n", GetNthElementValueB(&Queue, x));
    for(i = 0; i < QueueLimit - 1; i++){
        printf("%d ", Queue.Element[i]);
    }

return 0;
}

void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue\n");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

QueueElementType GetNthElementValueA(QueueType Queue, int n){
    int i;
    QueueElementType item;
    if(!EmptyQ(Queue)){
        for(i = 0; i < n; i++){
            RemoveQ(&Queue, &item);
        }
        return item;
    }else{
        return 0;
    }
}

QueueElementType GetNthElementValueB(QueueType *Queue, int n){
    if(!EmptyQ(*Queue)){
        return Queue ->Element[n - 1];
    }else{
        return 0;
    }
}
