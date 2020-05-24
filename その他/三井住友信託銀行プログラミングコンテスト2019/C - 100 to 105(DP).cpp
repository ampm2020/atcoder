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
    int x; cin >> x;
    vector<bool> dp(100200);
    dp[0] = 1;
    rep(i, 100000){
        if(dp[i] == 1){
            for(int j=i+100; j<= i+105; j++){
                dp[j] = 1;
            }
        }
    }
    cout << dp[x] << ln;
}
