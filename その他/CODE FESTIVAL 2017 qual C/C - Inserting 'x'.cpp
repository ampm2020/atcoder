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
    string s, t, u; cin >> s;
    for(char c: s) if(c != 'x') t += c;
    u = t; reverse(all(u));

    if(t != u) cout << -1 << ln;
    else{
        vector<int> counter; int cnt = 0;
        rep(i, s.size()){
            if(s[i] != 'x'){
                counter.push_back(cnt);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        counter.push_back(cnt);
        int res = 0;
        rep(i, counter.size()/2){
            res += abs(counter[i] - counter[counter.size()-1-i]);
        }
        cout << res << ln;
    }
}