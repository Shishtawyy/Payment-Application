//
// Created by mhmds on 10/16/2022.
//

#ifndef PAYMENT_APPLICATION_TERMINAL_H
#define PAYMENT_APPLICATION_TERMINAL_H

#endif //PAYMENT_APPLICATION_TERMINAL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define MAX_AMOUNT    15000



typedef enum EN_terminalError_t{TERMINAL_OK, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT,INVALID_MAX_AMOUNT
}EN_terminalError_t;



typedef struct ST_teminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_teminalData_t;



EN_terminalError_t getTransaactionDate(ST_teminalData_t * termData);


EN_terminalError_t isCardExpired(ST_cardData_t cardData , ST_teminalData_t termData);


EN_terminalError_t isValidCardPAN(ST_cardData_t * cardData);


EN_terminalError_t getTransactionAmount(ST_teminalData_t * termdata);


EN_terminalError_t isBelowMaxAmount(ST_teminalData_t *termdata);


EN_terminalError_t setMAxAmount(ST_teminalData_t * termdata);

