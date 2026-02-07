#include <stdio.h>
#include <stdlib.h>


struct binaryTree{
    int value;
    struct binaryTree *left;
    struct binaryTree *right;
};


void insertion(struct binaryTree **tree, int i){
    if(*tree == NULL){
        (*tree) = malloc(sizeof(struct binaryTree));
        (*tree)->value = i;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
        printf("\nNode created!");
        return;
    }
    if(i < (*tree)->value){
        insertion(&(*tree)->left, i);
    } else if(i > (*tree)->value){
        insertion(&(*tree)->right, i);
    } else {
        printf("\nIt already exists!");
    }
}

void searchNode(struct binaryTree *tree, int i){
    if(tree == NULL){
        printf("Sorry, we couldn't find it!");
        return;
    }


    if(i < tree->value){
        searchNode(tree->left, i);
    } else if(i > tree->value){
        searchNode(tree->right, i);
    } else {
        printf("\nWe found it!");
        return;
    }
}

struct binaryTree *findMin(struct binaryTree *tree){
    while(tree->left != NULL){
        tree = tree->left;
    }

    return tree;
    
}

void deleteNode(struct binaryTree **tree, int i){

    if(*tree == NULL){
        printf("Sorry, we couldn't find it!");
        return;
    }



    if(i < (*tree)->value){
        deleteNode(&(*tree)->left, i);
    } else if(i > (*tree)->value){
        deleteNode(&(*tree)->right, i);
    } else {
        printf("\nWe found it! Now, we have to delete it.");
        struct binaryTree *temp;
        
        if((*tree)->left == NULL && (*tree)->right == NULL){
            free(*tree);
            *tree = NULL;
        } else if((*tree)->left == NULL){
            temp = *tree;
            *tree = (*tree)->right;
            free(temp);
        } else if((*tree)->right == NULL){
            temp = *tree;
            *tree = (*tree)->left;
            free(temp);
        } else {
            (*tree)->value = findMin((*tree)->right)->value;
            deleteNode(&(*tree)->right, findMin((*tree)->right)->value);
        }
    }
}


int main(){
    struct binaryTree *tree = malloc(sizeof(struct binaryTree));
    tree->value = 1;
    tree->left = NULL;
    tree->right = NULL;

    while (1){
        printf("\n1. Search\n2. Insert\n3. Delete\n");
        int choice = 0;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int num = 0;
                printf("\nEnter num: ");
                scanf("%d", &num);
                searchNode(tree, num);
                break;
            case 2:
                int nnum = 0;
                printf("\nEnter num: ");
                scanf("%d", &nnum);
                insertion(&tree, nnum);
                break;
            case 3:
                int nnnum = 0;
                printf("\nEnter num: ");
                scanf("%d", &nnnum);
                deleteNode(&tree, nnnum);
                break;
        }
    }
    






    return 0;
}
