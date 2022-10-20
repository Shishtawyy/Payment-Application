//
// Created by kareem on 10/17/22.
//

#ifndef PAYMENT_APPLICATION_DATABASE_H
#define PAYMENT_APPLICATION_DATABASE_H
#include "stdint-gcc.h"
#include "../Server/Server.h"
#include <stdio.h>
#include <string.h>



void Save_Transaction(ST_transaction_t *transaction);

void Get_Transaction(char * PAN,ST_transaction_t *transaction);

void Get_Account(char *PAN,ST_accountsDB_t *account);



#endif //PAYMENT_APPLICATION_DATABASE_H

