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
    int n, m, k; cin >> n >> m >> k;
    vector<int> b_val(n);
    vector<vector<int>> books(n, vector<int>(m));
    rep(i, n){
            cin >> b_val[i];
        rep(j, m){
            cin >> books[i][j];
        }
    }

        // bit 全探索
        ll res = 1e18;
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<ll> und(m, 0);
        ll money = 0;
        bool fg = true;
	//i番目に関する処理
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)){
                money += b_val[i];
                rep(j, m) und[j] += books[i][j];
            }
        }
        rep(i, m){
            if(und[i] < k){ fg = false; break;}
        }
        if(fg) chmin(res, money);
    }
    if(res == 1e18) res = -1;
    cout << res << ln;
}
