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
    string s; int x, y; cin >> s >> x >> y;
    vector<int> X, Y;
    
    int turn = 0; int cnt = 0;
    for(char c: s){
        if(c == 'F') cnt++;
        else{
            if(turn%2==0){
                X.push_back(cnt);
            }else{
                Y.push_back(cnt);
            }
            cnt = 0;
            turn++;
        }
    }
    if(turn%2==0) X.push_back(cnt);
    else Y.push_back(cnt);

    int sx = X.size(), sy = Y.size();
    vector<vector<bool>> dx(sx+1, vector<bool>(8000*2+10));
    vector<vector<bool>> dy(sy+1, vector<bool>(8000*2+10));
    dx[0][8000] = true; dy[0][8000] = true;
    rep(i, sx){
        rep(j, 8000*2+10){
            if(dx[i][j]){
                dx[i+1][j+X[i]] = true;
                if(i>0) dx[i+1][j-X[i]] = true;
            }
        }
    }   
    rep(i, sy){
        rep(j, 8000*2+10){
            if(dy[i][j]){
                dy[i+1][j+Y[i]] = true;
                dy[i+1][j-Y[i]] = true;
            }
        }
    }    
    
    if(dx[sx][x+8000] && dy[sy][y+8000]) cout << "Yes" << ln;
    else cout << "No" << ln;
}
