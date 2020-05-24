#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n, p; cin >> n >> p;
    vector<int> A(n); rep(i, n) cin >> A[i];

    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[0][0] = 1;
    rep(i, n){
        if(A[i]%2 == 0){
            dp[i+1][0] += dp[i][0] *2;
            dp[i+1][1] += dp[i][1] *2;
        }else{
            dp[i+1][0] += dp[i][0] + dp[i][1];
            dp[i+1][1] += dp[i][0] + dp[i][1];
        }
    }
    if(p == 1) cout << dp[n][1] << ln;
    else cout << dp[n][0] << ln;
}
