#include <stdio.h>

int main() {
    int choice, i, type[50], count = 0,opt;
    float amount[50], balance = 0, money;

    do {
        printf("\n==== SIMPLE BANKING SYSTEM ====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Credit\n");
        printf("4. Show All Transactions\n");
        printf("5. Show Option Wise Transactions\n");
        printf("6. Check Balance\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:   // Deposit
            printf("Enter amount: ");
            scanf("%f", &money);

            balance += money;
            type[count] = 1;
            amount[count] = money;
            count++;

            printf("Deposit Successful!\n");
            break;

        case 2:   // Withdraw
            printf("Enter amount: ");
            scanf("%f", &money);

            if(money > balance) {
                printf("Insufficient Balance!\n");
            } else {
                balance -= money;
                type[count] = 2;
                amount[count] = money;
                count++;

                printf("Withdraw Successful!\n");
            }
            break;

        case 3:   // Credit
            printf("Enter amount: ");
            scanf("%f", &money);

            balance += money;
            type[count] = 3;
            amount[count] = money;
            count++;

            printf("Credit Added Successfully!\n");
            break;

        case 4:   // Show All Transactions
            printf("\n--- All Transactions ---\n");

            for(i = 0; i < count; i++) {
                if(type[i] == 1)
                    printf("Deposit  : %.2f\n", amount[i]);
                else if(type[i] == 2)
                    printf("Withdraw : %.2f\n", amount[i]);
                else if(type[i] == 3)
                    printf("Credit   : %.2f\n", amount[i]);
            }
            break;

        case 5:   // Option Wise Transactions
            printf("\n1. Deposit\n2. Withdraw\n3. Credit\n");
            printf("Enter option: ");
            scanf("%d", &opt);

            printf("\n--- Selected Transactions ---\n");

            for(i = 0; i < count; i++) {
                if(type[i] == opt) {
                    if(opt == 1)
                        printf("Deposit  : %.2f\n", amount[i]);
                    else if(opt == 2)
                        printf("Withdraw : %.2f\n", amount[i]);
                    else if(opt == 3)
                        printf("Credit   : %.2f\n", amount[i]);
                }
            }
            break;

        case 6:   // Balance
            printf("Current Balance = %.2f\n", balance);
            break;

        case 7:
            printf("Thank You for Using Banking System!\n");
            break;

        default:
            printf("Invalid Choice! Try Again.\n");
        }

    } while(choice != 7);

    return 0;
}