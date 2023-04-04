#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int arr[MAX*4];
struct Tree
{
    int sum,prop=0;

} tree[MAX*4];

void init(int node,int b, int e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node].sum = tree[left].sum + tree[right].sum;
}
int query(int node,int b,int e,int i,int j,int pro=0)
{
    if(i > e|| j < b)
    {
        return 0;
    }
    if(b >= i && e <=j)
    {
        return tree[node].sum + ((e-b+1)*pro);

    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    int leftSum = query(left,b,mid,i,j,tree[node].prop+pro);
    int rightSum = query(right,mid+1,e,i,j,tree[node].prop+pro);
    return leftSum+rightSum;
}
void update(int node,int b,int e,int i,int j,int val)
{
    if(i > e || j < b)
    {
        return;
    }
    if(b >= i && e <=j)
    {
        tree[node].sum += ((e-b+1)*val);
        tree[node].prop += val;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;

    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);

    tree[node].sum = tree[left].sum + tree[right].sum + ((e-b+1)*tree[node].prop);
}
void clear()
{
    for(int i=0; i<MAX*4; ++i)
    {
        tree[i].sum=0;
        tree[i].prop=0;
        arr[i]=0;
    }
}
int32_t main()
{

}
