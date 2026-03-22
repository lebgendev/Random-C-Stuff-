#include <stdio.h>
#include <stdlib.h>


int main(){

    char arr[] = "hiiii i must be a booooo";
    int m = sizeof(arr);
    int n = m*2 - 1;
    char *space = malloc(n * sizeof(char));

    for(int i = 0; i < m; i++){
        if(arr[i] != ' '){
            space[2*i] = arr[i];
            space[2*i + 1] = '_';
        }
        
    }

    for(int i = 0; i < n; i++){
        printf("%c", space[i]);
    }


    return 0;
}