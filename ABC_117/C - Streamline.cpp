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
    int n, m; cin >> n >> m;
    vector<int> X(m); rep(i, m) cin >> X[i];
    if(n>=m) cout << 0 << ln;
    else{
        sort(all(X));
        vector<int> D(m-1); int sum = 0;
        rep(i, m-1){
            D[i] = abs(X[i+1]-X[i]);
            sum += D[i];
        }
        sort(all(D), greater<int>());
        rep(i, n-1){
            sum -= D[i];
        }
        cout << sum << ln;
    }
}
