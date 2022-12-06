#include <bits/stdc++.h>
using namespace std;
void mergee(int ar[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; ++i)
    {
        a[i] = ar[left + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        b[i] = ar[1 + mid + i];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            ar[k] = a[i];
            k++;
            i++;
        }
        else
        {
            ar[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        ar[k] = a[i];
        k++, i++;
    }
    while (j < n2)
    {
        ar[k] = b[j];
        k++;
        j++;
    }
}
void merge_sort(int ar[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(ar, left, mid);
        merge_sort(ar, mid + 1, right);
        mergee(ar, left, mid, right);
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
    merge_sort(ar, 0, n-1); // sorting function

    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << " ";
    }
}

