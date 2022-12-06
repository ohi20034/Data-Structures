#include <bits/stdc++.h>
using namespace std;
void bubble_Sort(int ar[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar[j], ar[j + 1]);
            }
        }
    }
}
int main()
{
    int n; // size of a array
    cin >> n;
    int ar[n]; // array
    for (int i = 0; i < n; ++i)
    {
        cin >> ar[i];
    }
    bubble_Sort(ar,n); // bubble sort function
    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << " ";
    }
}