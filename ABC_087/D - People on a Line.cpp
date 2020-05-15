#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1e18;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n, m; cin >> n >> m;
    vector<vector<pll>> G(n);
    vector<ll> dist(n, INF);
    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        G[a].push_back(pll(b, c));
        G[b].push_back(pll(a, -c));
    }

    queue<int> que;
    bool fg = true;
    rep(i, n){
        if(dist[i] != INF) continue;
        que.push(i); dist[i] = 0;
        while(fg && !que.empty()){
            int num = que.front(); que.pop();
            for(auto edge: G[num]){
                int to = edge.first, cost = edge.second;     
                if(dist[to] == INF){
                    dist[to] = dist[num] + cost;
                    que.push(to);
                }else if(dist[to] != dist[num] + cost){
                    fg = false;
                    break;
                }
            }
        }
    }

    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
}

    

    
