#include <stdio.h>


int main() {
    int m,n;
    scanf("%d %d", &m, &n);
    int mat[m][n];
    
    if(m != n) 
        printf("Not a Symmetric Matrix"); // is matrix is not a square matrix(nxn), also not a symmetric matrix

    for(int i =0; i< m; i++){
        for(int j =0; j< n; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int symmetric = 1; 
    
    for(int i =0; i< m; i++){
        for(int j =0; j< n; j++){
            if(mat[i][j] !=mat[j][i]){
                symmetric = 0;
                break;
            } 
        }
        if(symmetric == 0)
            break;    
    }
    
    if(symmetric)
        printf("Symmetric Matrix");
    
    else
        printf("Not a Symmetric Matrix");

    return 0;
}    
