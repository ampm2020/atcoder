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


int main(){ 
    int n, A, B, C, D; cin >> n >> A >> B >> C >> D; A--, B--, C--, D--;
    string S; cin >> S;

    bool fg= true;
    for(int i=min(A,B); i<max(C,D); i++){
        if(S[i] == '#' && S[i+1] == '#'){
            fg = false; break;
        }
    }
    if(C>D){
        bool fg2 = false;
        for(int i=B; i<=D; i++){
            if(S[i] != '#' && S[i-1] != '#' && S[i+1] != '#'){
                fg2 = true; break;
            }
        }
        if(!fg2) fg = false;
    }

    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
}