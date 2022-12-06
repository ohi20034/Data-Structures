#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    s1 = '\0' + s1;
    s2 = '\0' + s2;
    int edit[n + 1][m + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (j == 0)
            {
                edit[i][j] = i;
            }
            else if (i == 0)
            {
                edit[i][j] = j;
            }
            else if (s1[j] == s2[i])
            {
                edit[i][j] = edit[i - 1][j - 1];
            }
            else
            {
                edit[i][j] = 1 + min({edit[i - 1][j - 1], edit[i - 1][j], edit[i][j - 1]});
            }
        }
    }
    cout << edit[n][m] << "\n";
}