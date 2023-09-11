// https://atcoder.jp/contests/dp/tasks/dp_m

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k,mod=1e9+7; cin>>n>>k;
  vector<int>arr(n);
  vector<vector<int>>dp(n,vector<int>(k+1,0));
  for(int i=0;i<n;i++) cin>>arr[i];
  for(int i=0;i<=arr[0];i++) dp[0][i]=1;
  
  for(int i=1;i<n;i++){
      dp[i][0]=1;
      for(int j=1;j<=k;j++){
          if(j<=arr[i]) dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
          else dp[i][j]=(dp[i][j-1]+(dp[i-1][j]-dp[i-1][j-arr[i]-1]+mod)%mod)%mod;
      }
  }
  cout<<dp[n-1][k]<<endl;
  
  return 0;
}
