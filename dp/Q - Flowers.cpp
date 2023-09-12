// https://atcoder.jp/contests/dp/tasks/dp_q

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >=0; i--)
#define P pair<ll,ll>
#define pb push_back
#define m_p make_pair
int INF = 1 << 30;
ll INFL = 1LL << 60;
ll MOD = 1000000007;

template<typename __T__>
int len(vector<__T__> x){
  return int(x.size());
}


ll lmax(ll x,ll y){
  if(x < y) return y;
  else return x;
}

ll lmin(ll x, ll y){
  if(x > y)return y;
  else return x;
}


struct Segtree{
  ll n;
  vector<ll> d;
  Segtree(ll x) : n(1), d(x*4,INFL) {
    ll t = 1;
    while(x > t){
      t *= 2;
    }
    n = t;
  }

  void update(ll i,ll x){
    i += n-1;
    d[i] = x;
    while(i > 0){
      i = (i-1)/2;
      d[i] = lmin(d[2*i+1],d[2*i+2]);
    }
  }

  ll query(ll a,ll b){
    return sub_query(a,b,0,0,n);
  }

  ll sub_query(ll a,ll b,ll k,ll l,ll r){
    if(a >= r || b <= l) return INFL;
    else if(a <= l && b >= r){
      return d[k];
    }else{
      ll res1 = sub_query(a,b,2*k+1,l,(r+l)/2);
      ll res2 = sub_query(a,b,2*k+2,(l+r)/2,r);
      return lmin(res1,res2);
    }
  }
};


int main(){
  ll n;
  cin >> n;
  vector<ll> h(n), a(n);
  rep(i,n) cin >> h[i];
  rep(i,n) cin >> a[i];

  Segtree dp(200010);
  rep(i,200010) {
    dp.update(i,INFL);
  }

  rep(i,n) {
    ll res = dp.query(0,h[i]);
    if (res == INFL) res = 0;
    else res *= -1;
    res += a[i];
    ll cnt = dp.query(h[i],h[i]+1);
    if (cnt == INFL) cnt = 0;
    else cnt *= -1;
    res = lmax(cnt,res);
    dp.update(h[i],-res);
  }

  ll ans = 0;
  rep(i,200005) {
    ll res = dp.query(i,i+1);
    if (res != INFL) {
      res *= -1;
      ans = lmax(ans,res);
    }
  }
  //ans = dp.query(0,n);
  cout << ans << endl;
  return 0;
}
