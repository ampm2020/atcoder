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
    string s; cin >> s;

    int res = 0;
    while(!s.empty()){
        char a = s[0], b = s.back();
        if(a == b){
            s.pop_back();
            if(!s.empty())s.erase(s.begin());
        }else if(a == 'x'){
            s.erase(s.begin());
            res++;
        }else if(b == 'x'){
            s.pop_back();
            res++;
        }else{
            res = -1; break;
        }
    }
    cout << res << ln;
}