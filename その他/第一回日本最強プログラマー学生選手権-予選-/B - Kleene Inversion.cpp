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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> A(n); rep(i, n) cin >> A[i];

    vector<ll> a(n), b(n);
    rep(i, n){
        rep(j, n){
            if(A[i] > A[j]){
                b[i]++;
                if(j>i)a[i]++;
            }
        }
    }
    ll res = 0;
    rep(i, n){
        ll num = a[i]*k%MOD;
        ll tmp = (b[i]*k%MOD * (k-1))%MOD;
        tmp = tmp * modinv(2, MOD) % MOD;
        num = (num + tmp) %MOD;
        res = (res + num) % MOD;
    }
    cout << res << ln;
}
