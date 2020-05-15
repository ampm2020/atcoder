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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int h,w; cin >> h >> w;
    vector<vector<int>> grid(h+2, vector<int>(w+2, -1));
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> res;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            if(h==1 && w== 1) break;
            if(grid[i][j] % 2 == 0) continue;
            vector<int> order{i, j};
            bool f_odd = false;
            rep(k, 4){
                int y = i + dy[k], x = j + dx[k];
                if(grid[y][x] != -1 && grid[y][x] % 2 == 1){
                    f_odd = true;
                    order.push_back(y); order.push_back(x);
                    grid[i][j]--; grid[y][x]++;
                    break;
                }
            }
            if(!f_odd){
                rep(k, 4){
                    int y = i + dy[k], x = j + dx[k];
                    if(grid[y][x] != -1){
                        order.push_back(y); order.push_back(x);
                        grid[i][j]--; grid[y][x]++;
                        break;
                    }
                }
            }
            res.push_back(order);
        }
    }
    cout << res.size() << ln;
    rep(i, res.size()){
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << " " << res[i][3] << ln;
    }   
}

    