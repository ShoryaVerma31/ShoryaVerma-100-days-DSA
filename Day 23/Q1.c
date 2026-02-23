/* Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged. */

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

    if(head == NULL)
        return newnode;

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newnode;
    return head;
}
struct Node* MergedList(struct Node* l1, struct Node* l2){

    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    struct Node* result = NULL;

    if(l1->data <= l2->data){
        result = l1;
        result->next = MergedList(l1->next, l2);
    }
    else{
       result = l2;
        result->next = MergedList(l1, l2->next); 
    }

    return result;
}

void printList(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    int n, m, value;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value);
        list1 = InsertAtEnd(list1,value);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &value);
        list2 = InsertAtEnd(list2, value);
    }

    struct Node* merged = MergedList(list1, list2);
    printList(merged);
    return 0;
}