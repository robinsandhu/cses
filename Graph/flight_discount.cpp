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

void dijkstra(vector<vector<pll>> &adj, vector<ll> &dist, vector<bool> &vis, ll start_node){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[start_node] = 0;
    pq.push({0, start_node});
    while(!pq.empty()){
        ll par_node = pq.top().second;
        ll par_node_dist = pq.top().first;
        pq.pop();

        if(vis[par_node])
            continue;

        vis[par_node] = true;

        for(auto edge: adj[par_node]){
            int child_node = edge.first;
            int edge_cost_par_child = edge.second;
            if(dist[child_node] > par_node_dist + edge_cost_par_child){
                dist[child_node] = par_node_dist + edge_cost_par_child;
                pq.push({dist[child_node], child_node});
            }
        }
    }
}

int main(){
    fast;
    int n, m;
    cin>>n>>m;
    vector<vector<pll>> graph(n+1);
    vector<vector<pll>> rev_graph(n+1);
    for(int i=0;i<m;i++){
        ll u, v, c; cin>>u>>v>>c;
        graph[u].push_back({v, c});
        rev_graph[v].push_back({u, c});
    }

    vector<ll> dist(n+1, LLONG_MAX), rev_dist(n+1, LLONG_MAX);
    vector<bool> vis(n+1, false);

    dijkstra(graph, dist, vis, 1);

    for(int i=0;i<=n;i++){
        vis[i] = false;
    }

    dijkstra(rev_graph, rev_dist, vis, n);

    ll ans=LLONG_MAX;
    for(int i=1;i<n;i++){
        for(auto edge: graph[i]){
            ans = min(ans, dist[i] + rev_dist[edge.first] + edge.second/2);
        }
    }
    cout<<ans<<endl;

    return 0;
}