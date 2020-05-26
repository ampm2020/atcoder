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

int main(){
    int n; string s; cin >> n >> s;
    vector<int> SW(n+1), SB(n+1);
    SW[0] = 0, SB[0] = 0;
    rep(i, n){
        SW[i+1] = SW[i]; SB[i+1] = SB[i];
        if(s[i] == '.') SB[i+1]++;
        else SW[i+1]++;
    }

    int res = INF;
    rep(i, n+1){
        chmin(res, SW[i]+(SB[n]-SB[i]));
    }
    cout << res << ln;
}