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

int N, W;
vector<ll> w, v;
vector<vector<ll>> dp;

ll rec(ll n, ll weight){
    if(n == N) return 0;

    if(dp[n][weight] != -1) return dp[n][weight];

    
    ll res;
    if(weight + w[n] <= W)
        res = max(rec(n+1, weight),
              rec(n+1, weight+w[n]) + v[n]);
    else
        res = rec(n+1, weight);

    return dp[n][weight] = res;
}

int main(){
    cin >> N >> W;
    rep(i, N){
        ll a, b; cin >> a >> b;
        w.push_back(a);
        v.push_back(b);
    }
    dp.assign(N+10, vector<ll>(W + 10, -1));

    ll ans = rec(0, 0);

    cout << ans << ln;
}