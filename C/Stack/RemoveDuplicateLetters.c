#include <stdbool.h>
char *removeDuplicateLetters(char *s)
{
    int count[26] = {0};
    bool check[26] = {false};

    int len = strlen(s);
    char *ans = (char *)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++)
    {
        if (check[s[i] - 'a'])
        {
            count[s[i] - 'a']--;
            continue;
        }

        while (top != -1 && ans[top] > s[i] && count[ans[top] - 'a'] > 0)
        {
            check[ans[top] - 'a'] = false;
            top--;
        }

        ans[++top] = s[i];
        count[s[i] - 'a']--;
        check[s[i] - 'a'] = true;
    }

    ans[top + 1] = '\0';
    return ans;
}
