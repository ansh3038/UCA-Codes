#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int postfix(char *string)
{
    int stack[1000];
    int top = -1;
    char *token = strtok(string, " ");
    while (token != NULL && strcmp(token, "?") != 0)
    {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
        {
            int op1 = stack[top--];
            int op2 = stack[top--];
            switch (token[0])
            {
            case '+':
                stack[++top] = op2 + op1;
                break;
            case '-':
                stack[++top] = op2 - op1;
                break;
            case '*':
                stack[++top] = op2 * op1;
                break;
            case '/':
                stack[++top] = op2 / op1;
                break;
            }
        }
        else
        {
            stack[++top] = atoi(token);
        }
        token = strtok(NULL, " ");
    }
    return stack[top];
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    while (n-- > 0)
    {
        char string[1000];
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';
        int result = postfix(string);
        printf("%d\n", result);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
