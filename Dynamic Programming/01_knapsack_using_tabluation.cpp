#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int profit[n], weight[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> profit[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i];
    }
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; ++i)
    {
        for (int w = 0; w <= m; ++w)
        {
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else if (weight[i] <= w)
            {
               dp[i][w]=max(dp[i-1][w], dp[i-1][w-weight[i]]+profit[i]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << dp[n][m] <<"\n";
}