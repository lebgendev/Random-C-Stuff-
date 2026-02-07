#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5



typedef struct
    {
        int arr[MAX_SIZE];
        int rank;
        
    } Stack;



void initializeStack(Stack *stack)
{
    stack->rank = -1;
}


int isFull(Stack *stack){
    if(stack->rank == MAX_SIZE-1){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Stack *stack){
    if(stack->rank == -1){
        return 1;
    } else {
        return 0;
    }
}


void push(Stack *stack){
    if(isFull(stack)){
        printf("\nPlease pop the stack before pushing an element, for the stack is full!\n");
    } else {
        int value = 0;
        printf("\nEnter a value: ");
        scanf("%d", &value);
        stack->arr[++stack->rank] = value;
    }

}

void pop(Stack *stack){
    if(isEmpty(stack)){
        printf("\nPlease push an element before popping one, for the stack is empty!\n");
    } else {
        printf("\nYou popped the number %d from the rank %d", stack->arr[stack->rank], stack->rank + 1);
        stack->rank--;
    }
    
}

void peek(Stack *stack){
    if(isEmpty(stack)){
        printf("\nThere are no elements in this stack!\n");
    } else {
        printf("\nThe top element is: %d", stack->arr[stack->rank]);
    }
    
}



int main(){

    Stack *stack;
    initializeStack(stack);
    while (1){
        int choice = 0;
        printf("\nWhat do you want to do with said stack? (Enter the correspoding number)\n1. Push\n2. Pop\n3. Peek\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push(stack);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                peek(stack);
                break;
            default:
                printf("\nPlease enter a valid choice!\n");
        }
    }


    return 0;
}

