#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long creditNum;
    int lastDigit;
    int lastDigit2;
    int sumNum = 0;
    int x = 0;
    int counterCred = 0;
    long card;

    creditNum = get_long("Card Number: \n");
    card = creditNum;

    while (creditNum > 1)
    {
        lastDigit = creditNum % 100; // this finds the last two numbers of the digits
        lastDigit = (lastDigit / 10); // this identifies the last digit
        sumNum = lastDigit * 2;

        if (sumNum > 9)
        {
            x = x + sumNum % 10 + sumNum / 10; // this calculate the digits one by one.
        }
        else
        {
            x = x + sumNum;
        }

        lastDigit2 = creditNum % 10;
        x = lastDigit2 + x;

        creditNum = (creditNum / 100);
    }
    
        
    if (x % 10 && x > 0) // here checks if the number is bigger than 0.
    {
        printf("INVALID\n");
        return 0;
    }

    while (card > 1)
    {
        card = (card / 10);
        counterCred++;

        if ((card == 34 || card == 37) && counterCred == 13) // here checks if the number has 15 digits and starts with 34 or 37.
        {
            printf("AMEX\n");
            return 0;
        }

        else if ((card == 51 || card == 52 || card == 53 || card == 54 || card == 55)
                 && counterCred == 14) // here checks if the number has 16 digits and starts with 51, 52, 53, 54, and 55.
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if (card == 4 && (counterCred == 12 || counterCred == 15)) // here checks if the number has 13 or 16 digits and starts with 4.
        {
            printf("VISA\n");
            return 0;
        }

    }
   
    printf("INVALID\n");
        
}
