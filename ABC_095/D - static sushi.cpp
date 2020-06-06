#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    int n; ll c; cin >> n >> c;
    vector<ll> X(n), V(n);
    rep(i, n) cin >> X[i] >> V[i];
    
    vector<ll> SR(n+1), SR_MAX(n+1), SL(n+1), SL_MAX(n+1);
    //R
    rep(i, n){
        ll val = V[i] - (X[i] - (i>0? X[i-1] : 0));
        SR[i+1] = SR[i] + val;
        SR_MAX[i+1] = max(SR_MAX[i], SR[i+1]);        
        //cout << "S:" << SR[i+1] << " SM:" << SR_MAX[i+1] << ln;
    }
    //L
    rep(i, n){
        int ind = n-1-i;
        ll val = V[ind] - (c-X[ind]-(i>0? c-X[ind+1] : 0));
        SL[i+1] = SL[i] + val;
        SL_MAX[i+1] = max(SL_MAX[i], SL[i+1]);
        //cout << "S:" << SL[i+1] << " SM:" << SL_MAX[i+1] << ln;
    }
    ll res = 0;
    rep(i, n+1){
        int R = i, L = n-i;
        chmax(res, SR_MAX[R] + SL_MAX[L] - (i>0?X[R-1]:0));
    }
    reverse(all(X));
    rep(i, n+1){
        int L = i, R = n-i;
        chmax(res, SL_MAX[L] + SR_MAX[R] - (i>0?c-X[L-1]:0));
    }

    cout << res << ln;
}