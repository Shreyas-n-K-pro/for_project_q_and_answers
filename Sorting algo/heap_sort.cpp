#include <iostream>
using namespace std;

void heapify(int H[], int n, int i) 
{
    int K = i;
    int V = H[i];
    bool heap = false;

    while (!heap && 2 * K <= n) 
    {
        int j = 2 * K;

        if (j < n && H[j] < H[j + 1]) 
        {
            j++;
        }

        if (V >= H[j]) 
        {
            heap = true;
        } 
        else 
        {
            H[K] = H[j];
            K = j;
        }
    }

    H[K] = V;
}

void printHeap(int H[], int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        cout << H[i] << " ";
    }
    cout << endl;
}

void heapSort(int H[], int n) 
{
    for (int i = n / 2; i >= 1; i--) 
    {
        heapify(H, n, i);
    }

    for (int i = n; i > 1; i--) 
    {
        swap(H[1], H[i]);
        heapify(H, i - 1, 1);
    }
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int H[n + 1];
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; i++) 
    {
        cin >> H[i];
    }

    heapSort(H, n);

    cout << "Sorted array: ";
    printHeap(H, n);

    return 0;
}
