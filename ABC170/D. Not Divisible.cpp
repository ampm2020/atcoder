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
  int n; cin >> n;
  vector<ll> A(n),counter(1000100); 
  rep(i, n){
    cin >> A[i];
    counter[A[i]]++;
  }
  sort(all(A));

  int res = 0;
  vector<bool> check(1000100);
  rep(i, n){
    int num = A[i];
    if(counter[num]==1 && check[num] == false)res++;
    if(counter[num] == INF)continue;//既にふるいをかけているなら飛ばす
    for(int j=num; j<=1000000; j += num){
      check[j] = true;
    }
    counter[num] = INF;//INF=ふるいをかけた状態
  }

  cout << res << ln;
}

