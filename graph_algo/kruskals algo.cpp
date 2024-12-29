// KRUSKALS 

#include<bits/stdc++.h>
using namespace std;

void merge_2_sorted_arrays(vector <tuple<int,int,int>> &a , vector <tuple<int,int,int>> &b , vector <tuple<int,int,int>> &v)
{
    int n1 = a.size() , n2 = b.size();
    int i = 0, j = 0 , k = 0;

    while(i < n1 and j < n2)
    {
        if(get<2>(a[i]) <= get<2>(b[j])) v[k++] = a[i++];
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
void mergesort(vector <tuple<int,int,int>>  &v)
{
    int n = v.size() , j = 0;
    if(n == 1) return;
    int n1 = n/2;
    int n2 = n - n/2;
    vector <tuple<int,int,int>> a (n1) ,b(n2);

    // copy the elements of vectors into (half half) arrays
    for(int i=0; i<n1; i++) a[i] = v[i];
    for(int i=n1; i<(n1+n2); i++) b[j++] = v[i];

    // do it recursively for both a and b
    mergesort(a);
    mergesort(b);

    // now we merge both , initially their size will be 1 so those 2 are merged
    
    merge_2_sorted_arrays(a,b,v);
}

int find(vector<int>nums,int u,int v)
{
    if(nums[u] == nums[v]) return 1;
    return 0;
}

void union_array(vector<int> &nums,int u,int v)
{ 
    int temp = nums[u];
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i] == temp) nums[i]=nums[v];
    }
}


void kruskals()
{
    int n, e;
    cout << "Enter the number of vertices :";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> e;
    cout << "Enter u, v, w (Lexi-cographical of (u,v) ) : \n";
    vector <tuple<int,int,int>> arr, store;     // u , v, w
    vector <int> nums(n);
    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        arr.push_back({u,v,w});
    }
    mergesort(arr);

    for (auto t : arr)
    {
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }

    for(int i=0; i<n; i++) nums[i] = i;      // store 1 to n vertices into an array
    
    int count = 0;
    int sum = 0;
    for(int i=0; i<e; i++)
    {
        auto u = get<0>(arr[i]), v = get<1>(arr[i]), w = get<2>(arr[i]);
        if(!find(nums,u,v))         // when it is not found then u store 
        {
            union_array(nums,u,v); 
            store.push_back({u,v,w});
            sum += w;
            count ++;
        }
        if(count == n-1) break;
    }
    cout << endl;
    for(auto it : store) cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    cout << sum << endl;
}

int main()
{
    kruskals();
    return 0;
}
