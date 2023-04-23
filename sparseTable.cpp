#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
const int K = 20;
int arr[MAX];
int sp[K][MAX];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
    }
    for(int i=0; i<n; ++i)
    {
        sp[0][i] = arr[i];
    }
    for(int ien=1; ien<K; ++ien)
    {
        for(int j=st; st<n; ++st)
        {
            if(st + (1<<len) > n) break;
            sp[len][st] =
        }
    }
    // int k = 31 - __builtin_clz(n);
    /*   int mn = n;
       int log2 = 0;
       while(mn > 1)
       {
           log2++;
           mn /= 2;
       } */

}
