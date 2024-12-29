#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> BIT;

void update(int x, int delta, int n) 
{
    for (; x <= n; x = x + (x & -x)) 
    {
        BIT[x] += delta;
    }
}

int query(int x) 
{
    int sum = 0;
    for (; x >= 1; x = x - (x & -x)) 
    {
        sum += BIT[x];
    }
    return sum;
}

int rangeQuery(int l, int r) 
{
    return query(r) - query(l - 1);
}

int main() 
{
    ifstream file("input.txt");

    if (!file.is_open()) 
    {
        cerr << "File Not found\n";
        return 1;
    }

    int n;
    file >> n;
    BIT.resize(n + 1, 0);

    for (int i = 1; i <= n; ++i) 
    {
        int val;
        file >> val;
        update(i, val, n);
    }

    int q;
    file >> q;

    while (q--) 
    {
        int type, x, l, r;
        file >> type;

        if (type == 1) 
        {
            file >> x;
            cout << query(x) << endl;
        } 
        else if (type == 2) 
        {
            file >> l >> r;
            cout << rangeQuery(l, r) << endl;
        }
    }

    file.close();
    return 0;
}
