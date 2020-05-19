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
    ll r, b, x, y; cin >> r >> b >> x >> y;

    ll ok = 0, ng = (r + b) / 2 + 1;
    while(ng - ok > 1){
        ll mid = (ng + ok) / 2;
        //cout << "mid:" << mid;
        ll r_ = r - mid, b_ = b - mid;
        //cout << " r_:" << r_ << " b_:" << b_ << ln;
        if(r_ < 0 || b_ < 0) ng = mid;
        else{
            ll p = r_ / (x - 1) + b_ / (y - 1);
            //cout << "p:" << p << ln;
            if(p >= mid) ok = mid;
            else ng = mid;
        }
    }
    cout << ok << ln; 
} 
