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

int func(int n){
    while(n>=10){
        n /=10;
    }
    return n;
}

int main(){

    int n; cin >> n;

    vector<vector<ll>> C(10, vector<ll>(10, 0));
    for(int i=1; i<=n; i++){
        int first = func(i), last = i%10;
        C[first][last]++;
    }
    ll res = 0;
    for(int i=1; i<=n; i++){
        int first = func(i), last = i%10;
        res += C[last][first];
    }
    cout << res << ln;
}

