// https://atcoder.jp/contests/dp/tasks/dp_n

#include <bits/stdc++.h>
using namespace std;

long long rec(int l,int r,vector<long long>&pre,vector<vector<long long>>&dp){
    if(l>=r) return 0;
    // if(l==r) return pre[l+1]-pre[l];
    
    if(dp[l][r]!=-1) return dp[l][r];
    
    long long ans=1e18;
    for(int i=l;i<r;i++) 
        ans=min(ans,pre[r+1]-pre[l]+rec(l,i,pre,dp)+rec(i+1,r,pre,dp));
    
    return dp[l][r]=ans;
}

int main(){
    int n; cin>>n;
    vector<long long>arr(n),pre(n+1);
    for(auto &i:arr) cin>>i;
    pre[0]=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i-1];
    vector<vector<long long>>dp(n,vector<long long>(n,-1));
    cout<<rec(0,n-1,pre,dp);
  
  return 0;
}
