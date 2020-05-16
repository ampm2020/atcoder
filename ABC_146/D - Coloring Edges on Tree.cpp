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

using edge = pii; //first: id, second: to
using node = pii; //first: id, second: before_color

int main() {
    int n; cin >> n;
    vector<vector<edge>> G(n, vector<edge>());
    vector<bool> seen(n, false); vector<int> colors(n-1, -1);
    rep(i, n-1){
        int a,b; cin >> a >> b; a--, b--;
        G[a].push_back(edge(i, b));
        G[b].push_back(edge(i, a));
    }
    int mx = 0, start;
    rep(i, n){
        if(mx < G[i].size()){
            mx = G[i].size();
            start = i;
        }
    }
    seen[start] = true;  
    queue<node> que;
    que.push(node(start, -1));

    while(!que.empty()){
        node nd = que.front(); que.pop();
        int num = nd.first, bc = nd.second;
        int nc = 1;
        for(edge e: G[num]){
            int id = e.first, to = e.second;
            if(seen[to]) continue;
            seen[to] = true;
            if(bc == nc) nc++;
            colors[id] = nc;
            que.push(node(to, nc));
            nc++;
        }
    }
    cout << mx << ln;
    rep(i, n-1) cout << colors[i] << ln;
}