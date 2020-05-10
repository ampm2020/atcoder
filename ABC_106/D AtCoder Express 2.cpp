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
    int n, m, Q; cin >> n >> m >> Q;
    vector<vector<int>> cnt(n, vector<int>(n, 0));
    rep(i, m){
        int l, r; cin >> l >> r; l--; r--;
        cnt[l][r]++;
    }
    rep(i, n){
        rep(j, n-1){
            cnt[i][j+1] += cnt[i][j];
        }
    }
    rep(i, n){
        for(int j=n-1; j > 0; j--){
            cnt[j-1][i] += cnt[j][i];
        }
    }
    rep(i, Q){
        int pl, pr; cin >> pl >> pr; pl--; pr--;
        cout <<  cnt[pl][pr] << ln;
    }
}
