//
// Created by mhmds on 10/16/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "Card.h"
#include <string.h>

EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
	printf("Enter The Card Holder Name: ");
	char NAME[25];
	fgets(NAME,30,stdin);
    NAME[strcspn(NAME,"\n")]=0;
	int length = strlen(NAME);
	if (NAME != NULL && length <=24 && length >=20 ){
		for (int i = 0; i < length; i++){		
		    if (NAME[i] >= '0' && NAME[i] <='9')
				return WRONG_EXP_DATE;
	    }	
		strcpy(cardData->cardHolderName,NAME);
		return OK_CARD;
	}
	else{
		return WRONG_NAME;
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
	printf("Please enter card expiry date in the format \"MM/YY\": ");
	char DATE[5]  ;
    scanf("%s",DATE);
	int length =strlen(DATE);
	int month ;
    fflush(stdin);
	if(DATE[0] == '0'){
		month = (DATE[1]-48);
	}else{
		month = DATE[0]*10+DATE[1]; 
	}		
	if (DATE == NULL || length != 5 || month<1 || month>12 || DATE[2] != '/')
		return WRONG_EXP_DATE;

    for (int i = 3; i < length; i++){
        if (DATE[i] < '0' || DATE[i]>'9')
            return WRONG_EXP_DATE;
    }
    strcpy(cardData->cardExpirationDate,DATE);
	return OK_CARD;	
}
int CheckLuhn(char CardNo[] ,int size){
	int sum =0 ,second = 0;
	for(int i = size-1;i>=0;i--){
		int d = CardNo[i] -'0';
		if(second == 1){
			d =d*2;
		}
		sum +=d/10;
		sum +=d%10;
		second = !second ;
	}
	return (sum % 10 == 0);
}

EN_cardError_t getCardPAN(ST_cardData_t*cardData){
	char NUM[20];
	printf("Please enter the card primary account number: ");
	scanf("%s",NUM);
	int length = strlen(NUM);
    fflush(stdin);
	if(CheckLuhn(NUM,length)){
		if(length<16 || length>19 ){
			return WRONG_PAN;
		}
		for (int i = 0; i < length; i++){		
			if (NUM[i] < '0' || NUM[i]>'9')
			{
				return WRONG_PAN; 
			}
		}
		strcpy(cardData->primaryAccountNumber,NUM);
		return OK_CARD;	
	}
	else{
		return WRONG_PAN;	
	}
}


















