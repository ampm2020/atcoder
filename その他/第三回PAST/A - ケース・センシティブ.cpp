#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct ToUpper {
    char operator()(char c) { return toupper(c); }
};

int main(){ 
    string s, t; cin >> s >> t;
    if(s == t) cout << "same" << ln;
    else{
        transform(all(s),s.begin(), ToUpper());
        transform(all(t),t.begin(), ToUpper());
        if(s == t) cout << "case-insensitive" << ln;
        else cout << "different" << ln;
    }
}
