#include <stdio.h>
#include "myBank.h"

int main() {
    char operation;
    double account_number, amount, interest_rate;
    int temp;
    do {
    printf("\n\n\n                                  main menu                                  \n");
    printf("Welcome to the Bank program, enter an operation you wish to do, or type \"H\" for the operation list\n");
    scanf(" %c", &operation);
        switch (operation) {
        case 'O':
            printf("how much would you like to deposit?\n");
            if (scanf("%lf", &amount)==1) {
                O(amount);
            }else printf("failed to open the account\n");
            break;
        case 'B':
            printf("which account would you like to check?\n");
            if (scanf("%lf", &account_number)==1) {
                B(account_number);
            }else printf("failed to identify an account\n");
            break;
        case 'D':
            printf("to which account would you like to deposit?\n"); 
            if (scanf("%lf", &account_number)==1) {
                temp=1;
            }else temp=0;
            printf("how much would you like to deposit?\n");
            if (scanf("%lf", &amount)==1 && temp==1) {
                D(account_number, amount);
            }else printf("failed to make the deposit\n");
            break;
        case 'W':
            printf("from which account would you like to withdraw?\n"); 
            if (scanf("%lf", &account_number)==1) {
                temp=1;
            }else temp=0;
            printf("how much would you like to withdraw?\n");
            if (scanf("%lf", &amount)==1 && temp==1) {
                W(account_number, amount);
            }else printf("failed to withdraw\n");
            break;
        case 'C':
            printf("which account would you like to close?\n");
            if (scanf("%lf", &account_number)==1) {
                C(account_number);
            }else printf("failed to close the account\n");
            break;
        case 'I':
            printf("enter the interest rate (in percentage)\n");
            if (scanf("%lf", &interest_rate)==1) {
                I(interest_rate);
            }else printf("failed to add interest rate\n");
            break;
        case 'P':
            P();
            break;
        case 'E':
            E();
            break;
        case 'H':
            printf("\"O\" to open an account.\n");
            printf("\"B\" to check how much money specific account have.\n");
            printf("\"D\" to deposit money to specific account.\n");
            printf("\"W\" to withdraw money from specific account.\n");
            printf("\"C\" to close specific account.\n");
            printf("\"I\" to add intrest rate to all accounts.\n");
            printf("\"P\" to print the information of all the existing accounts.\n");
            printf("\"E\" to close all accounts and exit the program.\n");
            printf("\"H\" to view command list.\n");
            break;
        default:
            printf("no such command exist, please try again.\n");
            break;
        }
    }while (operation != 'E');
    return 0;
}