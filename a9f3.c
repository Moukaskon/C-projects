#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define QueueLimit 3  //το όριο μεγέθους της ουράς
#define QueueLimit2 21

typedef char QueueElementType[25];   /* ο τύπος δεδομένων των στοιχείων της ουράς
                                ενδεικτικά τύπος int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef struct{
    QueueElementType name;
    char phnumber[11];
    int Code;
}QueueElementType2;

typedef struct{
    int Front, Rear;
    QueueElementType2 Element[QueueLimit2];
}QueueType2;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void showQ(QueueType Queue, int code);

void CreateWQ(QueueType2 *Queue);
boolean FullWQ(QueueType2 Queue);
boolean EmptyWQ(QueueType2 Queue);
void RemoveWQ(QueueType2 *Queue, QueueElementType2 *patient);
void AddWQ(QueueType2 *Queue, QueueElementType2 patient);
void showWaitingQ(QueueType2 WaitingQ);
void newAppointment(int code, QueueType *Queue, QueueType2 *Waiting);


int main(){
    QueueType Qs[6];
    QueueType2 WaitingQ;
    char con, bin;
    int i, code;
    for(i = 1; i < 6; i++){
        CreateQ(&Qs[i]);
    }
    CreateWQ(&WaitingQ);

    srand(54);
    while(TRUE){
        code = rand() % 5 + 1;
        newAppointment(code, &Qs[code], &WaitingQ);
        printf("Continue Y/N (Y=yes, N=No): ");
        scanf("%c%c", &con, &bin);
        if(con == 'N'){break;}
    }

    for(i = 1; i < 6; i++){
        printf("\nAppointments for clinic %d\n", i);
        showQ(Qs[i], i);
    }

    printf("\nWaiting List:\n");
    showWaitingQ(WaitingQ);

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

void CreateWQ(QueueType2 *Queue)
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

void RemoveQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		strcpy(Item, Queue ->Element[Queue -> Front]);
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
        strcpy(Queue ->Element[Queue ->Rear], Item);
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
	}
	else
		printf("Full Queue\n");
}

boolean FullWQ(QueueType2 Queue)
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit2));
}

boolean EmptyWQ(QueueType2 Queue){
    return (Queue.Front == Queue.Rear);
}

void RemoveWQ(QueueType2 *Queue, QueueElementType2 *patient){
	if(!EmptyWQ(*Queue))
	{
		Queue ->Element[Queue -> Front] = *patient;
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit2;
	}else{
		printf("Empty Queue\n");
    }
}

void AddWQ(QueueType2 *Queue, QueueElementType2 patient)
{
	if(!FullWQ(*Queue))
	{
        Queue ->Element[Queue ->Rear] = patient;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit2;
	}
	else
		printf("Full Queue\n");
}

void newAppointment(int code, QueueType *Queue, QueueType2 *WaitingQ){
    char bin, temp[10], name[25];
    QueueElementType2 patient;
    printf("Give your name: ");
    gets(name);
    if(!FullQ(*Queue)){
        AddQ(Queue, name);
        printf("Successful apointment for clinic %d\n", code);
    }else{
        printf("You are in a waiting list.\n");
        printf("Give your phone number: ");
        gets(temp);
        patient.Code = code;
        strcpy(patient.name, name);
        strcpy(patient.phnumber, temp);
        AddWQ(WaitingQ, patient);
    }

}

void showWaitingQ(QueueType2 WaitingQ){
    int current;
    QueueElementType2 temp;
    current = WaitingQ.Front;
    while(current != WaitingQ.Rear){
        temp = WaitingQ.Element[current];
        printf("%s, %d, %s\n", temp.name, temp.Code, temp.phnumber);
        current = (current + 1) % QueueLimit2;
    }
}



void showQ(QueueType Queue, int code){
    int current;
    QueueElementType temp;
    current = Queue.Front;
    while(current != Queue.Rear){
        printf("%s\n", Queue.Element[current]);
        current = (current + 1) % QueueLimit;
    }


}
