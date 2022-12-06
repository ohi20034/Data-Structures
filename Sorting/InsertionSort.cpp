#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int ar[], int n)
{
    for(int i=1; i<n; ++i)
    {
        int current = ar[i];
        int j = i-1;
        while(ar[j] > current && j >= 0){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = current;
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

    insertion_sort(ar, n); // sorting function

    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << " ";
    }
}