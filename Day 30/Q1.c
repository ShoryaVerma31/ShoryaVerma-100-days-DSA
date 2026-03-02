/* Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int coff, int pow){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->coff = coff;
    newnode->pow= pow;
    newnode->next = NULL;
    return newnode;
} 

struct Node* insertEnd(struct Node* head, int coff, int pow){
    struct Node* newnode = createNode(coff, pow);

    if(head == NULL) return newnode;

    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

void displayPoly(struct Node* head){
    struct Node* temp = head;

    while(temp != NULL){
        if(temp->pow == 0){
            printf("%d", temp->coff);
        }   
        else if(temp->pow == 1){
            printf("%dx",temp->coff);
        }
        else{
            printf("%dx^%d", temp->coff, temp->pow);
        }
        
        if(temp->next != NULL){
            printf(" + ");
        }

        temp = temp->next;
    }
}

int main(){
    int n, coefficient, power;
    struct Node* head = NULL;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &coefficient, &power);

        head = insertEnd(head, coefficient, power);
    }

    displayPoly(head);
    return 0; 
}