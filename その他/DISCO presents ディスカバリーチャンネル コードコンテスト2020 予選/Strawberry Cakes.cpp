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
    int h, w, k; cin >> h >> w >> k;
    vector<string> cake(h);
    rep(i, h) cin >> cake[i];

    vector<vector<int>> cut(h, vector<int>(w));
    int num = 0;
    rep(x, w){
        bool ichigo = false;
        rep(i, h) if(cake[i][x] == '#') ichigo = true;
        if(ichigo){
            num++;
            int cnt = 0;
            rep(i, h){
                if(cake[i][x] == '#'){
                    cnt++;
                    if(cnt >= 2) num++;
                }
                cut[i][x] = num;
            }
        }else{
            rep(i, h) cut[i][x] = 0;
        }
    }

    vector<int> val(h); int last = -1;
    rep(x, w){
        if(cut[0][x] != 0){
            rep(i, h) val[i] = cut[i][x];
            rep(i, h){
                for(int j=last+1; j<x; j++){
                   cut[i][j] = val[i];
                }
            }
            last = x;
        }
    }
    if(last != w-1){
        rep(i, h){
            for(int j=last+1; j<w; j++) cut[i][j] = val[i];
        }
    }

    rep(i, h){
        rep(j, w){
            cout << cut[i][j];
            if(j<w-1) cout << " ";
        }
        cout << ln;
    }
}