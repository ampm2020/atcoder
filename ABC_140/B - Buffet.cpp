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
    vector<int> A(n), B(n), C(n-1);
    rep(i, n) cin >> A[i], A[i]--;
    rep(i, n) cin >> B[i];
    rep(i, n-1) cin >> C[i];

    int res = 0;
    rep(i, n){
        res += B[A[i]];
        if(i<n-1 && A[i]+1==A[i+1]){
            res += C[A[i]];
        }
    }    
    cout << res << ln;
}
