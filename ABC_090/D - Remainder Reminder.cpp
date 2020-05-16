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
    int n, k; cin >> n >> k;
    /*rep(i, n){
        rep(j, n){
            cout << (i+1)%(j+1) << " ";
        }
        cout << ln;
    }*/
    ll res = 0, cnt = 1;
    for(int i=k; i<n; i++){
        res += (n / (i+1)) * cnt;
        //cout << "res:" << res << "  ";
        cnt++;
        res += max(0, (n % (i+1)) - max(0, k-1));
        //cout << "res:" << res << ln;
    }
    cout << res << ln;
}