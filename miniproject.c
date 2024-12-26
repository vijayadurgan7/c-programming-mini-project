#include <stdio.h>
#include <string.h>

// Define structure for account
struct Account {
    int accountNumber;
    char accountHolderName[100];
    float balance;
};


// Function to create new account
void createAccount(struct Account accounts[], int *size) {
    printf("Enter account number: ");
    scanf("%d", &accounts[*size].accountNumber);
    printf("Enter account holder name: ");
    scanf("%s", accounts[*size].accountHolderName);
    accounts[*size].balance = 0.0;
    (*size)++;
}

// Function to deposit money
void deposit(struct Account accounts[], int size, int accountNumber, float amount) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to withdraw money
void withdraw(struct Account accounts[], int size, int accountNumber, float amount) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to display account details
void displayAccountDetails(struct Account accounts[], int size, int accountNumber) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder Name: %s\n", accounts[i].accountHolderName);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

// Function to generate mini statement
void generateMiniStatement(struct Account accounts[], int size, int accountNumber) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Mini Statement for Account Number: %d\n", accounts[i].accountNumber);
            printf("Balance: %.2f\n", accounts[i].balance);
            // Add transaction history here
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    struct Account accounts[100];
    int size = 0;
    int choice;
    int accountNumber;
    float amount;

    while (1) {
        printf("Bank Account Management System\n");
        printf("1. Create new account\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Display account details\n");
        printf("5. Generate mini statement\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &size);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accounts, size, accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accounts, size, accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                displayAccountDetails(accounts, size, accountNumber);
                break;
            case 5:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                generateMiniStatement(accounts, size, accountNumber);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}