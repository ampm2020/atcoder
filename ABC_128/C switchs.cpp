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

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connect(m, vector<int>());
    vector<int> type(m); 
    rep(i, m){
        int k; cin >> k;
        rep(j, k){
            int s; cin >> s; s--;
            connect[i].push_back(s);
        }
    }
    rep(i, m) cin >> type[i];

    int res = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        bool f = true;
        rep(i, m){
            int number = 0;
            for(int denkyu: connect[i]){
                int on_off = bit & (1 << denkyu);
                if(on_off) number++;
            } 
            if(type[i] != number % 2){
                f = false;
                break;
            }
        }
        if(f) res++;
    }
    cout << res << ln;

}
