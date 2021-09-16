#include <bits/stdc++.h>
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define deb(x) std::cout << #x << " " << x << std::endl
#define PI 3.141592653589793238
 
using namespace std;
 
template <typename T>
void print(vector<T> &obj, int delim = 0)
{
    int n = obj.size();
    for (int i = 0; i < n; i++)
    {
        if (delim == 0)
            cout << obj[i] << " ";
        else if (delim == 1)
            cout << obj[i] << endl;
    }
    if (delim == 0)
        cout << endl;
}
 
struct Edge
{
    int u, v;
    ll c;
    Edge(int start, int end, ll cost) : u{start}, v{end}, c{cost} {}
};
 
int main()
{
    fast;
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    vector<ll> dist(n + 1, 0);
    vector<int> par(n + 1, -1);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j].u, v = edges[j].v;
            ll c = edges[j].c;
            if (dist[v] > dist[u] + c)
            {
                dist[v] = dist[u] + c;
                par[v] = u;
            }
        }
    }
 
    int cycle_node = -1;
    int relaxed_node = -1;
    bool flag = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j].u, v = edges[j].v;
        ll c = edges[j].c;
        if (dist[u] != LLONG_MAX)
        {
            if (dist[v] > dist[u] + c)
            {
                relaxed_node = v;
                flag = true;
                break;
            }
        }
    }
 
    if (!flag)
    {
        cout << "NO\n";
        return 0;
    }

    /// traceback ancestor n times so as to ensure that we are in a negative cycle

    cycle_node = relaxed_node;
    for(int i=0;i<n;i++){
        cycle_node = par[cycle_node];
    }

    vector<int> cycle;
    cycle.push_back(cycle_node);
    int temp = par[cycle_node];
    while (temp != cycle_node)
    {
        cycle.push_back(temp);
        temp = par[temp];
    }
    cout << "YES\n";
    for (auto &e : cycle)
    {
        cout << e << " ";
    }
    cout << cycle_node << endl;
    return 0;
}