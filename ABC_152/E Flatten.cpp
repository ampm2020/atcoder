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

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

ll rui(ll a,ll b){
     ll ans=1;
     while(b>0){
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
     return ans;
}

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

int main(){
    int n; cin >> n; 
    vector<ll> A(n), num(1100000, 0);
    rep(i, n){
        cin >> A[i];
        auto pf = prime_factorize(A[i]);
        for(auto p: pf) chmax(num[p.first], p.second);  
    }
    
    ll LCM = 1;
    for(int v = 2; v < 1100000; v++){
        LCM = LCM * rui(v, num[v]) % MOD;
    }

    ll res = 0;
    for(auto a: A){
        ll inv = modinv(a, MOD);
        ll tmp = LCM * inv % MOD;
        res = (res + tmp) % MOD;
    }
    cout << res << ln;
}

