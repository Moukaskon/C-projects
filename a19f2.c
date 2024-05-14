#include <stdio.h>
#include <stdlib.h>


#define StackLimit 8   // το όριο μεγέθους της στοίβας


typedef int StackElementType;   // ο τύπος των στοιχείων  της στοίβας

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
StackElementType minElement(StackType *Stack);
StackElementType maxElement(StackType *Stack);

int main(){
    StackType Stack;
    StackElementType min, max;
    int i, x;
    char bin;
    CreateStack(&Stack);
    for(i = 0; i < StackLimit; i++){
        printf("Dwse to epomeno stoixeio:");
        scanf("%d%c", &x, &bin);
        Push(&Stack, x);
    }
    printf("Plithos sto stack %d\n", Stack.Top + 1);
    for(i = 0; i < StackLimit-1; i++){
        printf("%d ", Stack.Element[i]);
    }
    min = minElement(&Stack);
    max = maxElement(&Stack);
    printf("\nMin: %d\n", min);
    printf("Max: %d\n", max);
    printf("Plithos sto stack %d\n", Stack.Top + 1);

    for(i = 0; i < StackLimit-1; i++){
        printf("%d ", Stack.Element[i]);
    }

return 0;
}


void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}


StackElementType minElement(StackType *Stack){
    StackElementType min, x;
    int i, j;
    StackType Temp;
    min = Stack -> Element[Stack->Top];
    for(i = Stack->Top-1; i > 0; i--){
        if(Stack->Element[i] < min){
            min = Stack->Element[Stack->Top];
        }
    }
    printf("\nInsude 2 %d\n", min);
    i = 0;
    while(Stack->Element[Stack->Top]!=min){
        Pop(Stack, &x);
        Temp.Element[i] = x;
        i++;
    }
    Pop(Stack, &x);
    Temp.Element[i] = x;
    for(j = 0; j < i+1; j++){
        Push(Stack, Temp.Element[j]);
    }
return min;
}


StackElementType maxElement(StackType *Stack){
    StackElementType max, x;
    int i, j;
    StackType Temp;
    max = Stack -> Element[Stack->Top];
    for(i = Stack -> Top - 1; i > 0; i--){
        if(Stack -> Element[i] > max){
            max = Stack -> Element[Stack->Top];
        }
    }
    printf("Inside %d", max);
    i = 0;
    while(Stack -> Element[Stack->Top]!=max){
        Pop(Stack, &x);
        Temp.Element[i] = x;
        i++;
    }
    Pop(Stack, &x);
    Temp.Element[i] = x;
    for(j = 0; j < i+1; j++){
        Push(Stack, Temp.Element[j]);
    }
return max;
}
