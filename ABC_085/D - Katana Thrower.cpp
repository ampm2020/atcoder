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
    int n, h; cin >> n >> h;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];
    sort(all(A)), sort(all(B),greater<ll>());
    
    //刀をi本投げる場合の最低攻撃回数
    ll throw_ = 0; ll res = INF;
    for(int i=0; i<=n; i++){
        ll slash_ = max(h - throw_, (ll)0);
        ll num = slash_ / A[n-1] + i;
        if(slash_ && slash_ % A[n-1]) num++;
        chmin(res, num);
        if(i < n) throw_ += B[i];
    }

    cout << res << ln;
}