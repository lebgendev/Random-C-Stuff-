#include <stdio.h>
#include <stdlib.h>




struct LL
    {
        int value;
        struct LL *next;
         
    };



void searchElement(struct LL *element, int i, int count){
    if(element == NULL){
        printf("\nWe couldn't find it! Sorry!");
        return;
    }

    if(element->value == i){
        printf("\nWe found the number %d at the element number #%d!", i, count);
    } else {
        searchElement(element->next, i, ++count);
    }
}

void insertion(struct LL **element, int i){
    if(*element == NULL){
        *element = malloc(sizeof(struct LL));
        (*element)->value = i;
        (*element)->next = NULL;
        return;
    } else {
        insertion(&(*element)->next, i);
    }
}

void delete(struct LL **element, int i){
    if(*element == NULL){
        printf("\nWe couldn't find it! Sorry!");
        return;
    }

    if((*element)->value == i){
        *element = (*element)->next;
        printf("\nSuccessfully deleted!");
        return;
    } else {
        delete(&(*element)->next, i);
    }
}

void show(struct LL *element){
    if(element == NULL){
        printf("\nNo more values to display!");
    } else {
        printf("%d, ", element->value);
        show(element->next);
    }
}



int main(){
    struct LL *head = malloc(sizeof(struct LL));
    head->value = 1;
    head->next = NULL;


    while (1){
        printf("\n1. Search\n2. Insert\n3. Delete\n4. Show All Elements\n");
        int choice = 0;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int num = 0, counter = 1;
                printf("\nEnter num: ");
                scanf("%d", &num);
                searchElement(head, num, counter);
                break;
            case 2:
                int nnum = 0;
                printf("\nEnter num: ");
                scanf("%d", &nnum);
                insertion(&head, nnum);
                break;
            case 3:
                int nnnum = 0;
                printf("\nEnter num: ");
                scanf("%d", &nnnum);
                delete(&head, nnnum);
                break;
            case 4:
                printf("\n");
                show(head);
                break;
            default:
                printf("\nPlease enter a valid choice!");
                break;
        }
    }

    return 0;
}