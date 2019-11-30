#include <stdio.h>
#include "myBank.h"

double Bank[accounts][data] = {{0}}; 

void O(double amount) {
    if (amount<0) {
        printf("you can't deposit $%.2lf, you must enter an amount that bigger or equal to 0\n", amount);
        return;
    }
    for (size_t i=0;i<sizeof(Bank)/sizeof(Bank[0]);i++) {
        if (Bank[i][0] == 0) {
            Bank[i][0] += 901+i;
            Bank[i][1] += amount;
            printf("deposit: $%.2lf\n", amount);
            printf("your new bank account number is %.0lf, and you have $%.2lf.\n", Bank[i][0], amount);
            return;
        }
    }
    printf("unable to open the account, there are 50 accounts already");
    return;
}

void B(int account_number) {
    if (isOpen(account_number)==true) {
        printf("you have $%0.2lf in your account\n", Bank[account_number-901][1]);
        return;
    }else {
        printf("error, no such account exist");
        return;
    }
    
}

void D(int account_number, double amount) {
    if (isOpen(account_number)==true) {
        Bank[account_number-901][1] += amount;
        printf("you have $%0.2lf in your account\n", Bank[account_number-901][1]);
        return;
    }else {
        printf("error, no such account exist");
        return;
    }
}

void W(int account_number, double amount) {
    if (isOpen(account_number)) {
        if (Bank[account_number-901][1]>=amount) {
            Bank[account_number-901][1] -= amount;
            printf("you have $%0.2lf left in your account\n", Bank[account_number-901][1]);
            return;
        }else {
            printf("there's not enough money in your account to make the withdrew");
            return;
        }
    }else {
        printf("error, no such account exist");
        return;
    }
    
}

void C(int account_number) {
    if (isOpen(account_number)==true) {
        for (size_t i=0;i<sizeof(Bank[0])/sizeof(Bank[0][0]);i++) {
            Bank[account_number-901][i] = 0;
        }
        printf("the account is now closed\n");
        return;
    }else {
        printf("error, no such account exist");
        return;
    }
}

void I(double interest_rate) {
    for (size_t i=0;i<sizeof(Bank)/sizeof(Bank[0]);i++) {
        double onePercent = Bank[i][1]/100;
        Bank[i][1] += onePercent*interest_rate;
    }
}

void P() {
    for (size_t i=0;i<sizeof(Bank)/sizeof(Bank[0]);i++) {
        if (Bank[i][0] != 0){
            printf("account number: %.0lf have $%0.2lf\n", Bank[i][0], Bank[i][1]);
        }else continue;
    }
}

void E(){
    for (size_t i=0;i<sizeof(Bank)/sizeof(Bank[0]);i++) {
        Bank[i][0] = 0;
        Bank[i][1] = 0;
    }
}

int isOpen(int account_number) {
    int index = account_number - 901;
    if (index>-1 && index<50 && Bank[index][0]==account_number) {
        return true;
    }else return false;
}