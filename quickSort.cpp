#include <bits/stdc++.h>
using namespace std;
int partition(int ar[],int low,int high)
{
    int pivot = ar[high];
    int i =  low-1;
    for(int j=low; j<high; ++j)
    {
        if(ar[j] < pivot){
            i++;
            swap(ar[i],ar[j]);
        }
    }
    i++;
    swap(ar[i],ar[high]);
    return i; // return pivot index
}
void quick_sort(int ar[],int low,int high)
{
     if(low < high){
         int pivotindex = partition(ar,low,high); // for pivot index
         quick_sort(ar,low,pivotindex-1);
         quick_sort(ar,pivotindex+1,high);
     }
}
int main()
{
    int n; // size of array
    cin >> n;
    int ar[n]; // array
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }

    quick_sort(ar,0,n-1); // sorting function

    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << " ";
    }
}