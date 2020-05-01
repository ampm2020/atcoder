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

int n;
vector<vector<int>> happy(100010, vector<int>(3,0));
vector<vector<int>> dp(100010, vector<int>(3, 0));

int rec(int x, int y){
    if(x == 0) return 0;
    if(dp[x][y] != 0) return dp[x][y];
    
    rep(i, 3){
        if(i == y) continue;
        chmax(dp[x][y], rec(x-1, i));
    }
    return dp[x][y];
}

int main(){
    cin >> n;
    rep(i, n){
        rep(j, 3){
            cin >> happy[i][j];
        }
    }
    rep(i, 3) rec(n, i);

    int ans = max(max(dp[n][0], dp[n][1]), dp[n][2]);
    cout << ans << ln;
}
    