//
// Created by mhmds on 10/16/2022.
//

#ifndef PAYMENT_APPLICATION_CARD_H
#define PAYMENT_APPLICATION_CARD_H


typedef unsigned char uint8_t;

typedef struct ST_cardData_t{
	uint8_t cardHolderName[25];
	uint8_t primaryAccount[20];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef enum EN_cardError_t{
	OK_CARD,WRONG_NAME,WRONG_EXP_DATE,WRONG_PAN	
}EN_cardError_t;

int CheckLuhn(char CardNo[] ,int size);
EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
EN_cardError_t getCardExpiryData(ST_cardData_t *cardData);
EN_cardError_t getCardPAN(ST_cardData_t*cardData);




#endif //PAYMENT_APPLICATION_CARD_H
