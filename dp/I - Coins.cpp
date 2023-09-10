// https://atcoder.jp/contests/dp/tasks/dp_i

#include <bits/stdc++.h>

using namespace std;

double rec(int level, int cnt, vector<double>&arr,vector<vector<double>>&dp){
    if(level==arr.size()){
        if(cnt>arr.size()/2) return 1;
        return 0;
    }
    
    if(dp[level][cnt]!=-1) return dp[level][cnt];
    
    double ans=rec(level+1,cnt,arr,dp)*(1-arr[level]);
    ans+=rec(level+1,cnt+1,arr,dp)*arr[level];
    
    return dp[level][cnt]=ans;
    
}
int main(){
  int n; cin>>n;
  vector<double>arr(n);
  vector<vector<double>>dp(n,vector<double>(n+1,-1));
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<setprecision(10);
  cout<<rec(0,0,arr,dp)<<endl;
  return 0;
}
