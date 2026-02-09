/* Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that 
its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored */

#include <stdio.h>
#include <string.h>

int main(){

    char mirror[100];
    fgets(mirror, 100, stdin);

    int n = strlen(mirror);

    if(mirror[n-1] == '\n'){
        mirror[n-1] = '\0';
        n--;
    }

    char temp = 0;
    for(int i=0; i<n/2; i++){
        temp = mirror[i];
        mirror[i] = mirror[n-i-1];
        mirror[n-i-1] = temp;
    }

    for(int i = 0; i<n; i++){
        printf("%c", mirror[i]);
    }
}