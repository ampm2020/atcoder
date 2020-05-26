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


int main() {
    int n, x, y; cin >> n >> x >> y; x--, y--;
    vector<vector<int>> G(n);
    rep(i, n-1){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x].push_back(y); G[y].push_back(x);

    vector<int> res(n, 0); //各距離の経路数
    queue<int> que;
    rep(i, n){
        vector<int> cost(n, -1);
        que.push(i); cost[i] = 0;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int e: G[v]){
                if(cost[e] != -1) continue;
                cost[e] = cost[v] + 1;
                if(e > i)res[cost[e]]++;
                que.push(e);
            }
        }
    }
    for(int i=1; i<n; i++){
        cout << res[i] << ln;
    }
}
