/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right */

#include <stdio.h>

int main(){
    int n, pos, x;

    scanf("%d", &n);  // Read the number of elements

    int arr[n + 1]; // size n+1 to make sure insertion

    for(int i = 0; i < n; i++){  // Read elements of array from user
        scanf("%d", &arr[i]);
    }
    
    // Read the postion (start from 1 not 0, postion = index + 1) 
    scanf("%d", &pos);

    // Read the element to insert
    scanf("%d", &x);

    // shifting elements to the right 
    for(int i = n; i >=pos; i--){
        arr[i] = arr[i - 1];
    }
    
    arr[pos - 1] = x;  // insert the element

    // printing updated array with n+1 elements
    for(int i = 0; i< n+1; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}