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
    int n, k; string s;
    cin >> n >> k >> s;

    int cnt = 0;
    rep(i, s.size()){
        if(i==0 && s[i]=='L' || i==s.size()-1 && s[i] == 'R')
            continue;
        if(s[i] == 'R' && s[i+1] == 'R' || s[i] == 'L' && s[i-1] == 'L')
            cnt++;
    }
    int res = min((int)s.size()-1, cnt + k * 2);
    cout << res << ln;
}
