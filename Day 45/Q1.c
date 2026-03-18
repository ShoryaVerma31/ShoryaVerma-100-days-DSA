/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1)
        return NULL;

    struct Node* queue[100];
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while(i < n) {
        struct Node* current = queue[front++];

        if(arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

int height(struct Node* root) {
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root = buildTree(arr,n);

    printf("%d", height(root));

    return 0;
}