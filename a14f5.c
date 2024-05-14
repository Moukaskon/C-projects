#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct{
    char name[20];
    char phone[10];
    int code;

} BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
typedef struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} BinTreeNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, char KeyValue[], boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root, int key);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);
void CreateBSTFile(BinTreePointer *Root);
void printteachers(BinTreePointer Root);
void insertNewTeacher(BinTreePointer *Root);
void SearchForTeacher(BinTreePointer Root);
void searchbysubject(BinTreePointer Root);
void deleteateacher(BinTreePointer *Root);

int main(){
    BinTreePointer Root;
    BinTreeElementType Item;

    CreateBSTFile(&Root);
    printteachers(Root);
    insertNewTeacher(&Root);
    SearchForTeacher(Root);
    searchbysubject(Root);
    deleteateacher(&Root);
    printteachers(Root);

return 0;
}

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        (*Root) ->Data = Item;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (strcmp(Item.name, (*Root) ->Data.name) < 0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (strcmp(Item.name, (*Root) ->Data.name) > 0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("TO STOIXEIO EINAI HDH STO DDA\n");
}

void RecBSTSearch(BinTreePointer Root, char KeyValue[],
                    boolean *Found, BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{
    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (strcmp(KeyValue, Root->Data.name) < 0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (strcmp(KeyValue, Root->Data.name) > 0)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ����� ������ �� KeyValue �� �� ������ *)
        printf("TO STOIXEIO DEN BRE8HKE STO DDA\n");
     else
         //* ��������� ���������� ��� ����� ��� �������� ��� ���� KeyValue ��� �������� ���
          if (strcmp(KeyValue.name, (*Root) ->Data.name) < 0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* �������� ��������� *
          else
            if (strcmp(KeyValue.name, (*Root)->Data.name) > 0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ����  ��������� *
            else                                       //* TO KeyValue ������� �������� ��� ������ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ��� ���� �������� ����� *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ���� �������� �����, ���� ��� ���� *)
                        free(TempPtr);
                   }
                   else                               //* ���� 2 ������ *)
                   {
                        //* ������ ��� INORDER �������� ��� *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ���������� ��� �������� ��� ����� ��� ����������
                        ��� ���������� ��� �������� ��� �������� ������ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root, int key)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
    //    printf("L");
        RecBSTInorder(Root->LChild, key);
        if(Root ->Data.code == key){
            printf("%s, %s, %d\n", Root->Data.name, Root ->Data.phone, Root ->Data.code);
        }
    //    printf("R");
        RecBSTInorder(Root->RChild, key);
    }
   // printf("U");
}

void RecBSTPreorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ��������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        printf("%d ",Root->Data);
       // printf("L");
        RecBSTPreorder(Root->LChild);
      //  printf("R");
        RecBSTPreorder(Root->RChild);
    }
   // printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
      //  printf("L");
        RecBSTPostorder(Root->LChild);
     //   printf("R");
        RecBSTPostorder(Root->RChild);
        printf("%d ",Root->Data);
    }
   // printf("U");
}

void CreateBSTFile(BinTreePointer *Root){
    FILE *file;
    file = fopen("I14F5.TXT", "r");
    int nscan;
    char bin;
    BinTreeElementType Temp;
    CreateBST(Root);

    while(TRUE){
        fscanf(file, "%20[^,]%c", Temp.name, &bin);
        fscanf(file, " %10[^,]%c ", Temp.phone, &bin);
        nscan = fscanf(file, "%d%c", &Temp.code, &bin);
        if(nscan == EOF){
            break;
        }
        if(file == NULL){
            exit(1);
        }
        RecBSTInsert(Root, Temp);
    }
    fclose(file);

}

void printteachers(BinTreePointer Root){
    if (Root!=NULL) {
        printteachers(Root->LChild);
        printf("%s, %s, %d\n", Root->Data.name, Root ->Data.phone, Root ->Data.code);
        printteachers(Root->RChild);
    }
}

void insertNewTeacher(BinTreePointer *Root){
    int i;
    char bin;
    BinTreeElementType Item;

    for(i = 0; i < 2; i++){
        printf("Give teacher full name: ");
        scanf("%20[^\n]%c", Item.name, &bin);
        printf("Give teacher phone number: ");
        scanf("%10[^\n]", Item.phone);
        printf("Give teacher code: ");
        scanf("%d%c", &Item.code, &bin);
        RecBSTInsert(Root, Item);
    }

}

void SearchForTeacher(BinTreePointer Root){
    char name[20];
    BinTreePointer LocPtr;
    boolean found;

    printf("Give teacher full name to search: ");
    gets(name);

    RecBSTSearch(Root, name, &found, &LocPtr);
    printf("%s, %s, %d\n", LocPtr ->Data.name, LocPtr ->Data.phone, LocPtr ->Data.code);
}

void searchbysubject(BinTreePointer Root){
    int key;
    char bin;

    printf("Give code to search: ");
    scanf("%d%c", &key, &bin);
    RecBSTInorder(Root, key);
}

void deleteateacher(BinTreePointer *Root){
    char bin;
    BinTreeElementType key;

    printf("Give teacher full name to delete: ");
    scanf("%20[^\n]%c", key.name, &bin);
    RecBSTDelete(Root, key);


}
