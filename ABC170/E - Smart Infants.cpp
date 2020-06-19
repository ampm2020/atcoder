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

const int mx_n = 500000;
int siz, dat[2*mx_n-1];

void init(int num){
  siz = 1;
  while(siz < num) siz *= 2;
  rep(i, 2*siz-1) dat[i] = INF;
}
//k番目の値をaに書き換える
void update(int k, int a){
  k += siz-1;
  dat[k] = a;
  while(k>0){
    k = (k-1)/2;
    dat[k] = min(dat[k*2+1], dat[k*2+2]);
  }
}

//区間[a, b)の最小値を求める
//kは節点の番号（初期値0)、l,rはその節点の持つ長さ
int query(int a, int b, int k, int l, int r){
  if(r <= a || b <= l) return INF;

  if(a <= l && r <= b) return dat[k];
  else{
    int vl = query(a, b, k*2+1, l, (l+r)/2);
    int vr = query(a, b, k*2+2, (l+r)/2, r);
    return min(vl, vr);
  }
}

int main(){ 
  int n, q; cin >> n >> q;
  vector<int> A(n), B(n); 
  vector<multiset<int>> sets(200010);
  rep(i, n){
    cin >> A[i] >> B[i]; B[i]--;//i人目の園児のレートはA[i]で、B[i]に所属している
    sets[B[i]].insert(A[i]);
  }
  init(200000);

  rep(i, 200000){
    if(sets[i].empty())continue;
    int num = *sets[i].rbegin();
    update(i, num);
  }


  rep(i, q){
    int c, d; cin >> c >> d; c--, d--;//c人目の園児をdに移動する
    //A[c] = 移動する園児のレート B[c] = 移動する園児が元々いた園
    sets[B[c]].erase(sets[B[c]].find(A[c]));
    sets[d].insert(A[c]);

    //最大値の更新
    //cout << "B[c]:" << B[c] << " d:" << d << " ";
    if(!sets[B[c]].empty()){
      int tmp = *sets[B[c]].rbegin();
      //cout << "tmp1:" << tmp << " ";
      update(B[c], tmp); 
    }else{
      update(B[c], INF);
    }
    int tmp = *sets[d].rbegin(); //cout << "tmp2:" << tmp << ln;
    update(d, tmp);
    
    B[c] = d;

    int res = query(0, 200001, 0, 0, siz);
    cout << res << ln;
  }
}

