#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;



typedef struct List{
    int value;
    struct List* next;
    //struct List *bach;
} List;



void push(List **pos, int val){

    List *tmp = (List*) malloc(sizeof(List));
    tmp->value = val;
    tmp->next = (*pos);
    (*pos) = tmp;

}

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

void printList(List *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int valuePos(List *head, int n){
    List *pos = head;
    int i = 0;
    while (i < n)
    {
        i++;
        pos = pos -> next;
        if(pos -> next == NULL)
            return -1;
    }
    return pos -> value;
}

int countList(List *head){
    List *pos = head;
    int c = 0;
    while (pos -> next != NULL)
    {
        c++;
        pos = pos -> next;
    }
    return c;
}



int main(){
    List* head = NULL;
    cout << &head <<'\n';

    push(&head, 1);

    //cout << head -> next << '\n';

    for(int i = 2; i < 10; i++)
        push(&head, i);


    pushStart(&head, 90);
    pushStart(&head, 90);
    //int k = valuePos(head, 72);

    //cout << k << '\n';

    cout << countList(head) << '\n';

    printList(head);
    //del(&head);



    printList(head);

    return 0;
}
