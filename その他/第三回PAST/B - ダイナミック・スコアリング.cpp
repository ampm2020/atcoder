#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> solved(N);
    vector<int> point(M, N);

    vector<ll> res;
    rep(i, Q){
        int q; cin >> q;
        if(q==1){
            int n; cin >> n; n--;
            int sum = 0;
            for(int num: solved[n])sum += point[num];
            res.push_back(sum);
        }else{
            int n, m; cin >> n >> m; n--, m--;
            point[m]--;
            solved[n].push_back(m);
        }
    }
    for(int ans: res) cout << ans << ln;
}