//
// Created by kareem on 10/17/22.
//
//
// Created by kareem on 10/18/22.
//

#include "DataBase.h"

void Save_Transaction(ST_transaction_t *transaction)
{
    FILE *fptr_card;
    FILE *fptr_terminal;
    int spaces = 0;
    int i = 0;
    while (spaces !=3  )
    {
        if (transaction->cardHolderData.cardHolderName[i] == ' ')
        {
            spaces++;
            transaction->cardHolderData.cardHolderName[i] = '|';
        }
        i++;

    }

    fptr_card = fopen("Card.txt", "a");
    fprintf(fptr_card,"%s %s %s \n",transaction->cardHolderData.primaryAccount,transaction->cardHolderData.cardHolderName,transaction->cardHolderData.cardExpirationDate);
    fptr_terminal = fopen("Terminal.txt","a");
    fprintf (fptr_terminal,"%s %s %f %f %d \n",transaction->cardHolderData.primaryAccount,transaction->terminalData.transactionDate,transaction->terminalData.maxTransAmount,transaction->terminalData.transAmount,transaction->transState);
    fclose(fptr_card);
    fclose(fptr_terminal);

}


void Get_Transaction(char * PAN,ST_transaction_t *transaction)
{
    FILE *fptr_card;
    FILE *fptr_terminal;
    int flag =0;

    fptr_card = fopen("Card.txt", "r");
    while (!feof(fptr_card)) {
        fscanf(fptr_card, "%s", transaction->cardHolderData.primaryAccount );
        if (strcmp(PAN, (char*)transaction->cardHolderData.primaryAccount ) == 0) {

            flag =1;

            fscanf(fptr_card, "%s %s",transaction->cardHolderData.cardHolderName,transaction->cardHolderData.cardExpirationDate);
            break;
        }

    }
    fclose(fptr_card);

    fptr_terminal = fopen("Terminal.txt","r");
    while (!feof(fptr_terminal)) {
        fscanf(fptr_terminal, "%s", transaction->cardHolderData.primaryAccount);
        if (strcmp(PAN, (char *) transaction->cardHolderData.primaryAccount) == 0) {


            fscanf(fptr_card, "%s %f %f %d",transaction->terminalData.transactionDate,&(transaction->terminalData.transAmount),&(transaction->terminalData.maxTransAmount),&(transaction->transState));
            break;
        }
    }
    if (flag == 0)
    {
        // a way to return that the transaction doesn't exist
        transaction->terminalData.transAmount = -1;
    }

    fclose(fptr_terminal);

}


void Get_Account(char *PAN,ST_accountsDB_t *account)
{
    int flag;
    FILE *fptr_account;
    fptr_account = fopen("Account.txt", "r");
    while (!feof(fptr_account))
    {
        fscanf(fptr_account,"%s",account->primaryAccountNumber);
        if (strcmp(PAN, (char *) account->primaryAccountNumber) == 0)
        {
            flag =1;
            fscanf(fptr_account,"%f",&(account->balance));
        }

    }
    if (flag == 0)
    {
        //if we didn't fin the account -1 means not found
        account->balance = -1;
    }





}

