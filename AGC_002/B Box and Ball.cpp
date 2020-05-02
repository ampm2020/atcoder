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
    int n, m;
    cin >> n >> m;
    vector<int> X(m), Y(m);
    rep(i, m){
        cin >> X[i] >> Y[i];
        X[i]--; Y[i]--;
    }

    vector<bool> isRed(n, false);
    vector<int> number(n, 1);
    isRed[0] = true;

    rep(i, m){
        int x = X[i], y = Y[i];
        if(isRed[x]) isRed[y] = true;
        number[x]--; number[y]++;
        if(number[x] == 0) isRed[x] = false;
    }

    int ans = 0;
    rep(i, n) ans += isRed[i];
    cout << ans << ln;
}
