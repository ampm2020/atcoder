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
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s; cin >> s;
    int dp[13][100001];

    rep(i, 13){
        rep(j, 100001){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;

    rep(i, s.size()){
        rep(j, 13){
            if(s[i] != '?'){
                int n = s[i] - '0';
                int mod = (j*10 + n) % 13;
                dp[mod][i+1] = (dp[mod][i+1] + dp[j][i]) % MOD;
            }else{
                rep(k, 10){
                    int mod = (j*10 + k) % 13;
                    dp[mod][i+1] = (dp[mod][i+1] + dp[j][i]) % MOD;
                }
            }
        }
    }
    cout << dp[5][s.size()] << ln;
}
