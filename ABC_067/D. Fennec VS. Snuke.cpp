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
    int n; cin >> n;
    vector<vector<int>> G(n);
    rep(i, n-1){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }  

    //bfs＆経路復元
    queue<int> que; que.push(0);
    vector<int> d(n, INF); d[0] = 0;
    vector<int> prev(n); prev[0] = -1;
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int e: G[v]){
            if(d[e] == INF){
                d[e] = d[v] + 1;
                prev[e] = v;
                que.push(e);
            }
        }
    }
    vector<int> pass{n-1}; int cur = n-1;
    while(cur != 0){
        cur = prev[cur];
        pass.push_back(cur);
    }
    
    int black = 0, white = 0;
    vector<int> color(n, 0); //黒=1, 白=-1, 無=0
    rep(i, pass.size()){
        if(i<pass.size()/2) color[pass[i]] = -1, white++;
        else color[pass[i]] = 1, black++;
        //cout <<pass[i] <<" :" << color[pass[i]] << ln;
    }

    rep(i, n){
        if(color[i] == 0) continue;
        que.push(i);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int e: G[v]){
                if(color[e] != 0) continue;
                color[e] = color[i];
                color[i] == 1 ? black++ : white++ ;
                que.push(e);
            }
        }
    }
    //cout<< "black:" << black << " white:" << white << ln;
    cout << (black > white ? "Fennec" : "Snuke") << ln;
}