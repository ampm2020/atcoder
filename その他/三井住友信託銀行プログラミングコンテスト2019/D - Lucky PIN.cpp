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
    int n; string s; cin >> n >> s;
    
    int res = 0;
    rep(i, 1000){
        vector<int> num{i/100, i/10%10, i%10};
        int p = 0;
        for(char c: s){
            if(c - '0' == num[p]){
               p++; 
            }
            if(p == 3){
                res++;
                break;
            }
        }
    }
    cout << res << ln;
}