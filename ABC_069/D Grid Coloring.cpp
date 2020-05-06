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
    int H, W, n; cin >> H >> W >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int grid[H][W];
    pii pos(0, 0);
    rep(i, n){
        int color = i + 1;
        rep(j, a[i]){
            int h = pos.first, w = pos.second;
            //cout << "h;" << h << " w:" << w << " color:" << color << ln;
            grid[h][w] = color;
            if(h%2==0){
                if(w==W-1) pos.first++;
                else pos.second++;
            }else{
                if(w==0) pos.first++;
                else pos.second--;
            }   
        }
    }

    rep(i, H){
        rep(j, W){
            cout << grid[i][j];
            if(j!=W-1) cout << " ";
        }
        cout << ln;
    }
}


