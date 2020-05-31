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
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {  
   int n; cin >> n;
   vector<ll> A(n+1); rep(i, n+1) cin >> A[i];

   ll min_max[100100][2]; //0:min, 1:max
   min_max[n][0] = min_max[n][1] = A[n];
   for(int i=n-1; i>=0; i--){
       min_max[i][0] = min_max[i+1][0]/2 + min_max[i+1][0]%2 + A[i];
       min_max[i][1] = min_max[i+1][1] + A[i];
   }/*
   rep(i, n+1){
       cout << min_max[i][0] << " " << min_max[i][1] << ln;
   }*/
   if(min_max[0][0] > 1 || min_max[0][1] < 1) cout << -1 << ln;
   else{
        ll cnt[100100];cnt[0] = 1; 
        for(int i=1; i<=n; i++){
            cnt[i] = min((cnt[i-1]-A[i-1])*2, min_max[i][1]);
        }
        
        ll sum = 0;
        rep(i, n+1) sum += cnt[i]; 
        cout << sum << ln;
    }
}