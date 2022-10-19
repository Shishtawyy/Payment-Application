//
// Created by mhmds on 10/16/2022.
//

#include "Terminal.h"
EN_terminalError_t getTransaactionDate(ST_teminalData_t * termdata)
{
     time_t t = time(NULL);
    struct tm *tm;
     char date[11];
      time(&t);
      tm = *localtime(&t);
     strftime(date, sizeof(date), "%d/%m/%Y",tm);
     strcpy(termdata->transactionDate,date);
}









EN_terminalError_t isCardExpired(ST_cardData_t cardData , ST_teminalData_t termData)
{
   if(termData.transactionDate[8]< ST_cardData_t.cardExpireDate[3])
   return TERMINAL_OK;

   else if (termData.transactionDate[8] > ST_cardData_t.cardExpireDate[3])
   return EXPIRED_CARD;

   else if ((termData.transactionDate[8] == ST_cardData_t.cardExpireDate[3]))
   {   
           
           if(termData.transactionDate[9] < ST_cardData_t.cardExpireDate[4])
           return TERMINAL_OK;

           else if (termData.transactionDate[9]< ST_cardData_t.cardExpireDate[4])
           return EXPIRED_CARD;

           else if (termData.transactionDate[9] == ST_cardData_t.cardExpireDate[4])
           {    
                if ((termData.transactionDate[3]< ST_cardData_t.cardExpireDate[0]))
    return TERMINAL_OK;

    else if ((termData.transactionDate[3] > ST_cardData_t.cardExpireDate[0]))
    return EXPIRED_CARD ;

    else if (termData.transactionDate[3] == ST_cardData_t.cardExpireDate[0])
    {    
         if (termData.transactionDate[4] < ST_cardData_t.cardExpireDate[1])
         return TERMINAL_OK;


         else
         return EXPIRED_CARD;

    }
           }



   }


   
}










EN_terminalError_t getTransactionAmount(ST_teminalData_t * termdata)
{
     
printf("Enter the TRansaction amount :     ");
scanf("%f", &termdata->transAmount);
if(termdata->transAmount  ==  0  ||  termdata->transactionDate < 0 )
return INVALID_AMOUNT ;


else 
return TERMINAL_OK ;

}






EN_terminalError_t isBelowMaxAmount(ST_teminalData_t *termdata)
{   
      if(termdata->transactionDate > termdata->maxTransAmount)
      return  EXCEED_MAX_AMOUNT ;
      
      
      
      else 
      return TERMINAL_OK ;

}    



EN_terminalError_t setMAxAmount(ST_teminalData_t * termdata)
{    termdata->maxTransAmount = MAX_AMOUNT ;
     if(termdata->maxTransAmount == 0 || termdata->maxTransAmount < 0 )
     return INVALID_MAX_AMOUNT ;


     else 
     return  TERMINAL_OK ;
}



EN_terminalError_t isValidCardPAN(ST_cardData_t * cardData)
{   int sumOdd=0, sumEven=0,allSum;
    for(int i = 1;i<16;i=i+2)
    sumOdd = sumOdd + ST_cardDate_t->primaryAcountNumber[i];
    for(int i = 0 ; i<16;i= i+2)
    {
        int sum =  ST_cardDate_t->primaryAcountNumber[i]* 2;

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