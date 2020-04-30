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


int main() {
  int n, q;
  cin >> n >> q;
  vector<int> field(n + 10);

  rep(i, q){
    int a, b; cin >> a >> b; a--; b--;
    field[a]++;
    field[b+1]--;
  }
  int cnt = 0;
  rep(i, n){
    cnt += field[i];
    int res = cnt % 2;
    cout << res;
  }
  cout << ln;
}
    
