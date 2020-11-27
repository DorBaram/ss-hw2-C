#include "myBank.h"
#include "stdio.h"
//@author DorBaram
int main() {

    char choice ;
    double doubleTemp;
    int intTemp;

while (choice!='E') {

    printf("\nPlease choose a transaction type:\n"
           " O-Open Account\n"
           " B-Balance Inquiry\n"
           " D-Deposit\n"
           " W-Withdrawal\n"
           " C-Close Account\n"
           " I-Interest\n"
           " P-Print\n"
           " E-Exit\n");

    scanf(" %c" , &choice);
    switch (choice) {
        case 'O':
            printf("Please enter amount for deposit: ");
            if (scanf("%lf", &doubleTemp) == 1) {
                open(doubleTemp);
            } else
                printf("Failed to read the amount\n");
            break;

        case 'B':
            printf("Please enter account number: ");
            if (scanf("%d", &intTemp) == 1) {
                balance(intTemp);
            } else
                printf("Failed to read the account number\n");
            break;

        case 'D':
            printf("Please enter account number: ");
            if (scanf("%d", &intTemp) == 1) {
                printf("Please enter amount for deposit: ");
                if (scanf("%lf", &doubleTemp) == 1) {
                    deposit(intTemp, doubleTemp);
                } else
                    printf("Failed to read the amount\n");
            } else
                printf("Failed to read the account number\n");
            break;

        case 'W':
            printf("Please enter account number: ");
            if (scanf("%d", &intTemp) == 1) {
                printf("Please enter the amount to withdraw: ");
                if (scanf("%lf", &doubleTemp) == 1) {
                    withdraw(intTemp, doubleTemp);
                } else
                    printf("Failed to read the amount");
            } else
                printf("Failed to read the account number\n");
            break;

        case 'C':
            printf("Please enter account number: ");
            if (scanf("%d", &intTemp) == 1) {
                close(intTemp);
            } else
                printf("Failed to read the account number\n");
            break;

        case 'I':
            printf("Please enter interest rate: ");
            if (scanf("%lf", &doubleTemp) == 1) {
                interest(doubleTemp);
            } else
                printf("Failed to read the interest rate\n");
            break;

        case 'P':
            print();
            break;

        case 'E':
            eX();
            break;
        default:
            printf("Invalid transaction type\n");
            break;
    }

}
        eX();

    return 0;
}