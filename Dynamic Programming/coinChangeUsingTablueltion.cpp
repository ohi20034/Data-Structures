#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int coin[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> coin[i];
    }
    int coins[n + 1][m + 1];
    // memset(coins,0,sizeof coins);
    for(int i=0; i<n+1; ++i){
        coins[i][0]=0;
    }
    for(int j=0; j<m+1; ++j){
        coins[0][j] = INT_MAX;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            if (j >= coin[i-1])
            {
                coins[i][j] = min(coins[i - 1][j], 1 + coins[i][j - coin[i-1]]);
            }
            else
            {
                coins[i][j] = coins[i - 1][j];
            }
        }
    }
    /* for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < m + 1; ++j)
        {
            cout << coins[i][j] << " ";
        }
        cout << "\n";
    } */
    cout << coins[n][m] << "\n";
}