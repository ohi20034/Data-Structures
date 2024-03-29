#include <bits/stdc++.h>
using namespace std;
#define MAX_S 1000005
#define MOD 1000000007
#define BASE 257
long long hashValue[MAX_S + 10], powerOfBase[MAX_S + 10];
void generatePrefixHash(string &s)
{
    hashValue[0] = s[0];
    for (int i = 1; i < s.size(); ++i)
    {
        hashValue[i] = ((hashValue[i - 1] * BASE) + s[i]) % MOD;
    }
    powerOfBase[0] = 1;
    for (int i = 1; i <= s.size(); ++i)
    {
        powerOfBase[i] = (powerOfBase[i - 1] * BASE) % MOD;
    }
}
long long getHash(int start, int end)
{
    if (start == 0)
        return hashValue[end];

    return (hashValue[end] - ((hashValue[start - 1] * powerOfBase[end - start + 1]) % MOD) + MOD) % MOD;
}
long long generateHash(string &s)
{
    long long hashVal = 0;
    for (auto &i : s)
    {
        hashVal = ((hashVal * BASE) + i) % MOD;
    }
    return hashVal;
}
int main()
{
}