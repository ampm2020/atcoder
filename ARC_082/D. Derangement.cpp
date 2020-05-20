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



int main(){ 
    int n; cin >> n;
    vector<int> P(n); rep(i, n) cin >> P[i];

    int res = 0;
    if(P[0] == 1) {swap(P[0], P[1]); res++;}
    for(int i=1; i<n; i++){
        if(P[i] == i+1){
            if(i != n-1 && P[i+1] == i+2){
                swap(P[i], P[i+1]);
            }
            else swap(P[i], P[i-1]);
            res++;
        }
    }
    cout << res << ln;
}