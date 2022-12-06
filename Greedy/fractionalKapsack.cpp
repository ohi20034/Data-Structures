#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k; // n is profit array size and m is weight array size
    cin >> n >> m >> k;
    int profit[n], weight[m];
    vector<pair<double, int>> perkg; // vector for store perkg and weight
    for (int i = 0; i < n; ++i)
    {
        cin >> profit[i];
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> weight[i];
        perkg.push_back({(profit[i] / (double)weight[i]), weight[i]});
    }
    sort(perkg.rbegin(), perkg.rend());
    double ans = 0;
    for (int i = 0; i < m; ++i)
    {
        if (perkg[i].second <= k)
        {
            k -= perkg[i].second;
            ans += (perkg[i].second * perkg[i].first);
        }
        else
        {
            ans += (k * perkg[i].first);
            break;
        }
    }
    cout << ans << "\n";
}