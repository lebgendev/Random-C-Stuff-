#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void Write();
void Read();

int main(){
    while(true){
        int choice = 0;
        int c;
        printf("\nWelcome to the notes app! What would you like to do?\n1. Write a new file\n2. Read a file\nChoose your option: ");
        scanf("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF);
        switch(choice){
            case 1:
                Write();
                break;
            case 2:
                Read();
                break;
            default:
                printf("\nChoose a valid option!");
                break;
        }
    }





    return 0;
}


void Write(){
    char fileNameInput[25] = "";
    char filename[50] ="notes\\";
    char input[1000] = "";
    printf("\nPlease enter the file name (without .txt): ");
    fgets(fileNameInput, sizeof(fileNameInput), stdin);
    fileNameInput[strcspn(fileNameInput, "\n")] = '\0';
    strcat(filename, fileNameInput);
    strcat(filename, ".txt");
    

    FILE *file = fopen(filename, "w");
    if(file == NULL){
        printf("\nSomething's missing!");
        return;
    }

    printf("\nNow enter the content of the file:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    fprintf(file, "%s", input);
    fclose(file);
    printf("\nFile written successfully!");
}

void Read(){
    char fileNameInput[25] = "";
    char filename[50] ="notes\\";
    char content[1024] = "";
    printf("\nPlease enter the file name (without .txt): ");
    fgets(fileNameInput, sizeof(fileNameInput), stdin);
    fileNameInput[strcspn(fileNameInput, "\n")] = '\0';
    strcat(filename, fileNameInput);
    strcat(filename, ".txt");

    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("\nEnter a valid file bozo.");
        return;
    }
    while(fgets(content, sizeof(content), file) != NULL){
        printf("\n%s\n", content);
    }
    fclose(file);
}