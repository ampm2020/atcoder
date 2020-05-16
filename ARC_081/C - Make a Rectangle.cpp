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
    int n; cin >> n;
    map<ll, int, greater<ll>> mp;
    rep(i, n){
        ll a; cin >> a;
        mp[a]++;
    }

    ll a = 0, b = 0;
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        ll key = iter->first; int val = iter->second;
        if(val >= 2){
            if(a==0) a = key;
            else if(b==0) b = key;
            val -= 2;
        }
        if(val >= 2){
            if(b==0) b = key;
        }
    }
    cout << a * b << ln;
}