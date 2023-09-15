// https://cses.fi/problemset/task/1674/

#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int rec(int node, vector<vector<int>>&g,vector<int>&ans){
    if(g[node].size()==0) return 0;
    
    int res=0;
    for(auto i:g[node]) res+=1+rec(i,g,ans);
    
    return ans[node]=res;
}


int main(){
    int n; cin>>n;
    vector<vector<int>>g(n);
    for(int i=0;i<n-1;i++){
        int a;cin>>a;
        g[a-1].push_back(i+1);
    }
    vector<int>ans(n);
    rec(0,g,ans);
    for(auto i:ans) cout<<i<<" "; cout<<endl;
}
