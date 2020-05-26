#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 998244353LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll rui(ll a,ll b){
     ll ans=1;
     while(b>0){
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
     return ans;
}

int main() {
    int n; cin >> n;
    vector<ll> counter(n, 0);
    ll res = 1;
    rep(i, n){
        ll d; cin >> d;
        counter[d]++;
        if(i==0&&d!=0 || i!=0&&d==0) res = 0;
    }
    bool not_find = false;
    for(int i=1; i<n; i++){
        if(counter[i] == 0) not_find = true;
        if(not_find && counter[i] != 0) res = 0;
    }
    if(res == 0) cout << res << ln;
    else{
        for(int i=1; i<n; i++){
            if(counter[i] == 0) break;
            res = res * rui(counter[i-1], counter[i]) % MOD;
        }
        cout << res << ln;
    }
}

