#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll d[200][200];
void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(){ 
    int n, m, r; cin >> n >> m >> r;
    vector<int> rute(r);
    rep(i, r) {cin >> rute[i]; rute[i]--;}
    rep(i, 200){
        rep(j, 200){
            d[i][j] = 1e18;
        }
    }
    rep(i, m){
        int a, b; ll c; cin >> a >> b >> c; a--; b--; 
        d[a][b] = c;
        d[b][a] = c;
    }

    warshall_floyd(n);
    sort(all(rute));
    ll res = 1e18;
    do{
        ll dist = 0;
        rep(i, rute.size()-1){
            dist += d[rute[i]][rute[i+1]];
        }
        chmin(res, dist);
    }while(next_permutation(all(rute)));
    cout << res << ln;
}
