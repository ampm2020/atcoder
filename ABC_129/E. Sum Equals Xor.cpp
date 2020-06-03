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

ll dp[100010][2];

int main() { 
    string L; cin >> L;
    int len = L.size();
    rep(i, 100010)rep(j ,2) dp[i][j] = 0;
    dp[0][0] = 1;

    rep(i, len){
        if(L[i] == '0'){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][1] * 3 % MOD;
        }else{
            dp[i+1][0] = dp[i][0] * 2 % MOD;
            dp[i+1][1] = (dp[i][1] * 3 % MOD + dp[i][0]) % MOD;
        }
    }
    cout << (dp[len][0] + dp[len][1]) % MOD << ln;
}

/*
Lの各桁ごとにa,bの二進数表現が取りうる値を見ていく
a+b<=Lなので、a<=L, b<=Lであり、Lより大きい桁を見る必要はない
各L[i]ごとに取れる組み合わせは(0,0)(0,1)(1,0)(1,1)の四通り。
L[i]==0のとき、
smallerなら(1,1)以外なら自由に組み合わせてよい
!smallerなら(0,0)以外を選ぶとa+b>Lになってしまうので1通り
L[i]==1のとき
smallerならry
!smallerなら、(0,0)を選ぶとその数はL未満になるのでsmallerに移行
(0,1),(1,0)なら和は1になり引き続きexactとなる
*/


