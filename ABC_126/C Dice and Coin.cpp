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

ll rui(ll a,ll b){
     ll ans=1;
     while(b>0){
        if(b&1) ans=ans*a%MOD;
        a=a*a%MOD;
        b/=2;
    }
     return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    double ans = 0;
    
    for(int i = 1; i <= n; i++){
        double win = 1.0 / n;
        int num = i;
        int cnt = 0;
        while(num < k){
            num *= 2;
            cnt++;
        }
        ll ruijo = rui(2, cnt);
        win /= ruijo;
        ans += win;
    }
    cout << fixed << setprecision(12);
    cout << ans << ln;
}
