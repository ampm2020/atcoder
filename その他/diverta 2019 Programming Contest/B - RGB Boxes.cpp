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
    int r, g, b, n; cin >> r >> g >> b >> n;
    ll res = 0;
    rep(i, n+1){
        rep(j, n+1){
            int m = r*i + g*j;
            if(m>n) continue;
            double z = (n-m)/(double)b;
            if(z == floor(z)) res++;
        }
    }
    cout << res << ln;
}
