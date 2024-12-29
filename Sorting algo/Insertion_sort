#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) 
{
    if (n == 1) return;

    int v, j = 0;

    for (int i = 1; i < n; i++) 
    {
        v = arr[i];
        j = i - 1;
        while (j >= 0 and arr[j] > v) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }
    return;
}

int main() 
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        insertion_sort(arr, i + 1); // Increment size as elements are read
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    return 0;
}
