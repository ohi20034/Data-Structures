#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 10;
int arr[MAX];
int tree[MAX];

void init(int node,int b, int e)
{
    if(b==e)
    {
        tree[node] = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);

    tree[node] = tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j)
{
    if(i > e|| j < b)
    {
        return 0;
    }
    if(b >= i && e <=j)
    {
        return tree[node];
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    int leftSum = query(left,b,mid,i,j);
    int rightSum = query(right,mid+1,e,i,j);
    return leftSum+rightSum;
}
void update(int node,int b,int e,int target,int val)
{
    if(target > e || target < b)
    {
        return;
    }
    if(b==e && b==target)
    {
        tree[node] = val;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;

    update(left,b,mid,target,val);
    update(right,mid+1,e,target,val);

    tree[node] = tree[left]+tree[right];
}
int32_t main()
{

}
