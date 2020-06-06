#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000000000000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
   int a, b, q; cin >> a >> b >> q;
   vector<ll> A(a), B(b);
   rep(i, a) cin >> A[i];
   rep(i, b) cin >> B[i];
   sort(all(A)); sort(all(B));

   vector<ll> ans(q);
   rep(i, q){
       ll x; cin >> x;
       ll lj = -INF, lt = -INF, rj = INF, rt = INF;
       auto jinja = lower_bound(all(A), x);
       auto tera = lower_bound(all(B), x);
       if(jinja != A.end()) rj = *jinja;
       if(jinja != A.begin()){ jinja--; lj = *jinja;}
       if(tera != B.end()) rt = *tera;
       if(tera != B.begin()){tera--; lt = *tera;}

       ll one = max(x-lj, x-lt);
       ll two = max(rj-x, rt-x);
       ll three = x-lj + rt-x + min(x-lj, rt-x);
       ll four = rj-x + x-lt + min(rj-x, x-lt);
       ll res = min(min(one, two), min(three, four));
       ans[i] = res;
   }
   rep(i, q){
       cout << ans[i] << ln;
   }
}