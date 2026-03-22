#include <stdio.h>
#include <stdlib.h>

int main(){

    int n = 10;
    int T[10] = {1, 4, 8, 2, 4, 9, 0, 1, 2, 10};

    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(T[j] < T[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = T[min];
            T[min] = T[i];
            T[i] = temp;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", T[i]);
    }



    return 0;
}