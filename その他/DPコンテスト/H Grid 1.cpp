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

 
int main(){
    int h, w;
    cin >> h >> w;
    vector<string> grid(h+10);
    rep(i, h){
        cin >> grid[i];
        grid[i] += ' ';
    }
  
    vector<vector<ll>> dp(h+10, vector<ll>(w+10, 0));
    dp[0][0] = 1;
    rep(i, h){
        rep(j, w){
            if(grid[i][j] == '#') continue;
            if(grid[i+1][j] == '.'){
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            }
            if(grid[i][j+1] == '.'){
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
            }
        }
    }
    cout << dp[h-1][w-1] << ln;
}