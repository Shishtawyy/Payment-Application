//
// Created by mhmds on 10/16/2022.
//

#include"../Card/Card.h"
#include"../Terminal/Terminal.h"
#include"../Server/Server.h"

void clear_Structs (ST_cardData_t * card,ST_terminalData_t *terminal , ST_transaction_t * transaction );

void print_transaction(ST_transaction_t * transaction);

void appStart(void);