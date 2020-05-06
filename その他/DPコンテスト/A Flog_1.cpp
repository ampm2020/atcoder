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
vector<int> h;
vector<int> dp;

int main(){
    cin >> n;
    h.resize(n); dp.resize(n, -1);
    rep(i, n) cin >> h[i];

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i ++){
        int one = dp[i-1] + abs(h[i] - h[i-1]);
        int two = dp[i-2] + abs(h[i] - h[i-2]);
        dp[i] = min(one, two);
    }

    cout << dp[n-1] << ln;
}