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
    vector<int> vec1, vec2;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i%2==1){
            vec1.push_back(i);
        }else{
            vec2.push_back(i);
        }
    }
    if(abs(vec1.front() - vec2.back()) != 1){
        for(auto &e: vec2){
            cout<<e<<" ";
        }
        for(auto &e: vec1){
            cout<<e<<" ";
        }
        cout<<endl;
    }else if(abs(vec2.front() - vec1.back()) != 1){
        for(auto &e: vec1){
            cout<<e<<" ";
        }
        for(auto &e: vec2){
            cout<<e<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO SOLUTION\n";
    }
    return 0;
}