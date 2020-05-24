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
    int a, b, m; cin >> a >> b >> m;
    vector<int> A(a), B(b);
    int min_A = INF, min_B = INF;
    rep(i, a){
        cin >> A[i];
        chmin(min_A, A[i]);
    }
    rep(i, b){
        cin >> B[i];
        chmin(min_B, B[i]);
    }
    int res = min_A + min_B;
    rep(i, m){
        int x, y, c; cin >> x >> y >> c; x--, y--;
        chmin(res, A[x] + B[y] - c);
    }
    cout << res << ln;
}
