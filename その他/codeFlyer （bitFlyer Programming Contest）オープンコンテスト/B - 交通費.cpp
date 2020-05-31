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


int main() {   
    int N, Q; cin >> N >> Q;
    vector<ll> X(N), S(N+1);
    rep(i, N)cin >> X[i];
    sort(all(X));
    rep(i, N) S[i+1] = S[i] + X[i];

    vector<ll> ans;
    rep(i, Q){
        ll c, d; cin >> c >> d;
        ll res = 0;
        int l = lower_bound(all(X), c-d) - X.begin();
        int r = lower_bound(all(X), c+d) - X.begin();
        int cen = lower_bound(all(X), c) - X.begin();
        res += (c * (cen - l)) - (S[cen] - S[l]);
        res += (S[r] - S[cen]) - (c * (r - cen));
        res += d * (N - (r - l));
        ans.push_back(res);
    }
    for(ll num: ans) cout << num << ln;
}

