#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(n+10);
    rep(i, m){
        int num; cin >> num; 
        dp[num] = -1;
    }
    dp[0] = 1;
    int res = 0;
    rep(i, n){
        if(dp[i] == -1) continue;  
        if(dp[i+1] != -1) dp[i+1] += dp[i] % MOD;
        if(dp[i+2] != -1) dp[i+2] += dp[i] % MOD;
    }
    cout << dp[n] % MOD << ln;
}
