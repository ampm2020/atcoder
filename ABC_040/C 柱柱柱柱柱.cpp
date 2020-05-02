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

const int MAX_N = 100100;

vector<int> a(MAX_N);
vector<int> dp(MAX_N, INF * 2);

int func(int n){
    if(n == 0) return dp[0] = 0;
    if(n == 1) return dp[1] = abs(a[1] - a[0]);
    if(dp[n] != INF*2) return dp[n];

    chmin(dp[n],func(n-1)+abs(a[n]-a[n-1]));
    chmin(dp[n], func(n-2)+abs(a[n]-a[n-2]));

    return dp[n];
}

int main(){
   int n;
   cin >> n;
   rep(i, n) cin >> a[i];

    func(n-1);
    cout << dp[n-1] << ln;;
}

