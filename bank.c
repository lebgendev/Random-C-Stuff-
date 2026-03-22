#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int deposit(int bal);
int withdraw(int bal);


int main(){
    int balance = 0;
    int choice = 0;
    bool bank = true;
    char input[100] = "";
    while(bank){
        printf("\nWelcome to the local bank! How may I help you?\n1. Check your balance.\n2. Deposit money.\n3. Withdraw money.\n4. Exit.\n");
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);
        if(choice < 1 || choice > 4){
            printf("\nPlease enter an existing choice!");
        } else {
            switch(choice){
                case 1:
                    printf("\nYou have $%d in your bank account!", balance);
                    break;
                case 2:
                    balance = deposit(balance);
                    break;
                case 3:
                    balance = withdraw(balance);
                    break;
                case 4:
                    bank = false;
                    break;
            }
        }
    }


    return 0;
}

int deposit(int bal){
    char added[100];
    printf("\nHow much would you like to deposit?: ");
    fgets(added, sizeof(added), stdin);
    int addedInt = atoi(added);
    if(addedInt > 0){
        bal += addedInt;
        printf("\nYou've successfully deposited $%d. You now have $%d", addedInt, bal);
    } else {
        printf("\nPlease enter a valid number!");
    }
    return bal;
}

int withdraw(int bal){
    char wthdrw[100];
    printf("\nHow much would you like to withdraw?: ");
    fgets(wthdrw, sizeof(wthdrw), stdin);
    int wthdrwInt = atoi(wthdrw);
    if(wthdrwInt > 0){
        if(wthdrwInt <= bal){
            bal -= wthdrwInt;
            printf("\nYou've successfully withdrew $%d. You now have $%d", wthdrwInt, bal);
        } else {
            printf("\nYou don't own enough money in your account! Please deposit later to be able to withdraw the amount you like!");
        }
    } else {
        printf("\nPlease enter a valid choice!");
    }
    return bal;
}
