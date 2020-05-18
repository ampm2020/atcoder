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


int main() {    
    double a, b, h, m; cin >> a >> b >> h >> m;
    
    double hour = h * (360.0/ 12) + m * (1.0 / 2);
    double minute = m * (360.0/ 60);

    double ang = abs(hour - minute); //度数
    ang = min(ang, (360 - ang)) * M_PI / 180; //度数→ラジアン

    cout << fixed << setprecision(12); 
    double res = sqrt(b * b + a * a - cos(ang) * 2 * b * a);
    cout << res << ln;
}