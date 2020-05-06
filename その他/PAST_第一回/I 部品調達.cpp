#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = LONG_LONG_MAX / 10;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n, m; cin >> n >> m;
    vector<string> parts(m);
    vector<ll> price(m);
    rep(i, m) cin >> parts[i] >>price[i];
    vector<ll> dp(1200, INF);

    dp[0] = 0;
    rep(i, m){
        int p = 0;
        rep(j, n){
            if(parts[i][j] == 'Y'){
                p += pow(2, j);
            }
        }
        for(int bit = 0; bit < (1<<n) - 1; bit++){
            //cout << "bit:" << bit << " ";
            if(dp[bit] == INF) continue;
            int np = p | bit;
            chmin(dp[np], dp[bit] + price[i]);
            
        }
    }
    int index = pow(2, n) - 1;
    if(dp[index] == INF) dp[index] = -1;
    cout << dp[index] << ln;
}


