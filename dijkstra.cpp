// DIJEKSTRAS


#include<bits/stdc++.h>
using namespace std;

auto init_dist(vector<vector<int>> &cost, vector<int> &dist, int src) 
{
    int n = dist.size();
    for (int j = 0; j < n; j++) 
    {
        dist[j] = cost[src][j];
    }
    return min_element(begin(dist), end(dist));
}

void update(vector<vector<int>> &c, vector<int> &vis, vector<int> &dist, int n) 
{
    for (int u = 0; u < n; u++) 
    {
        if (!vis[u]) 
        {
            for (int v = 0; v < n; v++) 
            {
                if (!vis[v] && c[u][v] != 99999) 
                {
                    dist[v] = min(dist[v], dist[u] + c[u][v]);
                }
            }
        }
    }
}

void start(vector<int> &vis, int src) 
{
    vis[src] = 1;
}

int min_vtx(vector<int> &dist, vector<int> &vis, int n) 
{
    int mv = -1;
    int md = 99999;
    for (int i = 0; i < n; i++) 
    {
        if (!vis[i] && dist[i] < md) 
        {
            md = dist[i];
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

    cout << "Enter the source vertex: ";
    int src;
    cin >> src;

    vector<vector<int>> c(n, vector<int>(n, 99999));
    vector<int> dist(n, 99999), vis(n, 0);

    cout << "Enter the cost adjacency matrix:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> c[i][j];
            if (i == j) c[i][j] = 0;
        }
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        int u = min_vtx(dist, vis, n);
        if (u == -1) break;
        start(vis, u);
        update(c, vis, dist, n);
    }

    for (int i = 0; i < n; i++) 
    {
        if (dist[i] == 99999) 
            cout << "INF\n";
        else 
            cout << dist[i] << "\n";
    }

    return 0;
}
