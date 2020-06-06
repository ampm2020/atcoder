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
#define fo(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
   int h, w, d; cin >> h >> w >> d;
   map<int, pii>mp;//各数のx座標,y座標
   rep(i, h){
       rep(j, w){
           int num; cin >> num;
           mp[num] = {i, j};
       }
   }
   int mx = h*w;
   vector<ll> S(90010);
   for(int i=1; i<=d; i++){
       int num = i; S[i] = 0;
       while(num+d <= mx){
           int nx = mp[num+d].first, ny = mp[num+d].second;
           int x = mp[num].first, y = mp[num].second;
           ll cost = abs(ny-y)+abs(nx-x);
           S[num+d] = S[num]+cost;
           num += d;
       }
   }
   /*fo(i, 1, 10) cout << S[i] << " ";
   cout << ln;*/
   int q; cin >> q;
   vector<ll> res;
   rep(i, q){
       ll l, r; cin >> l >> r;
       res.push_back(S[r]-S[l]);
   }
   for(ll ans: res) cout << ans << ln;
}