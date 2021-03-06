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
    int num = 0, res;
    for(int i=1; i<10000000; i++){
        num += i;
        if(num >= n){
            res = i;
            break;
        }
    }
    for(int i=res; i>0; i--){
        if(n <= 0) break;
        if(n-i>=0){
            cout << i << ln;
            n -= i;
        }
    }
}
