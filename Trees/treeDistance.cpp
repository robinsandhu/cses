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
vector<int> ht;
vector<int> dp;

int heightTree(int node, int par){
    int ans = -1;
    for(auto &child: adj[node]){
        if(child != par){
            int temp = heightTree(child, node);
            if(temp > ans){
                ans = temp;
            }
        }
    }
    ht[node] = ans+1;
    return ans + 1;
}

int treeDistance(int node, int par){
    for(auto &child: adj[node]){
        if(child == par){
            ans = max(ans, 1 + dp[par]);
        }else{
            ans = max(ans, 1 + ht[child]);
        }
    }

    return 
}

int main(){
    fast;
    int n; cin>>n;
    adj = vector<vector<int>>(n+1);
    ht = vector<int>(n+1);
    dp = vector<int>(n+1);
    for(int i=0;i<n-1;i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    return 0;
}