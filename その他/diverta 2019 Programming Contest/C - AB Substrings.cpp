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
    vector<string> b_a, b_, _a, non;
    rep(i, n){
        string s; cin >> s;
        if(s[0] == 'B' && s.back() == 'A') b_a.push_back(s);
        else if(s[0] == 'B')b_.push_back(s);
        else if(s.back() == 'A')_a.push_back(s);
        else non.push_back(s);
    }
    string res;
    if(!_a.empty()){
        res += _a[0];
        _a.erase(_a.begin());
    }
    for(string t: b_a){
        res += t;
    }
    int siz_a = _a.size(), siz_b = b_.size();
    for(int i=0; i<min(siz_a, siz_b); i++){
        res += b_[i]; res += _a[i];
    }
    if(siz_a > siz_b){
        for(int i=siz_b; i< siz_a; i++) res += _a[i];
    }else{
        for(int i=siz_a; i<siz_b; i++) res += b_[i];
    }
    for(string t: non){
        res += t;
    }

    int cnt = 0;
    rep(i, res.size()-1){
        if(res[i] == 'A' && res[i+1] == 'B') cnt++;
    }
    cout << cnt << ln;
}