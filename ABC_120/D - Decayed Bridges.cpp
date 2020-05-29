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

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};



int main(){
    ll n, m; cin >> n >> m;
    vector<pll> Q(m); 
    rep(i, m){
        ll a, b; cin >> a >> b; a--; b--; Q[i] = {a, b};
    }
    reverse(all(Q));
    vector<ll> res(m); res[0] = n*(n-1)/2;
    UnionFind uf(n);
    rep(i, m-1){
        ll a = Q[i].first, b = Q[i].second;
        ll sa = uf.size(a), sb = uf.size(b);
        uf.merge(a, b);
        ll sc = uf.size(a);

        ll num = res[i] - (sc*(sc-1)/2) + (sa*(sa-1)/2) + (sb*(sb-1)/2);
        if(sc == sa) res[i+1] = res[i];
        else res[i+1] = num;
    }
    for(int i=m-1; i>=0; i--){
        cout << res[i] << ln;
    }
}
