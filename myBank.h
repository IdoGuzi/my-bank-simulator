#ifndef MY_BANK_H
#define MY_BANK_H

#define true 1
#define false 0

void O(double amount);

void B(int account_number);

void D(int account_number, double amount);

void W(int account_number, double amount);

void C(int account_number);

void I(double interest_rate);

void P();

void E();

int isOpen(int account_number);

#endif