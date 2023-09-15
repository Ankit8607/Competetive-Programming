// https://cses.fi/problemset/task/1093/

#include <bits/stdc++.h>
using namespace std;

int mod=1e9+7;

int rec(int node, vector<vector<int>>&g,vector<int>&ans){
    if(g[node].size()==0) return 0;
    
    int res=0;
    for(auto i:g[node]) res+=1+rec(i,g,ans);
    
    return ans[node]=res;
}

int power(int a ,int b,int mode){
    int ans=1;
    while(b){
        if(b&1) ans=1LL*ans*a%mode;
        a=1LL*a*a%mode;
        b/=2;
    }
    return ans;
}


int main(){
    int n; cin>>n;
    int sum=n*(n+1)/2; 
    if(sum%2){
        cout<<0<<endl;
        return 0;
    }
    sum/=2;
    vector<int>dp(sum+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=i;j--){
            dp[j]+=dp[j-i];
            dp[j]%=mod;
        }
    }
    cout<<(1LL*dp[sum]*power(2,mod-2,mod))%mod<<endl;
}
