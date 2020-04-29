#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    string s, ans;
    cin >> s;
    string p = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";

    rep(i, 12){
        int n = p.find(s);
        if(n == 0 || n == 1) ans = "Do";
        if(n == 2 || n == 3) ans = "Re";
        if(n == 4) ans = "Mi";
        if(n == 5 || n == 6) ans = "Fa";
        if(n == 7 || n == 8) ans = "So";
        if(n == 9 || n == 10)ans = "La";
        if(n == 11) ans = "Si";
    }
    cout << ans << ln;
}
    
