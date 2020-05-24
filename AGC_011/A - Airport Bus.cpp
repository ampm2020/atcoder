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
    int n, c, k; cin >> n >> c >> k;
    vector<int> T(n); rep(i, n) cin >> T[i];

    sort(all(T));
    int res = 1, cnt = 1, last = T[0] + k;
    for(int i=1; i<n; i++){
        if(T[i] <= last && cnt < c){
             cnt++;
        }else{
            res++; cnt = 1;
            last = T[i] + k;
        }
    }
    cout << res << ln;
}
