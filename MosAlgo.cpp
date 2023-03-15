#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5;
struct Query
{
    int l, r, idx;
} query[MAX];

int n, q;
int arr[MAX];
int range_ans;
int rootN;

bool cmp(Query &a, Query &b)
{
    if (a.l / rootN == b.l / rootN)
    {
        return a.r < b.r;
    }
    return a.l / rootN < b.l / rootN;
}

void add(int idx)
{
    range_ans += arr[idx];
}
void remove(int idx)
{
    range_ans -= arr[idx];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    rootN = sqrtl(n);
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int left, right;
        cin >> left >> right;
        left--, right--;
        query[i].l = left;
        query[i].r = right;
        query[i].idx = i;
    }
    sort(query, query + q, cmp);
    vector<int> ans(q);
    int L = 0, R = -1;
    for (int i = 0; i < q; ++i)
    {
        int ql = query[i].l;
        int qr = query[i].r;

        while (L > ql)
        {
            L--;
            add(L);
        }
        while (R < qr)
        {
            R++;
            add(R);
        }
        while (L < ql)
        {
            remove(L);
            L++;
        }
        while (R > qr)
        {
            remove(R);
            R--;
        }
        ans[query[i].idx] = range_ans;
    }
    for (int i = 0; i < q; ++i)
    {
        cout << ans[i] << "\n";
    }
}