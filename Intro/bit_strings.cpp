#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll power_mod(ll a, ll n, ll mod){
    ll ans = 1;
    while(n != 0){
        if(n%2==1){
            ans = ((ans%mod)*(a%mod))%mod;
            n--;
        }
        a = ((a%mod)*(a%mod))%mod;
        n/=2;
    }
    return ans;
}

int main(){
    int n; cin>>n;
    cout<<power_mod(2, n, 1e9+7)<<endl;
    return 0;
}