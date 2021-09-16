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
    string str;
    cin>>str;
    int n=str.size();
    int count=1;
    int ans=1;
    for(int i=1;i<n;i++){
        if(str[i-1] == str[i]){
            count++;
            ans = max(ans, count);
        }else{
            count=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}