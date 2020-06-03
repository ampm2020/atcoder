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
    int n; cin >> n;
    vector<ll> A(n), B(n);
    rep(i, n) cin >> A[i] >> B[i];

    sort(all(A)), sort(all(B));
    ll res;
    if(n%2==1){
        res = B[n/2] - A[n/2] + 1;
    }else{
        res = (B[(n/2)-1] + B[n/2]) - (A[(n/2)-1] + A[n/2]) + 1;
    }
    cout << res << ln;
}


