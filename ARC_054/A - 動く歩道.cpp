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



int main(){ 
    double l, x, y, s, d;
    cin >> l >> x >> y >> s >> d;

    double res;
    if(s==d) res = 0;
    else{
        double dist_a, dist_b;
        if(d > s) dist_a = d - s, dist_b = l - dist_a;
        else dist_b = s - d, dist_a = l - dist_b;
        double speed_a = x + y, speed_b = y - x;
        if(speed_b <= 0) res = dist_a / speed_a;
        else res = min(dist_a / speed_a, dist_b / speed_b);
    }

    cout << fixed << setprecision(10);
    cout << res << ln;
}