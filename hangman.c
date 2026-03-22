#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(){
    srand(time(NULL));
    char words[3][10] = {"hello", "skibidi", "skiiii"};

    int tries = 6;

    char correctGuesses[] = {'\0'};
    
    int correctScore = 0;

    char guess = '\0';

    char word[10];
    strcpy(word, words[(rand() % (2 - 0 + 1)) + 0]);
    while(1){

        //fix unable to exit after entering everything

        printf("\nYou have %d chances!\n", tries);
        for(int i = 0; i < strlen(word); i++){
            if(strchr(correctGuesses, word[i]) == NULL){
                printf("_ ");
            } else {
                printf("%c ", toupper(word[i]));
            }
        }
        
        scanf(" %c", &guess);
        if(strchr(word, guess) != NULL){
            correctGuesses[correctScore] = guess;
            correctScore++;
            printf("\nGood job!");
        } else {
            tries--;
            printf("\nWrong choice! Try again!");
        }
    }

    

    





    return 0;
}