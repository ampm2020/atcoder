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



int main() {
    int h, n; cin >> h >> n;
    vector<int> dam(n), mp(n);
    rep(i, n) cin >> dam[i] >> mp[i];

    vector<int> dp(h+1, INF);
    dp[0] = 0;
    rep(i, h+1){
        rep(j, n){
            int index = min((int)dp.size()-1, i+dam[j]);
            chmin(dp[index], dp[i] + mp[j]);
        }
    }
    cout << dp[h] << ln;
}

