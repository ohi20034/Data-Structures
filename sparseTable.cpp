#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;
const int LOGMAX = 17;
int n;
int arr[MAX];
int st[MAX][LOGMAX];
void build()
{
    for(int k=1; k<LOGMAX; ++k)
    {
        for(int i=0; i+(1<<k)-1 < n; ++i)
        {
            st[i][k]=min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }
    }
}
int query(int low,int high)
{
    int l = high-low+1;
    int k = 0;
    while((1<<(k+1))<= l)
    {
        k++;
    }
    return min(st[low][k],st[low+l-(1<<k)][k]);
}
int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
        st[i][0] = arr[i];
    }
    build();
}
