#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Query{
    int type;
    pair<int, int> qry;
};

void constructSegTree(vector<ll> &segTree, vector<int> &arr, int v, int l, int r){
    if(l>r)
        return;
    if(l == r){
        segTree[v] = arr[l];
        return;
    }

    int mid = l + (r-l)/2;
    constructSegTree(segTree, arr, 2*v+1, l, mid);
    constructSegTree(segTree, arr, 2*v+2, mid+1, r);
    segTree[v] = segTree[2*v+1] + segTree[2*v+2];
}

ll rangeSum(vector<ll> &segTree, int v, int rl, int rr, int l, int r){
    if(l>r || rl>rr){
        return 0;
    }
    if(l == rl && r == rr){
        return segTree[v];
    }
    int mid = l + (r-l)/2;
    return rangeSum(segTree, 2*v+1, rl, min(rr, mid), l, mid) 
            + rangeSum(segTree, 2*v+2, max(rl, mid+1), rr, mid+1, r); 
}

void updateSegTree(vector<ll> &segTree, int v, int &index, int &val, int l, int r){
    if(l>r)
        return;
    if(l == r && l == index){
        segTree[v] = val;
        return;
    }
    int mid = l + (r-l)/2;
    if(index<=mid){
        updateSegTree(segTree, 2*v+1, index, val, l, mid);
    }else{
        updateSegTree(segTree, 2*v+2, index, val, mid+1, r);
    }
    segTree[v] = segTree[2*v+1]+segTree[2*v+2];
}

int main(){
    int n, q; cin>>n>>q;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<Query> queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i].type>>queries[i].qry.first>>queries[i].qry.second;
    }

    vector<ll> segTree(4*n);
    constructSegTree(segTree, vec, 0, 0, n-1);
    for(int i=0;i<q;i++){
        int type=queries[i].type, a=queries[i].qry.first, b=queries[i].qry.second;
        if(type == 1){
            a--;
            updateSegTree(segTree, 0, a, b, 0, n-1);
        }else if(type == 2){
            cout<<rangeSum(segTree, 0, a-1, b-1, 0, n-1)<<endl;
        }
    }
    return 0;
}