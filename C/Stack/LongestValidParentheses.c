#define Max(a, b) (a > b ? a : b)
int longestValidParentheses(char *s)
{
    int ans = 0;
    int n = strlen(s);
    int arr[n + 2];
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            arr[++j] = i;
        }
        else
        {
            if (j == -1)
            {
                arr[++j] = i;
            }
            else
            {
                if (s[arr[j]] == '(')
                {
                    j--;
                }
                else
                {
                    arr[++j] = i;
                }
            }
        }
    }
    int a = n;
    int b = 0;
    if (j == -1)
    {
        return n;
    }
    while (j != -1)
    {
        b = arr[j--];
        ans = Max(ans, a - b - 1);
        a = b;
    }
    ans = Max(ans, a);
    return ans;
}