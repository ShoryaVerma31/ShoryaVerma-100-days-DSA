/* Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer. */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* CreateNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Node* InsertAtEnd(struct Node* head, int data){
    struct Node* newnode = CreateNode(data);

    if(head == NULL) return newnode;

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
    return head;
}

struct Node* deleteKey(struct Node* head, int key){
    struct Node *temp = head, *prev = NULL;

    if(temp != NULL && temp->data == key){
        head = temp->next;
        free(temp);
        return head;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return head;

    prev->next = temp->next;
    free(temp);
    return head;
}

void Display(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int n, value, key;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &value);

        head = InsertAtEnd(head, value);
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    Display(head);

    return 0;
}