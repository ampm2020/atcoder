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
 
    string s, t;
    cin >> s >> t;

    int len_s = s.size(), len_t = t.size();
    vector<vector<int>> dp(len_t+1, vector<int>(len_s+1, 0));

    rep(i, len_t+1){
        rep(j, len_s+1){
            if(i == 0 || j == 0) continue;
            if(t[i-1] == s[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    string ans = "";
    int x = len_t, y = len_s;
    while(x > 0 && y > 0){
        if(dp[x][y] == dp[x-1][y]){
            x--;
        }else if(dp[x][y] == dp[x][y-1]){
            y--;
        }else{
            x--;
            y--;
            ans.push_back(s[y]);
        }
    }

    reverse(all(ans));
    cout << ans << ln;
}
 