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
    int res = INF;
    for(char ch='a'; ch <= 'z'; ch++){
        string t = s;
        while(!t.empty()){
            bool fg = true;
            for(int j=1; j<t.size(); j++){
                if(t[j] != t[0]){
                    fg = false; break;
                }
            }
            if(fg){
                chmin(res, (int)s.size() - (int)t.size());
                break;
            }
            string u = "";
            rep(i, t.size()-1){
                if(t[i] == ch || t[i+1] == ch) u += ch;
                else u += t[i];
            }
            t = u;
        }
    }
    cout << res << ln;
}
