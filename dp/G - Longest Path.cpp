// https://atcoder.jp/contests/dp/tasks/dp_g

#include <bits/stdc++.h>

using namespace std;

int rec(int node, vector<int>g[],vector<int>&dp){
    int &ans=dp[node];
    if(ans!=-1) return ans;
    ans=0;
    for(auto child:g[node]) ans=max(ans,1+rec(child,g,dp));
    return ans;
}
int main(){
  int n,m; cin>>n>>m;
  vector<int>g[n];
  for(int i=0;i<m;i++){
      int a,b; cin>>a>>b;
      g[a-1].push_back(b-1);
  }
  vector<int>dp(n,-1);
  for(int i=0;i<n;i++) if(dp[i]==-1) rec(i,g,dp);
  int ans=dp[0];
  for(auto i:dp) ans=max(ans,i);
  cout<<ans<<endl;
  return 0;
}
