/* Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop. */

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

struct Node* insertEnd(struct Node* head, int data){
    struct Node* newnode = CreateNode(data);

    if(head == NULL){
        newnode->next = newnode;
        return newnode;
    } 

    struct Node* temp = head;
    while(temp->next != head){
        temp = temp->next; 
    }
    temp->next = newnode;
    newnode->next = head;

    return head;
}

void print(struct Node* head){

    if(head == NULL) return ;

    struct Node* temp = head;

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
}

int main(){
    int n, value;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &value);

        head = insertEnd(head, value);
    }

    print(head);

    return 0;

}