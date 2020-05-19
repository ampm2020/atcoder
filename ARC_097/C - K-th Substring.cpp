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
    string s; int k; cin >> s >> k;

    set<string> used;
    bool fg = false;

    vector<string> substrings;
    rep(i, s.size()){
        substrings.push_back(s.substr(i));
    }
    sort(all(substrings));
    for(string t: substrings){
        if(fg) break;
        rep(i, t.size()){
            string u = t.substr(0, i+1);
            used.insert(u);
            if(used.size() == k && !fg){
                cout << u << ln;
                fg = true;
                break;
            }
        }
    }    
} 
