#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Query{
    ll a, b;
};

int main(){
    ll n, q; cin>>n>>q;
    vector<ll> vec(n);
    for(ll i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<Query> queries(q);
    for(ll i=0;i<q;i++){
        cin>>queries[i].a>>queries[i].b;
    }

    vector<ll> pref_sum(n, 0);
    pref_sum[0] = vec[0];
    for(ll i=1;i<n;i++){
        pref_sum[i] = pref_sum[i-1] + vec[i];
    }
    for(ll i=0;i<q;i++){
        ll a=queries[i].a, b=queries[i].b;
        ll ans = pref_sum[b-1];
        if(a-2>=0){
            ans -= pref_sum[a-2]; 
        }
        cout<<ans<<endl;
    }
    return 0;
}