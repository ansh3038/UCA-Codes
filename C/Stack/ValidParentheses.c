#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool isValid(char *s)
{
    char arr[strlen(s)];
    int a = -1;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            arr[++a] = s[i];
        }
        else
        {
            if (a == -1)
            {
                return false;
            }
            if ((s[i] == ')' && arr[a] == '(') ||
                (s[i] == ']' && arr[a] == '[') ||
                (s[i] == '}' && arr[a] == '{'))
            {
                a--;
            }
            else
            {
                return false;
            }
        }
        i++;
    }

    return a == -1;
}

int main()
{
    char s[1000];
    gets(s);
    if (isValid(s))
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
}
