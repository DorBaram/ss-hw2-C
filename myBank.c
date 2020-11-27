#include <stdio.h>
#include "myBank.h"
//@author DorBaram
const int maxAcc = 50;          //if you want to change the storing capacity
static double bank[50][2];      //chang it here too
static int counter = 0;
const int nineOone = 901;       //if you want to change the num of first account
//O
void open(double amount){
    if(counter<maxAcc){
        if(counter != -1){
            int ac = counter + nineOone;
            printf("New account number is: %d \n" ,ac );
            bank[counter][0] = amount;
            bank[counter][1] = 1;
            counter++;
        }
    }
    else{
        printf("Failed to open new account. Maximum capacity reached \n");
    }
}

//B
void balance(int account_number) {
    if (account_number < nineOone+maxAcc && account_number >= nineOone) {
        int acc = account_number - nineOone;
        if (bank[acc][1] == 1) {
            printf("The balance of account number %d is: %.2f \n", account_number, bank[acc][0]);
        } else
            printf("This account is closed\n");
    } else
        printf("account number out of bounds\n");
}

//D
void deposit(int account_number , double amount){
    int acc = account_number-nineOone;
    if(account_number<nineOone || account_number>nineOone+maxAcc)
        printf("account number out of bounds\n");
    else if(bank[acc][1]==1){
        if(amount<0)
            printf("ERROR --Cant Deposit Negative Amount--\n");
        else{
            bank[acc][0] += amount;
            printf("New Balance is: %.2f \n" ,bank[acc][0]);
        }
    }
    else
        printf("ERROR --The Account Is Closed--\n");
}

//W
void withdraw(int account_number , double amount){
    int acc = account_number-nineOone;
    if(account_number<nineOone || account_number>nineOone+maxAcc)
        printf("account number out of bounds\n");
    else if(bank[acc][1]==1){
        if(amount<0)
            printf("ERROR --Cant Withdraw Negative Amount--\n");
        else if(bank[acc][0]>=amount){
            bank[acc][0] -= amount;
            printf("New Balance is: %.2f \n" ,bank[acc][0]);
        } else
            printf("Cannot withdraw more than the balance\n");
    }
    else
        printf("ERROR --The Account Is Closed--\n");
}

//C
void close(int account_number){
    int acc = account_number-nineOone;
    if(bank[acc][1]==1){
        bank[acc][0]=0;
        bank[acc][1]=0;
        printf("The Account Is Closed \n");
    } else
        printf("ERROR --The Account Is Already Closed--\n");
}

//I
void interest(double interest_rate){
    double pre = 1+(interest_rate/100);
    for (int i = 0; i < counter; ++i) {
        if(bank[i][1]==1){
            bank[i][0] *= pre;
        }
    }
}

//P
void print(){
    for (int i = 0; i < counter; ++i) {
        if(bank[i][1]==1){
            balance(i+nineOone);
        }
    }
}

//E
void eX() {
    for (int i = 0; i < counter; ++i) {
        if (bank[i][1] == 1) {
            bank[i][0] = 0;
            bank[i][1] = 0;
        }
    }
    counter = -1;
}
