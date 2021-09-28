#include <bits/stdc++.h>

using namespace std;

struct Query{
    int a, b;
};

void constructSegTree(vector<int> &segTree, vector<int> &arr, int v, int l, int r){
    if(l>r)
        return;
    if(l == r){
        segTree[v] = arr[l];
        return;
    }

    int mid = l + (r-l)/2;
    constructSegTree(segTree, arr, 2*v+1, l, mid);
    constructSegTree(segTree, arr, 2*v+2, mid+1, r);
    segTree[v] = segTree[2*v+1]^segTree[2*v+2];
}

int rangeXor(vector<int> &segTree, int v, int rl, int rr, int l, int r){
    if(l>r || rl>rr){
        return 0;
    }
    if(l == rl && r == rr){
        return segTree[v];
    }
    int mid = l + (r-l)/2;
    return rangeXor(segTree, 2*v+1, rl, min(rr, mid), l, mid) 
            ^ rangeXor(segTree, 2*v+2, max(rl, mid+1), rr, mid+1, r); 
}

int main(){
    int n, q; cin>>n>>q;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i].a>>queries[i].b;
    }

    vector<int> segTree(4*n);
    constructSegTree(segTree, vec, 0, 0, n-1);
    for(int i=0;i<q;i++){
        int a=queries[i].a, b=queries[i].b; 
        cout<<rangeXor(segTree, 0, a-1, b-1, 0, n-1)<<endl;
    }
    return 0;
}