#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long n;
    int c = 0;
    int checknum = 0;
    n = get_long("Number: ");

    int m, l, s1 = 0, s2 = 0, oddnum, evennum, s = 0, d1, d2, d;
    do
    {
        if (n < 100 && n > 9)
        {
            m = n;
        }
        else if (n < 10 && n > 0)
        {
            l = n;
        }

        if (c % 2 != 0)
        {
            oddnum = (n % 10) * 2;
            if (oddnum > 9)
            {
                d1 = oddnum % 10;
                d2 = oddnum / 10;
                d = d1 + d2;
                s1 += d;
            }
            else
            {
                s1 += oddnum;
            }
        }
        else if (c % 2 == 0)
        {
            evennum = n % 10;
            s2 += evennum;
        }

        n /= 10;
        c++;
    }
    while (n != 0);

    s = s1 + s2;
    if (s % 10 == 0)
    {
        checknum = 1;
    }

    if (c == 15 && (m == 34 || m == 37) && checknum == 1)
    {
        printf("AMEX\n");
    }
    else if (c == 16 && (m == 51 || m == 52 || m == 53 || m == 54 || m == 55) && checknum == 1)
    {
        printf("MASTERCARD\n");
    }
    else if ((c == 13 || c == 16) && l == 4 && checknum == 1)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}