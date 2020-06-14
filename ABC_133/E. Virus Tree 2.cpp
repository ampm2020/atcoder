#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){ 
  ll n, k; cin >> n >> k;
  vector<vector<int>> G(n);
  rep(i, n-1){
    int a, b; cin >> a >> b; a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  ll res = k;
  queue<pii> que; //v, p
  que.push({0, -1});
  while(!que.empty()){
    auto tmp = que.front(); que.pop();
    int v = tmp.first, p = tmp.second;
    ll c = v==0? k-1 : k-2;
    for(auto e: G[v]){
      if(e == p) continue;
      res = res * c % MOD;
      c--;
      que.push({e,v});
    }
  }
  cout << res << ln;
}
