// https://atcoder.jp/contests/dp/tasks/dp_s

#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int rec(int level,int rem, int thi,string &s,vector<vector<vector<int>>>&dp,int &d){
    if(level==s.size()) return rem==0;
    
    if(dp[level][rem][thi]!=-1) return dp[level][rem][thi];
    
    int ans=0;
    for(int i=0;i<10;i++){
        int nthi=thi;
        if(nthi and (s[level]-'0')<i) continue;
        if(nthi and (s[level]-'0')>i) nthi=0; 
        ans+=rec(level+1,(rem+i)%d,nthi,s,dp,d);
        ans%=mod;
    }
    
    return dp[level][rem][thi]=ans;
}

int main(){
    string s; cin>>s;
    int d,n=s.size(); cin>>d;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(d,vector<int>(2,-1)));
    cout<<(rec(0,0,1,s,dp,d)-1+mod)%mod<<endl;
}

