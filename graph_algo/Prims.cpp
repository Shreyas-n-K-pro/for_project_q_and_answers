#include<bits/stdc++.h>
using namespace std;

void update(vector<vector<int>> &c, vector<int> &key, vector<int> &vis, int n) 
{
    for (int u = 0; u < n; u++) 
    {
        if (!vis[u]) 
        {
            for (int v = 0; v < n; v++) 
            {
                if (!vis[v] && c[u][v] != 99999) 
                {
                    key[v] = min(key[v], c[u][v]);
                }
            }
        }
    }
}

int min_vtx(vector<int> &key, vector<int> &vis, int n) 
{
    int mv = -1;
    int md = 99999;
    for (int i = 0; i < n; i++) 
    {
        if (!vis[i] && key[i] < md) 
        {
            md = key[i];
            mv = i;
        }
    }
    return mv;
}

int main() 
{
    cout << "Enter the number of vertices: ";
    int n;      
    cin >> n;

    vector<vector<int>> c(n, vector<int>(n, 99999));
    vector<int> key(n, 99999), vis(n, 0);
    vector<int> parent(n, -1);

    cout << "Enter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> c[i][j];
            if (i == j) c[i][j] = 0;
        }
    }

    key[0] = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        int u = min_vtx(key, vis, n);
        if (u == -1) break;
        vis[u] = 1;
        update(c, key, vis, n);
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) 
    {
        cout << parent[i] << " - " << i << "\t" << c[parent[i]][i] << "\n";
    }

    return 0;
}
