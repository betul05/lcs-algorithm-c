#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m + 1][n + 1];

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    char s1[] = "AGGTAB";
    char s2[] = "GXTXAYB";

    printf("%d\n", lcs(s1, s2));
    return 0;
}