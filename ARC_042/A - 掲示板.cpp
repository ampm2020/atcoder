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



int main(){ 
    int n, m; cin >> n >> m;
    
    map<int, int> mp;
    rep(i, m){
        int a; cin >> a;
        mp[a] = -(i+1);
    }
    vector<pii> list;
    rep(i, n){
        int key = i+1, val = mp[key];
        list.push_back(pii(val, key));
    }
    sort(all(list));
    rep(i,n){
        cout << list[i].second << ln;
    }
}