// MERGE SORT

#include <bits/stdc++.h>
using namespace std;

void merge_2_sorted_arrays(vector <int> &a , vector <int> &b , vector <int> &v)
{
    int n1 = a.size() , n2 = b.size();
    int i = 0, j = 0 , k = 0;

    while(i < n1 and j < n2)
    {
        if(a[i] <= b[j]) v[k++] = a[i++];
        else v[k++] = b[j++];
    }

    if(i == n1)
    {
        while(j < n2)
        {
            v[k++] = b[j++];
        }
    }
    else if(j == n2) 
    {
        while(i < n1)
        {
            v[k++] = a[i++];
        }
    }
    return;
}
void mergesort(vector <int> &v)
{
    int n = v.size() , j = 0;

    if(n == 1) return;      // instead of taking whole in n > 1 (base case)

    int n1 = n/2;
    int n2 = n - n/2;
    vector <int> a (n1) ,b(n2);

    // copy the elements of vectors into (half half) arrays
    for(int i=0; i<n1; i++) a[i] = v[i];
    for(int i=n1; i<(n1+n2); i++) b[j++] = v[i];

    // do it recursively for both a and b
    mergesort(a);
    mergesort(b);

    // now we merge both , initially their size will be 1 so those 2 are merged

    merge_2_sorted_arrays(a,b,v);
}
int main()
{
    vector <int> v;

    v.push_back(18);
    v.push_back(-1);
    v.push_back(10);
    v.push_back(0);
    v.push_back(-5);
    v.push_back(15);
    v.push_back(-3);
    v.push_back(-3);

    for(int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << endl;

    mergesort(v);

    for(int i=0; i<v.size(); i++) cout << v[i] << " ";

    return 0;
}
