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
    if (s == "zyxwvutsrqponmlkjihgfedcba") cout << -1 << ln;
    else{
        if(s.size()<26){
            for(char c='a'; c<='z'; c++){
                if(s.find(c) == s.npos){
                    s += c;
                    break;
                }
            }
            cout << s << ln;
        }else{
            vector<char> lst;
            while(!s.empty()){
                lst.push_back(s.back());
                s.erase(s.size()-1);
                sort(all(lst));
                auto iter = upper_bound(all(lst), s.back());
                if(iter == lst.end()) continue;
                s[s.size()-1] = *iter;
                cout << s << ln;
                break;
            }
        }
    }
}
