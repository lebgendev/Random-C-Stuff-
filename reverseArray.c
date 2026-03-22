#include <stdio.h>
#include <stdlib.h>



void reverse(int arr[], int s){
    int *rvs = malloc(s * sizeof(int));

    for(int i = 0; i < s; i++){
        rvs[i] = arr[s-1-i];
    }

    for(int i = 0; i < s; i++){
        printf("%d ", rvs[i]);
    }

    free(rvs);
    rvs = NULL;
}

int main(){

    int array[] = {4, 6, 8, 3, 1, 4, 6, 8, 3, 1, 4, 6, 8, 3, 1, 4, 6, 8, 3, 1, 4, 6, 8, 3, 1};
    int size = sizeof(array)/sizeof(array[0]);
    reverse(array, size);

    return 0;
}