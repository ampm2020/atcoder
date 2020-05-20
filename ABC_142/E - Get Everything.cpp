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



int main(){ 
    int n, m; cin >> n >> m;
    vector<int> price(m);
    vector<vector<int>> numbers(m, vector<int>(n, 0));
    rep(i, m){
        int b; cin >> price[i] >> b;
        rep(j, b){
            int c; cin >> c; c--;
            numbers[i][c] = 1;
        }
    }
    int p =pow(2, n);
    vector<int> dp(p, INF);
    dp[0] = 0;
    rep(i, m){
        int num = 0;
        rep(j, n){
           if(numbers[i][j] == 1) num += pow(2, j); 
        }
        for(int bit=0; bit < (1<<n) - 1; bit++){
            if(dp[bit] == INF) continue;
            int next = bit | num;
            chmin(dp[next], dp[bit] + price[i]);
        }
    }
    int res = dp[p-1];
    if(res == INF) res = -1;
    cout << res << ln;
}