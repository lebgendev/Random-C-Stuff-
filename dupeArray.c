#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[] = {0, 0, 5, 7, 3, 9, 0, 7, 8, 4, 0, 3};
    int size = sizeof(array)/sizeof(int);
    int *dupeList = malloc(sizeof(int));
    int score = 0;
    int badScore = 0;
    int length = 1;


    for(int i = 0; i < size-1; i++){
        score = 1;
        badScore = 0;
        for(int j = i+1; j < size; j++){
            if(array[i] == array[j]){
                score += 1;
            }
        }
        if(score > 1){
            if(length > 1){
                for(int k = 0; k < length; k++){
                    if(array[i] == dupeList[k]){
                        badScore += 1;
                    }
                }
                
            }
            if(badScore == 0){
                dupeList[length - 1] = array[i];
                printf("%d appeared %d times!\n", dupeList[length - 1], score);
                length++;
                dupeList = realloc(dupeList, length*sizeof(int));
            }    
        }
    }

    if(length == 1){
        printf("There are no duplicates!");
    }
    






    return 0;
}