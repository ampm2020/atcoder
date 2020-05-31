#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 998244353;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
vector<ll> H, S;

bool check(ll guess){
    vector<ll> v;
    rep(i, n){
        if(guess < H[i]) return false;
        ll num = (guess - H[i])/ S[i];
        v.push_back(num);
    }
    sort(all(v));
    rep(i, n){
        if(v[i]<i) return false;
    }
    return true;
}

int main() {   
    cin >> n;
    rep(i, n){
        ll h, s; cin >> h >> s;
        H.push_back(h); S.push_back(s);
    }

    ll ng = -1, ok = 1e18 + 100;
    while(ok - ng > 1){
        ll mid = (ng + ok) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << ln;
}

