#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 998244353;
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

int main() {   
    ll n, m; cin >> n >> m;
    UnionFind uf(n);
    rep(i, m){
        int a, b; cin >> a >> b; a--; b--;
        uf.merge(a, b);
    }
    int one = uf.size(0), two = uf.size(1);
    int big = one>=two ? 0 : 1;
    int small = big==0 ? 1 : 0;
    for(int i=2; i<n; i++){
        if(!uf.issame(big, i) && !uf.issame(small, i))uf.merge(big, i);
    }
    ll res = n*(n-1)/2 - ((ll)uf.size(0)*uf.size(1)) - m;
    //cout << uf.size(0) << " " << uf.size(1) << ln;
    cout << res << ln;
}

