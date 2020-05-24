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


int main() {
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    ll LCM = n / __gcd(n, m) * m;
    map<int, char> mp;
    bool fg = true;
    rep(i, n){
        mp[i*(LCM/n)] = s[i];
    }
    rep(i, m){
        int index = i*LCM/m;
        if(mp[index]>= 'a' && mp[index] <= 'z' && mp[index] != t[i]){
            fg = false; break;
        }
    }
    if(fg) cout << LCM << ln;
    else cout << -1 << ln;
}
