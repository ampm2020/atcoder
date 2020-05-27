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

int main(){
    int n; cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i];
    rep(i, n) cin >> B[i];

    ll mana = 0, cost = 0;
    rep(i, n){
        ll a = A[i], b = B[i];
        if(a < b) mana += (b-a)/2;
        else if(a > b) cost += a-b;
    }

    if(mana >= cost) cout << "Yes" << ln;
    else cout << "No" << ln;
    
}