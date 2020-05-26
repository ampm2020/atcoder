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
    map<int, int> mp;
    rep(i, n){
        int a; cin >> a;
        mp[a]++;
    }
    bool fg = true; int siz = mp.size();
    if(siz == 1 && mp[0] != 0) fg = true;
    else if(n%3 != 0) fg = false;
    if(siz > 3) fg = false;
    if(siz == 3){
        vector<int> key,v;
        for(auto m: mp){
            key.push_back(m.first);
            v.push_back(m.second);
        }
        sort(all(v));
        if(v[0] != v[2]) fg = false;
        if(mp.count(0) == 1) fg = false;
        else{
            int xor_ = key[0] ^ key[1];
            if(xor_ != key[2]) fg = false;
        }
    }
    if(siz == 2){
        if(mp.count(0) == 0) fg = false;
        else{
            if(mp[0] == n / 3) fg = true;
            else fg = false;
        }
    }
    if(siz == 1 && mp[0] == 0) fg = false;

    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
}
