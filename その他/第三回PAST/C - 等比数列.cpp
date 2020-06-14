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
    ll a, r, n; cin >> a >> r >> n;
    ll border = 1e9, fg = 0;
    if(r==1)cout << a << ln;
    else{
        rept(i, 1, n){
            if(a*r> border){fg = 1; break;}       
            a *= r;
        }
    if(fg) cout << "large" << ln;
    else cout << a << ln;
    }
}
