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

int main(){
    double n; cin >> n;
    int a, b, c;
    for(int i=1; i<=3500; i++){
        for(int j=1; j<=3500; j++){
            double d = n*i*j/(4*(double)i*j - n*i - n*j);
                if(d == (int)d && d > 0){
                    a = i, b = j, c = d;
                }
        }
    }
    cout << a << " " << b << " " << c << ln;
}
