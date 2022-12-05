#include <bits/stdc++.h>
using namespace std;
void selection_sort(int ar[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (ar[i] > ar[j])
            {
                swap(ar[i], ar[j]);
            }
        }
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
    selection_sort(ar, n); // Selection sorting function

    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << " ";
    }
}