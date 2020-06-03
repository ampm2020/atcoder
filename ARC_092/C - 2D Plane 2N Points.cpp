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
    vector<int> red(n*2, -1), blue(n*2, -1);
    vector<bool> check_red(n*2);
    rep(i, n){
        int a, b; cin >> a >> b;
        red[a] = b;
    }
    rep(i, n){
        int c, d; cin >> c >> d;
        blue[c] = d;
    }
    int res = 0;
    rep(i, n*2){
        if(blue[i] == -1) continue;
        int bx = i, by = blue[i];
        int rx = INF, ry = -1;
        rep(i, bx){
            if(red[i] > ry && red[i] < by && !check_red[i]){
                rx = i; ry = red[i];
            }
        }
        if(rx != INF){
            res++;
            check_red[rx] = true;
        }
    }
    cout << res << ln;
}


