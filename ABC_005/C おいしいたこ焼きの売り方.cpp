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
    int t, n, m;
    cin >> t >> n;
    vector<int> tako(n);
    rep(i, n) cin >> tako[i];
    cin >> m;
    vector<int> guest(m);
    rep(i, m) cin >> guest[i];

    bool f = true;
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i, n) que.push(tako[i]);
    rep(i, m){
        int gt = guest[i];
        //cout << "tt:" << tt << " gt" << gt << ln;
        bool f2 = false;
        while(!que.empty()){
            int tt = que.top(); que.pop();
            if(tt > gt) {f = false; break;}
            if(tt + t >= gt) {f2 = true; break;}
        }
        if(que.empty() && !f2){f = false; break;}
    }
    if(f) cout << "yes" << ln;
    else cout << "no" << ln;
    
}
