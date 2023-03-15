#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int main()
{
    int n,q;
    cin >> n;
    int arr[n+5];
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
    }
    cin >> q;
    int a = (sqrt(n))+1;
    int sq[a];
    for(int i=0; i<a; ++i)
    {
        sq[i] = INT_MAX;
    }
    for(int i=0; i<n; ++i)
    {
        sq[i/a] = min(arr[i],sq[i/a]);
    }
    while(q--)
    {
        int i,j;
        cin >> i >> j;
        int l=i,r=j;
        int ans = INT_MAX;
        for(int i=l; i<=r;)
        {
            if(i%(a)==0 && i+(a)-1<=r)
            {
                ans = min(ans,sq[i/a]);
                i += a;
            }
            else
            {
                ans = min(ans,arr[i]);
                i++;
            }
        }
        cout << ans << "\n";
    }
}
