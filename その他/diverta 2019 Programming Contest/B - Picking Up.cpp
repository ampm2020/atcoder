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

int main(){
    int n; cin >> n;
    vector<pii> pos(n);
    rep(i, n){
        int x, y; cin >> x >> y;
        pos[i] = {x, y};
    }

    map<pii, int> mp;
    rep(i, n){
        rep(j, n){
            if(i == j) continue;
            int x = pos[i].first - pos[j].first;
            int y = pos[i].second - pos[j].second;
            pii p{x,y}; mp[p]++;
        }
    }
    int mx = 0;
    for(auto m: mp){
        chmax(mx, m.second);
    }
    int res = n - mx;
    cout << res << ln;
}