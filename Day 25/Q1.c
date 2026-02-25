/* Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, 
increment a counter. After traversal, print the final count. */

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

struct Node* insertionAtEnd(struct Node* head, int data){
    struct Node* newnode  = CreateNode(data);

    struct Node* temp = head;

    if(temp == NULL) return newnode;
 
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

int counter(struct Node* head, int key){
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main(){
    int n, value, key;
    struct Node* head = NULL; 

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &value);

        head = insertionAtEnd(head, value);
    }

    scanf("%d", &key);

    int c = counter(head, key);
    printf("%d", c);
    return 0;
}