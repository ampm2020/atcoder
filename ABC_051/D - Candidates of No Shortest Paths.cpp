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

using edge = pll; //first: to, second: cost;
const int max_v = 110;
using pp = pair<ll, pll>;

int V;
vector<edge> G[max_v];
ll d[max_v];
map<pll, bool> passed; //辺{a, b}が通過済みかどうか

void dijkstra(int s){ 
    priority_queue<pp, vector<pp>, greater<pp>> que;
    fill(d, d+V, INF); 
    d[s] = 0; 
    que.push(pp(0, {-1, s}));

    while(!que.empty()){
        pp p = que.top(); que.pop();
        int f = p.second.first, t = p.second.second;
        int v = t;
        if(d[v] < p.first) continue; 
        //ここで通過チェック
        if(f != -1){
            pll p1{f, t}, p2{t, f};
            passed[p1] = true; passed[p2] = true;
        }

        for(edge e: G[v]){
            int to = e.first; ll cost = e.second;
            if(d[to] > d[v] + cost){
                d[to] = d[v] + cost;
                que.push(pp(d[to], {v,to}));
            }
        }
    }
}

int main(){
    int m; cin >> V >> m;
    rep(i, m){
        int a, b, c; cin >> a >> b >> c; a--; b--;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    rep(i, V) dijkstra(i);

    ll res = (m*2 - passed.size()) / 2;
    cout << res << ln;
}
