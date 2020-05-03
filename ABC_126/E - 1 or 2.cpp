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

int n;
vector<vector<int>> G;

void dfs(int v, vector<bool>& fg){
    for(int e: G[v]){
        if(!fg[e]){
            fg[e] = true;
            dfs(e, fg);
        }
    }
}

int main() {
    int m; cin >> n >> m;
    G.assign(n, vector<int>());
    rep(i, m){
        int x, y, z; cin >> x >> y >> z; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<bool> visited(n, false);
    int cnt = 0;
    rep(i, n){
        if(!visited[i]){
            visited[i] = true;
            cnt++;
            dfs(i, visited);
        }
    }
    cout << cnt << ln;
}

