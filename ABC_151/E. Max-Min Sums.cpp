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

const int MAX = 2100000;

long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}
int main(){ 
  COMinit();
  ll n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];

  ll mx = 0, mn = 0;
  sort(all(A));
  rep(i, n){
    int num = n - i - 1;
    ll com = COM(num, k-1);
    if(com==0) break;
    ll tmp = com * A[i] % MOD;
    mn = (mn + tmp + MOD) % MOD;
  }
  sort(all(A), greater<ll>());
  rep(i, n){
    int num = n - i - 1;
    ll com = COM(num, k-1);
    if(com==0) break;
    ll tmp = com * A[i] % MOD;
    mx = (mx + tmp + MOD) % MOD;
  }
  ll res = (mx - mn + MOD) % MOD;
  cout << res << ln;  
}
