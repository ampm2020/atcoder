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
    int n, c; cin >> n >> c;
    vector<vector<int>> D(c, vector<int>(c));
    rep(i, c){
        rep(j, c){
            cin >> D[i][j];
        }
    }
    vector<vector<int>> grid(n, vector<int>(n));
    rep(i, n){
        rep(j, n){
            cin >> grid[i][j];
        }
    }
    vector<int> X(c+1), Y(c+1), Z(c+1); //余り0, 1, 2の順
    for(int i=0; i<3; i++){
        for(int j=1; j<=c; j++){
            int cost = 0;
            rep(y, n){
                rep(x, n){
                    if((y+x+2)%3 != i) continue;
                    cost += D[grid[y][x]-1][j-1];
                }
                if(i==0) X[j] = cost;
                else if(i==1) Y[j] = cost;
                else if(i==2) Z[j] = cost;
            }
        }
    }
    int res = INF;
    for(int i=1; i<=c; i++){
        for(int j=1; j<=c; j++){
            for(int k=1; k<=c; k++){
                if(i==j || j==k || k==i) continue;
                chmin(res, X[i]+Y[j]+Z[k]);
            }
        }
    }

    cout << res << ln;
}
