#include <stdio.h>
#include <stdio.h>

#define QueueLimit 10  //το όριο μεγέθους της ουράς

typedef int QueueElementType;   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                  ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear, count;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main(){
    QueueType Queue;
    int i, number, times;
    char bin;

    CreateQ(&Queue);
    for(i = 3; i < 31; i += 3){
        AddQ(&Queue, i);
    }
    printf("(a)\n");
    TraverseQ(Queue);

    printf("(b)\n");
    while(TRUE){
        printf("Give a number:");
        scanf("%d%c", &number, &bin);
        if(number % 3 == 0){
            AddQ(&Queue, number);
            break;
        }else{
            printf("Give a multiple of 3\n");
        }
    }
    TraverseQ(Queue);

    printf("(c)\n");
    RemoveQ(&Queue, &number);
    TraverseQ(Queue);
    printf("Removed Item=%d\n", number);

    printf("(d)\n");
    for(i = 0; i < 2; i++){
        while(TRUE){
            printf("Give a number:");
            scanf("%d%c", &number, &bin);
            if(number % 3 == 0){
                AddQ(&Queue, number);
                break;
            }else{
                printf("Give a multiple of 3\n");
            }
        }
        TraverseQ(Queue);
    }

    printf("(e)\n");
    times = Queue.count;
    for(i = 0; i < times; i++){
        RemoveQ(&Queue, &number);
        TraverseQ(Queue);
        printf("Removed Item=%d\n", number);
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
	Queue ->count = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.count == 0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return (Queue.count == QueueLimit);
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
	    Queue ->count -= 1;
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
	    Queue ->count += 1;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}


void TraverseQ(QueueType Queue) {
	int current, i;
	i = 0;
	printf("Queue: ");
	if (!EmptyQ(Queue)) {
        current = Queue.Front;
	    while (i != Queue.count) {
            printf("%d ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
            i++;
	   }
	   printf("\n");
    }
    else printf("Empty Queue\n");

    printf("Front=%d Rear=%d Count=%d\n", Queue.Front, Queue.Rear, Queue.count);
}


