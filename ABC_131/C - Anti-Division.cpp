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
    ll a, b, c, d; cin >> a >> b >> c >> d;

    ll LCM = c / __gcd(c, d) * d;
    ll n = b / c + b / d - b / LCM;
    ll m = (a-1) / c + (a-1) / d - (a-1) / LCM;
    
    ll res = (b - a + 1) - (n - m);
    cout << res << ln;
} 
