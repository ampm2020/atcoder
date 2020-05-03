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
    int n, m;
    cin >> n >> m;
    vector<int> H(n); rep(i,n) cin >> H[i];
    vector<vector<int>> G(n, vector<int>());
    rep(i, m){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int cnt = 0;
    rep(i, n){
        bool fg = true;
        rep(j, G[i].size()){
            int index = G[i][j];
            if(H[i] <= H[index]){
                fg = false;
                break;
            }
        }
        if(fg) cnt++;
    }
    cout << cnt << ln;
}


