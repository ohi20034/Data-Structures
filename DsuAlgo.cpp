#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N];
int _size[N];
void make(int v)
{
    parent[v]=v;
    _size[v]=1;
}
int _find(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v]=_find(parent[v]);
}
int _union(int a,int b)
{
    a = _find(a);
    b = _find(b);
    if(a!=b)
    {
        if(_size[a] < _size[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        _size[a] += _size[b];
    }
}
int main()
{

}
