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
  int x, y, z, k; cin >> x >> y >> z >> k;
  vector<ll> A(x), B(y), C(z);
  rep(i, x) cin >> A[i];
  rep(i, y) cin >> B[i];
  rep(i, z) cin >> C[i];
  
  vector<ll> V;
  rep(i, x){
    rep(j, y){
      V.push_back(A[i] + B[j]);
    }
  }
  sort(all(V), greater<ll>());
  if(V.size()> k) V.resize(k);
  vector<ll> res;
  rep(i, V.size()){
    rep(j, z){
      res.push_back(V[i] + C[j]);
    }
  }
  sort(all(res), greater<ll>());
  rep(i, k){
    cout << res[i] << ln;
  }
}
