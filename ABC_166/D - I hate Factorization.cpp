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

ll rui(ll a,ll b){
     ll ans=1;
     while(b>0){
        if(b&1) ans=ans*a;
        a=a*a;
        b/=2;
    }
     return ans;
}

int main() {
    ll X; cin >> X;
    vector<ll> vc;
    ll A = MOD, B=MOD;
    ll i = 0;
    while(true){
        ll x = rui(i, 5);
        if(x > 10e15) break;
        vc.push_back(x);
        i++;
    }
    rep(i, vc.size()){
        rep(j, vc.size()){
            ll a = vc[i], b = vc[j];
            if(a - b == X)    A = i, B = j;
            
            if(a -(-b) == X) A = i, B = -j;
            if((-a) -b == X) A = -i, B = j;
            if((-a) -(-b) == X) A = -i, B = -j;
            if(A != MOD) break;
        }
    }
    cout << A << " " << B << ln;
}

