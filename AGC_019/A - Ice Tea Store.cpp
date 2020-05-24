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
    ll q, h, s, d, n; cin >> q >> h >> s >> d >> n;

    ll mn_hl = min(q*2, h);
    ll mn_l = min(mn_hl*2, s);
    ll mn_dl = min(mn_l*2, d);
    if(n%2==0) cout << mn_dl*(n/2) << ln;
    else cout << mn_dl * (n/2) + mn_l << ln;
}
