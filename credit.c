//Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
//Add the sum to the sum of the digits that weren’t multiplied by 2.
//If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

//CARD          Starts With             # of Digits
//-------------------------------------------------
//AMEX          34, 37                  15
//MSTR          51, 52, 53, 54, 55      16
//VISA          4                       13, 16

//eod --> Every Other Digit

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long cc_number;
    string card_type;

    //prompting user for credit card number
    do
    {
        cc_number = get_long_long("Credit Card Number: ");
    }
    while (cc_number <= 0);

    //make a copy of the credit card number to edit

    long long cc_digits = cc_number;

    //put credit card digits into an array and count number of digits
    int digits_array[16];
    int count = 0;
    for (int i = 0; cc_digits > 0; i++)
    {
        digits_array[i] = cc_digits % 10;
        cc_digits /= 10;
        count ++;
    }

    //multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together
    int eod_sum = 0;
    for (int j = 1; j <= count; j += 2)
    {
        if (digits_array[j] <= 4)
        {
            eod_sum = eod_sum + (digits_array[j] * 2);
        }
        else
        {
            eod_sum = eod_sum + (((digits_array[j] * 2) % 10) + 1);
        }
    }

    //add the sum to the sum of the digits that weren’t multiplied by 2.
    int total_sum = eod_sum;
    for (int k = 0; k < count; k += 2)
    {
        total_sum = total_sum + digits_array[k];
    }

    //check if total’s last digit is 0
    int validity_check = total_sum % 10;

    //determine whether card is AMEX, MASTER, VISA, or INVALID
    if (validity_check == 0)
    {
        if (count == 15 && digits_array[count - 1] == 3 && (digits_array[count - 2] == 4 || digits_array[count - 2] == 7))
        {
            card_type = "AMEX";
        }
        else if (count == 16 && digits_array[count - 1] == 5 && (5 >= digits_array[count - 2] >= 1))
        {
            card_type = "MASTERCARD";
        }
        else if ((count == 13 || count == 16) && digits_array[count - 1] == 4)
        {
            card_type = "VISA";
        }
        else
        {
            card_type = "INVALID";
        }
    }
    else
    {
        card_type = "INVALID";
    }

    //print result
    printf("%s\n", card_type);
}
