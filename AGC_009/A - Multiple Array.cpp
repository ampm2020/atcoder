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
    int n; cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n){
        ll a, b; cin >> a >> b;
        A[i] = a % b; B[i] = b;
    }
    ll res = 0;
    for(int i=n-1; i>=0; i--){
        A[i] = (A[i] + res) % B[i];
        res += A[i]== 0 ? 0 : B[i] - A[i];
    }
    cout << res << ln;
}
