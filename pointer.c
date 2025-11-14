#include <stdio.h>

struct BankAccount {
    char name[30];
    float balance;
};

void deposit(struct BankAccount *acc, float amount) {
    acc->balance += amount;
}

void withdraw(struct BankAccount *acc, float amount) {
    if (amount > acc->balance)
        printf("Insufficient balance!\n");
    else
        acc->balance -= amount;
}

int main() {
    struct BankAccount acc = {"John Doe", 1000.0};
    int choice;
    float amount;

    while (1) {
        printf("\n--- Bank Menu ---\n");
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter amount: ");
            scanf("%f", &amount);
            deposit(&acc, amount);
            break;

        case 2:
            printf("Enter amount: ");
            scanf("%f", &amount);
            withdraw(&acc, amount);
            break;

        case 3:
            printf("Balance = %.2f\n", acc.balance);
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
