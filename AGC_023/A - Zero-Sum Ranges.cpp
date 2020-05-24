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


int main(){ 
    int n; cin >> n;
    vector<ll> A(n), S(n+1);
    map<ll, int> mp; mp[0]++;
    rep(i, n){
        cin >> A[i];
        S[i+1] = S[i] + A[i];
        mp[S[i+1]]++;
    }
    ll res = 0;
    for(auto m: mp){
        ll val = m.second;
        res += val * (val-1) / 2;
    }
    cout << res << ln;
}