/**
 * Decimal to Binary Converter
*/
#include <stdio.h>
#include <string.h>

long double power(long double number, int times){
    if(times == 0)
    {
        return 1;
    }
    float original = number;
    number = (long double) number;
    for (long i = 1; i < times; i++)
    {
        number *= original;
    }
    return number;
};

int main()
{
    long double num, temp, binary = 0.0L;

    printf("  Enter Real number in Decimal form : ");
    scanf("%Lf", &num);
    long int integerPart = (long int) num;

    // finding integer binary part of number
    temp = integerPart;
    for(int i = 120; i >= 0; i--) 
    {
        if(temp - power(2, i) == 0)
        {
            binary += power(10, i);
            break;
        }
        else if(temp - power(2, i) > 0)
        {
            binary += power(10, i);
            temp -= power(2, i);
        }
    }
    
    //finding fractional binary part ob number
    temp = num - integerPart;
    for(int i = 1; i <= 120; i++) 
    {
        if(temp - power(0.5, i) == 0)
        {
            binary += power(0.1, i);
            break;
        }
        else if(temp - power(0.5, i) > 0)
        {
            binary += power(0.1, i);
            temp -= power(0.5, i);
        }
    }

    printf("  Real number in binary form : ");
    printf("%16.8Lf\n", binary);
}
