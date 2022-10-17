//
// Created by kareem on 10/17/22.
//

#ifndef PAYMENT_APPLICATION_DATABASE_H
#define PAYMENT_APPLICATION_DATABASE_H
#include "stdint-gcc.h"

//we will define this struct here instead
typedef struct ST_accountsDB_t
{
    float balance;
    uint8_t primaryAccountNumber [20];
}ST_accountsDB_t;

//messing the transaction struct as it needs card and
//terminal module to be implemented

//typedef struct ST_transaction_t
//{
//    ST_cardData_t cardHolderData;   (messing)
//    ST_terminalData_t terminalData;   (messing)
//    enum EN_transState_t transState;
//    uint32_t transactionSequenceNumber;
//}ST_transaction_t;

//accounts database functions to deal with text file
ST_accountsDB_t Get_Account (int i);
ST_accountsDB_t Set_Account(int i);
uint8_t Get_PAN (int i);
uint8_t Get_Balance(int i);


//transactions database functions to deal with text file (messing modules)

//ST_transaction_t Get_Transaction(int i)







#endif //PAYMENT_APPLICATION_DATABASE_H

