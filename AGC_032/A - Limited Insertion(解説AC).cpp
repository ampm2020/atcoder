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
    vector<int> B(n); rep(i, n) cin >> B[i];

    bool fg = true;
    vector<int> R;
    while(!B.empty()){
        int ins = -1;
        rep(i, B.size()){
            if(B[i] == i+1) ins = i+1;
        }
        if(ins == -1){
            fg = false; break;
        }
        R.push_back(ins);
        B.erase(B.begin()+ins-1);
    }
    if(fg){
        for(int i=n-1; i>=0; i--){
            cout << R[i] << ln;
        }
    }else cout << -1 << ln;
}
