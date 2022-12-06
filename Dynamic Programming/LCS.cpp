#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    int lcs[n+1][m+1];
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=n; ++j)
        {
            if(i==0||j==0){
                lcs[i][j]=0;
            }
            else if(s1[i]==s1[j]){
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    cout << lcs[n][m] <<"\n";
}