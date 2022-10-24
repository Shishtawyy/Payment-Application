//
// Created by mhmds on 10/16/2022.
//

#include "Terminal.h"
void getTransactionDate(ST_terminalData_t * termdata)
{
    char date[10];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //printf("Date and time: %d,%d,%d\n",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900);
    date[0]=((tm.tm_mday)/10)+48;
    date[1]=((tm.tm_mday)%10)+48;
    date[2]=47;
    date[3]=(((tm.tm_mon + 1))/10)+48;
    date[4]=(((tm.tm_mon + 1))%10)+48;
    date[5]=47;
    date[6]=((tm.tm_year + 1900)/1000)+48;
    date[7]=(((tm.tm_year + 1900)/100)%10)+48;
    date[8]=(((tm.tm_year + 1900)/10)%10)+48;
    date[9]=((tm.tm_year + 1900)%10)+48;
     strcpy(termdata->transactionDate,date);
}









EN_terminalError_t isCardExpired(ST_cardData_t cardData , ST_terminalData_t termData)
{
   if(termData.transactionDate[8] < cardData.cardExpirationDate[3])
   return TERMINAL_OK;

   else if (termData.transactionDate[8] > cardData.cardExpirationDate[3])
   return EXPIRED_CARD;

   else if ((termData.transactionDate[8] == cardData.cardExpirationDate[3]))
   {   
           
           if(termData.transactionDate[9] < cardData.cardExpirationDate[4])
           return TERMINAL_OK;

           else if (termData.transactionDate[9]< cardData.cardExpirationDate[4])
           return EXPIRED_CARD;

           else if (termData.transactionDate[9] == cardData.cardExpirationDate[4])
           {    
                if ((termData.transactionDate[3]< cardData.cardExpirationDate[0]))
    return TERMINAL_OK;

    else if ((termData.transactionDate[3] > cardData.cardExpirationDate[0]))
    return EXPIRED_CARD ;

    else if (termData.transactionDate[3] == cardData.cardExpirationDate[0])
    {    
         if (termData.transactionDate[4] < cardData.cardExpirationDate[1])
         return TERMINAL_OK;


         else
         return EXPIRED_CARD;

    }
           }



   }


   
}










EN_terminalError_t getTransactionAmount(ST_terminalData_t * termdata)
{
     
printf("Enter the TRansaction amount :     ");
scanf("%f", &termdata->transAmount);
    fflush(stdin);
if(termdata->transAmount  ==  0  ||  termdata->transactionDate < 0 )
return INVALID_AMOUNT ;


else 
return TERMINAL_OK ;

}






EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termdata)
{   
      if(termdata->transAmount > termdata->maxTransAmount)
      return  EXCEED_MAX_AMOUNT ;
      
      
      
      else 
      return TERMINAL_OK ;

}    



EN_terminalError_t setMaxAmount(ST_terminalData_t * termdata)
{    termdata->maxTransAmount = MAX_AMOUNT ;
     if(termdata->maxTransAmount == 0 || termdata->maxTransAmount < 0 )
     return INVALID_MAX_AMOUNT ;


     else 
     return  TERMINAL_OK ;
}



EN_terminalError_t isValidCardPAN(ST_cardData_t * cardData)
{   int sumOdd=0, sumEven=0,allSum;
    for(int i = 1;i<16;i=i+2)
    sumOdd = sumOdd + cardData->primaryAccountNumber[i];
    for(int i = 0 ; i<16;i= i+2)
    {
        int sum =  cardData->primaryAccountNumber[i]* 2;

    if (sum >= 10)
        {sum = sum - 9;
         sumEven = sumEven + sum ;
        }

    else
    sumEven = sumEven + sum;
    }


     allSum = sumEven + sumOdd;


     if(allSum%10 == 0)
     return TERMINAL_OK;

     else
     return INVALID_CARD;
     


}