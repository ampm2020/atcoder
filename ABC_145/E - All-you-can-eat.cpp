#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int n, t; cin >> n >> t;
    vector<pii> food(n);
    rep(i, n){
        int a, b; cin >> a >> b;
        food[i] = {a, b};
    }
    sort(all(food));

    int mx = -1;
    vector<vector<int>> dp(n+1, vector<int>(t, -1));
    dp[0][0] = 0;
    rep(i, n){
        rep(j, t){
            if(dp[i][j] == -1) continue;
            int a = food[i].first, b = food[i].second;
            //i番目の食事を食べる
            if(j + a >= t){ //合計コストがt以上になった場合、それ以上は食べられない。お会計
                chmax(mx, dp[i][j] + b);
            }else{
                chmax(dp[i+1][j+a], dp[i][j] + b);
            }
            //食べない
            chmax(dp[i+1][j], dp[i][j]);
        }
    }
    rep(i, t){
        chmax(mx, dp[n][i]);
    }
    cout << mx << ln;
}