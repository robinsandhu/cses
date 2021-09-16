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

int main(){
    fast;
    int n, x; cin>>n>>x;
    vector<int> price(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(price[i-1]<=j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-price[i-1]] + pages[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][x]<<endl;
    return 0;
}