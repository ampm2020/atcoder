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
    int h, w; cin >> h >> w;
    map<char, int> mp;
    rep(i, h){
        string s; cin >> s;
        for(char c: s) mp[c]++;
    }
    vector<int> count;
    for(auto m: mp) count.push_back(m.second);

    vector<int> query;
    rep(i, (h/2)*(w/2)) query.push_back(4);
    if(h%2==1 && w%2==1){
        rep(i, (h/2)+(w/2)) query.push_back(2);
        query.push_back(1);
    }else if(h%2==1 || w%2==1){
        int num = h%2==1 ? w : h;
        rep(i, num/2) query.push_back(2);
    }

    bool fg = true;
    for(int q: query){
        sort(all(count));
        auto iter = lower_bound(all(count), q);
        if(iter == count.end()){
            fg = false; break;
        }
        count[count.size()-1] -= q;
    }

    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
}
