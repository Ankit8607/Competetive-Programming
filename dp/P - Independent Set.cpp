// https://atcoder.jp/contests/dp/tasks/dp_p

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int rec(int node,int col,int par,vector<vector<int>>&g,vector<vector<int>>&dp){
    // if(g[node].size()==1 and g[node][0]==par) return 1;
    
    if(dp[node][col]!=-1) return dp[node][col];
    
    // int &ans=dp[node][col];
    long long ans=1;
    for(auto i:g[node]){
        if(i==par) continue;
        if(col==1) ans*=rec(i,0,node,g,dp);
        else ans*=(rec(i,1,node,g,dp)+rec(i,0,node,g,dp))%mod;
        ans%=mod;
    }
    
    return dp[node][col]=ans;
}

int main(){
    int n; cin>>n;
    vector<vector<int>>g(n);
    for(int i=0;i<n-1;i++){
        int a ,b; cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    vector<vector<int>>dp(n,vector<int>(2,-1));
    if(n==1) cout<<2<<endl;
    else cout<<(rec(0,0,0,g,dp)+rec(0,1,0,g,dp))%mod<<endl;
  
  return 0;
}
