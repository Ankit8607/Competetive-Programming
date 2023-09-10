// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,k;
  cin>>n>>k;
  vector<int>h(n);
  for(auto &i:h) cin>>i;
  vector<int>dp(n,1e9);
  dp[0]=0;
  for(int i=1;i<n;i++){
    for(int j=i-1;i-j<=k and j>=0;j--){
      dp[i]=min(dp[i],abs(h[i]-h[j])+dp[j]);
    }
  }
  cout<<dp[n-1]<<endl;
  return 0;
}
