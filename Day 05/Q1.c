/* Problem: A system receives two separate logs of user arrival times from two different servers.
 Each log is already sorted in ascending order. Your task is to create a single chronological log that 
 preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the
 final log until all entries are processed */

#include <stdio.h>

int main(){

    int r, s;

    scanf("%d", &r);
    int A[r];
    for(int i =0; i< r; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &s);
    int B[r];
    for(int i =0; i< s; i++){
        scanf("%d", &B[i]);
    }

    int i =0, j=0;
    while(i < r && j < s){
        if(A[i] <= B[j]){
            printf("%d ", A[i]);
            i++;
        }
        else{
            printf("%d ", B[j]);
            j++;
        }
    }

    while (i < r){            // to print remaining elements in A
        printf("%d ", A[i]);
        i++;
    }

    while (j < s){            // to print remaining elements in B
        printf("%d ", B[j]);
        j++;
    }

    return 0;
}