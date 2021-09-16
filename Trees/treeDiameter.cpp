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

int ans;

int treeDiameter(vector<vector<int>> &adj, int node, int par){

    vector<int> heights;
    for(auto &child: adj[node]){
        if(child != par){
            heights.push_back(treeDiameter(adj, child, node));
        }
    }
    sort(heights.begin(), heights.end(), greater<int>());
    int max_1, max_2; max_1 = max_2 = 0;
    if(heights.size()>=2){
        max_1 = heights[0];
        max_2 = heights[1];
    }else if(heights.size() == 1){
        max_1 = heights[0];
    }
    int temp_ans = max({max_1, max_2});
    ans = max({ans, temp_ans + 1, 1 + max_1 + max_2});

    return temp_ans+1;
}

int main(){
    fast;
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=0;
    treeDiameter(adj, 1, -1);
    cout<<ans-1<<endl;
    return 0;
}