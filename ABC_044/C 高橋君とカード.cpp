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


int main() {
    int n, a; cin >> n >> a;
    vector<int> X(n);
    rep(i, n) cin >> X[i];

    vector<vector<vector<ll>>> dp(55, vector<vector<ll>>(2600, vector<ll>(55, 0)));
    ll sum = 0; dp[0][0][0] = 1;
    
    rep(i, n){
        rep(j, 2501){
            rep(k, i+1){
                dp[i+1][j+X[i]][k+1] += dp[i][j][k];
                dp[i+1][j][k] += dp[i][j][k];
            }
        }
    }
    rep(i, 2501){
        for(int k = 1; k <= 50; k++){
            if(i / (double)k == a){;
                sum +=  dp[n][i][k];             
            }
        }
    }
    cout << sum << ln;
}


