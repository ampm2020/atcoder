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

int main(){
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll res = 0;
    //各桁の0,1の数を調査
    rep(d, 60){
        ll n0 = 0, n1 = 0;
        rep(i, n){
            if((A[i] >> d) & 1) n1++;
            else n0++; 
        }
        ll tmp = (1ll << d) % MOD;
        ll n = n0 * n1 % MOD;
        tmp = tmp * n % MOD;
        res = (res + tmp) % MOD;
    }
    cout << res % MOD << ln;
}

