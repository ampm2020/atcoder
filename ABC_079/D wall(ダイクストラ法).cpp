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

#define MAX_V 10

struct edge {
    int to;
    int cost;
};

int V = 10;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<pii> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(pii(0, s));

    while (!que.empty()) {
        pii p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(pii(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int h, w; cin >> h >> w;
    rep(i, 10){
        rep(j, 10){
            int cost; cin >> cost;
            if(i == j) continue;
            G[i].push_back(edge{j, cost});
        }
    }
    int to1_cost[10];
    rep(i, 10){
        if(i==1) to1_cost[i] = 0;
        else{
            dijkstra(i);
            to1_cost[i] = d[1];
        }
    }
    
    int sum = 0;
    rep(i, h){
        rep(j, w){
            int num; cin >> num;
            if(num == -1 || num == 1) continue;
            sum += to1_cost[num];
        }
    }
    cout << sum << ln;
}


