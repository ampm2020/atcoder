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

struct UnionFind {
    vector<int> par; 
    vector<int> size;

    UnionFind(int N) : par(N + 1), size(N + 1, 1) {
        for(int i = 0; i <= N; i++) 
          par[i] = i;
    }

    int root(int x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    int siz(int x){
      return size[root(x)];
    }

    void unite(int x, int y) { 
        int rx = root(x);
        int ry = root(y); 
        if (rx == ry) return;
        if(size[rx] < size[ry]){
          size[ry] += size[rx];
          par[rx] = ry;
        } else{
          size[rx] += size[ry];
          par[ry] = rx;
        }
    }

    bool is_same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> P(n);
    rep(i, n){
        int p; cin >> p;
        P[i] = p-1;
    }
    UnionFind uf(n);
    rep(i, m){
        int x, y; cin >> x >> y; x--, y--;
        uf.unite(x,y);
    }

    int res = 0;
    rep(i, n){
        int num = P[i];
        if(uf.is_same(num, P[num])) res++;
    }
    cout << res << ln;
}

