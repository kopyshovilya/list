#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;



typedef struct List{
    int value;
    struct List* adr;
} List;

typedef pair <List*, List*> link;

int countList = 0;

void push(List **posFirst, List **posSecond, int val){

    if (countList == 0){
        List *tmp = (List*) malloc(sizeof(List));
        tmp -> value = val;
        tmp -> adr = tmp;
        (*posFirst) = tmp;
    }

    if (countList == 1){
        List *tmp = (List*) malloc(sizeof(List));
        tmp -> value = val;
        tmp -> adr = tmp;
        (*posSecond) = tmp;
    }
    if (countList == 2){

        List *tmp = (List*) malloc(sizeof(List));
        tmp -> value = val;

        List *adrFirst = (*posFirst);
        List *adrSecond = (*posSecond);

        (*posSecond) -> adr = reinterpret_cast <List*>(reinterpret_cast<int>(tmp) ^ reinterpret_cast<int>(adrFirst));;
        //cout << "ok";
        (*posFirst) -> adr = reinterpret_cast <List*>(reinterpret_cast<int>(adrSecond) ^ NULL);

        tmp -> adr = reinterpret_cast <List*>(NULL ^ reinterpret_cast<int>(adrSecond));

        (*posSecond) = tmp;
        (*posFirst) = adrSecond;
    }
    if (countList > 2){
        List *tmp = (List*) malloc(sizeof(List));
        tmp -> value = val;

        List *adrFirst = (*posFirst);
        List *adrSecond = (*posSecond);
        tmp -> adr = reinterpret_cast <List*>(NULL ^ reinterpret_cast<int>(adrSecond));
        (*posSecond) -> adr = reinterpret_cast <List*>(reinterpret_cast<int>(tmp) ^ reinterpret_cast<int>(adrFirst));

        (*posSecond) = tmp;
        (*posFirst) = adrSecond;

    }

    countList++;

}
/*
void pushStart(List **head, int val){
    List *tmp = (List*) malloc(sizeof(List));
    tmp -> value = val;
    tmp -> next = NULL;
    List *pos = *head;
    while (pos -> next)
    {
        pos = pos -> next;
    }
    //cout << pos -> next << '\n';
    pos -> next = tmp;
}

bool del(List **head){
    if (head == NULL)
        return false;
    *head = (*head) -> next;
    return true;
}
*/
void printList(List *head1, List *head2) {
    while (head2 && head1) {
        cout << head2->value << " " << head1->value << " ";
        head2 = reinterpret_cast<List*>(reinterpret_cast<int>(head2) ^ reinterpret_cast<int>(head1 -> adr));

        if (head2 == NULL)
            break;
        head1 = reinterpret_cast<List*>(reinterpret_cast<int>(head1) ^ reinterpret_cast<int>(head2 -> adr));

    }
    printf("\n");
}

int valuePos(List *head1, List *head2, int n){
    int i = 1;
    if (n == 0)
        return head2 -> value;
    if (n == 1)
        return head1 -> value;

    while(i < n) {

        head2 = reinterpret_cast<List*>(reinterpret_cast<int>(head2) ^ reinterpret_cast<int>(head1 -> adr));
        i++;
        if (i == n)
            return head2 -> value;
        if (head2 == NULL)
            break;

        head1 = reinterpret_cast<List*>(reinterpret_cast<int>(head1) ^ reinterpret_cast<int>(head2 -> adr));
        i++;
        if (i == n)
            return head1 -> value;
        if (head1 == NULL)
            break;
    }
}





int main(){
    List* headOne = NULL;
    List* headTwo = NULL;

    for(int i = 0; i < 140; i++){
        push(&headOne, &headTwo, i);
    }
    push(&headOne, &headTwo, 12);
    printList(headOne, headTwo);
    cout << valuePos(headOne, headTwo, 2);
    
    return 0;
}
