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
    string s; cin >> s;
    int len = s.size();
    bool fg = false;
    if(s.substr(0, 7) == "keyence") fg = true;
    else if(s.substr(len-7, 7) == "keyence")fg = true;
    else if(s.substr(0, 1) == "k" && s.substr(len-6, 6) == "eyence") fg = true;
    else if(s.substr(0, 2) == "ke" && s.substr(len-5, 5) == "eyence") fg = true;
    else if(s.substr(0, 3) == "key" && s.substr(len-4, 4) == "ence") fg = true;
    else if(s.substr(0, 4) == "keye" && s.substr(len-3, 3) == "nce") fg = true; 
    else if(s.substr(0, 5) == "keyen" && s.substr(len-2, 2) == "ce") fg = true;
    else if(s.substr(0, 6) == "keyenc" && s.substr(len-1, 1) == "e") fg = true;  
    if(fg) cout << "YES" << ln;
    else cout << "NO" << ln; 
}
