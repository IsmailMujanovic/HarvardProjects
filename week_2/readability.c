#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);

    double L = (double) l / w * 100;
    double S = (double) s / w * 100;

    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int w = text[i];
        if ((w >= 65 && w <= 90) || (w >= 97 && w <= 122))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int space = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            space++;
        }
    }
    return space;
}

int count_sentences(string text)
{
    int end = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            end++;
        }
    }
    return end;
}