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
    int N, Q; cin >> N >> Q;
    vector<vector<char>> list(N, vector<char>(N,'N'));

    rep(i, Q){
        int n; cin >> n;
        if(n == 1){
            int from, to; cin >> from >> to; from--, to--;
            list[from][to] = 'Y';
        }
        if(n == 2){
            int u; cin >> u; u--;
            rep(j, N){
                if(j == u) continue;
                if(list[j][u] == 'Y') list[u][j] = 'Y';
            }
        }
        if(n == 3){
            int u ; cin >> u; u--;
            vector<int> fri;
            rep(j, N){
                if(list[u][j] == 'Y'){
                    rep(k, N){
                        if(list[j][k] == 'Y'){
                            fri.push_back(k);
                        }
                    }
                }
            }
            for(int f: fri) {
                if(u == f) continue;
                list[u][f] = 'Y';
                }
        }
    }
    rep(i, N){
        rep(j, N){
            cout << list[i][j];
        }
        cout << ln;
    }
}





