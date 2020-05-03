#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    map<ll, ll> L, R;
    rep(i, n){
        int l = A[i] + i + 1;
        int r = i + 1 - A[i];
        L[l]++, R[r]++;
    }
    ll sum = 0;
    auto begin = L.begin(), end = L.end();
    for (auto iter = begin; iter != end; iter++) {
       sum +=  L[iter->first] * R[iter->first];
    }
    cout << sum << ln;
}



