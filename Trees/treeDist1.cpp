#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define pll pair<ll, ll>
#define pii pair<int, int>
#define MP make_pair
#define PB push_back
#define PI 3.141592653589793238

using namespace std;

vector<vector<int>> adj;
vector<int> dist_end1, dist_end2;

pair<int, int> far_node(int node, int par=-1){

    pair<int, int> res{0, node};
    for(auto &child: adj[node]){
        if(child != par){
            auto temp = far_node(child, node);
            if(temp.first > res.first){
                res = temp;
            }
        }
    }
    res.first+=1;
    return res;
}

void find_dist(vector<int> &dist, int root, int par=-1, int d=0){
    dist[root] = d;

    for(auto &child: adj[root]){
        if(child!=par){
            find_dist(dist, child, root, d+1);
        }
    }
}

int main(){
    fast;
    int n; cin>>n;
    adj = vector<vector<int>>(n+1);
    dist_end1 = vector<int>(n+1);
    dist_end2 = vector<int>(n+1); 
    for(int i=0;i<n-1;i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int diam_end1 = far_node(1, -1).second;
    int diam_end2 = far_node(diam_end1, -1).second;
    find_dist(dist_end1, diam_end1);
    find_dist(dist_end2, diam_end2);
    for(int i=1;i<=n;i++){
        int ans = max(dist_end1[i], dist_end2[i]);
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}