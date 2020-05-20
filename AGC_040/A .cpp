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

ll sum(int mx, int mn){
    if(mx < mn) swap(mx, mn);

    ll ret = 0;
    for(int i=1; i<=mx; i++) ret += i;
    for(int i=1; i<mn; i++) ret += i;

    return ret;
}

int main(){ 
    string s; cin >> s;
    bool is_up = true;

    ll res = 0, up = 0, down = 0;
    rep(i, s.size()){
        char c = s[i];
        if(is_up && c == '>') is_up = false;
        if(!is_up && c == '<'){
            res += sum(up, down);
            is_up = true, up = 0, down = 0;
        }

        if(c == '<') up++;
        else down++;
    }
    res += sum(up, down);
    cout << res << ln;
}