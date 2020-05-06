#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string  s; cin >> s;
    bool is_num = true;
    rep(i, 3){
        if(s[i] < '0' || s[i] > '9'){
            is_num = false;
        }
    }
    if(is_num){
        int n = stoi(s);
        cout << n*2 << ln;
    } else{
        cout << "error" << ln;
    }
}













