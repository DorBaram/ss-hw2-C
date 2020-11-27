//@author DorBaram
#ifndef EX2_MYBANK_H
#define EX2_MYBANK_H


void open(double amount);
void balance(int account_number);
void deposit(int account_number , double amount);
void withdraw(int account_number , double amount);
void close(int account_number);
void interest(double interest_rate);
void print();
void eX();


#endif //EX2_MYBANK_H
