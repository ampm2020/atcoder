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

using pos = pair<pair<int, int>, int>; //座標、操作回数
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int H, W; cin >> H >> W;
    vector<vector<char>> grid(H+2, vector<char>(W+2, '#'));
    int cnt = 0; queue<pos> que;
    for(int i=1; i<=H; i++){
        string s; cin >> s;
        for(int j=1; j<=W; j++){
            grid[i][j] = s[j-1];
            if(grid[i][j] == '#'){
                pos p{{i, j}, 0};
                que.push(p);
                cnt++;
            }
        }
    }
    int res = 0;
    while(cnt < H*W){
        pos p = que.front(); que.pop();
        int y = p.first.first, x = p.first.second, cost = p.second;
        rep(i, 4){
            int ny = y + dy[i], nx = x + dx[i];
            if(grid[ny][nx] == '#')continue;
            pos np = {{ny, nx}, cost+1};
            que.push(np);
            grid[ny][nx] = '#';
            res = cost + 1;
            cnt++;
        }
    }
    cout << res << ln;
}
