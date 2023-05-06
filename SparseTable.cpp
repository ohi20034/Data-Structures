#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int LOGMAX = 17;
int n;
int arr[MAX];
int st[MAX][LOGMAX];
void build()
{
    for (int k = 1; k < LOGMAX; ++k)
    {
        for (int i = 1; i + (1 << k) - 1 <= n; ++i)
        {
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int query(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        st[i][0] = arr[i];
    }
    build();
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l++, r++;
        cout << query(l, r) << "\n";
    }
}
