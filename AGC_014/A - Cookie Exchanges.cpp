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


int main() {    
    int a, b, c;
    cin >> a >> b >> c;
    if( a%2 == 0 && a == b && b == c) cout << -1 << ln;
    else{
        int cnt = 0;
        while(1){
            if(a%2==1 || b%2==1 || c%2==1) break;
            int a_ = a/2, b_ = b/2, c_ = c/2;
            a = b_+c_;
            b = a_+c_;
            c = a_+b_;
            cnt++;
        }
        cout << cnt << ln;
    }
}
