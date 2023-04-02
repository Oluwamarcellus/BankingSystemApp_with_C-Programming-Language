#include <stdio.h>
#include <stdlib.h>

/* --FUNCTIONS PROTOTYPES-- */
void disBal(char*, float);
void askAct(void);
void bankAction(char act);
void deposit(float*);
void withdraw(float*);
void info(void);


/** --GLOBAL VARIABLES-- */
float bal = 0;
char name[30];
char acctN[20];

/**
*PLEASE READ THIS LIST TO UNDERSTAND WHY AND HOW THE FUNCTIONS ARE USED IN THE PROGRAM
*1. while ((getchar()) != '\n'); ==>  This function removes '\n' from the input stream and also clear the stream from any excess user inputs
*2. system("cls"); ==> This function clears all messages in the output stream
*/

void main(void)
{
    if (name[0] == '\0' && acctN[0] == '\0')
    {
        printf("HELLO, PLEASE INPUT YOUR NAME(14 characters long): ");
        fgets(name, 30, stdin);
        printf("SET YOUR ACCT NUMBER(9 characters long): ");
        fgets(acctN, 20, stdin);
    }
    /** Displays bal on startup*/
    disBal(name, bal);

    /**Function that asks for banking actions*/
    askAct();

    return 0;
}

/** function that displays current balance*/
void disBal(char *n, float b)
{
    printf("\n--------------------------------\n");
    printf("WELCOME <===> %s\nYOUR BALANCE IS $%.2f\n", n, b);
    printf("--------------------------------\n");
}

/**function that prompts user for action*/
void askAct(void)
{
    char act;

    printf("\n=>press 1 for DEPOSIT");
    printf("\n=>press 2 for WITHDRAWAL");
    printf("\n=>press 3 for account details");
    printf("\nSELECT OPTION: ");
    act = getchar();

    /**This if statement checks if user has entered more than a single input**/
    if ((getchar()) != '\n')
    {
            while ((getchar()) != '\n');
            printf("\n\nPLEASE SELECT THE RIGHT OPTION\n");
            askAct();
    }

    if (!(act >= '1' && act <= '3'))
    {
            printf("\n\nPLEASE SELECT THE RIGHT OPTION\n");
            askAct();
    }

    /**This function is called to check for user input and perform the action they selected**/
    bankAction(act);
}

/**Function that checks for user bank action input and perform action based on the input**/
void bankAction(char act)
{
    switch(act){
        case '1':
            system("cls");
            deposit(&bal);
        break;
        case '2':
            system("cls");
            withdraw(&bal);
        break;
        case '3':
            system("cls");
            info();
        break;
    }
}

/**Deposit function**/
void deposit(float *b)
{
    int res, res2;
    float dep;

    printf("\nPress 1 to initiate DEPOSIT");
    printf("\nPress 2 to return to MAIN MENU");
    printf("\nSELECT OPTION: ");
    scanf("%d", &res);
    while ((getchar()) != '\n');

    if (res != 1 && res != 2)
    {
        printf("\nPLEASE SELECT THE CORRECT OPTION\n");
        deposit(b);
    } else if (res == 2)
    {
        system("cls");
        disBal(name, bal);
        askAct();
    } else
    {
        printf("\nENTER AMOUNT TO BE DEPOSITED(min $1 per deposit): $");
        if (scanf("%f", &dep) && dep > 0)
        {
            system("cls");
            *b = *b + dep; /**This adds the deposited amount to the balance**/
            printf("\n----------------------------------------------------------");
            printf("\nSUCCESS! You deposited $%.2f\n\nNEW BALANCE is $%.2f", dep, *b);
            printf("\n----------------------------------------------------------\n");
            while ((getchar()) != '\n');
            askAct();
        } else
        {
            printf("ENTER A VALID AMOUNT ($1 minimum)\n");
            while ((getchar()) != '\n');
            deposit(b);
        }
    }
}

/**Withdraw function**/
void withdraw(float *b)
{
    char res, res2;
    float wit;

    printf("\nPress 1 to initiate WITHDRAW");
    printf("\nPress 2 to return to the MAIN MENU");
    printf("\nSELECT OPTION: ");
    res = getchar();

    if ((getchar()) != '\n')
    {
            while ((getchar()) != '\n');
            printf("\n\nPLEASE SELECT THE RIGHT OPTION\n");
            withdraw(b);
    }

    if (!(res >= '1' && res <= '2'))
    {
            printf("\n\nPLEASE SELECT THE RIGHT OPTION\n");
            withdraw(b);
    }

    if (res == '2')
    {
        system("cls");
        disBal(name, bal);
        askAct();
    }
    if (res = '1')
    {
        printf("\nENTER THE AMOUNT TO WITHDRAW: $ ");

        if (scanf("%f", &wit) && wit > 0)
        {
            /**Checks if withdraw amount is not greater than balance**/
            if (*b >= wit)
            {
                system("cls");
                *b = *b - wit; /**This removes the withdrawn amount from the balance**/
                printf("\n----------------------------------------------------------");
                printf("\nSUCCESS! You withdrew $%.2f\n\nNEW BALANCE is $%.2f", wit, *b);
                printf("\n----------------------------------------------------------\n");
                while ((getchar()) != '\n');
                askAct();
            } else
            {
                /**If withdraw amount is greater than balance**/
                printf("\n********** WITHDRAW OF $%.2f IS GREATER THAN ACCOUNT BALANCE $%.2f **********\nRETRY!!!\n", wit, *b);
                while ((getchar()) != '\n');
                printf("\nPress 1 to try again");
                printf("\nPress 2 to DEPOSIT");
                printf("\nSELECT OPTION: ");
                res2 = getchar();

                while ((getchar()) != '\n')
                {
                    while ((getchar()) != '\n');
                    printf("\nPLEASE ENTER THE CORRECT OPTION\n");
                    printf("Press 1 to try again");
                    printf("\nPress 2 to DEPOSIT");
                    printf("\nSELECT OPTION: ");
                    res2 = getchar();
                }

                while ((res2 != '1' && res2 != '2'))
                {
                    printf("\nPLEASE ENTER THE CORRECT OPTION\n");
                    printf("Press 1 to try again");
                    printf("\nPress 2 to DEPOSIT");
                    printf("\nSELECT OPTION: ");
                    res2 = getchar();
                }

                if (res2 == '1')
                {
                    system("cls");
                    withdraw(b);
                }
                if (res2 == '2')
                {
                    system("cls");
                    deposit(b);
                }
            }
        } else
        {
            while ((getchar()) != '\n');
            printf("\n\n==YOUR INPUT IS INVALID, PLEASE TRY AGAIN!==\n");
            system("cls");
            withdraw(b);
        }
    }
}

/**Functions that displays account details**/
void info(void)
{
    system("cls");
    printf("\n=================================");
    printf("\nACCOUNT NAME: %s\nACCOUNT NUMBER: %s\nACCOUNT BALANCE: %.2f", name, acctN, bal);
    printf("\n==================================\n");
    askAct();
}
