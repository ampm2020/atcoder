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

const int A = 0, C = 1, G = 2, T = 3;
bool agc_judge(int a, int b, int c, int now){
    vector<int> num = {c,b,a,now};
    rep(i, 4){
      if(i<3)swap(num[i], num[i+1]);
      if(num[0]==A && num[1] == G && num[2] == C) return false;
      if(num[1]==A && num[2] == G && num[3] == C) return false;
      if(i<3)swap(num[i], num[i+1]);
    }
    return true;
}

int dp[101][4][4][4];

int main(){ 
  int n; cin >> n;
  rep(i, 101)rep(a, 4)rep(b,4)rep(c,4)dp[i][a][b][c] = 0;
  rep(a, 4)rep(b, 4)rep(c, 4){
    bool ok = agc_judge(a,b,c, -1);
    if(ok) dp[3][a][b][c] = 1;
  }
  rept(i, 3, n){
    rep(a, 4){
      rep(b, 4){
        rep(c, 4){
          rep(j, 4){
            bool ok = agc_judge(a,b,c,j);
            if(ok)(dp[i+1][j][a][b] += dp[i][a][b][c]) % MOD;
          }
        }
      }
    }
  }
  ll res = 0;
  rep(a, 4)rep(b,4)rep(c,4) (res += dp[n][a][b][c]) % MOD;
  cout << res << ln;
}
