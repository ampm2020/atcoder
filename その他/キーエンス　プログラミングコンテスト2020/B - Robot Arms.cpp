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
    vector<pll> arms;
    rep(i, n){
        ll x, l; cin >> x >> l;
        ll left = x-l, right = x+l;
        arms.emplace_back(right, left);
    }
    sort(all(arms));
    ll res = 0, place = -INF*100;
    rep(i, n){
        ll left = arms[i].second, right = arms[i].first;
        if(left >= place){
            res++;
            place = right;
        }
    }
    cout << res << ln;
}