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

const int max_digit = 50;
long long dp[100][2];

int main() {
    int n; ll k; cin >> n >> k;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    rep(i, 100)rep(j,2) dp[i][j] = -1;
    dp[0][0] = 0;

    rep(d, max_digit){
        ll mask = 1LL<<(max_digit-d-1);

        int num = 0;
        rep(i, n) if(A[i] & mask) num++;

        ll cost0 = mask * num;
        ll cost1 = mask * (n-num);

        //smaller -> smaller 0->1, 0->0の二通りある
        //自由に遷移して良いので、貪欲に取る
        if(dp[d][1] != -1){
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));//どっちでも良い
        }
        //exact -> smaller 1->0しかない
        if(dp[d][0] != -1){
            if(k & mask){
                chmax(dp[d+1][1], dp[d][0] + cost0);//0しか選べない
            }
        }
        //exact ->exact 1->1, 0->0の二通りある
        if(dp[d][0]!= -1){
            if(k & mask) chmax(dp[d+1][0], dp[d][0]+cost1);
            else chmax(dp[d+1][0], dp[d][0] + cost0);
        }
    }
    cout << max(dp[max_digit][0], dp[max_digit][1]) << ln;
}