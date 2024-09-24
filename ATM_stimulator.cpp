#include <stdio.h>

int main() {
    int option;
    float balance = 50000.0f;  // Initial balance 
    float depositAmount, withdrawAmount;
    int attempts;

    while (1) {
        attempts = 0;  

        while (attempts < 2) {
            // Display menu
            printf("\nATM Simulator\n");
            printf("1. Check Balance\n");
            printf("2. Deposit\n");
            printf("3. Withdraw\n");
            printf("4. Exit\n");
            printf("Choose an option (1-4): ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    // Check balance
                    printf("Your current balance is: $%.2f\n", balance);
                    break;
                
                case 2:
                    // Deposit money
                    printf("Enter the amount to deposit: $");
                    scanf("%f", &depositAmount);
                    if (depositAmount > 0) {
                        balance += depositAmount;
                        printf("You have successfully deposited $%.2f\n", depositAmount);
                    } else {
                        printf("Invalid deposit amount.\n");
                    }
                    break;

                case 3:
                    // Withdraw money
                    printf("Enter the amount to withdraw: $");
                    scanf("%f", &withdrawAmount);
                    if (withdrawAmount > 0) {
                        if (withdrawAmount <= balance) {
                            balance -= withdrawAmount;
                            printf("You have successfully withdrawn $%.2f\n", withdrawAmount);
                        } else {
                            printf("Insufficient balance.\n");
                        }
                    } else {
                        printf("Invalid withdrawal amount.\n");
                    }
                    break;

                case 4:
                    // Exit
                    printf("Thank you for using the ATM. Goodbye!\n");
                    return 0;

                default:
                    // Invalid option
                    attempts++;
                    if (attempts < 2) {
                        printf("Invalid option. Please choose a number between 1 and 4.\n");
                    } else {
                        printf("Too many invalid attempts. Exiting...\n");
                        return 1;
                    }
                    break;
            }
            if (option >= 1 && option <= 4) {
                break;  // Exit loop if a valid option was selected
            }
        }
    }

    return 0;
}