#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    // making sure that number is greater than 0;
    while(number < 0);

    int digit1, digit2, digit3, digit4, digit5, digit6, digit7, digit8, digit9, digit10, digit11, digit12, digit13, digit14, digit15, digit16;
    digit1 = ((number % 100) / 10) * 2;
    digit2 = ((number % 10000) / 1000) * 2;
    digit3 = ((number % 1000000) / 100000) * 2;
    digit4 = ((number % 100000000) / 10000000) * 2;
    digit5 = ((number % 10000000000) / 1000000000) * 2;
    digit6 = ((number % 1000000000000) / 100000000000) * 2;
    digit7 = ((number % 100000000000000) / 10000000000000) * 2;
    digit8 = ((number % 10000000000000000) / 1000000000000000) * 2;

    // adding sum of second from last digits
    digit1 = (digit1 % 100) / 10 + (digit1 % 10);
    digit2 = (digit2 % 100) / 10 + (digit2 % 10);
    digit3 = (digit3 % 100) / 10 + (digit3 % 10);
    digit4 = (digit4 % 100) / 10 + (digit4 % 10);
    digit5 = (digit5 % 100) / 10 + (digit5 % 10);
    digit6 = (digit6 % 100) / 10 + (digit6 % 10);
    digit7 = (digit7 % 100) / 10 + (digit7 % 10);
    digit8 = (digit8 % 100) / 10 + (digit8 % 10);

    // finding digits that were not multiplied by 2
    digit9  = (number % 10);
    digit10 = (number % 1000) / 100;
    digit11 = (number % 100000) / 10000;
    digit12 = (number % 10000000) / 1000000;
    digit13 = (number % 1000000000) / 100000000;
    digit14 = (number % 100000000000) / 10000000000;
    digit15 = (number % 10000000000000) / 1000000000000;
    digit16 = (number % 1000000000000000) / 100000000000000;

    int sum1 = digit1 + digit2 + digit3 + digit4 + digit5 + digit6 + digit7 + digit8;
    int sum2 = digit9 + digit10 + digit11 + digit12 + digit13 + digit14 + digit15 + digit16;
    int sum3 = sum1 + sum2;

    // to count the length of the card
    int length = 0;
    // check the first number of visa
    long visa = number;
    // check the first number of amex
    long amex = number;
    // check the first number of master
    long master = number;

    if((sum3 % 10) != 0)
    {
        printf("%s\n","INVALID");
        return 0;
    }

    // Now we need to find if its VISA, MasterCard or Amex
    while(number > 0)
    {
        // number = number/10;
        number /= 10;
        // will give us the length of the card
        length++;
    }

    // checking if the card is VISA
    while (visa >= 10)
    {
        // visa = visa / 10;
        visa /= 10;
    }
    // printf("%li test\n", visa);

    if(visa == 4 && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }

    // checking if the card is AMEX
    while (amex >= 10000000000000)
    {
        // amex = amex / 10000000000000;
        //dividing by 13's digit to get the first two digits since its a 15 digit number
        amex /= 10000000000000;
    }
    // printf("%li test\n", amex);

    if(length == 15 && (amex == 34 || amex == 37))
    {
        printf("%s\n", "AMEX");
        return 0;
    }

    // checking if the card is a MasterCard
    while (master >= 100000000000000)
    {
        // master = master / 100000000000000;
        //dividing by 14's digit to get the first two digits since its a 16 digit number
        master /= 100000000000000;
    }
    // printf("%li test\n", master);

    if(length == 16 && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55))
    {
        printf("%s\n", "MASTERCARD");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }

}