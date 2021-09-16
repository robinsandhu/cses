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
    int n; cin>>n;
    int ans = 0;
    for(int i=5;i<=n;i*=5){
        ans += n/i;
    }
    cout<<ans<<endl;
    return 0;
}