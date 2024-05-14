#include <stdio.h>
#include <stdlib.h>


#define StackLimit 60   // το όριο μεγέθους της στοίβας


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
int GetTopElementA(StackType Stack);
int GetTopElementB(StackType *Stack);

int main(){
    StackType Stack;
    StackElementType i;
    CreateStack(&Stack);
    for(i = 2; i < 61; i+=2){
        Push(&Stack, i);
    }

    printf("Plithos sto stack %d\n",Stack.Top + 1);

    for(i = 0; i < 30; i++){
        printf("%d ", Stack.Element[i]);
    }

    printf("\nTop with GetTopElementA = %d\n", GetTopElementA(Stack));
    printf("Plithos sto stack %d\n",Stack.Top + 1);
    for(i = 0; i < 30; i++){
        printf("%d ", Stack.Element[i]);
    }

    printf("\nTop with GetTopElementB = %d\n", GetTopElementB(&Stack));
    printf("Plithos sto stack %d\n",Stack.Top += 1);

    for(i = 0; i < 30; i++){
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

int GetTopElementA(StackType Stack){
    StackElementType x;
    Pop(&Stack, &x);

return x;
}

int GetTopElementB(StackType *Stack){
    StackElementType x;
    x = Stack ->Element[Stack ->Top];

return x;
}
