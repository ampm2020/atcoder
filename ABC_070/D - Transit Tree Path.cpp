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

using edge = pll; //first: 移動先 second: コスト

int main() {
    int n; cin >> n;
    vector<vector<edge>> G(n);
    vector<ll> dist(n, -1);
    rep(i, n-1){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    int Q, k; cin >> Q >> k; k--;
    queue<int> que;
    que.push(k);
    dist[k] = 0;
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(pll e: G[pos]){
            ll to = e.first, cost = e.second;
            if(dist[to] != -1) continue;
            dist[to] = dist[pos] + cost;
            que.push(to);
        }
    }
    rep(i, Q){
        ll from, to; cin >> from >> to; from--, to--;
        ll res = dist[from] + dist[to];
        cout << res << ln;
    }
}