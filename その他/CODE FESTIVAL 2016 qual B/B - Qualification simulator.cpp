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
    int n, a, b; string s; cin >> n >> a >> b >> s;
    int pass = 0, cnt = 1;
    for(char c: s){
        if(c == 'c') cout << "No" << ln;
        if(c == 'a'){
            if(pass < a+b){
                cout << "Yes" << ln;
                pass++;
            }else cout << "No" << ln;
        }
        if(c == 'b'){
            if(pass < a+b && cnt <= b){
                cout << "Yes" << ln;
                pass++, cnt++;
            }else cout << "No" << ln;
        }
    }

}
