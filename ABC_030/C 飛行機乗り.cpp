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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    int time = 0, cnt = 0;
    while(true){
        int index = lower_bound(all(a), time) - a.begin();
        if(index == a.size()) break;
        time = a[index] + x;

        index = lower_bound(all(b), time) - b.begin();
        if(index == b.size()) break;
        time = b[index] + y;
        cnt++;
    }

    cout << cnt << ln;
}


