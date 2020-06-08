#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){ 
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m){
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
    }
    int s, t; cin >> s >> t; s--, t--;
    queue<pii> que; que.push({s, 0});
    vector<vector<int>> cost(n, vector<int>(3, -1));
    cost[s][0] = 0;
    while(!que.empty()){
        auto nd = que.front(); que.pop();
        int v1 = nd.first, v2 = nd.second;
        for(auto e: G[v1]){
            int nv2 = (v2+1)%3;
            if(cost[e][nv2] != -1) continue;
            cost[e][nv2] = cost[v1][v2] +1;
            que.push({e, nv2});
        }
    }
    if(cost[t][0] == -1) cout << -1 << ln;
    else cout << cost[t][0] / 3 << ln;
}