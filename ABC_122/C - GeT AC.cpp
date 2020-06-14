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
  int n, q; string s; cin >> n >> q >> s;
  vector<int> S(n+1);
  rept(i, 2, n+1){
    if(s[i-1] == 'C' && s[i-2] == 'A')S[i]++;
    S[i] += S[i-1];
  }

  vector<int> ans(q);
  rep(i, q){
    int l, r; cin >> l >> r;
    ans[i] = S[r] - S[l-1];
    if(l>1 && s[l-1]=='C' && s[l-2]=='A')ans[i]--;
  }
  for(auto res: ans) cout << res << ln;
}
