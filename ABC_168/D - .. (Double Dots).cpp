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


int main() {    
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n, vector<int>());
    rep(i, m){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> guide(n, -1);
    guide[0] = 0;
    queue<int> que; que.push(0);

    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(int e: G[pos]){
            if(guide[e] != -1) continue;
            guide[e] = pos;
            que.push(e);
        }
    }
    cout << "Yes" << ln;
    for(int i=1; i<n; i++) cout << guide[i] + 1 << ln; 
}
