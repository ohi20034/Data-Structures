#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+10;

int parent[MAX];

void make(int v)
{
    parent[v] = v;
}
int Find(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v] = Find(parent[v]);
}
void Union(int u,int v)
{
    u = Find(u);
    v = Find(v);
    if(u!=v)
    {
        parent[v] = u;
    }
}
int main()
{
    int n,q;
    cin >> n >> q;
    for(int i=0; i<=n; ++i){
        make(i);
    }
}
