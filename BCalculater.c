#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



struct transaction
{
    char date[20];
    char category[20];
    float amount;
};

struct user
{
    char username[50];
    char password[50];
    float balance;
};

void recordIncome(struct user *usr, struct transaction *transactions, int *incomeCount);
void recordExpense(struct user *usr, struct transaction *transactions, int *expenseCount);
void displayDetails(struct user *usr, struct transaction *transactions, int incomeCount, int expenseCount);
void predictAverage(struct transaction *transactions, int incomeCount, int expenseCount);
char* getRandomQuote();

int main()
{
    struct user user, usr;
    struct transaction transactions[100];
    int incomeCount = 0;
    int expenseCount = 0;

    char filename[50], username[50], password[50], pword[50], uname[50];

    FILE *fp, *fptr;
    int opt, choice;
    char cont = 'y';

    printf("\nPersonal Budget Calculator");
    do
    {
        printf("\n\n1. Register your account");
        printf("\n2. Login to your account");
        printf("\n3. Exit");

        printf("\n\nPlease enter your choice:\t");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                system("cls");
                printf("\nEnter your username:\t\t");
                scanf("%s", user.username);
                printf("Enter your new password:\t");
                scanf("%s", user.password);
                user.balance = 0.0; // Initialize balance to zero

                strcpy(filename, user.username);

                fp = fopen(strcat(filename, ".dat"), "wb"); // Use "wb" for binary write mode
                fwrite(&user, sizeof(user), 1, fp);

                if (fwrite != 0)
                {
                    printf("Successfully registered");
                    fclose(fp);
                }
                break;

            case 2:
                system("cls");
                printf("Username: ");
                scanf("%s", uname);
                printf("Password: ");
                scanf("%s", pword);

                strcpy(filename, uname);

                fp = fopen(strcat(filename, ".dat"), "rb"); // Use "rb" for binary read mode

                if (fp == NULL)
                {
                    printf("This user is not registered");
                }
                else
                {
                    fread(&usr, sizeof(struct user), 1, fp);
                    fclose(fp);

                    if (!strcmp(pword, usr.password))
                    {
                        printf("\n\t\tWelcome %s", usr.username);

                        while (cont == 'y')
                        {
                            system("cls");

                            printf("\n\n1. Show Balance");
                            printf("\n2. Record Income");
                            printf("\n3. Record Expense");
                            printf("\n4. Change Password");
                            printf("\n5. Display Details");
                            printf("\n6. Show Predictions");

                            printf("\n\nYour choice:\t");
                            scanf("%d", &choice);

                            switch (choice)
                            {
                                case 1:
                                    printf("\nYour current balance is Rs.%.2f", usr.balance);
                                    break;

                                case 2:
                                    recordIncome(&usr, transactions, &incomeCount);
                                    break;

                                case 3:
                                    recordExpense(&usr, transactions, &expenseCount);
                                    break;

                                case 4:
                                    printf("\nPlease enter your new password:\t");
                                    scanf("%s", pword);
                                    strcpy(usr.password, pword);
                                    fp = fopen(filename, "wb"); // Use "wb" for binary write mode
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    if (fwrite != 0)
                                        printf("\nPassword successfully changed");
                                    fclose(fp);
                                    break;

                                case 5:
                                    displayDetails(&usr, transactions, incomeCount, expenseCount);
                                    break;

                                case 6:
                                    predictAverage(transactions, incomeCount, expenseCount);
                                    break;

                                default:
                                    printf("\nInvalid option");
                            }

                            printf("\nDo you want to continue the transaction [y/n]\t");
                            scanf(" %c", &cont); // Add a space before %c to consume the newline character
                        }
                    }
                    else
                    {
                        printf("\nInvalid password");
                    }
                }
                break;

            case 3:
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid option");
        }
    } while (opt != 3);

    return 0;
}

// Rest of your functions remain unchanged...


