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
    int n; string s, t; cin >> n >> s >> t;
    string r = s + t;
    int res = r.size();
    for(int i=n-1; i>=0; i--){
        if(r.size() == 1) break;
        r.erase(i, 1);
        string a = r.substr(0, n), b = r.substr(r.size()-n);
        if(a == s && b == t)
            res = r.size();
    }
    cout << res << ln;
}
