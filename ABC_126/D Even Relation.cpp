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

using edge = pii;
using Graph = vector<vector<edge>>;
const int max_n = 1e5+10;

int n;
vector<int> color(max_n, -1);
Graph G(max_n, vector<edge>());

void dfs(int n){
    for(auto e: G[n]){
       int to = e.first, dist = e.second;
        if(color[to] == -1){
            if(dist % 2 == 1) color[n] == 1 ? color[to] = 0 : color[to] = 1;
            else color[n] == 1 ? color[to] = 1 : color[to] = 0;
            dfs(to);
        }
    }
}

int main(){
    cin >> n;
    rep(i, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back(edge(v, w));
        G[v].push_back(edge(u, w));
    }

    color[0] = 0;
    dfs(0);

    rep(i, n)
        cout << color[i] << ln;
}
