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


int main(){ 
  int r, c; cin >> r >> c;
  int senbei[r][c];
  rep(i, r)rep(j, c) cin >> senbei[i][j];

  int mx = -1;

  for (int bit = 0; bit < (1 << r); ++bit) {
    vector<int> one(c), zero(c);
	//i行目をひっくり返すかどうか
    for (int i = 0; i < r; ++i){
      bool rev = false;
      if (bit & (1 << i)) rev = true;
      for(int j = 0; j < c; j++){
        int num = senbei[i][j];
        if(!rev && num==0 || rev && num==1){
          zero[j]++;
        }else one[j]++;
      }       
    }
    int sum = 0;
    rep(i, c) sum += r-min(one[i], zero[i]);
    chmax(mx, sum);
  }
  cout << mx << ln;
}