void recordIncome(struct user *usr, struct transaction *transactions, int *incomeCount)
{
    printf("\nEnter the Income amount:\t");
    scanf("%f", &transactions[*incomeCount].amount);

    printf("Enter the Income category (1-6):\n");
    printf("1. Awards\n2. Salary\n3. Grants\n4. Refunds\n5. Sale\n6. Other\n\nYour Choise: ");
    int categoryChoice;
    scanf("%d", &categoryChoice);

    switch (categoryChoice)
    {
    case 1:
        strcpy(transactions[*incomeCount].category, "Awards");
        break;
    case 2:
        strcpy(transactions[*incomeCount].category, "Salary");
        break;
    case 3:
        strcpy(transactions[*incomeCount].category, "Grants");
        break;
    case 4:
        strcpy(transactions[*incomeCount].category, "Refunds");
        break;
    case 5:
        strcpy(transactions[*incomeCount].category, "Sale");
        break;
    case 6:
        strcpy(transactions[*incomeCount].category, "Other");
        break;
    default:
        strcpy(transactions[*incomeCount].category, "Other");
    }

    printf("Enter the date (YYYY-MM-DD):\t");
    scanf("%s", transactions[*incomeCount].date);

    usr->balance += transactions[*incomeCount].amount;

    (*incomeCount)++;
}

void recordExpense(struct user *usr, struct transaction *transactions, int *expenseCount)
{
    printf("\nEnter the Expense amount:\t");
    scanf("%f", &transactions[*expenseCount].amount);

    printf("Enter the Expense category (1-7):\n");
    printf("1. Bills\n2. Clothes\n3. Education\n4. Food\n5. Shopping\n6. Transport\n7. Other\n\nYour Choise: ");
    int categoryChoice;
    scanf("%d", &categoryChoice);

    switch (categoryChoice)
    {
    case 1:
        strcpy(transactions[*expenseCount].category, "Bills");
        break;
    case 2:
        strcpy(transactions[*expenseCount].category, "Clothes");
        break;
    case 3:
        strcpy(transactions[*expenseCount].category, "Education");
        break;
    case 4:
        strcpy(transactions[*expenseCount].category, "Food");
        break;
    case 5:
        strcpy(transactions[*expenseCount].category, "Shopping");
        break;
    case 6:
        strcpy(transactions[*expenseCount].category, "Transport");
        break;
    case 7:
        strcpy(transactions[*expenseCount].category, "Other");
        break;
    default:
        strcpy(transactions[*expenseCount].category, "Other");
    }

    printf("Enter the date (YYYY-MM-DD):\t");
    scanf("%s", transactions[*expenseCount].date);

    usr->balance -= transactions[*expenseCount].amount;

    (*expenseCount)++;
}

void displayDetails(struct user *usr, struct transaction *transactions, int incomeCount, int expenseCount)
{
    system("cls");
    printf("\n\t\tUser: %s", usr->username);
    printf("\n\t\tBalance: Rs.%.2f\n", usr->balance);

    printf("\nIncome Details:\n");
    printf("Date\t\tCategory\tAmount\n");
    for (int i = 0; i < incomeCount; i++)
    {
        printf("%s\t%s\t%.2f\n", transactions[i].date, transactions[i].category, transactions[i].amount);
    }

    printf("\nExpense Details:\n");
    printf("Date\t\tCategory\tAmount\n");
    for (int i = 0; i < expenseCount; i++)
    {
        printf("%s\t%s\t%.2f\n", transactions[i].date, transactions[i].category, transactions[i].amount);
    }
}

void predictAverage(struct transaction *transactions, int incomeCount, int expenseCount)
{
    float totalIncome = 0.0;
    float totalExpenses = 0.0;

    for (int i = 0; i < incomeCount; i++)
    {
        totalIncome += transactions[i].amount;
    }

    for (int i = 0; i < expenseCount; i++)
    {
        totalExpenses += transactions[i].amount;
    }

    float averageIncomePerDay = totalIncome / incomeCount;
    float averageExpensesPerDay = totalExpenses / expenseCount;

    printf("\nAverage Income per Day: Rs.%.2f", averageIncomePerDay);
    printf("\nAverage Expenses per Day: Rs.%.2f", averageExpensesPerDay);

    char *quote = getRandomQuote();
    printf("\nTips for you: %s", quote);
}

char* getRandomQuote()
{
    char *quotes[] = {
        "Save money today for a better tomorrow.",
        "A penny saved is a penny earned.",
        "Cut your coat according to your cloth.",
        "Money, like emotions, is something you must control to keep your life on the right track.",
        "The art is not in making money, but in keeping it.",
        // Add more quotes here
    };

    int numQuotes = sizeof(quotes) / sizeof(quotes[0]);
    int randomIndex = rand() % numQuotes;

    return quotes[randomIndex];
}







